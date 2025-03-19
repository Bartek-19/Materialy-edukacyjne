//
//  main.swift
//  PWJS_25-01-17
//
//  Created by student on 17/01/2025.
//

import Foundation

main()

func main() {
    var czasSr: Double = 0.0
    var czasMin: UInt16 = 0, czasMax: UInt16 = 0
    var album1 = Album()
    
    album1.info()
    sredniCzas(a: album1, czas: &czasSr)
    czasy(a: album1, czasMin: &czasMin, czasMax: &czasMax)
    print("Sredni czas trwania utworu w albumie: \(Int(round(czasSr)))s")
    print("Najkrotszy czas trwania utworu: \(czasMin)s, najdluzszy: \(czasMax)s.")
}

func sredniCzas(a: Album, czas: inout Double) {
    var tab = a.getUtwory()
    for u in tab {
        czas += Double(u.getCzas())
    }
    czas /= Double(tab.count)
}

func czasy(a: Album, czasMin: inout UInt16, czasMax: inout UInt16) {
    var tab = a.getUtwory()
    czasMin = (tab.first)!.getCzas()
    czasMax = czasMin
    for u in tab {
        if(u.getCzas()<czasMin) {
            czasMin = u.getCzas()
        }
        if(u.getCzas()>czasMax) {
            czasMax = u.getCzas()
        }
    }
}
