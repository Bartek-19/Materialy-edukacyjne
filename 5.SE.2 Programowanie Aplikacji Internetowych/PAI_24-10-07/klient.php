<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <?php
            $nazwisko = $_REQUEST['nazw'];
            $wiek = $_REQUEST['wiek'];
            $kraj = $_REQUEST['kraj'];
            $mail = $_REQUEST['mail'];
            
            echo "Nazwisko: ";
            if(isset($nazwisko)) {echo "$nazwisko";} else {echo "Nie podano";}
            echo "<br>Wiek: ";
            if(isset($wiek)) {echo "$wiek";} else {echo "Nie podano";}
            echo "<br>Panstwo: ";
            if(isset($kraj)) {echo "$kraj";} else {echo "Nie podano";}
            echo "<br>E-mail: ";
            if(isset($mail)) {echo "$mail";} else {echo "Nie podano";}
        ?>
    </body>
</html>
