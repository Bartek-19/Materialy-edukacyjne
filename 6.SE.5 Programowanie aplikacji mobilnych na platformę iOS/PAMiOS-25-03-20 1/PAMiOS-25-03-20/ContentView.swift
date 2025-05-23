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
    @State var szer = ""
    @State var wys = ""
    @State var ramka = false
    var body: some View {
        VStack {
            
            VStack {
                HStack {
                    FigurePickerView(kolory: $klasa.ksztalty, wybor: $wyb)
                    ColorPicker("", selection: $color) 
                }
                HStack {
                    Text("Szerokosc: ")
                    TextField("Podaj", text: $szer)
                } 
                HStack {
                    Text("Wysokosc: ")
                    TextField("Podaj", text: $wys)
                }
                HStack {
                    Toggle("Ramka", isOn: $ramka)
                }
            }.border(Color.black)
            
            Text("") 
                .padding()
                .background(
                    switch(wyb.name) {
                    case "Elipsa":
                        Ellipse()
                            .fill(color)
                            .frame(
                                width: klasa.convertStringToCGFloat(val: wys), 
                                height: klasa.convertStringToCGFloat(val: szer)
                            )
                    case "Kwadrat":
                        Rectangle()
                            .fill(color)
                            .frame(
                                width: klasa.convertStringToCGFloat(val: wys), 
                                height: klasa.convertStringToCGFloat(val: szer)
                            )
                    default:
                        Circle()
                            .fill(color)
                            .frame(
                                width: klasa.convertStringToCGFloat(val: wys), 
                                height: klasa.convertStringToCGFloat(val: szer)
                            )
                    }
                )
        }
        .padding()
    }
}

#Preview {
    ContentView()
}
