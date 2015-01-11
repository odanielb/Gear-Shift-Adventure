// gearshift-driver.cpp
// A driver for the GearShift class
// Author: Bridget O'Daniel (odanielbri@gmail.com)

#include <iostream>
#include <string>
#include "stdlib.h"
#include "GearShift.h"

using namespace std;

GearShift change_gears_according_to_string(GearShift stick, string shift_direction) {
//precondition: stick is an initialized GearShift object and shift_direction
// is either "up", "down", or "same".
//postcondition: stick is shifted up, down or stays the same accordingly.
    if (shift_direction.find ("up") != string::npos) {
        stick.shift_up();
    }
    else if (shift_direction.find ("down") != string::npos) {
        stick.shift_down();
    }
    return stick;
}

string get_user_choice( GearShift stick) {
//pre: stick is properly initialized.
//Gets the user to pick up, down, or same and returns a string containing the choice
    string shift_direction;

    cout << "You can now: shift up, shift down, or stay the same." << endl;
    cout << "Enter 'up', 'down' or 'same'. (Changing from " << stick << "):" << endl;
    cin >> shift_direction;

    while (shift_direction != "up" && shift_direction != "down" && shift_direction != "same") {
        cout << "\nThat is an invalid response." << endl;
        cout << "Enter 'up', 'down' or 'same'. (Changing from " << stick << "):" << endl;
        cin >> shift_direction;
    }
    cout << "\nYou've chosen " << shift_direction << ".\n" << endl;
    return shift_direction;
}

GearShift shift_gears_according_to_user(GearShift stick) {
//pre: The user has reason to change gears, stick is properly initialized
//post: User is asked how to change gears, and the gear is changed accordingly
    string shift_direction = get_user_choice(stick);
    stick = change_gears_according_to_string(stick, shift_direction);
    return stick;
}


