//
//  main.swift
//  PWJS_24-11-15
//
//  Created by student on 15/11/2024.
//

import Foundation

enum oceny {
    case ndst
    case dst
    case dstPlus
    case db
    case dbPlus
    case bdb
}

main()

func main() {
    let osoba1 = ("Jan", "Adamczewski", 1630)
    let osoba2 = ("Adam", "Janusz", 1984)
    zad1(os1:osoba1, os2:osoba2)
}

func zad1( os1: (i1: String, n1: String, r1: Int), os2: (i2: String, n2: String, r2: Int) ) {
    if os1.r1 == os2.r2 {
        print("Obie osoby sa w tym samym wieku")
    } else if os1.r1 < os2.r2 {
        print("Osoba 1 jest starsza od osoby 2")
    } else {
        print("Osoba 2 jest starsza od osoby 1")
    }
}

func zad2() {
    var student1 = ("Adamski", ocena(o: oceny.ndst), ocena(o: oceny.dbPlus), ocena(o: oceny.dst))
    var student2 = ("Jakubowski", ocena(o: oceny.bdb), ocena(o: oceny.dbPlus), ocena(o: oceny.db))
    var student3 = ("Zaborowski", ocena(o: oceny.dst), ocena(o: oceny.dstPlus), ocena(o: oceny.dst))
    
    var student1_nowy = studentSrednia(s: student1)
    var student2_nowy = studentSrednia(s: student2)
    var student3_nowy = studentSrednia(s: student3)
    
    
}

func ocena(o: oceny)->Double {
    switch o {
        case .ndst: return 2.0
        case .dst: return 3.0
        case .dstPlus: return 3.5
        case .db: return 4.0
        case .dbPlus: return 4.5
        case .bdb: return 5.0
    }
}

func studentSrednia(s: (nazw: String, o1: Double, o2: Double, o3: Double)) -> (String, Double) {
    var Srednia = (s.o1 + s.o2 + s.o3)/3
    return (s.nazw, Srednia)
}


//func wczytajDane()->(String, Double, Double, Double) {
//    var nazwisko: String
//}
