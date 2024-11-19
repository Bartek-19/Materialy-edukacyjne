<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <?php
            $var1 = 1234;
            $var2 = 567.789;
            $var3 = 1;
            $var4 = 0;
            $var5 = true;
            $var6 = "0";
            $var7 = "Typy w PHP";
            $var8 = [1, 2, 3, 4];
            $var9 = [];
            $var10 = ["zielony", "czerwony", "niebieski"];
            $var11 = ["Agata", "Agatowska", 4.67, true];
            $var12 = new DateTime();
                    
            echo 'var1 = ' . $var1 . '<br>';
            echo 'var2 = ' . $var2 . '<br>';
            echo 'var3 = ' . $var3 . '<br>';
            echo 'var4 = ' . $var4 . '<br>';
            echo 'var5 = ' . $var5 . '<br>';
            echo 'var6 = ' . $var6 . '<br>';
            echo 'var7 = ' . $var7 . '<br>';
            $count = count($var8);
            echo 'var8 = [';
            for($i=0; $i<$count; $i++)
            {
                echo $var8[$i];
                if($i<$count-1)
                {
                    echo ', ';
                }
            }
            $count = count($var9);
            echo '] <br>var9 = [';
            for($i=0; $i<$count; $i++)
            {
                echo $var9[$i];
                if($i<$count-1)
                {
                    echo ', ';
                }
            }
            echo '] <br>var10 = ';
            print_r($var10);
            echo '<br>var11 = ';
            var_dump($var11);
            echo '<br>var12 = ';
            var_dump($var12);
            
            echo '<br><br>';
            echo 'is_bool($var3) = ' . is_bool($var3) . '<br>';
            echo 'is_bool($var5) = ' . is_bool($var5) . '<br>';
            echo 'is_int($var4) = ' . is_int($var4) . '<br>';
            echo 'is_numeric($var2) = ' . is_numeric($var2) . '<br>';
            echo 'is_numeric($var8) = ' . is_numeric($var8) . '<br>';
            echo 'is_string($var4) = ' . is_string($var4) . '<br>';
            echo 'is_string($var6) = ' . is_string($var6) . '<br>';
            echo 'is_array($var11) = ' . is_array($var11) . '<br>';
            echo 'is_array($var9) = ' . is_array($var9) . '<br>';
            echo 'is_array($var7) = ' . is_array($var7) . '<br>';
            echo 'is_object($var1) = ' . is_object($var1) . '<br>';
            echo 'is_object($var7) = ' . is_object($var7) . '<br>';
            echo 'is_object($var9) = ' . is_object($var9) . '<br>';
            echo 'is_object($var12) = ' . is_object($var12) . '<br><br>';
            
            $comp1 = $var3==$var5;
            $comp2 = $var3===$var5;
            $comp3 = $var4==$var6;
            $comp4 = $var4===$var6;
            
            echo '1==true: ' . $comp1 . '<br>';
            echo '1===true: ' . $comp2 . '<br>';
            echo '0=="0": ' . $comp3 . '<br>';
            echo '0==="0": ' . $comp4 . '<br>';
        ?>
    </body>
</html>
