<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Pracodawca</title>
        <link rel="stylesheet" href="css/style.css">
    </head>
    <body>
        <?php
        require_once 'klasy/Baza.php';
        require_once 'Funkcje.php';
        
        $dbh = new Baza("localhost", "root", "", "projektzaliczeniowy"); 
        if(isset($_REQUEST['id'])){
            $pracodawcaId = filter_input($_REQUEST, "id", FILTER_SANITIZE_URL);
            $sql = "SELECT AdresId FROM Pracodawca WHERE Pracodawca.Id = $pracodawcaId;";
            
            echo "<div>
                 </div>";
            //Info o pracodawcy
            wyswietlenieOgloszenPracodawcy($dbh, $pracodawcaId);
        } else {
            header("index.php");
        }
        
        ?>
    </body>
</html>
