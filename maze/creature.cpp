//
// Created by Tensae Woldeselassie on 01/30/20.
//

#include "creature.h"

// Defines the "<<" operator. Outputs the create with its current postion in the maze "C(row, col)."
ostream& operator<<(ostream& out, const Creature& creature) {
    out << "C(" << creature.row << "," << creature.col << ")";
    return out;
}

// Initializes the a creature object with a given location in the maze.
Creature::Creature(int row, int col) : row(row), col(col) {}

// Checks if the creature is at the end of the maze. Returns true if it is and false otherwise.
bool Creature::atExit(const Maze& maze) const {
    return row == maze.getExitRow() && col == maze.getExitColumn();
}

// Chooses the first direction to go towards from the starting location.
// Returns the path taken by the user in the form of a string.
string Creature::solve(Maze& maze) {
    string path = goNorth(maze); // + goWest(maze) + goEast(maze) + goSouth(maze);
    if (path.length() == 0) {
        path += goWest(maze);
        if (path.length() == 0) {
            path += goEast(maze);
            if (path.length() == 0) {
                path += goSouth(maze);
            }
        }
    }
    if (atExit(maze)) {
        maze.markAsPath(maze.getExitRow(), maze.getExitColumn());
    }
    return path;
}

// Parameters: Maze& maze - reference of the maze that the creature is in
// Checks whether the creature can move north from its current position and moves north if it can.
// Checks whether we if the creature is now at the end of the maze. If its not, looks for the next
// direction to go to. If no valid direction, then it moves back and marks all the visited directions.
// Returns the path taken by the creature in the form of a string.
string Creature::goNorth(Maze& maze) {
    string path = "";
    if (maze.isClear(row - 1, col)) {           // Can i go north? YES
        maze.markAsPath(row, col);           // mark where you are leaving as a path
        row--;                                        // move north
        path = "N";
        if (!atExit(maze)) {  // if exit reached (maze's done);
            path += goNorth(maze); // returns empty string if invalid       // check and find the
            if (path.length() == 1) {                        // next available direction
                path += goWest(maze);                                       // that doesn't take me backwards
                if (path.length() == 1) {
                    path += goEast(maze);
                    if (path.length() == 1) {            // if all progressing directions fail
                        maze.markAsVisited(row, col);             // mark current space as checked
                        row++;                                              // go to previous space
                        path = "";                                          // erase path
                        maze.markAsVisited(row, col);         // mark previous space visited instead of path
                    }
                }
            }
        }
     }
    return path;
}

// Parameters: Maze& maze - reference of the maze that the creature is in
// Checks whether the creature can move west from its current position and moves west if it can.
// Checks whether we if the creature is now at the end of the maze. If its not, looks for the next
// direction to go to. If no valid direction, then it moves back and marks all the visited directions.
string Creature::goWest(Maze& maze) {
    string path = "";
    if (maze.isClear(row, col - 1)) {
        maze.markAsPath(row, col);
        col--;
        path = "W";
        if (!atExit(maze)) {
            path += goNorth(maze);
            if (path.length() == 1) {
                path += goWest(maze);
                if (path.length() == 1) {
                    path += goSouth(maze);
                    if (path.length() == 1) {
                        maze.markAsVisited(row, col);
                        col++;
                        path = "";
                        maze.markAsVisited(row, col);
                    }
                }
            }
        }
    }
    return path;
}

// Parameters: Maze& maze - reference of the maze that the creature is in
// Checks whether the creature can move east from its current position and moves east if it can.
// Checks whether we if the creature is now at the end of the maze. If its not, looks for the next
// direction to go to. If no valid direction, then it moves back and marks all the visited directions.
string Creature::goEast(Maze& maze) {
    string path = "";
    if (maze.isClear(row, col + 1)) {
        maze.markAsPath(row, col);
        col++;
        path = "E";
        if (!atExit(maze)) {
            path += goNorth(maze);
            if (path.length() == 1) {
                path += goEast(maze);
                if (path.length() == 1) {
                    path += goSouth(maze);
                    if (path.length() == 1) {
                        maze.markAsVisited(row, col);
                        col--;
                        path = "";
                        maze.markAsVisited(row, col);
                    }
                }
            }
        }
    }
    return path;
}

// Parameters: Maze& maze - reference of the maze that the creature is in
// Checks whether the creature can move south from its current position and moves south if it can.
// Checks whether we if the creature is now at the end of the maze. If its not, looks for the next
// direction to go to. If no valid direction, then it moves back and marks all the visited directions.
string Creature::goSouth(Maze& maze) {
    string path = "";
    if (maze.isClear(row + 1, col)) {
        maze.markAsPath(row, col);
        row++;
        path = "S";
        if (!atExit(maze)) {
            path += goWest(maze);
            if (path.length() == 1) {
                path += goEast(maze);
                if (path.length() == 1) {
                    path += goSouth(maze);
                    if (path.length() == 1) {
                        maze.markAsVisited(row, col);
                        row--;
                        path = "";
                        maze.markAsVisited(row, col);
                    }
                }
            }
        }
    }
    return path;
}