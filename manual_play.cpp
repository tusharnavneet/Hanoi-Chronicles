#include "manual_play.h"
#include "automatic_play.h"

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
