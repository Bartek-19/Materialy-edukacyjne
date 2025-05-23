//
//  SecondView.swift
//  PAMiOS-25-04-10
//
//  Created by student on 10/04/2025.
//

import SwiftUI

struct SecondView: View {
    @Binding var zamowienie: kawa
    var body: some View {
        NavigationView {
            Picker("Wybierz smak", selection: $zamowienie.smakKawy) {
                ForEach(smak.allCases, id: \.self) {
                    s in
                    Text(s.rawValue)
                }
            }
            NavigationLink("Powrot", destination: ContentView())
        }
    }
}
