//
//  OponyView.swift
//  PAMiOS_25-03-13
//
//  Created by student on 13/03/2025.
//

import SwiftUI

struct OponyView: View {
    @State var producenci = ["Pirelli", "Michelin", "Dębica", "Toyotires"]
    @State var rozmiary = ["R15", "R16", "R17", "R18", "R19"]

    @State var magazyn = Array(repeating: Array(repeating: Int.random(in: 10...20000), count: 4), count: 5)
    
    @State var i=0
    @State var j=0
    @State var count=0
    @State var countStr=""

    var body: some View {
        VStack {
            
            Picker("Producent", selection: $i) {
                ForEach(0..<producenci.count, id: \.self) {
                    ind in
                    Text(producenci[ind])
                }
            }.pickerStyle(SegmentedPickerStyle())
            
            Picker("Rozmiar", selection: $j) {
                ForEach(0..<rozmiary.count, id: \.self) {
                    ind in
                    Text(rozmiary[ind])
                }
            }.pickerStyle(SegmentedPickerStyle())
            
            TextField("Ilość sztuk", text: $countStr)
            
            //count = Int(countStr)!
            
            if(count > magazyn[i][j]) {
                Text("Nie można zrealizować zamówienia")
            } else {
                //magazyn[i][j] -= count
            }
        }
    }
}

#Preview {
    OponyView()
}
