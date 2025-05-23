//
//  SwiftUIView2.swift
//  PAMiOS_25-05-04
//
//  Created by student on 06/03/2025.
//

import SwiftUI

struct SwiftUIView2: View {
    var body: some View {
        ZStack {
            Image("pies")
                .frame(width: 300, height: 300, alignment: .center)
            Rectangle()
                .fill(.white)
                .frame(width:300, height: 50, alignment: .bottom)
                .border(Color.blue)
            HStack {
                VStack {
                    Text("Pies Corgi")
                        .foregroundStyle(.green)
                        .fontWeight(.bold)
                    Text("Zrodlo: alizoo.eu")
                        .foregroundStyle(.green)
                        .fontWeight(.light)
                }
            }
        }
                
    }
}

#Preview {
    SwiftUIView2()
}
