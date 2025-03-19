//
//  main.swift
//  PWJS_25-01-10
//
//  Created by student on 10/01/2025.
//

import Foundation

main()

func main() {
    zad1()
}

func zad1() {
    let pracownik1 = Pracownik()
    let pracownik2 = Pracownik(imie: "Aldona", nazwisko: "Szczesnik",rokUr: 2001, rokZat: 2023, stanowisko: .st1, stawka: 26.70, godziny: 20, nazwaFirmy: "Kolchozex")
    let pracownik3 = Pracownik(imie: "Adam", nazwisko: "Chlodny", rokUr: 1971, rokZat: 2005, stanowisko: .st4, stawka: 250.00, godziny: 80, nazwaFirmy: "Stacja Paliw Chlodny-Oil")
    let pracownik4 = Pracownik(imie: "Anna", nazwisko: "Tetnica", rokUr: 1964, rokZat: 1999, stanowisko: .st2, stawka: 29.20, godziny: 80, nazwaFirmy: "Biuro rachunkowe Expert")
    
    pracownik1.info()
    print("Wynagrodzenie w biezacym miesiacu: \(pracownik1.pensja())\n")
    pracownik2.info()
    print("Wynagrodzenie w biezacym miesiacu: \(pracownik2.pensja())\n")
    pracownik3.info()
    print("Wynagrodzenie w biezacym miesiacu: \(pracownik3.pensja())\n")
    pracownik4.info()
    print("Wynagrodzenie w biezacym miesiacu: \(pracownik4.pensja())\n")
}
