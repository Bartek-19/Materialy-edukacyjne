<?php
    include_once 'Baza.php'; 
    $ob = new Baza('localhost','root','','test'); 
    /*if (isset($_GET['id'])) {
        if ($ob->delete('DELETE FROM strony WHERE id="'.$ob->protect_int($_GET['id']).'"')) {
            echo 'Skasowano rekord o id='.$_GET['id']; 
        } else { 
            echo 'Nie można skasować rekordu!';
        }
    }*/
    if (isset($_POST['id'])) {
        if ($ob->delete('DELETE FROM strony WHERE id="'.$ob->protect_int($_POST['id']).'"')) {
            echo 'Skasowano rekord o id='.$_POST['id']; 
        } else { 
            echo 'Nie można skasować rekordu!';
        }
    }

