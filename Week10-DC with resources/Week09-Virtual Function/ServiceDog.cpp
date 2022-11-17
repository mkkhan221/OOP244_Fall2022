#include "ServiceDog.h"
#include <iostream>
#include "Dog.h"
using namespace std;

namespace sdds {
    ServiceDog::ServiceDog(const char* thename, int s, char type) :Dog(thename, s), m_type(type) {

        if (sdds::debug) cout << " with Service type as" << type << endl;
    }
    ServiceDog::ServiceDog(ServiceDog& d) : Dog(d), m_type(d.m_type) {
        cout << "Service Dog copy construcotr called" << endl;
        if (sdds::debug) cout << " with Service type as" << m_type << endl;
    }
    ServiceDog& ServiceDog::operator=(ServiceDog d) {
       
        m_type = d.m_type; // note change from other version 
        (Dog&)*this = d;
        cout << "Service Dog operator in action" << endl;
        return *this;
    }

    ServiceDog::~ServiceDog() {
        if (sdds::debug) cout << "Removing " << name() << " the Service Dog" << endl;
    }
    char ServiceDog::skillset() {
        cout << "Service Dog skill" << endl;
        return m_type;
    }
}
