#include <iostream>
#include <vector>
#include <chrono> // Include for timing functionality
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

// Function to check if a move is valid
bool is_valid_move(const vector<string> &from, const vector<string> &to)
{
    if (from.empty())
        return false; // Can't move from an empty tower
    if (!to.empty() && to[0].length() < from[0].length())
    {
        // Can't move a larger disk onto a smaller disk
        return false;
    }
    return true;
}

// Function to move a disk from one tower to another
void process(int &tower_a, int &tower_b, int &tower_c, vector<string> &a, vector<string> &b, vector<string> &c, string from, string to)
{
    switch (to[0])
    {
    case 'a':
        if (from[0] == 'b')
        {
            a.insert(a.begin(), b[0]);
            b.erase(b.begin());
            tower_a++;
            tower_b--;
        }
        else if (from[0] == 'c')
        {
            a.insert(a.begin(), c[0]);
            c.erase(c.begin());
            tower_a++;
            tower_c--;
        }
        break;
    case 'b':
        if (from[0] == 'a')
        {
            b.insert(b.begin(), a[0]);
            a.erase(a.begin());
            tower_b++;
            tower_a--;
        }
        else if (from[0] == 'c')
        {
            b.insert(b.begin(), c[0]);
            c.erase(c.begin());
            tower_b++;
            tower_c--;
        }
        break;
    case 'c':
        if (from[0] == 'a')
        {
            c.insert(c.begin(), a[0]);
            a.erase(a.begin());
            tower_c++;
            tower_a--;
        }
        else if (from[0] == 'b')
        {
            c.insert(c.begin(), b[0]);
            b.erase(b.begin());
            tower_c++;
            tower_b--;
        }
        break;
    }
    // Save previous state for backtracking
    previous_a = a;
    previous_b = b;
    previous_c = c;

    show(a, b, c, tower_a, tower_b, tower_c);
}

// Function to handle user input for moving disks manually
void input(int &tower_a, int &tower_b, int &tower_c, vector<string> &a, vector<string> &b, vector<string> &c)
{
    string from, to;
    bool valid = false;

    while (!valid)
    {
        cout << "Which tower do you want to move from (a/b/c), or type 'z' to return to the previous step: ";
        getline(cin, from);

        if (from == "z")
        {
            // Check if there is a previous state before allowing backtracking
            if (!previous_a.empty() && !previous_b.empty() && !previous_c.empty())
            {
                a = previous_a;
                b = previous_b;
                c = previous_c;
                tower_a = previous_a.size();
                tower_b = previous_b.size();
                tower_c = previous_c.size();
                steps--; // Decrement step count to reflect going back
                show(a, b, c, tower_a, tower_b, tower_c);
                return; // Exit the input function to allow for the next step
            }
            else
            {
                cout << "No previous step to return to.\n";
                continue;
            }
        }

        if (from.length() == 1 && (from[0] == 'a' || from[0] == 'b' || from[0] == 'c'))
        {
            switch (from[0])
            {
            case 'a':
                if (a.empty())
                {
                    cout << "Can't move from tower A, it is empty.\n";
                }
                else
                    valid = true;
                break;
            case 'b':
                if (b.empty())
                {
                    cout << "Can't move from tower B, it is empty.\n";
                }
                else
                    valid = true;
                break;
            case 'c':
                if (c.empty())
                {
                    cout << "Can't move from tower C, it is empty.\n";
                }
                else
                    valid = true;
                break;
            }
        }

        if (!valid)
        {
            cout << "Invalid input, please try again.\n";
        }
    }

    valid = false;
    while (!valid)
    {
        cout << "Move to which tower (a/b/c), or type 'z' to return to the previous step: ";
        getline(cin, to);

        if (to == "z")
        {
            if (!previous_a.empty() && !previous_b.empty() && !previous_c.empty())
            {
                a = previous_a;
                b = previous_b;
                c = previous_c;
                tower_a = previous_a.size();
                tower_b = previous_b.size();
                tower_c = previous_c.size();
                steps--; // Decrement step count to reflect going back
                show(a, b, c, tower_a, tower_b, tower_c);
                return; // Exit the input function to allow for the next step
            }
            else
            {
                cout << "No previous step to return to.\n";
                continue;
            }
        }

        if (to.length() == 1 && (to[0] == 'a' || to[0] == 'b' || to[0] == 'c') && to[0] != from[0])
        {
            valid = is_valid_move(from == "a" ? a : (from == "b" ? b : c), to == "a" ? a : (to == "b" ? b : c));
            if (!valid)
            {
                cout << "Invalid move. You can't place a larger disk on a smaller one. Try again.\n";
                points -= 1;                          // Deduct point for invalid move
                cout << "Points: " << points << "\n"; // Show points after invalid move
            }
        }
        else
        {
            cout << "Invalid move. Please try again.\n";
        }
    }

    points += 1; // Award point for valid move
    process(tower_a, tower_b, tower_c, a, b, c, from, to);
    cout << "Points: " << points << "\n"; // Show points after each valid move
}

