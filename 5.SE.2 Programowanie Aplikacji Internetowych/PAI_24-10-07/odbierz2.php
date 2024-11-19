<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <?php
            echo "Tablica \$_REQUEST: <br>";
            foreach ($_REQUEST as $key=>$value) {
                echo "$key = $value <br>";
            }
            echo "<br>Tablica \$_POST: <br>";
            foreach ($_POST as $key=>$value) {
                echo "$key = $value <br>";
            }
            echo "<br>Tablica \$_GET: <br>";
            foreach ($_GET as $key=>$value) {
                echo "$key = $value <br>";
            }
        ?>
    </body>
</html>
