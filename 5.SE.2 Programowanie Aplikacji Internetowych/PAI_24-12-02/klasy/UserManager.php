<?php
class UserManager {
    function loginForm() { 
    ?> 
        <h3>Formularz logowania</h3><p> 
        <form action="loginProcess.php" method="post"> 
            Login: <input type="text" name="login"><br>
            Hasło: <input type="password" name="passwd"><br>
            <input type="submit" value="Zaloguj" name="zaloguj">
            <input type="reset" value="Anuluj" name="Anuluj">
        </form></p> <?php 
    } 
    function login($db) { 
        //funkcja sprawdza poprawność logowania  
        //wynik - id użytkownika zalogowanego lub -1 
        $args = [ 
                'login' => FILTER_SANITIZE_ADD_SLASHES, 
                'passwd' => FILTER_SANITIZE_ADD_SLASHES 
            ]; 
        //przefiltruj dane z GET (lub z POST) zgodnie z ustawionymi  
        //w $args filtrami: 
        $dane = filter_input_array(INPUT_POST, $args); 
        //sprawdź czy użytkownik o loginie istnieje w tabeli users  
        //i czy podane hasło jest poprawne 
        $login = $dane["login"]; 
        $passwd = $dane["passwd"]; 
        $userId = $db->selectUser($login, $passwd, "users"); 
        if ($userId >= 0) { //Poprawne dane  
            session_start(); //rozpocznij sesję zalogowanego użytkownika
            $query = "DELETE FROM logged_in_users WHERE userId=$userId;"; //usuń wszystkie wpisy historyczne dla użytkownika o $userId 
            if($db->delete($query)) {
                echo "Usunieto logowania użytkownika";
            } else {
                echo "Nie można usunąć logowań użytkownika";
            }
            echo "<br>";
            $date = date("Y-m-d H:i:s"); //ustaw datę - format("Y-m-d H:i:s"); 
            $insertQuery = "INSERT INTO logged_in_users (sessionId, userId, lastUpdate) VALUES ('" . session_id() . "', $userId, '$date');";
            if($db->insert($insertQuery)) {
                echo "Zalogowano";
            } else {
                echo "Nie udało się zalogować";
            }
        } 
        return $userId; 
    } 
    
    function logout($db) { 
        session_start();
        $sesID = session_id();
        session_destroy();
        $query = "DELETE FROM logged_in_users WHERE sessionId='$sesID';";
        if($db->delete($query)) {
            echo "Wylogowano";
        }
        //pobierz id bieżącej sesji (pamiętaj o session_start() 
        //usuń sesję (łącznie z ciasteczkiem sesyjnym) 
        //usuń wpis z id bieżącej sesji z tabeli logged_in_users 
    } 
    
    function getLoggedInUser($db, $sessionId) { 
        $id = -1;
        $mysqli = $db->getMysqli();
        $wynik = $mysqli->query("SELECT * FROM logged_in_users WHERE sessionId='$sessionId';");
        $ile = $wynik->num_rows; 
            if ($ile == 1) { 
                $row = $wynik->fetch_object();
                $id = $row->userId;
            } 
        //wynik $userId - znaleziono wpis z id sesji w tabeli logged_in_users  
        //wynik -1 - nie ma wpisu dla tego id sesji w tabeli logged_in_users  
        return $id;
    }
}

