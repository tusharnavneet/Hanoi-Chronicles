#ifndef MANUAL_PLAY_H
#define MANUAL_PLAY_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Global variables used in the implementation
extern int points;           // Points for valid/invalid moves
extern int steps;            // Keeps track of the number of steps
extern vector<string> previous_a; // Previous state of tower A
extern vector<string> previous_b; // Previous state of tower B
extern vector<string> previous_c; // Previous state of tower C

// Function declarations
bool is_valid_move(const vector<string> &from, const vector<string> &to);

// Function to move a disk from one tower to another
void process(int &tower_a, int &tower_b, int &tower_c, vector<string> &a, vector<string> &b, vector<string> &c, string from, string to);

// Function to handle user input for moving disks manually
void input(int &tower_a, int &tower_b, int &tower_c, vector<string> &a, vector<string> &b, vector<string> &c);

// Function to display the state of towers after each move (Assumed to be defined elsewhere)
void show(const vector<string> &a, const vector<string> &b, const vector<string> &c, int tower_a, int tower_b, int tower_c);

#endif // MANUAL_PLAY_H

