#include "add.h" //
#include <iostream>
#include <fstream> // files
#include <cmath>
#include <unordered_map>

#include "degreesToRadians.h"
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



struct Cities{
    string Name;
    int Population;
};


void hashmap() {
    // Create an unordered_map
    unordered_map<string, Cities> cityMap;

    // Insert key-value pairs into the unordered_map
    cityMap["Oxford"] = Cities {"Oxford", 10000};
    cityMap["London"] = Cities {"London", 150000};
    cityMap["Lisbon"] = Cities {"Lisbon", 125000};


    Cities& oxfordData = cityMap["Oxford"];
    cout << oxfordData.Population;

}



int main() {

    cout<<"Cities of the World";
    cout<<"\n1. Finding Cities";
    cout<<"\n2. Saving Cities";
    cout<<"\n3. Add (testing)";
    cout<<"\n4. Exit";
    cout<<"\n5. map";

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
            distance();
            break;
        case 4:
            cout << "Exiting...";
            break;
        case 5:
            hashmap();
            break;
        default:
            break;
    }
}