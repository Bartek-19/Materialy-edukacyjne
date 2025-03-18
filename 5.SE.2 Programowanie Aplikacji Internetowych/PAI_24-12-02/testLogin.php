<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <?php
            include_once 'klasy/Baza.php'; 
            include_once 'klasy/User.php'; 
            include_once 'klasy/UserManager.php';
            session_start();
            $um = new UserManager();
            $db = new Baza("localhost", "root", "", "klienci");
            $sessionId = session_id();
            $userId = $um->getLoggedInUser($db, $sessionId);
            if($userId>0) {
                echo "<a href='loginProcess.php?akcja=wyloguj'>Wyloguj</a></p>"; 
                echo "<br><h4>Dane zalogowanego użytkownika:</h4>";
                $sql = "SELECT id, userName, email FROM users WHERE id=$userId;";
                echo $db->select($sql, ['id', 'userName', 'email']);
            } else {
                header("Location: loginProcess.php");
            }
        ?>
    </body>
</html>
