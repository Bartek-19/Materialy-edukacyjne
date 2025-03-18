<?php
    function walidacja($bd) {
        $args =  [
            'nazw' => [ 'filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/^[A-Z]{1}[a-ząęłńśćźżó-]{1,25}$/'] ], 
            'wiek' => [ 'filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/^[0-9]{1,3}/'] ],
            'kraj' => FILTER_SANITIZE_FULL_SPECIAL_CHARS, 
            'mail' => [ 'filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/^[a-zA-Z0-9_]+@[a-zA-Z0-9\-]+\.[a-zA-Z0-9\-\.]+$/'] ],
            'jezyki' => FILTER_SANITIZE_FULL_SPECIAL_CHARS,
            'platnosc' => FILTER_SANITIZE_FULL_SPECIAL_CHARS
        ];
        $dane = filter_input_array(INPUT_POST, $args);
        $errors = "";
        foreach ($dane as $key => $val) { 
            if ($val === false or $val === NULL) { $errors .= $key . " "; } 
        } 
        if ($errors === "") {
            $query = "INSERT INTO klienci (Nazwisko, Wiek, Panstwo, Email, Zamowienie, Platnosc) VALUES (";
            foreach ($dane as $key => $val) {
                if($key==='wiek') {$query .= "$val, ";} else {$query .= "'$val', ";}
            }
            $query = substr($query, 0, strlen($query)-2).");";
            if($bd->insert($query)) { echo 'Zapisano rekord w bazie danych'; } 
            else { echo 'Nie udało się zapisać rekordu w bazie danych'; }
            echo '<br>'.$query.'<br>';
        } else { 
            echo "<br>Niepoprawnie dane: " . $errors; 
        }
    }
    
    function dodajdoBD($bd){ 
        echo "<h3>Dodawanie do Bazy Danych:</h3>"; 
        //walidacja($bd); 
        walidacjaDBO($bd);
    }
    
    function wyczysc() {
        echo "";
    }
    
    function walidacjaDBO($bd) {
        $args =  [
            'nazw' => [ 'filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/^[A-Z]{1}[a-ząęłńśćźżó-]{1,25}$/'] ], 
            'wiek' => [ 'filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/^[0-9]{1,3}/'] ],
            'kraj' => FILTER_SANITIZE_FULL_SPECIAL_CHARS, 
            'mail' => [ 'filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/^[a-zA-Z0-9_]+@[a-zA-Z0-9\-]+\.[a-zA-Z0-9\-\.]+$/'] ],
            'jezyki' => FILTER_SANITIZE_FULL_SPECIAL_CHARS,
            'platnosc' => FILTER_SANITIZE_FULL_SPECIAL_CHARS
        ];
        $dane = filter_input_array(INPUT_POST, $args);
        $errors = "";
        foreach ($dane as $key => $val) { 
            if ($val === false or $val === NULL) { $errors .= $key . " "; } 
        } 
        if ($errors === "") {
            $bd->insert($dane['nazw'], $dane['wiek'], $dane['kraj'], $dane['mail'], $dane['jezyki'], $dane['platnosc']);
            echo '<br>';
        } else { 
            echo "<br>Niepoprawnie dane: " . $errors; 
        }
    }