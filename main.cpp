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
    char country[15];
    int population;
    int yearRecorded;
    char mayorName[50];
    char mayorAddress[100];
    char history[500];
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
    bool found = false;
    cout << "Finding cities\n";
    cout << "Enter the name of the city: ";
    cin >> searchName;

    while (cityFile.read((char *) this, sizeof(Cities))) {
        if (strcmp(name, searchName) == 0) {
            cout << "----------------------------\n";
            cout << "City: " << name << "\n";
            cout << "Country: " << country << "\n";
            cout << "Population: " << population << " (Recorded in: " << yearRecorded << ")\n";
            cout << "Mayor: " << mayorName << "\n";
            cout << "Mayor's Address: " << mayorAddress << "\n";
            cout << "History: " << history << "\n";
            cout << "Latitude: " << latitude << ", Longitude: " << longitude << "\n";
        }
    }

    if (!found) {
        cout << "No city found...\n";
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

    char tempName[15], tempMayorName[50], tempMayorAddress[100], tempHistory[500], tempCountry[15];
    int tempPopulation, tempYearRecorded;
    double tempLatitude, tempLongitude;


    cout << "Enter the name of the city: ";
    cin >> tempName;
    cout << "Enter the population: ";
    cin >> tempPopulation;
    cout << "Enter the year the population was recorded: ";
    cin >> tempYearRecorded;
    cout << "Enter the country: ";
    cin >> tempCountry;
    cout << "Enter the name of the mayor: ";
    cin.ignore();
    cin.getline(tempMayorName, 50);
    cout << "Enter the address of the mayor: ";
    cin.getline(tempMayorAddress, 100);
    cout << "Enter a short history of the city: ";
    cin.getline(tempHistory, 500);
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
        strcpy(country, tempCountry);
        strcpy(name, tempName);
        population = tempPopulation;
        yearRecorded = tempYearRecorded;
        strcpy(mayorName, tempMayorName);
        strcpy(mayorAddress, tempMayorAddress);
        strcpy(history, tempHistory);
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

    bool found = false;

    while (cityFile.read((char *)&tempCity, sizeof(Cities))) {
        if (strcmp(tempCity.name, searchName) == 0) {
            cityFilePos = cityFile.tellg() - streampos(sizeof(Cities));
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No city found...\n";
        return;
    }

     // Display current details of the city
    cout << "\n Details of " << tempCity.name << "\n";
    cout << "Population: " << tempCity.population << " (Recorded in: " << tempCity.yearRecorded << ")\n";
    cout << "Country: " << tempCity.country << "\n";
    cout << "Mayor: " << tempCity.mayorName << "\n";
    cout << "Mayor's Address: " << tempCity.mayorAddress << "\n";
    cout << "History: " << tempCity.history << "\n";
    cout << "Latitude: " << tempCity.latitude << "\n";
    cout << "Longitude: " << tempCity.longitude << "\n";

    // Update fields
    cout << "Enter new Population (or -1 to keep current): \n";
    int newPopulation;
    cin >> newPopulation;
    if (newPopulation != -1) tempCity.population = newPopulation;

    cout << "Enter new Year Population Recorded (or -1 to keep current): \n";
    int newYearRecorded;
    cin >> newYearRecorded;
    if (newYearRecorded != -1) tempCity.yearRecorded = newYearRecorded;

    cout << "Enter new Country (or press Enter to keep current): \n";
    cin.ignore(); // Clear newline left by previous input
    char newCountry[15];
    cin.getline(newCountry, 15);
    if (strlen(newCountry) > 0) strcpy(tempCity.country, newCountry);

    cout << "Enter new Mayor's Name (or press Enter to keep current): \n";
    char newMayorName[50];
    cin.getline(newMayorName, 50);
    if (strlen(newMayorName) > 0) strcpy(tempCity.mayorName, newMayorName);

    cout << "Enter new Mayor's Address (or press Enter to keep current): \n";
    char newMayorAddress[100];
    cin.getline(newMayorAddress, 100);
    if (strlen(newMayorAddress) > 0) strcpy(tempCity.mayorAddress, newMayorAddress);

    cout << "Enter new History (or press Enter to keep current): \n";
    char newHistory[500];
    cin.getline(newHistory, 500);
    if (strlen(newHistory) > 0) strcpy(tempCity.history, newHistory);

    cout << "Enter new Latitude: \n";
    double newLatitude;
    cin >> newLatitude;

    cout << "Enter new Longitude: \n";
    double newLongitude;
    cin >> newLongitude;

    // Write updated data back to file
    cityFile.seekp(cityFilePos);
    cityFile.write((char*)&tempCity, sizeof(Cities));

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

