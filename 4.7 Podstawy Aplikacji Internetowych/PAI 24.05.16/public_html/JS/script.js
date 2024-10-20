function Zapisz() {
    var item = {};
    item.name = document.getElementById("Nazwa").value.toString();
    item.price = parseFloat(document.getElementById("Cena").value);
    item.color = document.getElementById("Kolor").value.toString();
    item.quantity = parseInt(document.getElementById("Sztuki").value);
    item.number = 'item_'+localStorage.length.toString();
    
    localStorage.setItem(item.number, JSON.stringify(item));
    
    document.getElementById("Nazwa").value = '';
    document.getElementById("Cena").value = '';
    document.getElementById("Kolor").value = '';
    document.getElementById("Sztuki").value = '';
}

function Wyswietl() {
    var tresc = '<br><thead><tr><th>Numer</th><th>Nazwa</th><th>Kolor</th>' + 
                '<th>Cena szt.</th><th>Ilosc</th><th>Cena</th></tr></thead><tbody>';
    var item;
    var itemKey;
    for(var i=0; i<localStorage.length; i++)
    {
        itemKey = 'item_'+i.toString();
        item = JSON.parse(localStorage.getItem(itemKey));
        tresc += '<tr><td>'+i+'</td><td>'+item.name+'</td><td>'+item.color+'</td><td>'+parseFloat(item.price).toFixed(2)+
                 '</td><td>'+item.quantity+'</td><td>'+parseFloat(parseInt(item.quantity) * parseFloat(item.price).toFixed(2))+'</td></tr>';
    }
    tresc += '</tbody><div id="SchowajTabele"><button id="Schowaj" onclick="Schowaj()">Schowaj listę produktów</button></div>';
    
    document.getElementById("ListaProduktow").innerHTML = tresc;
}

function UsunProdukty() {
    var itemKey;
    var n = localStorage.length;
    for(var i=0; i<n; i++)
    {
        itemKey = 'item_'+i.toString();
        localStorage.removeItem(itemKey);
    }
    document.getElementById("Info").innerHTML = 'usunięto wszystkie produkty z koszyka';
    setTimeout(() => { document.getElementById("Info").innerHTML = ''; }, 2000);
}

function Wybor() {
    Wyswietl();
    var max = localStorage.length;
    var tresc = 'Podaj numer produktu do usuniecia: <input type="number" id="UsunNumer" min="0" max="'+parseInt(max)+'"><br><button id="Usun" onclick="Usun()">Usuń</button>';
    document.getElementById("Info").innerHtml = tresc;
}

function Usun() {
    var numer = parseInt(document.getElementById("UsunNumer").value);
    var tab = [];
    var item;
    var itemKey;
    var searchKey = 'item_'+numer;
    
    for(var i=0; i<localStorage.length; i++)
    {
        itemKey = 'item_'+i.toString();
        item = JSON.parse(localStorage.getItem(itemKey));
        tab += item;
    }
    for(var i=0; i<tab.length; i++)
    {
        if(tab[i].number === searchKey)
        {
            tab.pop(tab[i]);
            break;
        }
    }
    for(var i=0; i<tab.length; i++)
    {
        tab[i].number = 'item_'+i.toString();
        localStorage.setItem(tab[i].number, JSON.stringify(tab[i]));
    }
    
    Wyswietl();
    setTimeout(() => { document.getElementById("Info").innerHTML = 'Usunięto wybrany produkt z koszyka'; }, 5000);
    document.getElementById("Info").innerHTML = '';
    Schowaj();
}

function Schowaj() {
    document.getElementById("ListaProduktow").innerHTML = '';
}