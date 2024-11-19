<?php
include_once('klasy/User.php');

class RegistrationForm {
    protected $user;

    function __construct() {
        echo '<h3>Formularz rejestracyjny</h3>' .  
             '<form method="post" action="">' .
             'Imie i nazwisko: <input type="text" name="fullName" required><br>' . 
             'Adres E-mail: <input type="email" name="email" required><br>' . 
             'Nazwa użytkownika: <input type="text" name="userName" required><br>' .
             'Hasło: <input type="password" name="passwd" required><br>' .
             '<input type="submit" name="submit" value="Wyślij"><br>' . 
             '</form><br>';
    }

    function checkUser() {
        $args = [
            'fullName' => [ 'filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/^[A-ZŁŚŻŹĆŃ][a-ząęłńśćźżó-]{1,25}(?: [A-ZŁŚŻŹĆŃ][a-ząęłńśćźżó-]{1,25})*$/'] ],
            'email' => FILTER_VALIDATE_EMAIL,
            'userName' => [ 'filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/^[a-zA-Z0-9]{3,20}$/'] ],
            'passwd' => [ 'filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/^.{8,}$/'] ]
        ];
        
        $dane = filter_input_array(INPUT_POST, $args);
        $blad = "";
        foreach ($dane as $key => $val) { 
            if ($val === false or $val === NULL) { 
                $blad .= $key . " "; 
            } 
        }

        if ($blad === "") {
            echo "Blad: $blad <br>";
            return NULL;
        } else {
            $fullName = $dane["fullName"];
            $email = $dane["email"];
            $userName = $dane["userName"];
            $passwd = $dane["passwd"];
            return new User($userName, $fullName, $email, $passwd);
        }
    }
}