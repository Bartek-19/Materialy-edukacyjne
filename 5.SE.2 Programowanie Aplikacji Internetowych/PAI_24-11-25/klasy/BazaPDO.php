<?php
class BazaPDO {
    private $dbh; //uchwyt do BD 
    
    public function __construct($serwer, $user, $pass) { 
        try {   $this->dbh = new PDO($serwer, $user, $pass,   
                [PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES utf8"]);  
        } catch (PDOException $e) {  
            print "Error!: " . $e->getMessage() . "<br>";  die();  
        } 
    } 
    
    function __destruct() {  
        $this->dbh=null; 
    } 
    
    public function select($sql) { 
        foreach ($this->dbh->query($sql) as $row) {  print_r($row); print("<br>");  } 
    }
    
    public function insert($nazwisko, $wiek, $panstwo, $email, $zamowienie, $platnosc) {
        $stmt = $this->dbh->prepare('INSERT INTO klienci (Nazwisko, Wiek, Panstwo, Email, Zamowienie, Platnosc) VALUES (?, ?, ?, ?, ?, ?);');
        $stmt->bindParam(1, $nazwisko); 
        $stmt->bindParam(2, $wiek);
        $stmt->bindParam(3, $panstwo);
        $stmt->bindParam(4, $email);
        $stmt->bindParam(5, $zamowienie);
        $stmt->bindParam(6, $platnosc);
        $stmt->execute();
    }
    
    public function delete($sql) {
        //if( $this->dbh->query($sql)) {return true;} else {return false;} 
    }
    
    public function getMysqli() {   
        return $this->dbh;  
    }
}
