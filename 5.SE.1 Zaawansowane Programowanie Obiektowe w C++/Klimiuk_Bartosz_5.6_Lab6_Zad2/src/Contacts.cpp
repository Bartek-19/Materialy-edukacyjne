#include "Contacts.h"

void Contacts::add_contact(Contact contact) {
    auto& phone_index = contacts.get<2>();
    if (phone_index.find(contact.numerTelefonu) == phone_index.end()) {
        contacts.insert(contact);
    } else {
        cout << "Kontakt o numerze telefonu " << contact.numerTelefonu << " już istnieje." << endl;
    }
}

void Contacts::remove_contact(string phone) {
    auto& phone_index = contacts.get<2>();
    auto it = phone_index.find(phone);

    if (it != phone_index.end()) {
        phone_index.erase(it);
    } else {
        cout << "Nie znaleziono kontaktu z numerem telefonu " << phone << endl;
    }
}

void Contacts::find_by_street(string street) const {
    auto& street_index = contacts.get<0>();
    auto range = street_index.equal_range(street);

    if (range.first == range.second) {
        cout << "Brak osób mieszkających na ulicy: " << street << endl;
    } else {
        for (auto it = range.first; it != range.second; ++it) {
            it->show();
        }
    }
}

void Contacts::find_by_age_range(int min_age, int max_age) const {
    auto& age_index = contacts.get<1>();
    bool found = false;

    for (auto it = age_index.begin(); it != age_index.end(); ++it) {
        if (it->wiek >= min_age && it->wiek <= max_age) {
            it->show();
            found = true;
        }
    }

    if (!found) {
        cout << "Brak osób w podanym przedziale wiekowym." << endl;
    }
}

void Contacts::find_by_phone(string phone) const {
    auto& phone_index = contacts.get<2>();
    auto it = phone_index.find(phone);

    if (it != phone_index.end()) {
        it->show();
    } else {
        cout << "Nie znaleziono kontaktu z numerem telefonu " << phone << endl;
    }
}

void Contacts::change_street(string old_street, string new_street) {
    auto& street_index = contacts.get<0>();
    auto range = street_index.equal_range(old_street);

    if (range.first == range.second) {
        cout << "Nie znaleziono osób mieszkających na ulicy " << old_street << endl;
    } else {
        for (auto it = range.first; it != range.second; ++it) {
            street_index.modify(it, [&](Contact& contact) {
                contact.ulica = new_street;
            });
        }
        cout << "Zmieniono nazwę ulicy " << old_street << " na " << new_street << endl;
    }
}

void Contacts::count_adults() const {
    int count = 0;
    for (auto& contact : contacts) {
        if (contact.wiek >= 18) {
            count++;
        }
    }
    cout << "Liczba osób pełnoletnich: " << count << endl;
}

void Contacts::count_unique_surnames() const {
    set<string> unique_surnames;
    for (auto& contact : contacts) {
        unique_surnames.insert(contact.nazwisko);
    }
    cout << "Liczba unikalnych nazwisk: " << unique_surnames.size() << endl;
}

void Contacts::show_contacts() const {
    for (auto& contact : contacts) {
        contact.show();
    }
}
