//
//  ListaWydarzen.swift
//  PAMiOS-25-04-24
//
//  Created by student on 24/04/2025.
//

import SwiftUI

struct ListaWydarzen: View {
    @State var wydarzenia = [
        Wydarzenie(nazwaWydarzenia: "Wydarzenie_1", czasTrwania: 0),
        Wydarzenie(nazwaWydarzenia: "Wydarzenie_2", czasTrwania: 0),
        Wydarzenie(nazwaWydarzenia: "Wydarzenie_3", czasTrwania: 0),
        Wydarzenie(nazwaWydarzenia: "Wydarzenie_4", czasTrwania: 0)
    ]
    var body: some View {
        VStack {
            NavigationView {
                List {
                    ForEach(0..<wydarzenia.count, id: \.self) {
                        i in
                        NavigationLink(destination: EdycjaWydarzenia(wydarzenie: $wydarzenia[i])) {
                            WidokWydarzenia(wydarzenie: $wydarzenia[i])
                            
                        }
                    }
                }
            }
        }
    }
}

#Preview {
    ListaWydarzen()
}
