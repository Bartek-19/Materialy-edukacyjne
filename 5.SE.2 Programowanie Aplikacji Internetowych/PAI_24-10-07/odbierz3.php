<!DOCTYPE html>
<!--
Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHPWebPage.php to edit this template
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <?php
            echo "<h3>Wybrane tutoriale:</h3>";
            foreach ($_REQUEST['jezyki'] as $key => $value) {
                echo "$value <br>";
            }
            echo "<br><br>Wersja łączona: <br>";
            echo join(", ", $_REQUEST['jezyki']);
        ?>
    </body>
</html>
