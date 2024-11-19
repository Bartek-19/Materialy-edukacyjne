<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Formularz rejestracyjny</title>
</head>
    <body>
        <?php
        include('klasy/User.php'); 
        include('klasy/RegistrationForm.php'); 
        $rf = new RegistrationForm();
        if ($_SERVER['REQUEST_METHOD'] === 'POST' && filter_input(INPUT_POST, 'submit', FILTER_SANITIZE_FULL_SPECIAL_CHARS)) {
            $user = $rf->checkUser();
            if ($user === NULL) {
                echo "<p>Niepoprawne dane rejestracji.</p>";
            } else {
                echo "<p>Poprawne dane rejestracji:</p>";
                $user->show();
                $user->saveXML();
                echo "<br>";
                User::getAllUsersFromXML();
            }
        }
        ?>
    </body>
</html>