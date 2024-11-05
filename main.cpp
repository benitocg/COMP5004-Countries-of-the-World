#include <iostream>
#include <fstream> // files
#include <cstring>
#include <cstdio>
#include <cmath>


#include "degreesToRadians.h"


using namespace std;

class Cities {
private:
    char name[15];
    int population;
    char country[15];
    double latitude;
    double longitude;

public:
    void addingCities();
    void findingCities();
    void mainMenu();
    void distance();
    void deleteCities();
    void modifyCities();
}c;

void Cities::findingCities() {
    ifstream cityFile("cities.dat", ios::binary);
    char searchName[15];
    cout << "Finding cities\n";
    cout << "Enter the name of the city: ";
    cin >> searchName;

    while (cityFile.read((char *) this, sizeof(Cities))) {
        if (strcmp(name, searchName) == 0) {
            cout << "----------------------------\n";
            cout << "City: " << name << ", Population: " << population << ", Country: " << country << "\n";
            cout << "Latitude: " << latitude << ", Longitude: " << longitude << "\n";
        }
    }
}

void savingCities() {
    cout << "Saving cities";
}

void Cities::addingCities() {
    //output data to cities.dat, ios::app appends to end of file instead of overwriting.
    //ios::binary opens file in binary mode, data is treated as raw bytes

    ifstream tempCity("cities.dat", ios::binary);
    ofstream cityFile("cities.dat", ios::binary | ios::app);

    char tempName[15];
    int tempPopulation;
    char tempCountry[15];
    double tempLatitude, tempLongitude;


    cout << "Enter the name of the city: ";
    cin >> tempName;
    cout << "Enter the population: ";
    cin >> tempPopulation;
    cout << "Enter the country: ";
    cin >> tempCountry;
    cout << "Enter the latitude: ";
    cin >> tempLatitude;
    cout << "Enter the longitude: ";
    cin >> tempLongitude;


    bool duplicate = false;
    while (tempCity.read((char*) this, sizeof(Cities))) {
        if (strcmp(name, tempName) == 0 && strcmp(country, tempCountry) == 0) {
            duplicate = true;
            break;
        }
    }

    if (!duplicate) {
        strcpy(name, tempName);
        population = tempPopulation;
        strcpy(country, tempCountry);
        latitude = tempLatitude;
        longitude = tempLongitude;

        // .write writes data directly to file. (char*)this gets current object to char* pointer.
        // sizeof(Cities)
        cityFile.write((char *) this, sizeof(Cities));
        cout << "City saved...\n";
    } else {
        cout << "City already exists\n";
    }
}

void Cities::modifyCities() {
    cout << "Modify cities\n";
    fstream cityFile("cities.dat", ios::binary | ios::in | ios::out);

    char searchName[15];

    cout << "Enter the name of the city: \n";
    cin >> searchName;

    Cities tempCity;
    streampos cityFilePos;

    while (cityFile.read((char *)&tempCity, sizeof(Cities))) {
        if (strcmp(tempCity.name, searchName) == 0) {
            cityFilePos = cityFile.tellg() - streampos(sizeof(Cities));
            break;
        }
    }

    cout << "\n Details of " << tempCity.name << "\n";
    cout << "Population: " << tempCity.population << "\n";
    cout << "Country: " << tempCity.country << "\n";
    cout << "Latitude: " << tempCity.latitude << "\n";
    cout << "Longitude: " << tempCity.longitude << "\n";

    cout << "Enter new Population: \n";
    cin >> tempCity.population;
    cout << "Enter new Country: \n";
    cin >> tempCity.country;
    cout << "Enter new Latitude: \n";
    cin >> tempCity.latitude;
    cout << "Enter new Longitude: \n";
    cin >> tempCity.longitude;

    cityFile.seekp(cityFilePos);
    cityFile.write((char *) &tempCity, sizeof(Cities));

    cout << "City saved...\n";
}

void Cities::deleteCities() {
    cout << "Deleting cities\n";
    ifstream cityFile("cities.dat", ios::binary);
    ofstream tempCity("temp.dat", ios::binary);

    char searchName[15], searchCountry[15];
    cout << "Enter the name of the city: \n";
    cin >> searchName;
    cout << "Enter the name of the country: \n";
    cin >> searchCountry;

    while (cityFile.read((char*) this, sizeof(Cities))) {
        if (strcmp(name, searchName) == 0 && strcmp(country, searchCountry) == 0){
        } else {
            tempCity.write((char * )this, sizeof(Cities));
        }
    }

    cityFile.close();
    tempCity.close();

    remove("cities.dat");
    rename("temp.dat", "cities.dat");

    cout << "City deleted...\n";

}


void Cities::distance() {

    ifstream cityFile("cities.dat", ios::binary);
    char cityName1[15], cityName2[15];
    Cities city1,city2;
    cout << "Distance between two cities...\n";
    cout << "Enter the name of the first city: ";
    cin >> cityName1;
    cout << "Enter the name of the second city: ";
    cin >> cityName2;

    while (cityFile.read((char *)&city1, sizeof(Cities))) {
        if (strcmp(city1.name, cityName1) == 0) {
            break;
        }
    }

    cityFile.seekg(0, ios::beg);

    while (cityFile.read((char *)&city2, sizeof(Cities))) {
        if (strcmp(city2.name, cityName2) == 0) {
            break;
        }
    }

    // coordinates for two cities
    double lat1 = city1.latitude; // oxford lat/long
    double long1 = city1.longitude;
    double lat2 = city2.latitude; // london lat/long
    double long2 = city2.longitude;

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

    cout << "Distance between " << city1.name <<  " and " << city2.name <<  " is: " << distance << " km\n";
}


void Cities::mainMenu() {
    int option;

    while (true) {
        cout << "------------------------";
        cout << "\nCities of the World";
        cout << "\n------------------------";
        cout << "\n1. Finding Cities";
        cout << "\n2. Adding Cities";
        cout << "\n3. Distance";
        cout << "\n4. Modify Cities" ;
        cout << "\n5. Delete Cities";
        cout << "\n6. Exit";
        cout << "\n------------------------";
        cout << "\nInput your option";
        if (!(cin >> option)) {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        switch (option) {
            case 1:
                findingCities();
                break;
            case 2:
                addingCities();
                break;
            case 3:
                distance();
                break;
            case 4:
                modifyCities();
                break;
            case 5:
                deleteCities();
                break;
            case 6:
                cout << "Exiting...";
                return;
            default:
                cout << "\n------------------------";
                cout << "Please choose an option available...\n";

        }
    }
}

int main() {
    c.mainMenu();
}

