#include"manual_play.h"
#include"automatic_play.h"

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


