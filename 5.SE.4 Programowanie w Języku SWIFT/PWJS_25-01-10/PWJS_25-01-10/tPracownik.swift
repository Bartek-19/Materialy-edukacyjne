//
//  tPracownik.swift
//  PWJS_25-01-10
//
//  Created by student on 10/01/2025.
//


enum Stanowiska {
    case st1 //"Osoba sprzatajaca"
    case st2 //"Pracownik ksiegowosci"
    case st3 //"Czlonek zarzadu"
    case st4 //Prezes
}

class Pracownik : Osoba {
    var rokZatrudnienia: UInt16
    var stanowisko: Stanowiska
    var stawka: Double
    var godziny: UInt16
    var nazwaFirmy: String
    
    override init() {
        rokZatrudnienia = 2007
        stanowisko = .st3
        stawka = 100.51
        godziny = 40
        nazwaFirmy = "Januszex"
        super.init()
    }
    
    init(imie: String, nazwisko: String, rokUr: UInt16, rokZat: UInt16, stanowisko: Stanowiska, stawka: Double, godziny: UInt16, nazwaFirmy: String) {
        rokZatrudnienia = rokZat
        self.stanowisko = stanowisko
        self.stawka = stawka
        self.godziny = godziny
        self.nazwaFirmy = nazwaFirmy
        super.init(imie: imie, nazwisko: nazwisko, rok: rokUr)
    }
    
    func doswiadczenie() -> UInt16 {
        return 2025 - rokZatrudnienia
    }
    
    func pensja() -> Double {
        return Double((100*stawka*Double(godziny)).rounded()/100)
    }
    
    override func info() {
        print("\(nazwisko) \(imie), ur. \(rokUrodzenia), Stanowisko: ", terminator: "")
        switch(stanowisko) {
        case .st1:
            print("Osoba sprzatajaca, ", terminator: "")
        case .st2:
            print("Osoba sprzatajaca, ", terminator: "")
        case .st3:
            print("Osoba sprzatajaca, ", terminator: "")
        case .st4:
            print("Osoba sprzatajaca, ", terminator: "")
        }
        print("Stawka godzinowa: \(stawka), Ilosc przepracowanych godzin w tym miesiacu: \(godziny), Nazwa firmy: \(nazwaFirmy)")
    }
}
