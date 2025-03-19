//
//  main.swift
//  PWJS_24-11-08
//
//  Created by student on 08/11/2024.
//

import Foundation

main()

func main() {
    //zad1()
    zad2()
    //zad3()
    //zad4()
    print("\n")
}

func zad1() {
    var tab: [Int] = Array(repeating: 1, count: 12)
    for i in tab {
        print(i)
    }
}

func zad2() {
    var tab: [Int] = []
    var x: Int
    
    print("Tablica poczatkowa:", terminator: " ")
    for _ in 1...10 {
        x = Int.random(in: 1...100)
        tab.append(x)
        print("\(x)", terminator: " ")
    }
    
    print("\nPodaj liczbe calkowita o indeksie 0: ", terminator: "")
    x = Int(readLine()!)!
    tab.insert(x, at: 0)
    print("Tablica zmodyfikowana:", terminator: " ")
    for i in 0...9 {
        print("\(tab[i])", terminator: " ")
    }
    
    print("\nPodaj liczbe calkowita o losowym indeksie: ", terminator: "")
    x = Int(readLine()!)!
    tab.insert(x, at: Int.random(in: 1...10))
    print("Tablica ponownie zmodyfikowana:", terminator: " ")
    for i in 0...9 {
        print("\(tab[i])", terminator: " ")
    }
}

func zad3() {
    var tab: [Int] = []
    var x: Int
    var n: Int
    
    repeat {
        print("Podaj liczbe elementow tablicy: ", terminator: "")
        n = Int(readLine()!)!
    } while(n<=0)
    
    for i in 1...n {
        print("Podaj element \(i-1): ")
        x = Int(readLine()!)!
        tab.append(x)
    }
    
    print("Podaj liczbe calkowita: ", terminator: "")
    x = Int(readLine()!)!
    
    if(x==tab[0]) {
        print("Podana liczba zanjduje sie na poczatku tablicy")
    } else {
        print("Podana liczba nie zanjduje sie na poczatku tablicy")
    }
    
    if(x==tab[n-1]) {
        print("Podana liczba zanjduje sie na koncu tablicy")
    } else {
        print("Podana liczba nie zanjduje sie na koncu tablicy")
    }
}

func zad4() {
    var n = Int.random(in: 3...100), l=0
    var tab: [Int] = Array(repeating: 0, count: n)
    var S1 = 0.0
    var S2 = 1.0
    var S3 = 0.0;
    
    for i in 0...n-1 {
        tab[i] = Int.random(in: 3...100)
    }
    
    print("Elementy tablicy: ", terminator: "")
    for i in 0...n-1 {
        print("\(tab[i])", terminator: " ")
    }
    
    for i in 0...n-1 {
        S1 += Double(tab[i])
    }
    S1 /= Double(n)
    
    for i in 0...n-1 {
        if(tab[i]%2==0) {
            S2 *= Double(tab[i])
            l+=1
        }
    }
    S2 = nthroot(of: S2, at: Double(l))
    
    for i in 0...n-1 {
        S3 += 1/Double(tab[i])
    }
    S3 = Double(n)/S3
    
    print("\nSrednia arytmetyczna liczb z tablicy: \(S1)")
    print("Srednia geometryczna liczb z tablicy: \(S2)")
    print("Srednia harmoniczna liczb z tablicy: \(S3)")
}

func nthroot(of value: Double,  at n: Double) -> Double {
    let multipleOf2 = abs(n.truncatingRemainder(dividingBy: 2)) == 1
    return value < 0 && multipleOf2 ? -pow(-value, 1/n) : pow(value, 1/n)
}
