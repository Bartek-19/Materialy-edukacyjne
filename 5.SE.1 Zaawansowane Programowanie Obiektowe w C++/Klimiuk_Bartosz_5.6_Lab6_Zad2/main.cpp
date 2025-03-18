#include <iostream>
#include "Contacts.h"

int main() {
    Contacts contacts;

    // Dodanie kilku kontakt�w
    contacts.add_contact({"Jan", "Kowalski", 25, "123456789", "Warszawska"});
    contacts.add_contact({"Anna", "Nowak", 34, "987654321", "Krakowska"});
    contacts.add_contact({"Piotr", "Kowalski", 17, "111111111", "Warszawska"});

    // Wy�wietlenie wszystkich kontakt�w
    cout << "Lista kontakt�w:" << endl;
    contacts.show_contacts();

    // Wyszukanie po ulicy
    cout << "\nOsoby mieszkaj�ce na ulicy Warszawska:" << endl;
    contacts.find_by_street("Warszawska");

    // Liczba pe�noletnich
    contacts.count_adults();

    return 0;
}
