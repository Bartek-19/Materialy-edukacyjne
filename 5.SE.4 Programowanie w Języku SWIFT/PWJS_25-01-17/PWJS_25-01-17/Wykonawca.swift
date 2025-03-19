//
//  Wykonawca.swift
//  PWJS_25-01-17
//
//  Created by student on 17/01/2025.
//

class Wykonawca {
    var imie, nazwisko: String
    
    init() {
        self.imie = "Taco"
        self.nazwisko = "Hemingway"
    }
    
    init(imie: String, nazwisko: String) {
        self.imie = imie
        self.nazwisko = nazwisko
    }
    
    func info() {
        print("\(self.imie) \(self.nazwisko)", terminator: "")
    }
}
