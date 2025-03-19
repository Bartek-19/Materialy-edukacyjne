//
//  main.swift
//  PWJS 24-10-18
//
//  Created by student on 18/10/2024.
//

import Foundation

main()

func main()
{
    zad1()
}

func zad1()
{
    print("Podaj ciag znakow: ")
    let ciag = readLine()!
    print("Podaj pojedynczy znak: ")
    let znak = Character(readLine()!)
    print("Podaj liczbe calkowita: ")
    let ind = Int(readLine()!)!
    print("\n")
    
    if(znak == ciag.first) {
        print("Znak znajduje sie na poczatku ciagu")
    }
    if(znak == ciag.last) {
        print("Znak znajduje sie na koncu ciagu")
    }
    if(znak == ciag[ciag.index(ciag.startIndex, offsetBy: ind)]) {
        print("Znak jest oddalony od poczatku ciagu o \(ind) znakow")
    }
    if(znak == ciag[ciag.index(ciag.endIndex, offsetBy: -1-ind)]) {
        print("Znak jest oddalony od konca ciagu o \(ind) znakow")
    }
}

func zad2()
{
    print("Podaj ciag 1: ")
    let ciag1 = readLine()!
    
    print("Podaj ciag 2: ")
    let ciag2 = readLine()!
    
    if(ciag1.elementsEqual(ciag2)) {
        print("Ciagi sa identyczne")
    }
    
    print("\nPodaj prefiks: ")
    let prefix = readLine()!
    
    if(prefix == ciag1.prefix(upTo: prefix.endIndex)) {
        print("Ciag 1 posiada podny prefiks")
    }
    if(prefix == ciag2.prefix(upTo: prefix.endIndex)) {
        print("Ciag 2 posiada podny prefiks")
    }
    
    print("\nPodaj sufiks: ")
    let sufix = readLine()!
    
    if() {
        print("Ciag 1 posiada podny sufiks")
    }
    if() {
        print("Ciag 2 posiada podny sufiks")
    }
}
