<html>
    <head>
        <meta charset="UTF-8">
        <title>Galeria PHP</title>
        <link rel="stylesheet" href="style.css">
    </head>
    <body>
        <h1>Galeria zdjęć</h1>
        <br>
        <?php
            function galeria($rows, $cols)
            {
                for($i=0; $i<$rows; $i++)
                {
                    for($j=1; $j<=$cols; $j++)
                    {
                        $n = $i * $cols + $j;
                        print("<img src='galeria/uwu$n.jpg' width=400 height=400 alt='uwu$n'>");
                    }
                    print("<br>");
                }
            }
            
            galeria(2, 3);
        ?>
    </body>
</html>
