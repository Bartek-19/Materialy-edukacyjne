<?php
class User {
    const STATUS_USER = 1; 
    const STATUS_ADMIN = 2; 
    protected $userName;
    protected $passwd;
    protected $fullName;
    protected $email;
    protected $date;
    protected $status;

    function __construct($userName, $fullName, $email, $passwd) {
        $this->fullName = $fullName;
        $this->userName = $userName;
        $this->email = $email;
        $this->setPasswd($passwd);
        $this->date = date("Y-m-d");
        $this->status = self::STATUS_USER;
    }

    public function setPasswd($passwd): void { 
        $this->passwd = password_hash($passwd, PASSWORD_DEFAULT);
    }

    public function show() {
        echo "Pełne imię: " . $this->fullName . "<br>";
        echo "Nazwa użytkownika: " . $this->userName . "<br>";
        echo "E-mail: " . $this->email . "<br>";
        echo "Hasło (zahaszowane): " . $this->passwd . "<br>";
        echo "Data utworzenia: " . $this->date . "<br>";
        echo "Status: " . ($this->status === self::STATUS_ADMIN ? "Administrator" : "Użytkownik") . "<br>";
    }

    static function getAllUsers($plik) { 
        if (!file_exists($plik)) {
            echo "<p>Brak zarejestrowanych użytkowników.</p>";
            return;
        }
        $tab = json_decode(file_get_contents($plik));
        if ($tab === null) {
            echo "<p>Brak zarejestrowanych użytkowników.</p>";
            return;
        }
        foreach ($tab as $val) { 
            echo "<p>{$val->userName} - {$val->fullName} - {$val->date}</p>";
        }
    }
    
    function toArray() { 
        return [
            "userName" => $this->userName,
            "passwd" => $this->passwd,
            "fullName" => $this->fullName,
            "email" => $this->email,
            "date" => $this->date,
            "status" => $this->status
        ]; 
    }

    function save($plik) { 
        $tab = file_exists($plik) ? json_decode(file_get_contents($plik), true) : [];
        if (!is_array($tab)) { $tab = []; }
        $tab[] = $this->toArray();
        file_put_contents($plik, json_encode($tab, JSON_PRETTY_PRINT));
    }
    
    function saveXML() {
        $xml = simplexml_load_file('users.xml'); 
        $xmlCopy=$xml->addChild("user"); 
        $xmlCopy->addChild("userName", $this->userName); 
        $xmlCopy->addChild("passwd", $this->passwd);
        $xmlCopy->addChild("fullName", $this->fullName);
        $xmlCopy->addChild("email", $this->email);
        $xmlCopy->addChild("date", $this->date);
        $xmlCopy->addChild("status", $this->status); 
        $xml->asXML('users.xml');    
    }
    
    static function getAllUsersFromXML() {
        $allUsers = simplexml_load_file('users.xml'); 
        echo "<ul>"; 
        foreach ($allUsers as $user): 
            $userName = $user->userName; 
            $date = $user->date;
            $fullName = $user->fullName;
            echo "<li>$userName, $fullName, $date </li>"; 
        endforeach; 
        echo "</ul>"; 
    }
}
