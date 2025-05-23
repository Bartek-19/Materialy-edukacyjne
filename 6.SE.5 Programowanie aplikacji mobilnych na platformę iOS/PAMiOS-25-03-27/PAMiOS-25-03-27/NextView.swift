//
//  NextView.swift
//  PAMiOS-25-03-27
//
//  Created by student on 27/03/2025.
//

import SwiftUI

struct NextView: View {
    var viewModel: MyViewModel
    @Binding var pictures: (animal: String?, car: String?, flower: String?)
    @State var category: MyViewModel.ImageCategory
    var categoryRange: [(MyViewModel.ImageCategory, Int)] 
    var body: some View {
        NavigationStack {
            VStack {
                
                Picker("Wybierz kategorie", selection: $category) {
                    ForEach(MyViewModel.ImageCategory.allCases, id: \.self) {
                        cat in
                        Text(cat.rawValue)
                    }
                }
                //categoryRange = viewModel.getImageNumbersForCategories()
                
                Button("Wylosuj obraz", action: <#T##() -> Void#>)
                
                NavigationLink("Powrot", destination: ContentView(viewModel: viewModel, category: $category))
            }
            .navigationTitle("Wybrane elementy")
        }
    }
    
    
}

//#Preview {
//    NextView()
//}
