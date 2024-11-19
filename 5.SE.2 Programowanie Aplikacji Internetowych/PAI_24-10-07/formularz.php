<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Formularz</title>
    </head>
    <body>
        <div>
            <h2>Formularz zamówienia</h2><br>
            <form method="post" action="odbierz4.php">
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
                <input type="submit" value="Wyślij">
                <input type="reset" value="Anuluj">
            </form>
        </div>
    </body>
</html>
