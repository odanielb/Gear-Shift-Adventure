// GearShift.h
//Header file for the class GearShift.
//Represents a gearshift as in a car
//Author: Bridget O'Daniel (odanielbri@gmail.com)

#ifndef GEARSHIFT_H //prevents inclusion of header file more than once
#define GEARSHIFT_H

using namespace std;

class GearShift {

public:

    GearShift(int current_gear = 0);
    //Initializes the GearShift at the provided gear or 0 if none
    // is provided.
    //pre: current_gear is a valid gear, which is asserted here.
    //post: Creates a GearShift object in the current_gear, or at
    //0 if current_gear is invalid or none is provided.

    int get_current_gear() const { return gear_; }
    //Precondition: GearShift is in a gear
    //Postcondition: Returns the current gear of GearShift

    void shift_up();
    //precondition: GearShift is in a gear and can be shifted up
    //postcondition: GearShift is shifted up 1 gear, unless it cannot
    //  go any higher, in which case nothing will change.

    void shift_down();
    //precondition: GearShift is in a gear and can be shifted down
    //postcondition: GearShift is shifted down 1 gear, unless it cannot
    //   go any lower, in which case nothing will change.

    friend bool operator ==(const GearShift& gearShift1, const GearShift& gearShift2);
    //Returns true if gearShift1 and gearShift2 are in the same gear
    //otherwise, returns false.


    friend ostream& operator <<(ostream& outs, const GearShift& gearShift);
    //Overloads the << operator for outputting a gearShift object.
    //precondition: gearShift is an initialized gearShift object.


private:
    int gear_;                              //current state of GearShift
    static const int valid_gears_[7];       //class variable array containing valid gears
    bool check_valid_gear(int gear) const;
    //method to check if the provided gear is valid
    //postcondition: Returns true (if valid) or false (if not)

};

#endif // GEARSHIFT_H
