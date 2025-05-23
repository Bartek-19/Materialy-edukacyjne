//
//  WidokWydarzenia.swift
//  PAMiOS-25-04-24
//
//  Created by student on 24/04/2025.
//

import SwiftUI

struct WidokWydarzenia: View {
    @Binding var wydarzenie: Wydarzenie
    var body: some View {
        HStack {
            Image(systemName: "globe")
                .imageScale(.large)
                .foregroundStyle(.tint)
            Text(wydarzenie.nazwaWydarzenia)
                .multilineTextAlignment(.center)
            Text("Czas trwania: \(String(format: "%.0f", wydarzenie.czasTrwana)) min.")
                .multilineTextAlignment(.trailing)
                .font(.caption)
        }
        .presentationCornerRadius(5.0)
        .padding()
        .contentMargins(2.0)
    }
}

//#Preview {
//    WidokWydarzenia(wydarzenie: $wydarzenie)
//}
