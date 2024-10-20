/*!
* Start Bootstrap - Small Business v5.0.6 (https://startbootstrap.com/template/small-business)
* Copyright 2013-2023 Start Bootstrap
* Licensed under MIT (https://github.com/StartBootstrap/startbootstrap-small-business/blob/master/LICENSE)
*/
// This file is intentionally blank
// Use this file to add JavaScript to your project

function wyswietl(nrStrony) {
    switch(nrStrony) {
        case 1: zmienZawartoscElementu("content/stronaGlowna.txt"); break;
        case 2: zmienZawartoscElementu("content/dlaczegoMy.txt"); break;
        case 3: zmienZawartoscElementu("content/oferta.txt"); break;
        case 4: zmienZawartoscElementu("content/cenyUslug.txt"); break;
        case 5: zmienZawartoscElementu("content/wskazniki.txt"); break;
        case 6: zmienZawartoscElementu("content/dojazd.txt"); break;
        case 7: zmienZawartoscElementu("content/kontakt.txt"); break;
        case 8: zmienZawartoscElementu("content/linki.txt"); break;
        case 9: zmienZawartoscElementu("content/ksiegiRachunkowe.txt"); break;
        case 10: zmienZawartoscElementu("content/ksiegiPrzychodow.txt"); break;
        case 11: zmienZawartoscElementu("content/kadryPlace.txt"); break;
        case 12: zmienZawartoscElementu("content/inne.txt"); break;
        case 13: zmienZawartoscElementu("content/formularz.txt"); break;
        case 14: zmienZawartoscElementu("content/podsumowanie.txt"); break;
        case 15: zmienZawartoscElementu("content/sukces.txt"); break;
        case 16: zmienZawartoscElementu("content/powrot.txt"); break;
        default: zmienZawartoscElementu("content/stronaGlowna.txt");
    }
}

async function pobierzZawartoscPliku(nazwaPliku) {
    try {
        const odpowiedz = await fetch(nazwaPliku);
        if (!odpowiedz.ok) {
            throw new Error(`Błąd sieciowy: ${odpowiedz.statusText}`);
        }
        const tresc = await odpowiedz.text();
        return tresc;
    } catch (error) {
        console.error('Wystąpił błąd podczas pobierania pliku:', error);
    }
}

async function zmienZawartoscElementu(nazwaPliku) {
    const tresc = await pobierzZawartoscPliku(nazwaPliku);
    if (tresc) {
        const elementZawartosc = document.getElementById("Zawartosc");
        if (elementZawartosc) {
            elementZawartosc.fadeOut(1000, function(){
                elementZawartosc.innerHTML = tresc;
                elementZawartosc.fadeIn(1000);
            });
        } 
        else {
            console.error('Nie znaleziono elementu z identyfikatorem "Zawartosc".');
        }
    }
    else {
        console.error('Nie udało się pobrać zawartości pliku.');
    }
}

function podsumowanie() {
    var item;
    item.key = 'key_item';
    item.companyName = document.getElementById("nazwaFirmy").value;
    item.name = document.getElementById("imie").value;
    item.surname = document.getElementById("nazwisko").value;
    item.email = document.getElementById("email").value;
    item.tel = document.getElementById("tel").value;
    item.form = document.getElementById("forma").value;
    item.vat = document.getElementById("vat").value;
    item.export = document.getElementById("export").value;
    item.dokumenty = document.getElementById("dokumenty").value;
    item.uop = document.getElementById("uop").value;
    item.ucp = document.getElementById("ucp").value;
    sessionStorage.setItem(item.key, JSON.stringify(item));
    
    wyswietlPodsumowanie();
}

function wyswietlPodsumowanie() {
    var item = JSON.parse(localStorage.getItem('key_item'));
    var elem;
    
    wyswietl(14);
    elem = document.getElementById('imieNazwisko');
    elem.innerHtml = item.name + ' ' + item.surname;
    elem = document.getElementById('email');
    elem.innerHtml = item.email;
    elem = document.getElementById('tel');
    elem.innerHtml = item.tel;
    elem = document.getElementById('nazwaFirmy');
    elem.innerHtml = item.companyName;
    elem = document.getElementById('forma');
    elem.innerHtml = forma(elem.form);
    elem = document.getElementById('vat');
    if(item.vat === 1)
        elem.innerHtml = 'Tak';
    else
        elem.innerHtml = 'Nie';
    elem = document.getElementById('export');
    if(item.export === 1)
        elem.innerHtml = 'Tak';
    else
        elem.innerHtml = 'Nie';
    elem = document.getElementById('dokumenty');
    elem.innerHtml = item.dokumenty;
    elem = document.getElementById('uop');
    elem.innerHtml = item.uop;
    elem = document.getElementById('ucp');
    elem.innerHtml = item.ucp;
}

function forma(nrFormy) {
    switch(nrFormy) {
        case 1: return "Działalność gospodarcza";
        case 2: return "Fundacja/Stowarzyszenie";
        case 3: return "Prosta spółka akcyjna";
        case 4: return "Spółka akcyjna";
        case 5: return "Spółka cywilna";
        case 6: return "Spółka jawna";
        case 7: return "Spółka komandytowa";
        case 8: return "Spółka komandytowo-akcyjna";
        case 9: return "Spółka partnerska";
        case 10: return "Spółka z o. o.";
    }
}

function dalej() {
    wyswietl(15);
    setTimeout(() => { wyswietl(1); }, 3000);
}

function powrot() {
    wyswietl(16);
    setTimeout(() => { wyswietl(1); }, 3000);
}