//
//  Egzample.swift
//  PAMiOS-25-04-24
//
//  Created by student on 24/04/2025.
//

import SwiftUI

struct Egzample: View {
    @State var time: Double = 10
    @State var edit: Bool = false
    @State var text = ""
    var body: some View {
        NavigationView {
            VStack {
                Text("Show").toolbar {
                    ToolbarItem {
                        Button("Edit"){
                            edit.toggle()
                            time = 30
                            text = "Czarny pies"
                        }
                    }
                }
                
                Menu() {
                    Button(action: {
                        text = "Ala ma kota"
                    }) {
                        Text("Pokaz")
                    }
                } label: {
                    Text("Menu")
                }
                
                Image(systemName: "globe")
                    .imageScale(.large)
                    .foregroundStyle(.tint)
                Text(text)
                
                Slider(value: $time, in: 0...100, step: 5, onEditingChanged: {
                    editing in
                    edit = editing
                })
                
                Text("\(time)")
                    .font(.largeTitle)
                    .foregroundStyle(edit ? .green : .red)
                
                    .padding()
            }
        }
    }
}

#Preview {
    Egzample()
}
