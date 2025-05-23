//
//  Model.swift
//  PAMiOS-25-03-20
//
//  Created by student on 20/03/2025.
//

import Foundation
import SwiftUI

struct FigurePickerElement: Hashable {
    var name: String
    var icon: String
    var id: Int
}

class DataForView {
    var ksztalty: [FigurePickerElement] = []
    
    init() {
        ksztalty.append(FigurePickerElement(name: "Kolo", icon: "pencil.circle.fill", id: 1))
        ksztalty.append(FigurePickerElement(name: "Kwadrat", icon: "square.fill", id: 2))
        ksztalty.append(FigurePickerElement(name: "Elipsa", icon: "pencil.and.outline", id: 3))
    }
    
    
}
