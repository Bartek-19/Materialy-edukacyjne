<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <h2>Dane odebrane z formularza</h2>
        <?php
            $request = 'klient.php?';
            $nazwisko = $_REQUEST['nazw'];
            $wiek = $_REQUEST['wiek'];
            $kraj = $_REQUEST['kraj'];
            $mail = $_REQUEST['mail'];
            
            if(isset($nazwisko)) { $request .= "nazw=$nazwisko&"; }
            if(isset($wiek)) { $request .= "wiek=$wiek&"; }
            if(isset($kraj)) { $request .= "kraj=$kraj&"; }
            if(isset($mail)) { $request .= "mail=$mail&"; }
            
            echo "<br>Wybrano tutoriale: " . join(" ", $_REQUEST['jezyki']) . "Sposób płatności: " . $_REQUEST['platnosc'] .
                "<br><br><a href='klient.php?$request'><h4>Dane Klienta</h4></a>" .
                "<br><br><a href='formularz.html'>Powrot do formularza</a>";
            //http://localhost/PAI_24-10-07/formularz.html?nazw=maxiKaz&wiek=29&kraj=Polska&mail=maxi%40kaz.pl&CPP=on&platnosc=Visa&
        ?>
    </body>
</html>

