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
    
    public function setStatus($stat): void {
        if($stat===2 || $stat==='Admin' || $stat==='ADMIN') {
            $this->status = self::STATUS_ADMIN;
        } else {
            $this->status = self::STATUS_USER;
        }
    }

    public function show() {
        echo "Pełne imię: " . $this->fullName . "<br>";
        echo "Nazwa użytkownika: " . $this->userName . "<br>";
        echo "E-mail: " . $this->email . "<br>";
        echo "Hasło (zahaszowane): " . $this->passwd . "<br>";
        echo "Data utworzenia: " . $this->date . "<br>";
        echo "Status: " . ($this->status === self::STATUS_ADMIN ? "Administrator" : "Użytkownik") . "<br>";
    }
    
    public function showTest() {
        echo "username: $this->userName<br>" . 
             "fullname: $this->fullName<br>" . 
             "email: $this->email<br>" . 
             "status: $this->status<br>";
    }

    public function saveDB($db) {
        echo "Zapisywanie uzytkownika do bazy danych<br>";
        $query = "INSERT INTO users (userName, fullName, email, passwd, status, date)" . 
            "VALUES ('$this->userName', '$this->fullName', '$this->email', " .
            "'$this->passwd', $this->status, '$this->date');";
        if( $db->query($query)) {return true;} else {return false;} 
    }
    
    static function getAllUsersFromDB($db) {
        $tresc = "";
        $sql = "SELECT id,userName,fullName,email,status,date FROM users";
        $pola = ['id', 'userName', 'fullName', 'email', 'status', 'date'];
        if (($result = $db->query($sql))) {
            $ilepol = count($pola);
            $ile = $result->num_rows;
            $tresc.="<table><tbody>";
            while ($row = $result->fetch_object()) {
                $tresc.="<tr>";
                for ($i = 0; $i < $ilepol; $i++) {
                    $p = $pola[$i];
                    $tresc.="<td>" . $row->$p . "</td>";
                }
                $tresc.="</tr>";
            }
            $tresc.="</table></tbody>";
            $result->close();
        }
        echo "$tresc";
    }
}
