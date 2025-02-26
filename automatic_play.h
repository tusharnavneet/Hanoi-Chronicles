#ifndef AUTOMATIC_PLAY_H
#define AUTOMATIC_PLAY_H

#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

// Global variables used in the implementation
extern int tower_a; // Number of disks on tower A
extern int tower_b; // Number of disks on tower B
extern int tower_c; // Number of disks on tower C
extern int points;  // Points for valid/invalid moves
extern int steps;   // Keeps track of the number of steps
extern string bar;  // String representation of tower bars

// Function declarations

// Function to solve the Tower of Hanoi puzzle automatically with user approval
void solve_computer(int &tower_a, int &tower_b, int &tower_c, vector<string> &a, vector<string> &b, vector<string> &c, int n, char T1, char T2, char T3);

// Function to generate the visual representation of the disks on a tower
void input_disk(vector<string> &a, int tower_a);

// Function to reset the state of the towers and the steps counter
void reset_state(vector<string> &a, vector<string> &b, vector<string> &c);

// Function to handle manual play mode
void play_game();

// Function to handle automatic play mode
void automatic_mode();

// Function to display the state of towers after each move (Assumed to be defined elsewhere)
void show(const vector<string> &a, const vector<string> &b, const vector<string> &c, int tower_a, int tower_b, int tower_c);

#endif // AUTOMATIC_PLAY_H

