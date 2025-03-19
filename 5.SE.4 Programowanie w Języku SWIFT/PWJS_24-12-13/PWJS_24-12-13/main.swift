//
//  main.swift
//  PWJS_24-12-13
//
//  Created by student on 13/12/2024.
//

import Foundation

main()

func main() {
    //zad1()
    print("\n")
    //zad2()
}

func zad1() {
    let P1 = Punkt(x: 2.71, y: 3.81)
    let P2 = Punkt(w: -1.786)
    let P3 = Punkt()
    let P4 = Punkt(w: 2.0001)
    let P5 = Punkt(x: -2.0001, y: 1.5)
    let P6 = Punkt(x: 1.3, y: 2.0001)
    let kwadrat = 2.0001
    
    print("P1: ", terminator: "")
    P1.show()
    print("P2: ", terminator: "")
    P2.show()
    print("P3: ", terminator: "")
    P3.show()
    print("P4: ", terminator: "")
    P4.show()
    print("P5: ", terminator: "")
    P5.show()
    print("P6: ", terminator: "")
    P6.show()
    
    print("\nOdleglosc P1 od P2: ", terminator: " ")
    print(P1.odleglosc(P: P2))
    print("Odleglosc P2 od P3: ", terminator: " ")
    print(P2.odleglosc(P: P3))
    print("Odleglosc P1 od P3: ", terminator: " ")
    print(P3.odleglosc(P: P1))
    
    print("\nPorownanie cwiartek:")
    print("P1 > P2: ", terminator: "")
    print(P1 > P2)
    print("P2 > P3: ", terminator: "")
    print(P2 > P3)
    
    print("\nPunkty wzgledem kwadratu \(kwadrat):")
    print("P1: ", terminator: "")
    print(punktWzgledemKwadratu(k: kwadrat, P: P1))
    print("P2: ", terminator: "")
    print(punktWzgledemKwadratu(k: kwadrat, P: P2))
    print("P3: ", terminator: "")
    print(punktWzgledemKwadratu(k: kwadrat, P: P3))
    print("P4: ", terminator: "")
    print(punktWzgledemKwadratu(k: kwadrat, P: P4))
    print("P5: ", terminator: "")
    print(punktWzgledemKwadratu(k: kwadrat, P: P5))
    print("P6: ", terminator: "")
    print(punktWzgledemKwadratu(k: kwadrat, P: P6))
}

class Punkt {
    private var x: Double
    private var y: Double
    
    func getX() -> Double {
        return self.x
    }
    
    func getY() -> Double {
        return self.y
    }
    
    init() {
        x=0.0
        y=0.0
    }
    
    init(w: Double) {
        self.x = w
        self.y = w
    }
    
    init(x: Double, y: Double) {
        self.x = x
        self.y = y
    }
    
    func odleglosc(P: Punkt) -> Double {
        return sqrt( pow(self.x - P.getX(), 2) + pow(self.y - P.getY(), 2) )
    }
    
    func cwiartka() -> Int8 {
        if( self.x>0 && self.y>0 ) { return 1 }
        else if( self.x>0 && self.y<0 ) { return 2 }
        else if( self.x<0 && self.y<0 ) { return 3 }
        else if( self.x<0 && self.y>0 ) { return 4 }
        else { return 0 }
    }
    
    func show() {
        print("(\(self.x); \(self.y)), cwiartka \(self.cwiartka())")
    }
    
    static func > (lhs: Punkt, rhs: Punkt) -> Int8 {
        if( lhs.cwiartka() > rhs.cwiartka() ) {
            return 2
        } else if( lhs.cwiartka()==rhs.cwiartka() ) {
            return 1
        } else {
            return 0
        }
    }
}

func punktWzgledemKwadratu(k: Double, P: Punkt) -> Int8 {
    let t = abs(k)
    if( P.getX()<t && P.getX()>(-t) && P.getY()<t && P.getY()>(-t) ) {
        return 1
    } else if ( (P.getX()==t || P.getX()==(-t)) && P.getY()<=t && P.getY()>=(-t) ) {
        return 0
    } else if ( (P.getY()==t || P.getY()==(-t)) && P.getX()<=t && P.getX()>=(-t) ) {
        return 0
    } else {
        return -1
    }
}

func zad2() {
    var O1 = Osoba(Imie: "Janusz", Nazwisko: "Kowal", rok: 2000)
    var O2 = Osoba(Imie: "Anna", Nazwisko: "Adamczewska", rok: 1984)
    
    O1.info()
    O2.info()
    
    var K1 = Ksiazka(autor: O1, tytul: "Slownik jezyka francuskiego", rok: 2023, strony: 304)
    
    
}
