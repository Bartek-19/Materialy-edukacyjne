<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <div>
            <h2>Formularz zamówienia</h2><br>
            <form method="post" action="index.php">
                <table>
                    <tr>
                        <td>Nazwisko: </td>
                        <td><input type="text" name="nazw"></td>
                    </tr>
                    <tr>
                        <td>Wiek: </td>
                        <td><input type="number" name="wiek"></td>
                    </tr>
                    <tr>
                        <td>Panstwo: </td>
                        <td>
                            <select name="kraj">
                                <option value="Polska">Polska</option>
                                <option value="Niemcy">Niemcy</option>
                                <option value="Wielka Brytania">GB</option>
                                <option value="Czechy">Czechy</option>
                            </select>
                        </td>
                    </tr>
                    <tr>
                        <td>Adres e-mail: </td>
                        <td><input type="email" name="mail"></td>
                    </tr>
                </table>
                <br>
                <h5>Zamawiam tutorial z języka:</h5>
                <?php
                    $jezyki = ["CPP", "Java", "PHP"];
                    foreach ($jezyki as $value) {
                        echo "<input type='radio' name='jezyki' value='$value'>$value ";
                    }
                ?>
                <br>
                <h5>Sposób zapłaty:</h5>
                <input type="radio" name="platnosc" value="Visa">Visa
                <input type="radio" name="platnosc" value="Master Card">Master Card 
                <input type="radio" name="platnosc" value="Przelew">Przelew bankowy
                <br><br>
                <input type="submit" name="submit" value="Wyczysc">
                <input type="submit" name="submit" value="Dodaj">
                <input type="submit" name="submit" value="Pokaz">
                <input type="submit" name="submit" value="PHP">
                <input type="submit" name="submit" value="CPP">
                <input type="submit" name="submit" value="Java">
                <br><br>
            </form>
        </div>
        <?php  
            include_once("funkcje.php"); 
            include_once "klasy/Baza.php"; 
            include_once "klasy/BazaPDO.php";
            //$bd = new Baza("localhost", "root", "", "klienci"); 
            $bd = new BazaPDO('mysql:host=localhost;dbname=klienci', 'root','');
            if (filter_input(INPUT_POST, "submit")) { 
                $akcja = filter_input(INPUT_POST, "submit"); 
                switch ($akcja) { 
                    case "Dodaj" : dodajdoBD($bd); break; 
                    case "Pokaz" : echo $bd->select("select Id,Nazwisko,Zamowienie from klienci", 
                            ["Id","Nazwisko","Zamowienie"]); break;
                    case "PHP" : echo $bd->select("SELECT Id,Nazwisko,Zamowienie FROM klienci WHERE Zamowienie LIKE '%PHP%'", 
                            ["Id","Nazwisko","Zamowienie"]); break;
                    case "Java" : echo $bd->select("SELECT Id,Nazwisko,Zamowienie FROM klienci WHERE Zamowienie LIKE '%Java%'", 
                            ["Id","Nazwisko","Zamowienie"]); break;
                    case "CPP" : echo $bd->select("SELECT Id,Nazwisko,Zamowienie FROM klienci WHERE Zamowienie LIKE '%CPP%'", 
                            ["Id","Nazwisko","Zamowienie"]); break;
                }
            }
        ?>
    </body>
</html>
