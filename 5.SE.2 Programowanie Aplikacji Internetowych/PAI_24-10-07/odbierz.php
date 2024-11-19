<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <h2>Dane odebrane z formularza</h2>
        <br>
        <?php
            $nazwisko = htmlspecialchars(trim($_REQUEST['nazw']));
            if (isset($nazwisko)&&($nazwisko!="")) {
                echo "Nazwisko: $nazwisko <br>";
            } else {
                echo "Nie wpisano nazwiska <br>";
            }
            
            $wiek = htmlspecialchars(trim($_REQUEST['wiek']));
            if (isset($wiek)&&($wiek>0)) {
                echo "Wiek: $wiek <br>";
            } else {
                echo "Nie podano wieku <br>";
            }
            
            $kraj = htmlspecialchars(trim($_REQUEST['kraj']));
            echo "Kraj: $kraj <br>";
            
            $mail = htmlspecialchars(trim($_REQUEST['mail']));
            if (isset($mail)&&($mail!="")) {
                echo "Adres e-mail: $mail <br>";
            } else {
                echo "Nie podano adresu e-mail <br>";
            }
            
            echo "Wybrane tutoriale: ";
            if (isset($_REQUEST['PHP'])) { 
                echo "PHP ";
            } else { echo ""; }
            if (isset($_REQUEST['CPP'])) { 
                echo "C/C++ ";
            } else { echo ""; }
            if (isset($_REQUEST['Java'])) { 
                echo "Java ";
            } else { echo ""; }
            echo "<br>Metoda płatności: ";
            $platnosc = htmlspecialchars(trim($_REQUEST['platnosc']));
            if(isset($platnosc)) {
                echo "$platnosc <br>";
            } else {
                echo "brak <br>";
            }
            
            echo "<a href='formularz.html'>Powrot do formularza</a>"
        ?>
        
    </body>
</html>
