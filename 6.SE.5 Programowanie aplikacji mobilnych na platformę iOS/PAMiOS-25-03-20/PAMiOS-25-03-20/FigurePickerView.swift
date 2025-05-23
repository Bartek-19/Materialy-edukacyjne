//
//  FigurePickerView.swift
//  PAMiOS-25-03-20
//
//  Created by student on 20/03/2025.
//

import SwiftUI

struct FigurePickerView: View {
    @Binding var kolory: [FigurePickerElement]
    @Binding var wybor: FigurePickerElement
    var body: some View {
        VStack {
            Picker("Kolor",
                   selection: $wybor,
                   content: {
                ForEach(kolory, id: \.self) {
                    i in
                    HStack {
                        Text(i.name)
                        Image(systemName: i.icon)
                    }
                }
            })  .pickerStyle(MenuPickerStyle())
        }
        
    }
}

//#Preview {
//    FigurePickerView(kolory: , )
//}
