//
//  ContentView.swift
//  PAMiOS-25-03-20
//
//  Created by student on 20/03/2025.
//

import SwiftUI

struct ContentView: View {
    @State var color : Color = .red
    @State var wyb: FigurePickerElement = FigurePickerElement(name: "", icon: "", id: 0)
    @State var klasa = DataForView()
    var body: some View {
        VStack {
            
            VStack {
                HStack {
                    FigurePickerView(kolory: $klasa.ksztalty, wybor: $wyb)
                    ColorPicker("Kolor", selection: $color)
                }
                HStack {
                    Text("Szerokosc: ")
                    
                }
            }
        }
        .padding()
    }
}

#Preview {
    ContentView()
}
