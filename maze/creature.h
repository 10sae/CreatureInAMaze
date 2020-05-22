//
// Created by Tensae Woldeselassie on 02/03/2020.
//

#pragma once

#include "maze.h"
#include <ostream>

class Creature {
  public:
    // Defines the "<<" operator. Outputs the create with its current postion in the maze "C(row, col)."
    friend ostream& operator<<(ostream& out, const Creature& creature);

  public:
    // Initializes the a creature object with a given location in the maze.
    Creature(int row, int col);

    // Chooses the first direction to go towards from the starting location.
    // Returns the path taken by the user in the form of a string.
    string solve(Maze& maze);

    // Checks if the creature is at the end of the maze. Returns true if it is and false otherwise.
    bool atExit(const Maze& maze) const;

    // Checks whether the creature can move north from its current position and moves north if it can.
    // Checks whether we if the creature is now at the end of the maze. If its not, looks for the next
    // direction to go to. If no valid direction, then it moves back and marks all the visited directions.
    // Returns the path taken by the creature in the form of a string.
    string goNorth(Maze& maze);

    // Parameters: Maze& maze - reference of the maze that the creature is in
    // Checks whether the creature can move north from its current position and moves north if it can.
    // Checks whether we if the creature is now at the end of the maze. If its not, looks for the next
    // direction to go to. If no valid direction, then it moves back and marks all the visited directions.
    // Returns the path taken by the creature in the form of a string.

    // Parameters: Maze& maze - reference of the maze that the creature is in
    // Checks whether the creature can move south from its current position and moves south if it can.
    // Checks whether we if the creature is now at the end of the maze. If its not, looks for the next
    // direction to go to. If no valid direction, then it moves back and marks all the visited directions.
    string goSouth(Maze& maze);

    // Parameters: Maze& maze - reference of the maze that the creature is in
    // Checks whether the creature can move east from its current position and moves east if it can.
    // Checks whether we if the creature is now at the end of the maze. If its not, looks for the next
    // direction to go to. If no valid direction, then it moves back and marks all the visited directions.
    string goEast(Maze& maze);

    // Parameters: Maze& maze - reference of the maze that the creature is in
    // Checks whether the creature can move west from its current position and moves west if it can.
    // Checks whether we if the creature is now at the end of the maze. If its not, looks for the next
    // direction to go to. If no valid direction, then it moves back and marks all the visited directions.
    string goWest(Maze& maze);

  private:
    int row;
    int col;
};
