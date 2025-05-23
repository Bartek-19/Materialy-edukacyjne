//
//  Dog+CoreDataProperties.swift
//  PAMiOS-25-05-08-2
//
//  Created by student on 08/05/2025.
//
//

import Foundation
import CoreData


extension Dog {

    @nonobjc public class func fetchRequest() -> NSFetchRequest<Dog> {
        return NSFetchRequest<Dog>(entityName: "Dog")
    }

    @NSManaged public var name: String?
    @NSManaged public var birthYear: Int32
    @NSManaged public var attribute: NSObject?
    @NSManaged public var toBreed: Breed?

}

extension Dog : Identifiable {

}
