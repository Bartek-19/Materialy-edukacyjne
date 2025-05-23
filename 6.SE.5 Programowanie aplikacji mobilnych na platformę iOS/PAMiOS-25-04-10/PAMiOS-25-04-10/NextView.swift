//
//  NextView.swift
//  PAMiOS-25-04-10
//
//  Created by student on 10/04/2025.
//

import SwiftUI

struct NextView: View {
    @Binding var zamowienie: kawa
    var body: some View {
        NavigationView {
            Picker("Wybierz rodzaj", selection: $zamowienie.rodzajKawy) {
                ForEach(rodzaj.allCases, id: \.self) {
                    r in
                    Text(r.rawValue)
                }
            }
            NavigationLink("Powrot", destination: ContentView())
        }
    }
}
