//
//  ContentView.swift
//  PAMiOS_25-03-13
//
//  Created by student on 13/03/2025.
//

import SwiftUI

struct ContentView: View {
    @State var count = 0
    var body: some View {
        VStack {
            Text("Wcisnij przycisk:")
            PanelView(count: $count)
            Text("Wcisnieto \(count) razy!")
        }
    }
    
    
}

#Preview {
    ContentView()
}
