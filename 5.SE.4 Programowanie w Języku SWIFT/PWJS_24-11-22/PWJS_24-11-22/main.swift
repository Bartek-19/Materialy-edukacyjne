//
//  main.swift
//  PWJS_24-11-22
//
//  Created by student on 22/11/2024.
//

import Foundation

func zad1() {
    var n, m, wart, max, min: Int
    var licznik = 0
    
    print("Podaj liczbe wierszy: ", terminator: " ")
    n = Int(readLine()!)!
    print("Podaj liczbe kolumn: ", terminator: " ")
    m = Int(readLine()!)!
    print("Podaj liczbe, ktora chcesz zliczac w tablicy [-100, 100]: ", terminator: " ")
    wart = Int(readLine()!)!
    
    var tab: [[Int]] = Array(repeating: Array(repeating: 0, count: m), count: n)
    
    for i in 0..<n {
        for j in 0..<m {
            tab[i][j] = Int.random(in: -100...100)
        }
    }
    
    max = tab[0][0]
    min = tab[0][0]
    
    for i in 0..<n {
        for j in 0..<m {
            if(tab[i][j] == wart) {
                licznik+=1
            }
            if(tab[i][j] > max) {
                max = tab[i][j]
            }
            if(tab[i][j] < min) {
                min = tab[i][j]
            }
        }
    }
    
    print("Element najmniejszy: \(min), element najwiekszy: \(max),")
    print("Ilosc wystapien \(wart) w tablicy: \(licznik)")
}

func zad2() {
    var m, n: Int
    var podaj: Character
    var tab: [[Double]]
    
    repeat {
        print("Czy chcesz samodzielnie podac parametry macierzy(T/N): ", terminator: "")
        podaj = Character(readLine()!)
    } while(podaj != "T" && podaj != "t" && podaj != "N" && podaj != "n")
    
    if(podaj == "T" || podaj == "t") {
        (tab, n, m) = podajMacierz()
    } else {
        (tab, n, m) = generujMacierz()
    }
    
    
}

func wyswietlMacierz(tab: [[Int]], n: Int, m: Int) {
    for i in 0..<n {
        print("[ ", terminator: "")
        for j in 0..<m {
            print("\(tab[i][j]) ", terminator: "")
        }
        print("]")
    }
}

func podajMacierz() -> (tab: [[Double]], n: Int, m: Int) {
    var n, m: Int
    
    repeat {
        print("Podaj pierwszy wymiar macierzy: ", terminator: "")
        n = Int(readLine()!)!
    } while(n < 0)
    
    repeat {
        print("Podaj drugi wymiar macierzy: ", terminator: "")
        m = Int(readLine()!)!
    } while(m < 0)
    
    var tab: [[Double]] = Array(repeating: Array(repeating: 0.0, count: m), count: n)
    
    for i in 0..<n {
        for j in 0..<m {
            print("tab[\(i)][\(j)] = ", terminator: "")
            tab[i][j] = Double(readLine()!)!
        }
    }
    
    return (tab, n, m)
}

func generujMacierz() -> (tab: [[Double]], n: Int, m: Int) {
    var n = Int.random(in: 2...10), m = Int.random(in: 2...10)
    var tab: [[Double]] = Array(repeating: Array(repeating: 0.0, count: m), count: n)
    
    for i in 0..<n {
        for j in 0..<m {
            tab[i][j] = Double.random(in: -15.5...15.5)
        }
    }
    
    return (tab, n, m)
}

func czySymetryczna(tab: [[Double]], n: Int, m: Int) -> Bool {
    for i in 0..<n {
        for j in i+1..<m {
            if(tab[i][j] != tab[j][i]) {
                return false
            }
        }
    }
    
    return true
}

func wektorSum(tab: [[Double]], n: Int, m: Int) -> [Double] {
    var wektor: [Double] = Array(repeating: 0.0, count: n), suma: Double
    
    for i in 0..<n {
        suma = 0.0
        for j in 0..<m {
            suma += tab[i][j]
        }
        wektor[i] = suma
    }
    
    return wektor
}

func norma(tab: [[Double]], n: Int, m: Int) -> Double {
    var wynik = 0.0
    
    for i in 0..<n {
        for j in 0..<m {
            wynik += pow(tab[i][j], 2)
        }
    }
    
    return sqrt(wynik)
}

func wektorMax(tab: [[Double]], n: Int, m: Int) -> [Double] {
    var wektor: [Double] = Array(repeating: 0.0, count: m), max: Double
    
    for j in 0..<m {
        max = tab[0][j]
        for i in 1..<n {
            if(tab[i][j] > max) {max = tab[i][j]}
        }
        wektor[j] = max
    }
    
    return wektor
}

func czyDiagonalna(tab: [[Double]], n: Int, m: Int) -> Bool {
    if(n != m) {
        return false
    } else {
        for i in 0..<n {
            for j in 0..<m {
                if(i==j) {
                    if(tab[i][j] == 0) {
                        return false
                    }
                } else {
                    if(tab[i][j] != 0) {
                        return false
                    }
                }
            }
        }
    }
    return true
}

func dominujacaGlownaPrzekatna(tab: [[Double]], n: Int, m: Int) -> Bool {
    var suma: Double
    
    if(n != m) {
        return false
    } else {
        for i in 0..<n {
            suma = 0.0
            for j in 0..<m {
                if(i != j) { suma+=tab[i][j] }
                if(tab[i][i] < suma) { return false }
            }
        }
    }
    return true
}
