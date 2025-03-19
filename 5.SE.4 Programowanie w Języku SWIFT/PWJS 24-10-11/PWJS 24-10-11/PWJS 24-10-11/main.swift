//
//  main.swift
//  PWJS 24-10-11
//
//  Created by student on 11/10/2024.
//

import Foundation

func zad1() {
    var bok, obw, pole: Double
    
    print("Podaj bok szescianu: ")
    bok = Double(readLine()!)!
    
    if(bok>0) {
        obw = 4 * bok
        pole = bok * bok
        let bokStr = String(format: "%.2lf", bok)
        let obwStr = String(format: "%.2lf", obw)
        let poleStr = String(format: "%.2lf", pole)
        
        print("Obwod kwadratu o boku \(bokStr) wynosi \(obwStr) \nJego pole wynosi \(poleStr)")
    }
    else {
        print("Wprowadzono zla liczbe")
    }
}

func zad2() {
    var a, b, z, s, wynik: Double
    
    repeat {
        print("Podaj wymiar sciany pokoju (cm): ")
        a = Double(readLine()!)!
    } while a<=0
    
    repeat {
        print("Podaj wymiar sciany pokoju wspolnej z korytarzem (cm): ")
        b = Double(readLine()!)!
    } while b<=0
    
    repeat {
        print("Podaj wymiar sciany korytarza (cm): ")
        z = Double(readLine()!)!
    } while z<=0
    
    repeat {
        print("Podaj wymiar drzwi w korytarzu (cm): ")
        s = Double(readLine()!)!
    } while s<=0
    
    wynik = 2 * a + 4 * b + 2 * z - 2 * s
    
    let wynikStr = String(Int(ceil(wynik/100)))
    
    print("Wynik: Potrzebne jest \(wynikStr) metrow biezacych listwy do pokoju oraz korytarza")
}

func zad3() {
    var n : [Int] = [0, 0, 0]
    var S : Double
    
    for i in 1...3 {
        n[i-1] = Int.random(in: 1...9)
    }
    
    S = 0.0
    for i in 1...3 {
        S += Double(n[i-1])
    }
    S /= 3.0
    
    print("Srednia liczb \(n[0]), \(n[1]), \(n[2]) wynosi \(String(format: "%.3lf", S))")
}

func zad4() {
    var oceny = Array(repeating: 0, count: 3)
    var wagi = Array(repeating: 0, count: 3)
    var S : Double
    var sumaWag : Int
    
    for i in 1...3 {
        repeat {
            print("Ocena \(i): ")
            oceny[i-1] = Int(readLine()!)!
        } while oceny[i-1]>6 || oceny[i-1]<1
        repeat {
            print("Waga oceny \(i): ")
            wagi[i-1] = Int(readLine()!)!
        } while wagi[i-1]>3 || wagi[i-1]<1
    }
    
    S = 0.0
    for i in 1...3 {
        S += Double(oceny[i-1]) * Double(wagi[i-1])
    }
    
    sumaWag = 0
    for i in 1...3 {
        sumaWag += wagi[i-1]
    }
    
    S /= Double(sumaWag)
    
    print("Srednia wazona ocen \(oceny[0]), \(oceny[1]), \(oceny[2]) o wagach odpowiednio \(wagi[0]), \(wagi[1]), \(wagi[2]) wynosi \(String(format: "%.3lf", S))")
}

func zad5() {
    let napis1 = "Napis jednoliniowy\n\n"
    let napis2 = """
                Potezny\n
                napis\n
                wieloliniowy\n
                koniec\n
                """
    
    print(napis1, napis2)
}

func zad6() {
    let napis = "\n\tNauka kodowania to nie tylko nauka języka technologii.\n\tTo odkrywanie nowych sposobów myślenia \n\ti urzeczywistnianie rozmaitych koncepcji.\n"
    
    print(napis)
}

func zad7() {
    
}
