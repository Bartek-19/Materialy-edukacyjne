//
//  PAMiOS_25_05_08App.swift
//  PAMiOS-25-05-08
//
//  Created by student on 08/05/2025.
//

import SwiftUI

@main
struct PAMiOS_25_05_08App: App {
    let persistenceController = PersistenceController.shared

    var body: some Scene {
        WindowGroup {
            ContentView()
                .environment(\.managedObjectContext, persistenceController.container.viewContext)
        }
    }
}
