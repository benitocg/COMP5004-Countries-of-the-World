#include "add.h" //
#include <iostream>
#include <string>

using namespace std;

int main() {

    cout<<"Cities of the World";
    cout<<"\n1. Finding Cities";
    cout<<"\n2. Saving Cities";
    cout<<"\n3. Add (testing)";
    cout<<"\n4. Exit";

    int option;
    cout << "\ninput your option:";
    cin >> option;

    switch(option) {
        case 1:
            cout << "Finding cities";
            return 0;
        case 2:
            cout << "Saving cities";
            return 0;
        case 3:
            cout << "the sum of 3 and 4 is " << add(3,4) <<  '\n' ;
            return 0;
        case 4:
            cout << "Exiting...";
            break;
        default:
            break;
    }
}