// Modified solve_computer function with user prompts after each step
// Modified solve_computer function with user prompts after each step
void solve_computer(int &tower_a, int &tower_b, int &tower_c, vector<string> &a, vector<string> &b, vector<string> &c, int n, char T1, char T2, char T3)
{
    if (n == 1)
    {
        string approve;
        do
        {
            cout << "The computer wants to move from " << T1 << " to " << T3 << ". Type 'y', 'Y' or press enter to approve the move: ";
            getline(cin, approve);
            // Accept 'y', 'Y', or empty input (enter)
            if (approve != "y" && approve != "Y" && approve != "")
            {
                cout << "Invalid input! Please type 'y', 'Y', space, or press enter to approve the move.\n";
            }
        } while (approve != "y" && approve != "Y" && approve != " " && approve != "");

        // Proceed with the move if the input is valid
        process(tower_a, tower_b, tower_c, a, b, c, string(1, T1), string(1, T3));
    }
    else
    {
        solve_computer(tower_a, tower_b, tower_c, a, b, c, n - 1, T1, T3, T2);

        string approve;
        do
        {
            cout << "The computer wants to move from " << T1 << " to " << T3 << ". Type 'y', 'Y' or press enter to approve the move: ";
            getline(cin, approve);
            // Accept 'y', 'Y', space, or empty input (enter)
            if (approve != "y" && approve != "Y" && approve != "")
            {
                cout << "Invalid input! Please type 'y', 'Y'or press enter to approve the move.\n";
            }
        } while (approve != "y" && approve != "Y"  && approve != "");

        process(tower_a, tower_b, tower_c, a, b, c, string(1, T1), string(1, T3));

        solve_computer(tower_a, tower_b, tower_c, a, b, c, n - 1, T2, T1, T3);
    }
}


// Function to generate the visual representation of the disks on a tower
void input_disk(vector<string> &a, int tower_a)
{
    a.push_back("");
    for (int c = tower_a - 1; c >= 2; c--)
        a[0] += "  ";
    a[0] += " ()\n";

    for (int b = 1; b < tower_a; b++)
    {
        a.push_back("");
        for (int c = tower_a - 1; c >= b + 1; c--)
            a[b] += "  ";
        for (int d = 1; d <= b; d++)
            a[b] += "()()";
        a[b] += "\n";
    }

    for (int b = 1; b < (tower_a * 2); b++)
        bar += "-";
    bar += "\n";
}

// Function to reset the state of the towers and steps counter
void reset_state(vector<string> &a, vector<string> &b, vector<string> &c)
{
    a.clear();
    b.clear();
    c.clear();
    previous_a.clear();
    previous_b.clear();
    previous_c.clear();
    steps = 0;
    points = 0; // Reset points when starting a new game
    tower_a = tower_b = tower_c = 0;
    bar = "";
}

// Function to handle manual play mode
void play_game()
{
    int total;
    vector<string> a, b, c;

    reset_state(a, b, c); // Reset state before starting the game

    cout << "How many disks (minimum 3, maximum 7): ";
    cin >> total;
    cin.ignore();

    if (total < 3 || total > 7)
    {
        cout << "Invalid input! Please enter a number between 3 and 7.\n";
        return;
    }

    input_disk(a, total);
    tower_a = total;

    char timed_mode;
    

    cout << "Do you want to play in timed mode? (enter 'y' for timed mode and any other key for without timed mode): ";
    cin >> timed_mode;
    cin.ignore();
    auto start_time = std::chrono::high_resolution_clock::now();
    auto end_time = start_time;

    show(a, b, c, tower_a, tower_b, tower_c);

    while (tower_b != total && tower_c != total)
    {
        input(tower_a, tower_b, tower_c, a, b, c);

        if (timed_mode == 'y' || timed_mode == 'Y')
        {
            end_time = std::chrono::high_resolution_clock::now(); // Update end time
            auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
            cout << "Elapsed time: " << elapsed_time.count() << " seconds.\n";
        }
    }

    cout << "Congratulations! You've won!\n";

    if (timed_mode == 'y' || timed_mode == 'Y')
    {
        end_time = std::chrono::high_resolution_clock::now(); // Final end time
        auto total_time = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
        cout << "Total time taken: " << total_time.count() << " seconds.\n";
    }

    // Display final points
    cout << "Total points: " << points << "\n";
}

// Function to handle automatic play mode
void automatic_mode()
{
    int total;
    vector<string> a, b, c;

    reset_state(a, b, c); // Reset state before starting automatic mode

    cout << "How many disks (minimum 3, maximum 7): ";
    cin >> total;
    cin.ignore();

    if (total < 3 || total > 7)
    {
        cout << "Invalid input! Please enter a number between 3 and 7.\n";
        return;
    }

    input_disk(a, total);
    tower_a = total;

    show(a, b, c, tower_a, tower_b, tower_c);

    cout << "The computer will solve the puzzle, but you will need to approve each move.\n";

    solve_computer(tower_a, tower_b, tower_c, a, b, c, total, 'a', 'b', 'c');

    cout << "\nComputer solved the puzzle!\n";
    cout << "---------------------------------------------" << endl;
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
