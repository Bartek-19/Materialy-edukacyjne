//
//  ContentView.swift
//  PAMiOS-25-05-08-2
//
//  Created by student on 08/05/2025.
//

import SwiftUI
import CoreData

struct ContentView: View {
    @Environment(\.managedObjectContext) private var viewContext

    @FetchRequest(
        sortDescriptors: [NSSortDescriptor(keyPath: \Dog.name, ascending: true)],
        animation: .default)
    private var dogs: FetchedResults<Dog>
    
    @FetchRequest(
        sortDescriptors: [NSSortDescriptor(keyPath: \Breed.name, ascending: true)],
        animation: .default)
    private var breeds: FetchedResults<Breed>
    
    @State private var selectedBreed: Breed?
    @State var dogName: String = ""
    @State var dogYear: String = ""

    var body: some View {
        NavigationView {
            List {
                ForEach(breeds) { breed in
                    Section(header: Text("\(breed.name!)")) {
                        ForEach(breed.dogArray) { dog in
                            Text("\(dog.name!) - urodzony w \(dog.birthYear)")
                        }
                        .onDelete(perform: deleteDog)
                    }
                }
            }
            .toolbar {
                ToolbarItem(placement: .navigationBarTrailing) {
                    EditButton()
                }
                ToolbarItem {
                    Button(action: addDog) {
                        Label("Add Item", systemImage: "plus")
                    }
                }
            }
            Text("Select an item")
        }
    }

    private func addDog() {
        withAnimation {
            let newDog = Dog(context: viewContext)
            newDog.name = newDogName
            let intYear = Int32(newDogAge)
            newDog.birthYear = intYear!
            newDog.toBreed = selectedBreed

            do {
                try viewContext.save()
            } catch {
                // Replace this implementation with code to handle the error appropriately.
                // fatalError() causes the application to generate a crash log and terminate. You should not use this function in a shipping application, although it may be useful during development.
                let nsError = error as NSError
                fatalError("Unresolved error \(nsError), \(nsError.userInfo)")
            }
        }
    }

    private func deleteDog(offsets: IndexSet) {
        withAnimation {
            offsets.map { dogs[$0] }.forEach(viewContext.delete)

            do {
                try viewContext.save()
            } catch {
                // Replace this implementation with code to handle the error appropriately.
                // fatalError() causes the application to generate a crash log and terminate. You should not use this function in a shipping application, although it may be useful during development.
                let nsError = error as NSError
                fatalError("Unresolved error \(nsError), \(nsError.userInfo)")
            }
        }
    }
}

private let itemFormatter: DateFormatter = {
    let formatter = DateFormatter()
    formatter.dateStyle = .short
    formatter.timeStyle = .medium
    return formatter
}()

#Preview {
    ContentView().environment(\.managedObjectContext, PersistenceController.preview.container.viewContext)
}
