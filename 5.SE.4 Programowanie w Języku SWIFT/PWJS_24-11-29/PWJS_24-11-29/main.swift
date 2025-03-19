//
//  main.swift
//  PWJS_24-11-29
//
//  Created by student on 29/11/2024.
//

import Foundation

struct liczbaZespolona {
    var real: Double
    var imaginary: Double
}

struct rzutOszczepem {
    var athleteID: UInt
    var attempts: [Double] = [0.0, 0.0, 0.0]
}

//var lotniska [String : String] = ["BZG" : "Bydgoszcz", "GDN" : "Gdansk", "KTW" : "Katowice"]

func main() {
    //zad1()
    //zad2()
}

func zad1() {
    var cars: Set = ["Challenger", "Charger", "Barracuda", "Eldorado", "Cobra"]
    cars.insert("Impala")
    cars.insert("Charger")
    var carToDel: String
    
    if(cars.isEmpty) {
        print("Brak elementow w zbiorze")
    } else {
        print(cars)
    }
    
    print("Podaj nazwe samochodu do usuniecia: ", terminator: " ")
    carToDel = readLine()!
    
    if(cars.contains(carToDel)) {
        print("Usunieto \"\(carToDel)\" ze zbioru aut")
    } else {
        print("Samochod \"\(carToDel)\" nie wystepuje w zbiorze aut")
    }
    print(" ")
}

func zad2() {
    var students: [UInt : String] = [:]
    var ID: UInt
    var surname: String
    var searchID: UInt?
    
    for _ in 1...5 {
        (ID, surname) = pobierzDane()
        if(students.isEmpty) {
            students.updateValue(surname, forKey: ID)
        } else {
            while(students.keys.contains(ID)) {
                print("Podany identyfikator istnieje juz w systemie, wprowadz dane ponownie: ")
                (ID, surname) = pobierzDane()
            }
            students.updateValue(surname, forKey: ID)
        }
    }
    
    print("Wyszukaj nazwisko po identyfikatorze")
    searchID = wyszukajStudenta(students: students)
    if(searchID==nil) {
        print("Podany student nie wystepuje w systemie")
    } else {
        print("\(students[searchID!])")
    }
    
    print("Usuwanie studenta")
    searchID = wyszukajStudenta(students: students)
    if(searchID==nil) {
        print("Podany student nie wystepuje w systemie")
    } else {
        students[searchID!] = nil
        print("Usunieto studenta o ID \(searchID!)")
    }
}

func pobierzDane() -> (ID: UInt, name: String) {
    var ID: UInt?
    var name: String?
    
    repeat {
        print("Podaj identyfikator studenta: ", terminator: " ")
        ID = UInt(readLine()!)!
    } while(ID! < 0 || ID==nil)
    
    repeat {
        print("Podaj nazwisko studenta: ", terminator: " ")
        name = readLine()!
    } while(name=="" || name==" " || name==nil)
    
    return (ID!, name!)
}

func wyswietlStudentow(students: [UInt : String]) {
    for (k, v) in students {
        print("\(k): \(v)")
    }
}

func wyszukajStudenta(students: [UInt : String]) -> UInt? {
    var ID: UInt?
    
    repeat {
        print("Podaj identyfikator: ", terminator: " ")
        ID = UInt(readLine()!)!
    } while(ID! < 0 || ID==nil)
    
    if(students.keys.contains(ID!)) {
        return ID!
    } else {
        return nil
    }
}
