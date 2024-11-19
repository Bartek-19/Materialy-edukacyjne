<html>
    <head>
        <meta charset="UTF-8">
        <title>Pierwszy skrypt PHP</title>
    </head>
    <body>
        <?php
            $n = 5678;
            $x = 3.14159;
            printf("Domyślny format n=%d, x=%f <br>"
                    . "Zaokrąglenie do liczby całkowitej x=%d <br>" . 
                    "Z trzema cyframi po kropce x=%.3f", $n, $x, $x, $x);
        ?>
    </body>
</html>
