<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Formularz</title>
    </head>
    <body>
        <div>
            <h2>Formularz zamówienia</h2><br>
            <form method="post" action="pliki.php">
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
                                <option value="Ukraina">Ukraina</option>
                                <option value="Słowacja">Słowacja</option>
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
                    $jezyki = ["C", "CPP", "Java", "C#", "HTML", "CSS", "XML", "PHP", "JavaScript"];
                    foreach ($jezyki as $value) {
                        echo "<input type='checkbox' name='jezyki[]' value='$value'>$value ";
                    }
                ?>
                <br>
                <h5>Sposób zapłaty:</h5>
                <input type="radio" name="platnosc" value="Eurocard">eurocard 
                <input type="radio" name="platnosc" value="Visa">visa
                <input type="radio" name="platnosc" value="Przelew">przelew bankowy
                <br><br>
                <input type="submit" name="submit" value="Wyczysc">
                <input type="submit" name="submit" value="Zapisz">
                <input type="submit" name="submit" value="Pokaz">
                <input type="submit" name="submit" value="PHP">
                <input type="submit" name="submit" value="CPP">
                <input type="submit" name="submit" value="Java">
                <input type="submit" name="submit" value="Statystyki">
                <br><br>
                <?php 
                    include_once 'funkcje.php';
                    if (filter_input(INPUT_POST, "submit")) { 
                        $akcja = filter_input(INPUT_POST, "submit");  //odczytaj jego value 
                        switch ($akcja) { 
                            case "Wyczysc": wyczysc(); break;
                            case "Zapisz": dodaj(); break; 
                            case "Pokaz": pokaz(); break; 
                            case "Java": pokaz_zamowienie("Java"); break; 
                            case "PHP": pokaz_zamowienie("PHP"); break;
                            case "CPP": pokaz_zamowienie("CPP"); break;
                            case "Statystyki": statystyki(); break;
                        } 
                    }

                    echo "<br><br>";
                    //var_dump($_SERVER);
                ?>
            </form>
        </div>
    </body>
</html>
