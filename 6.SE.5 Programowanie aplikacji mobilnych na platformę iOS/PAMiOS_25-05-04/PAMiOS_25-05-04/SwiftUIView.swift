//
//  SwiftUIView.swift
//  PAMiOS_25-05-04
//
//  Created by student on 06/03/2025.
//

import SwiftUI

struct SwiftUIView: View {
    var body: some View {
        let tablica_kolorow: [Color] = [Color.red, Color.orange, Color.yellow, Color.green, Color.blue, Color.purple]
        var body: some View {
                ZStack {
                    ForEach(0..<tablica_kolorow.count, id: \.self) {
                        i in
                        Rectangle()
                            .fill(tablica_kolorow[i])
                            .frame(width: 200, height: 200)
                            .offset(x: CGFloat(i) * 10.0,y: CGFloat(i) * 10.0)
                        
                    }
                }
            .padding()
        }
    }
}

#Preview {
    SwiftUIView()
}
