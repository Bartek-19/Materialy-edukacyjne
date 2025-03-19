//
//  tOsoba.swift
//  PWJS_24-12-13
//
//  Created by student on 13/12/2024.
//

class Osoba {
    private var Imie: String
    private var Nazwisko: String
    private var rokUr: UInt
    
    init(Imie: String, Nazwisko: String, rok: UInt) {
        self.Imie = Imie
        self.Nazwisko = Nazwisko
        if(rok>2024) {
            self.rokUr = 2024
        } else {
            self.rokUr = rok
        }
    }
    
    func info() {
        print("Nazwisko: \(Nazwisko)")
        print("Imie: \(Imie)")
        print("Rok urodzenia: \(rokUr)")
    }
    
    func getRokUrodzenia() -> UInt {
        return self.rokUr
    }
}