int main()
{
    GearShift stick;
    cout << "You are going on a trip with a few friends to a lake." << endl;
    cout << "None of you know how to drive a stick shift car, but " << endl;
    cout << "you think you can handle it, even though you find the" << endl;
    cout << "clutch to be a bit intimidating. You've googled when " << endl;
    cout << "to use each gear, getting the following information:\n" <<endl;
    cout << "R = Reverse\nP = Park\n1 = 0-5 mph\n2 = 5-15/20 mph\n"
         << "3 = 20-30 mph\n4 = 30-40 mph\n5 = 40+ mph\n" <<endl;

    cout << "Your friend says that once you back down the driveway," << endl;
    cout << "you'll have to turn left and head down the street.\n" << endl;
    while (stick.get_current_gear() != -1) { //while the correct choice isn't made yet...
        stick = shift_gears_according_to_user(stick);

        if (stick.get_current_gear() == 1) { //If they choose to go forward
            cout << "You begin to go forward, up the driveway and are" << endl;
            cout << "headed straight for the garage! Stop before you hit it!" << endl;
            stick = shift_gears_according_to_user(stick);
            if (stick.get_current_gear() == 1 || stick.get_current_gear() == 2) { //If they go forward again, they lose
                cout << "You hit the garage, and now you owe lots " << endl;
                cout << "of money and can't go to the lake. :( " << endl;
                exit(1);
            }
            cout << "You stop in time to avoid hitting the garage. Phew!" << endl; //If they stop going forward
        }
        else if (stick.get_current_gear() == 0) { //If they didn't go anywhere
            cout << "You don't change gears and do not move. You should " << endl;
            cout << "probably get going!\n" << endl;
            stick = shift_gears_according_to_user(stick);
        }
    }
    //correct choice: reverse
    cout << "You back down the driveway, turning onto the road as " << endl;
    cout << "directed. The speed limit here is 30 mph, and you're " << endl;
    cout << "going in reverse! You should probably fix that."  <<endl;
    stick = shift_gears_according_to_user(stick);
    while (stick.get_current_gear() != 0) {
        cout << "Why are you still reversing?! Someone might hit " << endl;
        cout << "you at this rate. " << endl;
        stick = shift_gears_according_to_user(stick);
    }
    cout << "You shift into " << stick << ", but you need to go forward!" << endl; //Into 0
    while (stick.get_current_gear() != 1) {
        stick = shift_gears_according_to_user(stick);

        if (stick.get_current_gear() == -1) {
            cout << "Whoa! That's not the correct way down the road." << endl;
            stick = shift_gears_according_to_user(stick);
        }

        if (stick.get_current_gear() == 0) {
            cout << "There are cars approaching you, try to speed up!" << endl;
            stick = shift_gears_according_to_user(stick);
        }
    }
    cout << "You put the car into 1st, but it's not a high enough " << endl;
    cout << "gear for this road. Cars further down the road are " << endl;
    cout << "beginning to catch up to you." << endl;
    while (stick.get_current_gear() != 2) {
        stick = shift_gears_according_to_user(stick);

        if (stick.get_current_gear() < 2) {
            cout << "A higher gear means you can go faster remember?" << endl;
            cout << "The driver in the car behind you isn't paying " << endl;
            cout << "much attention to his surroundings." << endl;
            stick = shift_gears_according_to_user(stick);
            if (stick.get_current_gear() < 2) {
                cout << "The driver is too busy looking at his phone" << endl;
                cout << "and is unable to react in time to your car" << endl;
                cout << "moving slowly in front of him, so he rear ends" << endl;
                cout << "you. No one is hurt, but it looks like you" << endl;
                cout << "aren't going anywhere!" << endl;
                exit(1);
            }
        }
    }
    cout << "You are now in " << stick <<"nd gear, going down the " <<endl;
    cout << "street at a break-neck speed of ...9 miles per hour." << endl;
    while (stick.get_current_gear() != 3) {
        stick = shift_gears_according_to_user(stick);

        if (stick.get_current_gear() < 3) {
            cout << "A higher gear means you can go faster remember?" << endl;
            cout << "The driver in the car behind you isn't paying " << endl;
            cout << "much attention to his surroundings." << endl;
            stick = shift_gears_according_to_user(stick);
            if (stick.get_current_gear() < 3) {
                cout << "The driver is too busy looking at his phone" << endl;
                cout << "and is unable to react in time to your car" << endl;
                cout << "moving slowly in front of him, so he rear ends" << endl;
                cout << "you. No one is hurt, but it looks like you" << endl;
                cout << "aren't going anywhere!" << endl;
                exit(1);
            }
        }
    }
    cout << "Now you're getting somewhere, going about 30 mph. The" << endl;
    cout << "speed limit is 35 though, so you might consider going" << endl;
    cout << "a bit faster, or maybe not!" << endl;
    stick = shift_gears_according_to_user(stick);
    while (stick.get_current_gear() < 3) {
        cout << "You might want to go a bit faster; it IS illegal to be" << endl;
        cout << "too far under the speed limit, you know." << endl;
        stick = shift_gears_according_to_user(stick);
        if (stick.get_current_gear() < 3) {
            cout << "A cop sees you and comes after you, blue and red lights" << endl;
            cout << "spinning. You pull over and get a ticket for going too " << endl;
            cout << "slowly. What a bummer. Even if you still went, you'd be" << endl;
            cout << "Too upset to have a good time. You head home sadly." << endl;
            exit(1);
        }
    }
    cout << "You cruise down the road excitedly, stopping at all the necessary" << endl;
    cout << "stop signs and lights (You know to shift to P now!) Eventually " << endl;
    cout << "your friend tells you to turn onto the highway. Looks like you " << endl;
    cout << "have to change gears again." << endl;
    while (stick.get_current_gear() < 5) {
        stick = shift_gears_according_to_user(stick);
        if (stick.get_current_gear() < 5) {
            cout << "The highway requires that you go at least 60 here! You'll " << endl;
            cout << "need to shift into the highest gear you've got, 5." << endl;
            stick = shift_gears_according_to_user(stick);
            if (stick.get_current_gear() < 3) {
            cout << "You're going way too slow for this area! A cop comes up" << endl;
            cout << "behind you and gives you a ticket. Even if you still go" << endl;
            cout << "to the lake, you'd be too upset about it to have a good" << endl;
            cout << "time. You head home sadly, with a car of sad friends." << endl;
            exit(1);
            }
        }
    }
    cout << "You head down the highway, making sure to follow speeding laws." << endl;
    cout << "You couldn't go any faster if you wanted to, but you try your " << endl;
    cout << "best to avoid going slower--you want to get there soon after " << endl;
    cout << "all! It takes a while, but the lake isn't too far, and soon you" << endl;
    cout << "get to your exit, at the bottom of which is a stop light." << endl;
    while (stick.get_current_gear() == 5) {
        stick = shift_gears_according_to_user(stick);
        if (stick.get_current_gear() == 5){
            cout << "You take the exit and do not slow down at all. The light" << endl;
            cout << "changes to yellow, but you're too far away to catch it. " << endl;
            stick = shift_gears_according_to_user(stick);
            if (stick.get_current_gear() == 5) {
                cout << "You're going too fast and barrel through the stop light," << endl;
                cout << "running into another car and spinning to a stop. The car " << endl;
                cout << "is damaged and you hope everyone is alright, but you " << endl;
                cout << "really should've slowed down. No more trip for you!" << endl;
                exit(1);
            }
        }
        cout << "You begin to slow down as the light changes to yellow." << endl;
        cout << "You've got to come to a complete stop, however." << endl;
    }
    int i = 0;
    while (stick.get_current_gear() != 0) {
        stick = shift_gears_according_to_user(stick);
        cout << "You're not to P yet, hurry!" << endl;
        i++;
        if (i > 4) {
            cout << "You take too long to slow down and you go through the light" << endl;
            cout << "when it is red. Another driver barely avoids you, but you " << endl;
            cout << "manage not to hit anyone. That was close! You come up to " << endl;
            cout << "another light, so you need to shift into P anyway." << endl;
            i = 0;
        }
    }
    stick.shift_up(); //into 1st
    stick.shift_up(); //into 2nd
    stick.shift_up(); //into 3rd
    cout << "You manage to stop in time, and you're almost to the lake. " << endl;
    cout << "You shift into 3rd to go down the road, and prepare for the" << endl;
    cout << "turn onto the road that leads to the cabin you're staying at." << endl;
    cout << "It's a bit sharp, so you need to slow down to make it, probably." << endl;
    stick = shift_gears_according_to_user(stick);
    if (stick.get_current_gear() == 2) {
        cout << "You slow into the turn and make it cleanly. Good job!" << endl;
    }
    if (stick.get_current_gear() == 3) {
        cout << "You don't slow down, but you manage the turn with some " << endl;
        cout << "scary jostling. You did it, at least." << endl;
    }
    if (stick.get_current_gear() == 4) {
        cout << "You speed up, and don't make the turn properly. You hit " << endl;
        cout << "a tree on the side of the road. No one's hurt and you've" << endl;
        cout << "made it this far so you go on, but your family " << endl;
        cout << "won't be happy about the huge dent in the car." << endl;
    }
    cout << "You finally make it to the lake, and you and your friends are ready" << endl;
    cout << "for a really great time! Congrats on making it here, stick shift " << endl;
    cout << "newbie! Have fun!\n\n   The end!" << endl;
}
