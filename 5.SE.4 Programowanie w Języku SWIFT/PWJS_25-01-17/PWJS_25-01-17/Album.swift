//
//  Album.swift
//  PWJS_25-01-17
//
//  Created by student on 17/01/2025.
//

class Album : Wykonawca {
    var rokWydania: UInt16
    var tablicaUtworow: [Utwor] = []
    var tytul: String
    
    override init() {
        self.rokWydania = 2018
        self.tytul = "Cafe Belga"
        self.tablicaUtworow.append(Utwor(tytul: "Cafe Belga", czasTrwania: 250))
        self.tablicaUtworow.append(Utwor())
        self.tablicaUtworow.append(Utwor(tytul: "Wszystko na niby", czasTrwania: 258))
        self.tablicaUtworow.append(Utwor(tytul: "Rezyseria: Kubrick", czasTrwania: 212))
        self.tablicaUtworow.append(Utwor(tytul: "2031", czasTrwania: 300))
        self.tablicaUtworow.append(Utwor(tytul: "Fiji", czasTrwania: 243))
        self.tablicaUtworow.append(Utwor(tytul: "Abonent jest czasowo niedostepny", czasTrwania: 274))
        self.tablicaUtworow.append(Utwor(tytul: "Motorola", czasTrwania: 192))
        self.tablicaUtworow.append(Utwor(tytul: "Modigliani", czasTrwania: 230))
        self.tablicaUtworow.append(Utwor(tytul: "Adieu", czasTrwania: 287))
        self.tablicaUtworow.append(Utwor(tytul: "4 AM in Girona", czasTrwania: 189))
        super.init()
    }
    
    override convenience init(imie: String, nazwisko: String) {
        self.init()
    }
    
    init(imie: String, nazwisko: String, rokWydania: UInt16, tablicaUtworow: [Utwor], tytul: String) {
        self.rokWydania = rokWydania
        self.tytul = tytul
        self.tablicaUtworow = tablicaUtworow
        super.init(imie: imie, nazwisko: nazwisko)
    }
    
    override func info() {
        super.info()
        print(", Album \"\(self.tytul)\". Utwory:")
        for u in tablicaUtworow {
            u.info()
            print(",")
        }
    }
    
    func getUtwory() -> [Utwor] {
        return tablicaUtworow
    }
}
