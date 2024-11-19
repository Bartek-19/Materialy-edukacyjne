<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <?php
        $tech = ["C", "CPP", "Java", "C#", "Html", "CSS", "XML", "PHP", "JavaScript"]; 
        $path = "ankieta.txt";
        echo "<h3>Wybierz technologie, ktore znasz:<br><br></h3><form method='post' action='ankieta.php'>";
        foreach($tech as $val) {
            echo "<input type='checkbox' name='jezyki[]' value='$val'> $val<br>";
        }
        echo "<input type='submit' name='submit' value='Wyslij'></form>";
        if(filter_input(INPUT_POST, "submit")) {
            if ( !(file_exists($path)) ||  file($path)=="") { 
                $plik=fopen($path,"w+");
                foreach($tech as $val) {
                    fwrite($plik, $val.":0".PHP_EOL); 
                }
                fclose($plik);
            } 
            $plik=file($path); 
            if (!$plik) { echo "Nie da się otworzyć pliku.";  } else { 
                for ($i=0; $i<count($plik); $i++) {
                    $tab = explode(":", $plik[$i]);
                    $tab2 = join(",", $_REQUEST['jezyki']);
                    $tab2 = explode(",", $tab2);
                    foreach($tab2 as $val) {
                        if($val==$tab[0]) {
                            $L = intval($tab[1]);
                            $L++;
                            $tab[1] = strval($L);
                            $plik[$i] = $tab[0].":".$tab[1].PHP_EOL;
                        }
                    }
                }
                foreach($plik as $line) {
                    echo "$line<br>";
                }
                $file = fopen($path, "w");
                foreach($plik as $line) {
                    fwrite($file, $line);
                }
                fclose($file);
            }
        }
        ?>
    </body>
</html>
