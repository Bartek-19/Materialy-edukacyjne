//
//  PAMiOS_25_05_08_2App.swift
//  PAMiOS-25-05-08-2
//
//  Created by student on 08/05/2025.
//

import SwiftUI

@main
struct PAMiOS_25_05_08_2App: App {
    let persistenceController = PersistenceController.shared

    var body: some Scene {
        WindowGroup {
            ContentView()
                .environment(\.managedObjectContext, persistenceController.container.viewContext)
        }
    }
}
