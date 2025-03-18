#include <iostream>
#include "Contacts.h"

int main() {
    Contacts contacts;

    // Dodanie kilku kontaktów
    contacts.add_contact({"Jan", "Kowalski", 25, "123456789", "Warszawska"});
    contacts.add_contact({"Anna", "Nowak", 34, "987654321", "Krakowska"});
    contacts.add_contact({"Piotr", "Kowalski", 17, "111111111", "Warszawska"});

    // Wyœwietlenie wszystkich kontaktów
    cout << "Lista kontaktów:" << endl;
    contacts.show_contacts();

    // Wyszukanie po ulicy
    cout << "\nOsoby mieszkaj¹ce na ulicy Warszawska:" << endl;
    contacts.find_by_street("Warszawska");

    // Liczba pe³noletnich
    contacts.count_adults();

    return 0;
}
