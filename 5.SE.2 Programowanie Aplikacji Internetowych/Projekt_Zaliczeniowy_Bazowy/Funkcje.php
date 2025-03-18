<?php
function wyswietlenieOgloszenia($akcja, $dbh) {
    $query = 'SELECT o.Id, o.Nazwa, d.Nazwa, o.Wynagrodzenie, o.WynagrodzenieGorne, p.Nazwa, p.Id FROM Ogloszenie o 
            JOIN Pracodawca p ON o.PracodawcaId = p.Id JOIN Doswiadczenie d ON o.DoswiadczenieId = d.Id;';
    $pola = ['o.Id', 'o.Nazwa', 'd.Nazwa', 'o.Wynagrodzenie', 'o.WynagrodzenieGorne', 'p.Nazwa', 'p.Id'];
    $ilepol = count($pola);
    
    if(isset($akcja)) {
        $tresc = walidacjaWyszukiwarki();
        if($tresc==null) {
            $wynikZapytania = $dbh->select($query);
        } else if(substr($tresc, 0, 6)==="SELECT") {
            $wynikZapytania = $dbh->select($tresc);
            if ($wynikZapytania->num_rows === 0) {
                echo '<div class="Uwaga"><ul><li>Brak ogłoszeń o podanych parametrach</li></ul></div>';
                $wynikZapytania = $dbh->select($query);
            }
            
        } else {
            //Wyswietlenie bledow wyszukiwania linijka po linijce
            $tresc = explode(".", $tresc);
            echo '<div class="Uwaga"><ul>';
            foreach($tresc as $i) {
                echo "<li>$i</li>";
            }
            echo '</ul></div>';
            $wynikZapytania = $dbh->select($query);
        }
        //Można zrobić funkcję wyświetlającą wszystkie ogłoszenia
    } else {
        $wynikZapytania = $dbh->select($query);
    }
    
    if($wynikZapytania->num_rows === 0) {
        echo '<div class="Uwaga"><ul><li>Brak ogłoszeń w serwisie</li></ul></div>';
    } else {
        while($ogloszenie = $wynikZapytania->fetch_object()) {
            echo "<div class='Ogloszenie'><a href='ogloszenie.php?id=$ogloszenie->$pola[0]'>
                 <div>
                 <span>$ogloszenie->$pola[1]</span>
                 <span>$ogloszenie->$pola[2]</span>
                 <span>$ogloszenie->$pola[3]";
            if($ogloszenie->$pola[4] != null) { echo " - $ogloszenie->$pola[4]"; }
            echo "</span></div>
                 <div>
                 <a href='profilPracodawcy.php?id=$ogloszenie->$pola[6]'>$ogloszenie->$pola[5]</a>
                 </div>
                 </a></div>";
        }
    }
}

function wyswietlenieOgloszenPracodawcy($dbh, $id) {
    $query = "SELECT o.Id, o.Nazwa, d.Nazwa, o.Wynagrodzenie, o.WynagrodzenieGorne FROM Ogloszenie o 
            JOIN Doswiadczenie d ON o.DoswiadczenieId = d.Id WHERE o.PracodawcaId = $id;";
    $pola = ['o.Id', 'o.Nazwa', 'd.Nazwa', 'o.Wynagrodzenie', 'o.WynagrodzenieGorne'];
    $wynikZapytania = $dbh->select($query);
    
    if($wynikZapytania->num_rows === 0) {
        echo '<div class="Uwaga"><ul><li>Brak ogłoszeń tego pracodawcy w serwisie</li></ul></div>';
    } else {
        while($ogloszenie = $wynikZapytania->fetch_object()) {
            echo "<div class='Ogloszenie'><a href='ogloszenie.php?id=$ogloszenie->$pola[0]'>
                 
                 <span>$ogloszenie->$pola[1]</span>
                 <span>$ogloszenie->$pola[2]</span>
                 <span>$ogloszenie->$pola[3]";
            if($ogloszenie->$pola[4] != null) { echo " - $ogloszenie->$pola[4]"; }
            echo "</span></a></div>";
        }
    }
}

