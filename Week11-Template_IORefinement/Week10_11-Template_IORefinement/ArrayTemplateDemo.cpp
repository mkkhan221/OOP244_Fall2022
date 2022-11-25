#include <iostream>
#include <iomanip>
#include "Array.h"
#include "Room.h"
using namespace std;
using namespace sdds;


template <typename type>
void prnArray(const Array<type>& d) {
    for (unsigned i = 0; i < d.size(); i++) {
        if (i != 0) cout << ", ";
        cout << d[i];
    }
    cout << endl;
}

int main() {
    Array<double> D(5);
    Array<int> I(10);
    for (unsigned i = 0; i < 10; i++) {
        D[i] = i * 12.345;
    }
    for (unsigned i = 0; i < 20; i++) {
        I[i] = i * 12;
    }
    prnArray(D);
    prnArray(I);
    cout << I.search(12) << endl;

    // array rooms of type Room created with 5 elements. each will call Room default constructor
    Array<Room> rooms[5];
    
  //  rooms[0]
    Room& r1 = rooms[0].getData(0);

    r1.display();

    return 0;
}

