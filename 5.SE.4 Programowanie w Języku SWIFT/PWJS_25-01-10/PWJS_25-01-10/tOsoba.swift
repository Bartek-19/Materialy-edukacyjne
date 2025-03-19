//
//  tOsoba.swift
//  PWJS_25-01-10
//
//  Created by student on 10/01/2025.
//

class Osoba {
    var imie: String
    var nazwisko: String
    var rokUrodzenia: UInt16
    
    init() {
        imie = "Jan"
        nazwisko = "Kowalski"
        rokUrodzenia = 1989
    }
    
    init(imie: String, nazwisko: String, rok: UInt16) {
        self.imie = imie
        self.nazwisko = nazwisko
        self.rokUrodzenia = rok
    }
    
    func info() {
        print("\(nazwisko) \(imie), ur. \(rokUrodzenia)")
    }
}
