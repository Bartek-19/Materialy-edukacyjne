//
//  ContentView.swift
//  PAMiOS-25-04-10
//
//  Created by student on 10/04/2025.
//

import SwiftUI

struct ContentView: View {
    //@State private var isPresented = false
    @State var zamowienie: kawa = kawa(smakKawy: smak.lemon.rawValue, rodzajKawy: rodzaj.latte.rawValue)
    var body: some View {
        NavigationStack {
            VStack {
                Text("Rodzaj kawy: \(zamowienie.rodzajKawy)")
                    .bold()
                
                Text("Smak kawy: \(zamowienie.smakKawy)")
                    .bold()
                
                NavigationLink("Edytuj smak", destination: SecondView(zamowienie: $zamowienie))
                NavigationLink("Edytuj rodzaj kawy", destination: NextView(zamowienie: $zamowienie))
                
                /*Button("Show") {
                    isPresented.toggle()
                }
                .sheet(isPresented: $isPresented, content: {SecondView()})*/
            }
            .padding()
        }
    }
}

#Preview {
    ContentView()
}
