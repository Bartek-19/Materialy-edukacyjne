function pokaz(id)
{
    var tresc="";
    switch (id)
    { 
        case 2: tresc += pokazGalerie();break;
        case 3: tresc += pokazPost(); break;
        case 4: tresc += pokazKontakt();break; 
        default: tresc += pokazO();
    }
    //pobierz element o wskazanym id i ustaw jego nową zawartość:
    document.getElementById('blok').innerHTML = tresc; 
}
function pokazO(){
    var tresc ='<h2><br />Pierwsze kroki</h2> '; //operator += uzupełnia łańcuch kolejną porcją znaków:
    tresc += '<p> W aplikacjach typu SPA ......</p>'+
    '<p class="srodek"><img src="img/baner.jpg" alt="Zdjęcie" /></p>'+
    '<article><h2>Wady SPA</h2><p>'+ ' Czas wytworzenia oraz nakład pracy ... </p></article>';
    //przekaż wynik – gotową zawartość – do miejsca wywołania funkcji:
    return tresc;
}
function pokazGalerie()
{ 
    var tresc='<h2><br />Moja galeria</h2>';
    tresc+=' <div class="galeria">';
    //wygeneruj kod HTML z obrazami za pomocą pętli for:
    for(i=1;i<=10;i++)
    {
       tresc+='<div class="slajd"> <img src="img/obraz'+i+'.jpg"/></div>';
    }
    return tresc+'</div>';
}
function pokazKontakt()
{ 
    var tresc='<h2><br>Kontakt<br></h2>';
    //uzupełnij treść:
    tresc += '<p><h6>Telefon: </h6>101010101 </p> <br>'+'<p><h6>Email: </h6>politechnika@pollub.pl </p> <br>'+'<p> <h6>Adres: </h6>ul. Nadbystrzycka 38, 20-618 Lublin</p> <br>';
    return tresc;
}
function pokazPost()
{ 
    //funkcja generuje kod formularza – dane wpisane w odpowiednie pola przez 
    //użytkownika zostaną przekazane mailem na wskazany adres, ale najpierw po 
    //zajściu zdarzenia submit (wyślij) – zostanie wywołana funkcja pokazDane()
    tresc = '<h2><br />Dodaj post</h2>';
    tresc += '<article class="srodek" ><form action="#" method="get" onsubmit="return pokazDane();">'+
    'Twój email:<br> <input type="email" name="email" id="email" required pattern="[^@]+@[^@]+\.[^@]"><br>'+
    'Nazwisko i Imię:<br> <input type="text" name="imie" id="imie" required pattern="[A-Za-z]+\s+[A-Za-z]"><br>'+
    'Numer telefonu:<br><input type="tel" name="tel" id="tel" required pattern="[0-9]{9}"><br>'+
    'Komentarz:<br><textarea rows="3" cols="20" id="wiadomosc" name="wiadomosc" required></textarea><br>'+
    '<input type="submit" name="wyslij" value="Wyślij">'+
    '</form></article>';
    return tresc;
}
function pokazDane()
{
    //Funkcja zbiera dane wpisane w pola formularza i wyświetla okienko typu confirm do zatwierdzenia przez użytkownika:
    var dane="Następujące dane zostaną wysłane:\n";
    dane+="Email: "+document.getElementById('email').value+"\n"+
    "Nazwisko i imię: "+document.getElementById('imie').value+"\n"+
    "Telefon: "+document.getElementById('tel').value+"\n"+
    "Wiadomość: "+document.getElementById('wiadomosc').value+"\n";
    if (window.confirm(dane)) return true;
    else return false;
}
