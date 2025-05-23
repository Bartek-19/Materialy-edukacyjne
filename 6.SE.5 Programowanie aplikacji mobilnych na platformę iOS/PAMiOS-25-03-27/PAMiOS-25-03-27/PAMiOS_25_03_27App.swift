//
//  PAMiOS_25_03_27App.swift
//  PAMiOS-25-03-27
//
//  Created by student on 27/03/2025.
//

import SwiftUI

@main
struct PAMiOS_25_03_27App: App {
    @StateObject var viewModel = MyViewModel()
    var body: some Scene {
        WindowGroup {
            ContentView(viewModel: viewModel)
        }
    }
}
