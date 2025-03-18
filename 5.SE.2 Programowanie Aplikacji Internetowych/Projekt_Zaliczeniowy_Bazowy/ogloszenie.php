<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Ogłoszenie</title>
        <link rel="stylesheet" href="css/style.css">
    </head>
    <body>
        <?php
        include_once 'klasy/Baza.php';
        
        $idOgloszenia = filter_input($_REQUEST, "id", FILTER_SANITIZE_URL);
        
        if($idOgloszenia) {
            $dbh = new Baza("localhost", "root", "", "projektzaliczeniowy");
            $query = "SELECT o.Nazwa, o.Opis, o.Wynagrodzenie, o.WynagrodzenieGorne, p.Nazwa, 
                p.Opis, p.Email, a.KodPocztowy, a.Miejscowosc, a.Ulica, a.Numer, d.Nazwa, p.Id
                FROM Ogloszenie o JOIN Pracodawca p ON o.PracodawcaId = p.Id
                JOIN Adres a ON p.AdresId = a.Id JOIN Doswiadczenie d ON o.DoswiadczenieId = d.Id
                WHERE o.Id = $idOgloszenia; ";
            $pola = ['o.Nazwa', 'o.Opis', 'o.Wynagrodzenie', 'o.WynagrodzenieGorne', 'p.Nazwa', 
                'p.Opis', 'p.Email', 'a.KodPocztowy', 'a.Miejscowosc', 'a.Ulica', 'a.Numer', 'd.Nazwa', 'p.Id'];
            
            $wynik = $dbh->select($query);
            if($wynik->num_rows === 0) {
                echo '<div class="Uwaga"><ul><li>Podane ogłoszenie nie istnieje</li></ul></div>';
            } else {
                $queryWytyczne = "SELECT Kategoria, Opis FROM Wytyczne WHERE OgloszenieId = $idOgloszenia;";
                $polaWytyczne = ["Kategoria", "Opis"];
                $wymagania = [];
                $nicetohave = [];
                $obowiazki = [];
                $wytyczne = $dbh->select($queryWytyczne);
                $ogloszenie = $wynikZapytania->fetch_object();
                echo "<div class='CaleOgloszenie'>
                    <div class='NaglowekOgloszenia'><span>$ogloszenie->$pola[0] ($ogloszenie->$pola[11])</span>
                        <span>$ogloszenie->$pola[2]";
                if($ogloszenie->$pola[3]!=null) { echo " - $ogloszenie->$pola[3]"; }
                echo "</span>
                    <br><span><a href='profilPracodawcy.php?id=$ogloszenie->$pola[12]'>$ogloszenie->$pola[4]</a>, ";
                if($ogloszenie->$pola[7]===null) {echo "Zdalnie";} else {
                    echo "$ogloszenie->$pola[9] $ogloszenie->$pola[10], $ogloszenie->$pola[7] $ogloszenie->$pola[8]";
                }
                echo "</span><span><a href='mailto:$ogloszenie->$pola[6]'>$ogloszenie->$pola[6]</a></span>
                    </div>
                    <div><br>
                    $ogloszenie->$pola[1]
                    <br><strong>";
                    while($w = $wytyczne->fetch_object()) {
                        switch($w->$polaWytyczne[0]){
                            case "Wymagania": 
                                array_push($wymagania, $w->$polaWytyczne[1]);
                                break;
                            case "Dodatkowo":
                                array_push($nicetohave, $w->$polaWytyczne[1]);
                                break;
                            case "Obowiazki":
                                array_push($obowiazki, $w->$polaWytyczne[1]);
                                break;
                            default:
                                break;
                        }
                    }
                    if(!empty($wymagania)) {
                        echo "<br>Wymagania<br><ul>";
                        foreach($wymagania as $val) {
                            echo "<li>$val</li>";
                        }
                        echo "</ul>";
                    }
                    if(!empty($nicetohave)) {
                        echo "<br>Mile widziane<br><ul>";
                        foreach($nicetohave as $val) {
                            echo "<li>$val</li>";
                        }
                        echo "</ul>";
                    }
                    if(!empty($obowiazki)) {
                        echo "<br>Zakres obowiązków<br><ul>";
                        foreach($obowiazki as $val) {
                            echo "<li>$val</li>";
                        }
                        echo "</ul>";
                    }
                echo "<br><br>O firmie:<br></strong>
                    $ogloszenie->$pola[5]
                    </div></div>";
            }
        } else {
            echo '<div class="Uwaga"><ul><li>Podane ogłoszenie nie istnieje</li></ul></div>';
        }
        ?>
    </body>
</html>
