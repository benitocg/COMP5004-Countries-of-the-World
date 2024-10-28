#include "add.h" //
#include <iostream>
#include <fstream> // files
#include <cstring>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cmath>


#include "degreesToRadians.h"
#include <sstream> // storing in memory

using namespace std;

class Cities {
private:
    char name[15];
    int population;
    char country[15];

public:
    void addingCities();
    void findingCities();
    void mainMenu();
}c;

void Cities::findingCities() {
    ifstream cityFile("cities.dat", ios::binary);
    char sname[15];
    cout << "Finding cities\n";
    cout << "Enter the name of the city: ";
    cin >> sname;

    while (cityFile.read((char *) this, sizeof(Cities))) {
        if (strcmp(name, sname) == 0) {
            cout << "City: " << name << ", Population: " << population << ", Country: " << country << endl;
        }
    }
}

void savingCities() {
    cout << "Saving cities";
}

void Cities::addingCities() {
    //output data to cities.dat, ios::app appends to end of file instead of overwriting.
    //ios::binary opens file in binary mode, data is treated as raw bytes


    ofstream cityFile("cities.dat", ios::binary | ios::app);
    cout << "Adding cities";
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter population: ";
    cin >> population;
    cout << "Enter country: ";
    cin >> country;

    // .write writes data directly to file. (char*)this gets current object to char* pointer.
    // sizeof(Cities)
    cityFile.write((char *) this, sizeof(Cities));
    cout << "City saved...";
}

void modifyCities() {
    cout << "Modify cities";
}

void deleteCities() {
    cout << "Deleting cities";
}


void distance() {
    cout << "Distance between two cities...\n";

    // coordinates for two cities
    double lat1 = 51.7522; // oxford lat/long
    double long1 = -1.256;
    double lat2 = 51.5085; // london lat/long
    double long2 = -0.1257;

    // converts lat/long degrees to radians
    lat1 = degreesToRadians(lat1);
    long1 = degreesToRadians(long1);
    lat2 = degreesToRadians(lat2);
    long2 = degreesToRadians(long2);

    // angular distance for d
    double d = acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1 - long2));

    // d is in radians. Converting it to degrees
    d = d * 180 / M_PI;

    // linear distance
    double distance = (6371.0 * M_PI * d) / 180;

    cout << "Distance between Oxford and London is: " << distance << " km";
}


void Cities::mainMenu() {
    int option;

    while (true) {
        cout << "------------------------";
        cout << "\nCities of the World";
        cout << "\n------------------------";
        cout << "\n1. Finding Cities";
        cout << "\n2. Adding Cities";
        cout << "\n3. Add (testing)";
        cout << "\n4. Exit";
        cout << "\n------------------------";
        cout << "\nInput your option: ";
        cin >> option;
        switch (option) {
            case 1:
                findingCities();
                break;
            case 2:
                addingCities();
                break;
            case 3:
                cout << "the sum of 3 and 4 is " << add(3, 4) << '\n';
                distance();
                break;
            case 4:
                cout << "Exiting...";
                break;
            default:
                cout << "Please choose an option available...";
        }
    }
}

int main() {
    c.mainMenu();
}

