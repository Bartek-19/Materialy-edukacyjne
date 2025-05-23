//
//  Item+CoreDataProperties.swift
//  PAMiOS-25-05-08
//
//  Created by student on 08/05/2025.
//
//

import Foundation
import CoreData


extension Item {

    @nonobjc public class func fetchRequest() -> NSFetchRequest<Item> {
        return NSFetchRequest<Item>(entityName: "Item")
    }

    @NSManaged public var timestamp: Date?
    @NSManaged public var toKwiatek: NSSet?

}

// MARK: Generated accessors for toKwiatek
extension Item {

    @objc(addToKwiatekObject:)
    @NSManaged public func addToToKwiatek(_ value: Kwiatek)

    @objc(removeToKwiatekObject:)
    @NSManaged public func removeFromToKwiatek(_ value: Kwiatek)

    @objc(addToKwiatek:)
    @NSManaged public func addToToKwiatek(_ values: NSSet)

    @objc(removeToKwiatek:)
    @NSManaged public func removeFromToKwiatek(_ values: NSSet)

}

extension Item : Identifiable {

}
