<?php
function drukuj_form() {  
    $zawartosc = ' 
    <form action="?strona=formularz" method="POST" > 
    <table> 
    <tr><td>Nazwisko: </td><td><input type="text" name="nazw"></td></tr>
    <tr><td>Wiek: </td><td><input type="number" name="wiek"></td></tr>
    <tr><td>Panstwo: </td><td>
    <select name="kraj">
        <option value="Polska">Polska</option>
        <option value="Niemcy">Niemcy</option>
        <option value="Wielka Brytania">GB</option>
        <option value="Czechy">Czechy</option>
    </select></td></tr>
    <tr><td>Adres e-mail: </td><td><input type="email" name="mail"></td></tr>
    </table><br><h5>Zamawiam tutorial z języka:</h5>
    <input type="radio" name="jezyki" value="CPP">C/C++ 
    <input type="radio" name="jezyki" value="Java">Java 
    <input type="radio" name="jezyki" value="PHP">PHP <br>
    <h5>Sposób zapłaty:</h5>
    <input type="radio" name="platnosc" value="Visa">Visa
    <input type="radio" name="platnosc" value="Master Card">Master Card 
    <input type="radio" name="platnosc" value="Przelew">Przelew bankowy
    <br><br>
    <input type="submit" name="submit" value="Dodaj">
    <input type="submit" name="submit" value="Pokaz">
    <input type="reset" name="Anuluj" value="Anuluj">
    </form>';  
    return $zawartosc; 
} 

function walidacja() { //jak poprzednio – tylko usunąć polecenia echo 
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
            return $query;
        } else {
            return "";
        }
} 

function dodajdoBD($bd) { //funkcja powinna zwracać łańcuch z komunikatem  
//czy udało się czy nie dodać dane do bazy – reszta bez zmian 
    $sql = walidacja($bd);
    if($sql!="" && $bd->insert($sql)) {
        return "<br><p style='color: #00cc33'>Dodano rekord do bazy danych</p><br>";
    } else {
        return "<br><p style='color: #ff0000'>Nie dodano rekordu do bazy danych</p><br>";
    }
} 

include_once "klasy/Baza.php"; 
$tytul = "Formularz zamowienia"; 
$zawartosc = drukuj_form(); 
$bd = new Baza("localhost", "root", "", "klienci"); 
if (filter_input(INPUT_POST, "submit")) { 
    $akcja = filter_input(INPUT_POST, "submit"); 
    switch ($akcja) { 
        case "Dodaj" : 
            $zawartosc.= dodajdoBD($bd); 
            break; 
        case "Pokaz" : 
            $zawartosc.= $bd->select("select * from klienci", ["Email", "Zamowienie"]); 
            break; 
    } 
}
