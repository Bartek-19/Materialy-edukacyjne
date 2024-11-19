<?php 
    /*function dodaj() {
        $dane = ""; 
        if (isset($_REQUEST["nazw"])) { $dane .= htmlspecialchars($_REQUEST['nazw'])." "; }
        if (isset($_REQUEST["wiek"])) { $dane .= htmlspecialchars($_REQUEST['wiek'])." "; }
        if (isset($_REQUEST["kraj"])) { $dane .= htmlspecialchars($_REQUEST['kraj'])." "; }
        if (isset($_REQUEST["mail"])) { $dane .= htmlspecialchars($_REQUEST['mail'])." "; }
        if (isset($_REQUEST["jezyki"])) { $dane .= join(",", $_REQUEST['jezyki'])." "; }
        if (isset($_REQUEST["platnosc"])) { $dane .= htmlspecialchars($_REQUEST['platnosc'])." "; }
        $dane .= "\n";
        $dRoot = $_SERVER['DOCUMENT_ROOT'];
        if ( !(file_exists("$dRoot/../Mojepliki/dane.txt")) ) { $plik=fopen("$dRoot/../Mojepliki/dane.txt","w+"); fputs($plik,""); fclose($plik); } 
        $plik=fopen("$dRoot/../Mojepliki/dane.txt", "a"); 
        if (!$plik) { echo "Nie da się otworzyć pliku.";  } else { 
            fwrite($plik, $dane);
            fclose($plik);   
        }
    }*/
                    
    function pokaz() {
        $dRoot = $_SERVER['DOCUMENT_ROOT'];
        if ( !(file_exists("$dRoot/../Mojepliki/dane.txt")) ) { $plik=fopen("$dRoot/../Mojepliki/dane.txt","w+"); fputs($plik,""); fclose($plik); } 
        $plik=file("$dRoot/../Mojepliki/dane.txt"); 
        if (!$plik) { echo "Nie da się otworzyć pliku.";  } else { 
            foreach ($plik as $line) {
                $line .= "<br>";
                echo "$line";
            }
        }
    }
                    
    function pokaz_zamowienie($tut) { 
        $dRoot = $_SERVER['DOCUMENT_ROOT'];
        if ( !(file_exists("$dRoot/../Mojepliki/dane.txt")) ) { $tab=fopen("$dRoot/../Mojepliki/dane.txt","w+"); fputs($tab,""); fclose($tab); } 
        $tab=file("$dRoot/../Mojepliki/dane.txt"); 
        if (!$tab) { echo "Nie da się otworzyć pliku.";  } else { 
            foreach ($tab as $value) {
                if(preg_match("/$tut/", $value)) {
                    $value .= "<br>";
                    echo "$value";
                }
            }
        }
    }
    
    function walidacja() {
        $args =  [
            'nazw' => [ 'filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/^[A-Z]{1}[a-ząęłńśćźżó-]{1,25}$/'] ], 
            'wiek' => [ 'filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/^[0-9]{1,3}/'] ],
            'kraj' => FILTER_SANITIZE_FULL_SPECIAL_CHARS, 
            'mail' => [ 'filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/^[a-zA-Z0-9_]+@[a-zA-Z0-9\-]+\.[a-zA-Z0-9\-\.]+$/'] ],
            'jezyki' => [ 'filter' => FILTER_SANITIZE_FULL_SPECIAL_CHARS, 'flags' => FILTER_REQUIRE_ARRAY ],
            'platnosc' => FILTER_SANITIZE_FULL_SPECIAL_CHARS
        ];
        
        $dane = filter_input_array(INPUT_POST, $args);
        var_dump($dane);
        
        $errors = "";
        foreach ($dane as $key => $val) { 
            if ($val === false or $val === NULL) { 
                $errors .= $key . " "; 
            } 
        } 

        if ($errors === "") {
            dopliku("dane.txt", $dane); 
        } else { 
            echo "<br>Nie poprawnie dane: " . $errors; 
        }
    }
    
    function dodaj(){ 
        echo "<h3>Dodawanie do pliku:</h3>"; 
        walidacja(); 
    }
    
    function dopliku($nazwaPliku, $tablicaDanych) { 
        $dane = ""; 
        foreach ($tablicaDanych as $key => $val) {
            if($key === 'jezyki') {
                $dane .= join(",", $val);
            } else {
                $dane .= $val;
            }
            $dane .= " "; 
        }
        $dane .= PHP_EOL; //dodaj koniec linii za pomocą stałej PHP 
        $dRoot = $_SERVER['DOCUMENT_ROOT'];
        if ( !(file_exists("$dRoot/../Mojepliki/$nazwaPliku")) ) { $plik=fopen("$dRoot/../Mojepliki/$nazwaPliku","w+"); fputs($plik,""); fclose($plik); } 
        $plik=fopen("$dRoot/../Mojepliki/$nazwaPliku", "a"); 
        if (!$plik) { echo "Nie da się otworzyć pliku.";  } else { 
            fwrite($plik, $dane);
            fclose($plik);   
        }
        echo "<p>Zapisano: <br> $dane</p>";
    }
    
    function statystyki() {
        $dRoot = $_SERVER['DOCUMENT_ROOT'];
        if ( !(file_exists("$dRoot/../Mojepliki/dane.txt")) ) { $plik=fopen("$dRoot/../Mojepliki/dane.txt","w+"); fputs($plik,""); fclose($plik); } 
        $plik=file("$dRoot/../Mojepliki/dane.txt"); 
        if (!$plik) { echo "Nie da się otworzyć pliku.";  } else { 
            $L1 = 0;
            $L2 = 0;
            $L3 = 0;
            foreach ($plik as $line) {
                $temp = explode(" ", $line);
                if($temp[1]<18) {$L2++;}
                if($temp[1]>=50) {$L3++;}
                $L1++;
            }
            echo "Liczba wszystkich zamowien: $L1<br><br>";
            echo "Liczba zamowien od osob w wieku <18 lat: $L2<br><br>";
            echo "Liczba zamowien od osob w wieku >=50 lat: $L3<br><br>";
        }
    }
    
    function wyczysc() {
        echo "";
    }