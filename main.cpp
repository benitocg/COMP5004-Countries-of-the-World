#include "add.h" //
#include <iostream>
#include <fstream> // files
#include <sstream> // storing in memory

using namespace std;

void findingCities() {
    cout << "Finding cities";
}

void savingCities() {
    cout << "Saving cities";
}

void addingCities() {
    cout << "Adding cities";
}

void modifyCities() {
    cout << "Modify cities";
}

void deleteCities() {
    cout << "Deleting cities";
}

void distance() {
    cout << "Distance between two cities...";
}

int main() {

    cout<<"Cities of the World";
    cout<<"\n1. Finding Cities";
    cout<<"\n2. Saving Cities";
    cout<<"\n3. Add (testing)";
    cout<<"\n4. Exit";

    int option;
    cout << "\n input your option: ";
    cin >> option;

    switch(option) {
        case 1:
            findingCities();
            return 0;
        case 2:
            cout << "Saving cities";
        case 3:
            cout << "the sum of 3 and 4 is " << add(3,4) <<  '\n' ;
        case 4:
            cout << "Exiting...";
            break;
        default:
            break;
    }
}