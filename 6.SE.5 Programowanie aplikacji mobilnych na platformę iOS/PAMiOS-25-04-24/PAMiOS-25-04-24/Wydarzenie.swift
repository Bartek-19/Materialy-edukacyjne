//
//  Wydarzenie.swift
//  PAMiOS-25-04-24
//
//  Created by student on 24/04/2025.
//

class Wydarzenie {
    var nazwaWydarzenia: String
    var czasTrwana: Double
    
    init() {
        nazwaWydarzenia = "Wydarzenie"
        czasTrwana = 0
    }
    
    init(nazwaWydarzenia: String, czasTrwania: Double) {
        self.nazwaWydarzenia = nazwaWydarzenia
        self.czasTrwana = czasTrwania
    }
}