function walidacjaWyszukiwarki() {
    $filtry = [];
    $wynik = "";
    $walidacja = [];
    
    if(isset($_POST["Fraza"])) {$filtry['Fraza'] = FILTER_SANITIZE_STRING; }
    if(isset($_POST["Wynagrodzenie"])) {$filtry['Wynagrodzenie'] = FILTER_SANITIZE_NUMBER_INT; }
    if(isset($_POST["WynagrodzenieGorne"])) {$filtry['WynagrodzenieGorne'] = FILTER_SANITIZE_NUMBER_INT; }
    if(isset($_POST["Doswiadczenie"])) {
        $filtry['Doswiadczenie'] = ['filter' => FILTER_SANITIZE_FULL_SPECIAL_CHARS, 'flags' => FILTER_REQUIRE_ARRAY ]; 
    }
    
    if($filtry==[]) {
        return null;
    } else {
        $walidacja = filter_input_array(INPUT_POST, $filtry);
        foreach($walidacja as $key => $value) {
            switch($key) {
                case "Fraza": 
                    if($value==false) { $wynik .= "Źle wprowadzona fraza."; }
                    break;
                case "Wynagrodzenie":
                    if($value==false) { $wynik .= "Źle wprowadzona minimalna kwota (Podaj jako liczbę całkowitą)."; }
                    if(intval($_POST['Wynagrodzenie']) < 0) { $wynik .= "Wprowadzono ujemną minimalną kwotę."; }
                    break;
                case "WynagrodzenieGorne":
                    if($value==false) { $wynik .= "Źle wprowadzona maksymalna kwota (Podaj jako liczbę całkowitą)."; }
                    if(intval($_POST['WynagrodzenieGorne']) < 0) { $wynik .= "Wprowadzono ujemną maksymalną kwotę."; }
                    if(isset($_POST['Wynagrodzenie']) && intval($_POST['WynagrodzenieGorne']) < intval($_POST['Wynagrodzenie'])) { $wynik .= "Kwota minimalna nie może być niższa od kwoty maksymalnej."; }
                    break;
                case "Doswiadczenie":
                    if($value==false) { $wynik .= "Źle wybrany poziom doświadczenia."; }
                    break;
                default:
                    break;
            }
        }
        if($wynik === "") {
            $iloscParametrow = count($filtry);
            $sql = "SELECT o.Id, o.Nazwa, d.Nazwa, o.Wynagrodzenie, o.WynagrodzenieGorne, p.Nazwa FROM Ogloszenie o 
                    JOIN Pracodawca p ON o.PracodawcaId = p.Id JOIN Doswiadczenie d ON o.DoswiadczenieId = d.Id WHERE ";
            $sqlTemp = "";
            foreach($filtry as $key => $value) {
                switch($key) {
                    case "Fraza":
                        $fraza = $walidacja['Fraza'];
                        $sqlTemp .= "(o.Nazwa LIKE '%$fraza%' OR o.Opis LIKE '%$fraza%' OR d.Nazwa LIKE '%$fraza%'
                            OR p.Nazwa LIKE '%$fraza%' OR P.Opis LIKE '%$fraza%'
                            OR o.Id IN ( SELECT OgloszenieId FROM Wytyczne WHERE Wytyczne.Opis LIKE '%$fraza% ) )";
                        break;
                    case "Wynagrodzenie":
                    case "WynagrodzenieGorne":
                        if( isset($_POST['Wynagrodzenie']) && isset($_POST['WynagrodzenieGorne']) ) {
                            $Wmin = $walidacja['Wynagrodzenie'];
                            $Wmax = $walidacja['WynagrodzenieGorne'];
                            $sqlTemp .= "(o.WynagrodzenieGorne IS NOT NULL AND o.Wynagrodzenie >= $Wmin AND o.WynagrodzenieGorne <= $Wmax 
                                        OR o.WynagrodzenieGorne IS NULL AND o.Wynagrodzenie >= $Wmin AND o.Wynagrodzenie <= $Wmax)";
                        } else {
                            if( isset($_POST['Wynagrodzenie']) ) {
                                $Wmin = $walidacja['Wynagrodzenie'];
                                $sqlTemp .= "(o.Wynagrodzenie >= $Wmin)";
                            } else {
                                $Wmax = $walidacja['WynagrodzenieGorne'];
                                $sqlTemp .= "(o.WynagrodzenieGorne IS NOT NULL AND O.WynagrodzenieGorne <= $Wmax 
                                            OR o.WynagrodzenieGorne IS NULL AND o.Wynagrodzenie <= $Wmax)";
                            }
                        }
                        break;
                    case "Doswiadczenie":
                        $doswiadczenia = $walidacja['Doswiadczenie'];
                        $sqlTemp .= "(";
                        foreach($doswiadczenia as $doswiadczenieID) {
                            $sqlTemp .= "d.Id = $doswiadczenieID OR ";
                        }
                        $sqlTemp = substr($sqlTemp, 0, strlen($sqlTemp)-4);
                        $sqlTemp .= ")";
                        break;
                    default:
                        break;
                }
                if($iloscParametrow==1) {
                    $sqlTemp .= ";";
                } else {
                    $sqlTemp .= " AND ";
                }
            }
            if($iloscParametrow > 1) { $sqlTemp = substr($sqlTemp, 0, strlen($sqlTemp)-5); }
            $sql .= $sqlTemp . ";";
            return $sql;
        } else {
            return $wynik;
        }
    }
    
    function walidacjaOgloszenia() {
        
    }
}
