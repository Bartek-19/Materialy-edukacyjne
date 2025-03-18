#ifndef ZAD6_2_CONTACTS_H
#define ZAD6_2_CONTACTS_H

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include "Contact.h"
#include <iostream>
#include <set>

using namespace boost::multi_index;
using namespace std;

class Contacts {
private:
    typedef multi_index_container<Contact, indexed_by<
        hashed_non_unique<member<Contact, string, &Contact::ulica>>,
        hashed_non_unique<member<Contact, int, &Contact::wiek>>,
        hashed_unique<member<Contact, string, &Contact::numerTelefonu>>,
        hashed_non_unique<member<Contact, string, &Contact::nazwisko>>
    >> contact_multi;

    contact_multi contacts;

public:
    void add_contact(Contact contact);
    void remove_contact(string phone);
    void find_by_street(string street) const;
    void find_by_age_range(int min_age, int max_age) const;
    void find_by_phone(string phone) const;
    void change_street(string old_street, string new_street);
    void count_adults() const;
    void count_unique_surnames() const;
    void show_contacts() const;
};

#endif //ZAD6_2_CONTACTS_H
