**Hanoi Chronicles: A Timed Journey of Moves and Strategies**

**Overview**

Hanoi Chronicles is a feature-rich implementation of the Tower of Hanoi game in C++. This project offers both manual and automatic gameplay modes, integrating real-time user interaction with educational value. Designed with an emphasis on recursion, algorithmic problem-solving, and interactive learning, the game includes features such as a scoring system, timed gameplay, dynamic visualization, and an undo functionality for backtracking.

**Features**

**Manual Mode:** Users manually move disks between rods while following game rules.

**Automatic Mode:** The computer solves the puzzle step-by-step, with user approval for each move.

**Point-Based Scoring System:** Rewards valid moves and penalizes invalid moves.

**Undo Feature:** Allows players to revert their last move for strategic experimentation.

**Timed Gameplay:** An optional mode that tracks the time taken to solve the puzzle.

**Dynamic Visualization:** Displays the tower states dynamically after each move.

**Move Validation:** Ensures legal disk movements, preventing incorrect moves.

**System Requirements**

Operating System: Windows, Linux, macOS

Compiler: Any C++11 compatible compiler (GCC, Clang, MSVC)

Development Environment: gedit, Visual Studio Code, or any preferred text editor

**Installation**

Clone the repository:

git clone https://github.com/tusharnavneet/Hanoi-Chronicles

Compile the source code:

g++ -o hanoi hanoi.cpp

Run the program:

./hanoi

Usage

Upon launching, select a mode:

Manual Mode: Enter moves manually.

Automatic Mode: Watch the computer solve the puzzle step-by-step with user approval.

Enter the number of disks (3 to 7 recommended).

Follow on-screen prompts to move disks between rods.

Enable timed mode to track solution time.

Utilize the undo feature to correct mistakes.

**Game Rules**

Only one disk can be moved at a time.

A larger disk cannot be placed on top of a smaller one.

All disks start on the first rod and must be moved to the last rod.

**Code Structure**

Game Logic: Handles disk movements, game rules, and move validation.

User Interface: Manages input handling, prompts, and error messages.

Automatic Solver: Implements a recursive algorithm to solve the puzzle.

Scoring System: Rewards or penalizes players based on their moves.

Timed Mode: Tracks elapsed time for game completion.

**Result**
![Screenshot from 2024-10-14 22-48-51](https://github.com/user-attachments/assets/3722809e-c863-4322-9463-379ccdd69054)\\
![Screenshot from 2024-10-14 22-50-10](https://github.com/user-attachments/assets/d5d0552d-6ed1-42a3-94fd-802051a82c2c) \\
![Screenshot from 2024-10-14 22-50-37](https://github.com/user-attachments/assets/54a0673f-3e9d-45ac-92cf-ec4c6697b926) \\
![Screenshot from 2024-10-15 15-59-02](https://github.com/user-attachments/assets/3cdc70ab-b998-4117-afb1-117ef3e483d1)





**Performance Analysis**

Execution time increases exponentially with the number of disks.

Recursive approach ensures efficiency but requires optimization for large disk numbers.

Handles up to 7 disks efficiently without noticeable delays.

**Challenges & Limitations**

Move Suggestion Accuracy: Ensuring that suggested moves align with the current state.

Performance in Large Disk Counts: Recursive approach causes longer execution times.

Scalability: Extending the game beyond 7 disks requires additional optimizations.

**Future Enhancements**

Machine Learning-Based Move Suggestions: Improving recommendation accuracy.

Graphical Interface: Enhancing visual representation with a GUI.

Multiplayer Mode: Enabling competition between players.

Extended Difficulty Levels: Introducing more complex variations of the puzzle.

**References**

The project is inspired by the classical Tower of Hanoi problem, extensively studied in computational theory.

References include standard algorithmic literature and previous research on game implementations in C++.

**Author**

Tushar Navneet

Supervised by Dr. M Dennis Singh

**Department of Computer Science and Engineering, IIIT Senapati, Manipur**
