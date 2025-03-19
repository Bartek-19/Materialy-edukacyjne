//
//  tStudent.swift
//  PWJS_25-01-10
//
//  Created by student on 10/01/2025.
//

enum Kierunki {
    case inf
    case ekon
    case fir
    case zarz
    case mat
    case fiz
    case air
    case lot
    case mibm
}

enum Oceny {
    case ndst
    case dst
    case dstp
    case db
    case dbp
    case bdb
}

class Studnet : Osoba {
    var numerIndeksu: UInt16
    var kierunek: Kierunki
    var rokStudiow: UInt8
    var oceny: [Oceny] = Array(repeating: .ndst, count: 5)
    
    override init() {
        numerIndeksu = 0
        kierunek = .inf
        rokStudiow = 1
        oceny = [.dst, .dbp, .dstp, .dstp, .db]
        super.init()
    }
}
