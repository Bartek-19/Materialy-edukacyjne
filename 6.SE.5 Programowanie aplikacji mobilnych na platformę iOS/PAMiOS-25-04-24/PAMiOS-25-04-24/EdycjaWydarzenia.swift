//
//  EdycjaWydarzenia.swift
//  PAMiOS-25-04-24
//
//  Created by student on 24/04/2025.
//

import SwiftUI

struct EdycjaWydarzenia: View {
    @Binding var wydarzenie: Wydarzenie
    @State private var edit = false
    var body: some View {
        VStack {
            HStack {
                Text("Podaj nazwe wydarzenia: ")
                    .font(.title)
                TextField("Wprowadz nazwe wydarzenia", text: $wydarzenie.nazwaWydarzenia)
            }
            
            Text("Podaj czas trwania (w minutach): ")
            Slider(value: $wydarzenie.czasTrwana, in: 0...60, step: 5, onEditingChanged: {
                editing in
                edit = editing
            })
        }
        
    }
}

//#Preview {
//    EdycjaWydarzenia(wydarzenie: )
//}
