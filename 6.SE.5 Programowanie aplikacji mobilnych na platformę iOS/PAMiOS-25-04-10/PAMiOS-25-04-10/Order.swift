//
//  Order.swift
//  PAMiOS-25-04-10
//
//  Created by student on 10/04/2025.
//

enum smak: String, CaseIterable {
    case lemon = "Cytrynowy"
    case raspberry = "Malinowy"
    case pistachio = "Pistacjowy"
    case jalapeno = "Jalapeno"
}

enum rodzaj: String, CaseIterable {
    case latte = "Latte Machiato"
    case capuccino = "Capuccino"
    case espresso = "Espresso"
}

struct kawa {
    var smakKawy: String
    var rodzajKawy: String
}

