//Implementation file GearShift.cpp This is the IMPLEMENTATION of the class GearShift.
//The interface for the class GearShift is in the header file GearShift.h.
//Author: Bridget O'Daniel (odanielbri@gmail.com)

#include <iostream>
#include "GearShift.h"

using namespace std;

const int GearShift::valid_gears_[7] = { -1, 0, 1, 2, 3, 4, 5};
//Assignment of class variable containing the valid range of gears (gear value = index - 1)

bool operator ==(const GearShift& gearShift1, const GearShift& gearShift2)
//Returns True if the current gears of gearShift1 and gearShift2 are the same.
//precondition: Both objects must have a current gear
{
    return (gearShift1.gear_ == gearShift2.gear_);
}

GearShift::GearShift( int current_gear ) {
//Initializes the GearShift at the provided gear or 0 if none
// is provided.
//pre: current_gear is a valid gear, which is asserted here.
//post: Creates a GearShift object in the current_gear, or at
//0 if current_gear is invalid or none is provided.
    if ( check_valid_gear(current_gear) ){
        gear_ = current_gear;
    }
    else {
        gear_ = 0;
    }
}

void GearShift::shift_up() {
//precondition: GearShift is in a gear and can be shifted up
//postcondition: GearShift is shifted up 1 gear, unless it cannot
//  go any higher, in which case nothing will change.
    if (gear_ < 5) {
        gear_++;
    }
}

void GearShift::shift_down() {
//precondition: GearShift is in a gear and can be shifted down
//postcondition: GearShift is shifted down 1 gear, unless it cannot
//   go any lower, in which case nothing will change.
    if (gear_ > -1) {
        gear_--;
    }
}

ostream& operator <<(ostream& outs, const GearShift& gearShift) {
//Overloads the << operator for outputting a gearShift object.
//precondition: gearShift is an initialized gearShift object.
    if (gearShift.gear_ == -1) {
        outs << "R";
    }
    else if (gearShift.gear_ == 0) {
        outs << "P";
    }
    else {
        outs << gearShift.gear_;
    }
    return outs;
}

bool GearShift::check_valid_gear(int gear) const {
//method to check if the provided gear is valid
//postcondition: Returns true (if valid) or false (if not)
    for (int i=0; i < 7; i++) {
        if ( gear == valid_gears_[i] ) {
            return true;
            }
    }
    return false;
}
