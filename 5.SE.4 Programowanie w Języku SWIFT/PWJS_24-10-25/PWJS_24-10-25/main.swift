//
//  main.swift
//  PWJS_24-10-25
//
//  Created by student on 25/10/2024.
//

import Foundation

func zad1() {
    var fib, temp: Int
    var i=0, j=1
    
    repeat {
        print("Podaj maksymalna wartosc elementow ciagu Fibonacciego: ")
        fib = Int(readLine()!)!
        if(fib<0) {
            print("!!!Podano liczbe mniejsza od zera!!!")
        }
    } while(fib<0)
    
    while(j<=fib) {
        print(j)
        temp = i
        i = j
        j = i + temp
    }
}

func zad2() {
    var n: Int
    var i=2
    var isFirst = false
    
    repeat {
        print("Podaj liczbe: ")
        n = Int(readLine()!)!
    } while(n<0)
    
    var lim=Int(sqrt(Double(n)))
    
    while(i<lim) {
        if(n%i==0) {
            isFirst = true
        }
    }
    
    if(isFirst) {
        print("Podana liczba jest pierwsza")
    } else {
        print("Podana liczba jest nie pierwsza")
    }
}

func zad3() {
    var liczba: String
    var liczbaInt, n: Int
    var S: Double
    
    repeat {
        print("Podaj liczbe min. trzycyfrowa: ")
        liczba = readLine()!
    } while(Int(liczba)!<100)
    
    liczbaInt = Int(liczba)!
    S = 1.0
    n = 0
    
    while(liczbaInt != 0) {
        S *= Double(liczbaInt%10)
        liczbaInt /= 10
        n += 1
    }
    
    S = sqrt(S)
    
    print("Srednia geometryczna cyfr: \(S)")
}

func zad4() {
    var str: String
    var i, j: Int
    
    print("Podaj palindrom: ")
    str = readLine()!
    
    if(str.isEmpty) {
        print("Podano pusty ciag")
    } else {
        i = 0
        j = str.count-1
        while( (str[str.index(str.startIndex, offsetBy: i)] == str[str.index(str.startIndex, offsetBy: j)]) && (i<j) ) {
            i += 1
            j -= 1
        }
        
        if(i==j) {
            print("Podany ciag jest palindromem")
        } else {
            print("Podany ciag nie jest palindromem")
        }
    }
}

func zad5() {
    var n, i, j: Int
    
    repeat {
        print("Podaj liczbe elementow calkowitych: ")
        n = Int(readLine()!)!
    } while(n<=3)
    
    var a = Array(repeating: 0, count: n)
    
    i = 0
    while(i<n) {
        print("Podaj liczbe a[\(i)]: ")
        a[i] = Int(readLine()!)!
        j = 0
        for j in 0..<i {
            if(a[j]==a[i]) {
                print("Podana liczba juz wystepuje!")
                i -= 1
            }
        }
        i += 1
    }
    
    
}

func main() {
    var wybor: Int
    
    repeat {
        print("Podaj numer zadania (1-5): ")
        wybor = Int(readLine()!)!
        switch(wybor) {
            case 0: print("Koniec programu")
            case 1: zad1()
            case 2: zad2()
            case 3: zad3()
            case 4: zad4()
            case 5: zad5()
            default: print("Zly wybor")
        }
    } while(wybor != 0)
}
