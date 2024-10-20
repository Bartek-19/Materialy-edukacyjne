function wartoscPozyczki() {
    var kwota=document.getElementById("kwota");
    kwota = parseFloat(kwota.value);
    var raty = document.getElementById("raty");
    raty = parseInt(raty.value);
    var procent = document.getElementById("procent");
    procent = parseFloat(procent.value)/100.0;
    var rata = document.getElementById("rata");
    var r = (kwota*procent/12)/(1-1/(1+procent/12)**raty);
    r = Math.round(r * 100);
    r /= 100;
    rata.value = r;
    var suma = document.getElementById("suma");
    suma.value = r * raty;
    
}