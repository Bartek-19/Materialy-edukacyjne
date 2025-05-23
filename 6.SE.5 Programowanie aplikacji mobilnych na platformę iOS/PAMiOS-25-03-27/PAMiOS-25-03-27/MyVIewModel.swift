//
//  MyVIewModel.swift
//  PAMiOS-25-03-27
//
//  Created by student on 27/03/2025.
//

import Foundation

class MyViewModel : ObservableObject {
    var zwierzeta: [String] = []
    var samochody: [String] = []
    var kwiaty: [String] = []
    
    enum ImageCategory : String, CaseIterable {
        case animals = "Animals"
        case cars = "Cars"
        case flowers = "Flowers"
    }
    
    init() {
        for i in 1...8 {
            zwierzeta.append(String("a\(i)"))
        }
        for i in 1...6 {
            samochody.append(String("c\(i)"))
        }
        for i in 1...11 {
            kwiaty.append(String("f\(i)"))
        }
    }
    
    func getImageNameForCategory(category: ImageCategory, andIndex: Int) -> String? {
        switch(category) {
        case .animals:
            return zwierzeta[andIndex]
        case .cars:
            return samochody[andIndex]
        case .flowers:
            return kwiaty[andIndex]
        }
    }
    
    func getImageNumbersForCategories() -> [(ImageCategory,Int)] {
        return [(.animals, zwierzeta.count), (.cars, samochody.count), (.flowers, kwiaty.count)]
    }
}
