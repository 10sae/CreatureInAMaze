//
// Created by XXX on YYY.
//

#include "creature.h"
#include "maze.h"
#include <iostream>
#include <cassert>
#include <sstream>

void test() {
    Maze m("maze.txt");
    cout << m << endl;
    Creature c(4, 4);
    cout << "Path: " << c.solve(m) << endl;
    cout << m << endl;
}

void test1() {
    Maze m("maze1.txt");
    cout << m << endl;
    Creature c(5,13);
    stringstream s;
    s << c;
    assert(s.str() == "C(5,13)");

    string path = c.solve(m);
    cout << "Path: " << path << endl;
    cout << m << endl;

    // creature changes out value as it moves
    stringstream s2;
    s2 << c;
    assert(s2.str() == "C(6,8)");
    assert(path == "NWNWWWWSSS");
}

void test2() {
    Maze m("maze2.txt");
    cout << m << endl;
    Creature c(4,4);
    stringstream s;
    s << c;
    assert(s.str() == "C(4,4)");

    string path = c.solve(m);
    cout << "Path: " << path << endl;
    cout << m << endl;

    // creature changes out value as it moves
    stringstream s2;
    s2 << c;
    assert(s2.str() == "C(0,17)");
    assert(path == "EEEEEEEESSEEENEEENNNNWN");
}

void test3() {
    Maze m("maze3.txt");
    cout << m << endl;
    Creature c(14,3);
    stringstream s;
    s << c;
    assert(s.str() == "C(14,3)");

    string path = c.solve(m);
    cout << "Path: " << path << endl;
    cout << m << endl;

    // creature changes out value as it moves
    stringstream s2;
    s2 << c;
    assert(s2.str() == "C(15,23)");
    assert(path == "WNNEEEENNNEEENNNEEEEEEEESSEEEESSSSSESES");
}



int main() {
    test();
    test1();
    test2();
    test3();
    cout << "Done!" << std::endl;
    return 0;
}