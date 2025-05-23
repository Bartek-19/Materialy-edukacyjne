//
//  Kwiatek+CoreDataProperties.swift
//  PAMiOS-25-05-08
//
//  Created by student on 08/05/2025.
//
//

import Foundation
import CoreData


extension Kwiatek {

    @nonobjc public class func fetchRequest() -> NSFetchRequest<Kwiatek> {
        return NSFetchRequest<Kwiatek>(entityName: "Kwiatek")
    }

    @NSManaged public var name: String?
    @NSManaged public var height: Int16
    @NSManaged public var toItem: Item?

}

extension Kwiatek : Identifiable {

}
