<?php
class Baza {
    private $mysqli; //uchwyt do BD 
    
    public function __construct($serwer, $user, $pass, $baza) { 
        $this->mysqli = new mysqli($serwer, $user, $pass, $baza); 
        /* sprawdz połączenie */ 
        if ($this->mysqli->connect_errno) { 
            printf("Nie udało sie połączenie z serwerem: %s\n", $this->mysqli->connect_error); 
            exit(); 
        } 
        /* zmien kodowanie na utf8 */ 
        if ($this->mysqli->set_charset("utf8")) { 
            //udało sie zmienić kodowanie 
        } 
    } //koniec funkcji konstruktora 
    
    function __destruct() { 
        $this->mysqli->close(); 
    } 
    public function select($sql) { 
        if (($result = $this->mysqli->query($sql))) { 
            return $result; 
        } else {
            return null;
        }
    } 
     
    public function delete($sql) { 
        if( $this->mysqli->query($sql)) {return true;} else {return false;} 
    } 
 
    public function insert($sql) {  
        if( $this->mysqli->query($sql)) {return true;} else {return false;}
    } 
 
    public function getMysqli() {   
        return $this->mysqli;
    }
}
