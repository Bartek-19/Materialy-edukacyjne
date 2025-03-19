//
//  main.swift
//  PWJS 24-10-04
//
//  Created by student on 04/10/2024.
//

/*
import Foundation

var a, s : Int
s = 0
for _ in 1...5 {
    a = Int.random(in: 1..<100)
    s+=a
    print("Wygenerowan Liczba: ", a)
    print("Aktualna suma: ", s)
}

print("\nSuma elementow: ", s)
print("\n\n")

//deklaracja stalej
let pi = 3.14159
var r: Double = 0.0
print("Podaj promien")
r = Double(readLine()!)!
let pole = pi * r * r
let obwod = 2 * pi * r

//ustalenie typu zmiennych
//var aa, b, c: Double

//deklaracja zmiennych
var maxValue = 20
var aa = 0.0, b = 1.0, c = 5.0

//deklaracja zmiennej z typem
var name: String
var age = 23
name = "Ann"
print(name)
print(name, age)
print("Witaj \(name)! Masz \(age) lat")

var value1: Int
//var � = "smile" emotki cos nie dzialaja

print("Tekst z przejściem do nowej linii")
print("Tekst bez łamania linii", terminator:"")
print(" kolejna linia")

/* Zewnetrzny komentarz
    /* 
        Wewnetrzny komentarz
    */
*/

//stala minimalna i maksymalna calkowitej liczby 16-bitowej
let min = Int16.min
let max = Int16.max

aa = 878.66
b = 66.983
c = aa/b
let str = String(format: "%.2lf", c)
print(str) //13.12

//Przypisanie do zmiennych wartosci w roznych systemach liczbowych
let val = 21
let valBin = 0b10101
let valoct = 0o25
let valHex = 0x15

let val1 = 1.45e2 //145
let val2 = 1.45e-2 //0.0145
let valhex = 0xFp3 //120

let num1 = 00056.78
let num2 = 23_560_000

let num3 = 7.896543
let intNum1 = Int(num1)//7
let num4 = -5.63214
let intNum2 = Int(num2)//-5

let num5 = 5
let num6 = 2
let c1 = num5 / num6 //2
let c2 = Double(num5) / Double(num6) //2.5

var str1: String? = "223"
print(str1!)

var str2: String = "223"
var val1: Int?
val1 = Int (str2)
print(val1!) - w tym przykladzie cos nie dziala
*/

import Foundation

var S = 0, n = 3, a: Int
var Sr: String
for _ in 1...n {
    a = Int.random(in: 1..<50)
    S += a
    print("Wylosowana liczba: ", a)
}

Sr = String(format: "%2.2lf", (Double(S)/Double(n)))

print("Suma liczb: ", S)
print("Sredni liczb: ", Sr)
print("\n")



let rok = 2024
var rokUrodzenia: String?
var rokUrodzeniaInt: Int?

print("Podaj rok urodzenia")
rokUrodzenia = readLine()!
rokUrodzeniaInt = Int(rokUrodzenia!)

if(rokUrodzeniaInt! > rok) {
    print("Podano niepoprawny rok urodzenia")
} else {
    print("Masz ", (rok - rokUrodzeniaInt!), " lat")
}
print("\n")



let pi = 3.14159
var r: Double = 0.0

print("Podaj promien")
r = Double(readLine()!)!

if(r<0.0) {
    print("Podano ujemny promien")
} else {
    let pole = pi * r * r
    let obwod = 2 * pi * r
    let rStr = String(format: "%.2lf", r)
    let poleStr = String(format: "%.2lf", pole)
    let obwodStr = String(format: "%.2lf", obwod)
    print("Promien: ", rStr, "\nPole: ", poleStr, "\nObwod: ", obwodStr)
}

