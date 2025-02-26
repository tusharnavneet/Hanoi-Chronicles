#include <iostream>
#include <vector>
#include <chrono> // Include for timing functionality
#include "manual_play.h"
#include "automatic_play.h"
using namespace std;

int steps = 0;
int tower_a = 0, tower_b = 0, tower_c = 0;
int points = 0; // New variable to track points
string bar = "";

// Variables to store previous states for backtracking
vector<string> previous_a, previous_b, previous_c;

// Function to display the current state of the towers
void show(const vector<string> &a, const vector<string> &b, const vector<string> &c, int tower_a, int tower_b, int tower_c)
{
    cout << "Step: " << steps++ << "\n";
    cout << "TOWER A\n";
    for (int ar = 0; ar < tower_a; ar++)
    {
        cout << a[ar];
    }
    cout << bar;
    cout << "TOWER B\n";
    for (int ar = 0; ar < tower_b; ar++)
    {
        cout << b[ar];
    }
    cout << bar;
    cout << "TOWER C\n";
    for (int ar = 0; ar < tower_c; ar++)
    {
        cout << c[ar];
    }
    cout << bar << "\n";
}



void printDecorativeLine(int width, char cornerChar = '+', char fillChar = '-') {
    cout << "   " << cornerChar;
    for (int i = 0; i < width - 2; ++i) {
        cout << fillChar;
    }
    cout << cornerChar << endl;
}

void printLineWithStars(int width, char borderChar = '|', char fillChar = ' ',
                        int numStars = 4) {
    int starsPosition = (width - numStars) / 2;
    cout << "   " << borderChar;
    for (int i = 0; i < starsPosition - 1; ++i)
        cout << fillChar;
    for (int i = 0; i < numStars; ++i)
        cout << "*";
    for (int i = starsPosition + numStars - 1; i < width - 2; ++i)
        cout << fillChar;
    cout << borderChar << endl;
}

void printCenteredText(int width, string text) {
    int padding = (width - text.length()) / 2;
    cout << "   |";
    cout << string(padding, ' ') << text
         << string(width - text.length() - padding - 2, ' ') << "|" << endl;
}

void printWelcomeBox() {
    int width = 60; // Width of the box

    // Top border with decoration
    printDecorativeLine(width, '+', '-');

    // Decorative lines with stars
    printLineWithStars(width);
    printLineWithStars(width);

    // Welcome message
    printCenteredText(width, "Welcome to the Tower of Hanoi!");

    // Empty line for spacing
    printCenteredText(width, "");

    // Instructions
    printCenteredText(width, "1. Move the disks from the");
    printCenteredText(width, "   first rod to the last rod.");
    printCenteredText(width, "2. Only move one disk at a time.");
    printCenteredText(width, "3. Larger disks cannot be");
    printCenteredText(width, "   placed on smaller ones.");
    printCenteredText(width, "4. All disks start on rod A.");

    // Empty line for spacing
    printCenteredText(width, "");

    // Decorative lines with stars
    printLineWithStars(width);
    printLineWithStars(width);

    // Bottom border with decoration
    printDecorativeLine(width, '+', '-');

    cout << endl;
}
int main()
{
   
    char mode;
    printWelcomeBox();
    int choice;
    do
    {
        cout << "Choose a mode: \n";
        cout << "1. Manual Play\n";
        cout << "2. Automatic Play\n";
        cout << "3. Exit\n";

        cin >> mode;
        cin.ignore();

        switch (mode)
        {
        case '1':
            play_game();
            break;
        case '2':
            automatic_mode();
            break;
        case '3':
            cout << "Exiting the game.\n";
            exit(0);
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }

        cout << "Press 1 to continue playing or any other number to exit: ";
        cin >> choice;
        cin.ignore();
    } while (choice == 1);

    return 0;
}
