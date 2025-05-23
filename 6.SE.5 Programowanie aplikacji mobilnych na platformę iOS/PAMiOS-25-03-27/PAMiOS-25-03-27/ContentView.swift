//
//  ContentView.swift
//  PAMiOS-25-03-27
//
//  Created by student on 27/03/2025.
//

import SwiftUI

struct ContentView: View {
    var viewModel: MyViewModel
    @State var pictures: (animal: String?, car: String?, flower: String?)
    @Binding var category: MyViewModel.ImageCategory
    var body: some View {
        NavigationStack {
            VStack {
                if(pictures.animal != nil) {
                    Image(pictures.animal!)
                        .resizable()
                        .scaledToFit()
                }
                
                if(pictures.car != nil) {
                    Image(pictures.car!)
                        .resizable()
                        .scaledToFit()
                }
                
                if(pictures.flower != nil) {
                    Image(pictures.flower!)
                        .resizable()
                        .scaledToFit()
                }
                
                NavigationLink("Wylosuj obrazek", destination: NextView(viewModel: viewModel, pictures: $pictures, category: category))
                
                
            }
            .padding()
            .navigationTitle("Wybrane elementy")
        }
    }
}

//#Preview {
//    ContentView()
//}
