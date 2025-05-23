//
//  PanelView.swift
//  PAMiOS_25-03-13
//
//  Created by student on 13/03/2025.
//

import SwiftUI

struct PanelView: View {
    @Binding var count: Int
    
    var body: some View {
        VStack {
            Button(action: {count+=1}) {
                Text("Wcisnij")
                    .font(.title)
                    .fontWeight(.bold)
                    .padding(5)
                    .background(Color.gray)
                    .foregroundStyle(Color.green)
                    .cornerRadius(15)
            }
        }
    }
}

#Preview {
    PanelView(count: .constant(0))
}
