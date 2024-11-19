<!DOCTYPE html>
<!--
Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
Click nbfs://nbhost/SystemFileSystem/Templates/Scripting/EmptyPHPWebPage.php to edit this template
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <?php 
        //skrypt generuje formularz i jednoczesnie   
        //odbiera dane z niego wysłane  
            if (isset($_POST['tekst'])) { //przesłano żądanie z parametrem 'tekst'
                $tekst= htmlspecialchars($_POST['tekst']); 
                print "Wpisano: $tekst <br>"; 
                print "<a href='wyklad.php'> Powrót do formularza</a>"; 
            } 
            else {
                //nie przesłano danych z formularza - w żądaniu nie 
                //ma parametru o kluczu 'tekst' - wyswietl formularz 
                print "Podaj tekst :<form  method='post' action='wyklad.php'>";
                print "<input type='tekst' name='tekst' size='30'>";
                print "<input type='submit' value='Wyślij'>";
                print "</form>";
            }
        ?>
    </body>
</html>
