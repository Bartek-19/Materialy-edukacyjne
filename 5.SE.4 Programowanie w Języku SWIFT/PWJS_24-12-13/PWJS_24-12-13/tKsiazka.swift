//
//  tKsiazka.swift
//  PWJS_24-12-13
//
//  Created by student on 13/12/2024.
//

class Ksiazka {
    private var autor: Osoba
    private var tytul: String
    private var rokWydania: UInt
    private var liczbaStron: UInt
    
    init(autor: Osoba, tytul: String, rok: UInt, strony: UInt) {
        self.autor = autor
        self.tytul = tytul
        if(rok>2024 || rok<self.autor.getRokUrodzenia()) {
            self.rokWydania = 2024
        } else {
            self.rokWydania = rok
        }
        self.liczbaStron = strony
    }
    
    func info() {
        print("Autor:")
    }
}
    
