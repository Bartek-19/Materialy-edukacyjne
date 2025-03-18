<?php
$tytul = "Galeria"; 
$i = 1;
$zawartosc = "";
while($i <= 10) {
    $zawartosc .= "<a href='zdjecia/obraz$i.JPG' target='_blank'><img class='miniaturka' src='miniaturki/obraz$i.JPG' alt='Obraz $i'></a>";
    $i++;
}
