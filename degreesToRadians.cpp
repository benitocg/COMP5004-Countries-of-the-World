//
// Created by benito on 11/10/2024.
//

#include "degreesToRadians.h"
#include <cmath>
#include <iostream>
#include <ostream>
using namespace std;


double degreesToRadians(double degrees) {
     double radian = degrees * M_PI/180;

     cout << "Degrees to radians: " << degrees << " to " << radian << "\n";
     return radian;
}
