//
//  Utwor.swift
//  PWJS_25-01-17
//
//  Created by student on 17/01/2025.
//

class Utwor {
    var tytul: String
    var czasTrwania: UInt16
    
    init() {
        self.tytul = "ZTM"
        self.czasTrwania = 280
    }
    
    init(tytul: String, czasTrwania: UInt16) {
        self.tytul = tytul
        self.czasTrwania = czasTrwania
    }
    
    func info() {
        print("\"\(self.tytul)\", czas trwania: \(self.czasTrwania/60):\(self.czasTrwania%60)", terminator: "")
    }
    
    func getCzas() -> UInt16 {
        return self.czasTrwania
    }
}
