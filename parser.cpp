//  Vedansh Mehta
//  parser.cpp
//  lab3
//
//  Modified by Tarek Abdelrahman on 2020-10-04.
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018-2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "Shape.h"
#include "globals.h"

// This is the shape array, to be dynamically allocated
Shape** shapesArray;

// The number of shapes in the database, to be incremented
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes = 0;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here
bool isMaxShapecalled = false;
int main() {
  string line;
  string command;

  while (1) {
    cout << "> ";  // Prompt for input
    getline(cin, line);
    if (cin.eof()) {
      break;
    }
    stringstream lStream(line);
    lStream >> ws;
    lStream >> command;
    if (command == keyWordsList[2]) {  // CREATE
      string n;                        // NAME
      // check if too few args
      if (lStream.eof()) {
        cout << "Error: too few arguments" << endl;
        continue;
      }
      lStream >> ws;
      lStream >> n;  // HOW TO CHECK FOR WHITE SPACES IN NAME?
      if (lStream.fail()) {
        cout << "Error: invalid argument" << endl;
        lStream.clear();
        continue;
      }
      if (n == keyWordsList[0] || n == keyWordsList[1] ||
          n == keyWordsList[2] || n == keyWordsList[3] ||
          n == keyWordsList[4] || n == keyWordsList[5] ||
          n == keyWordsList[6] || n == shapeTypesList[0] ||
          n == shapeTypesList[1] || n == shapeTypesList[2] ||
          n == shapeTypesList[3]) {
        cout << "Error: invalid shape name" << endl;
        continue;
      }

      bool shouldCont = false;
      for (int i = 0; i < max_shapes; i++) {
        if (shapesArray[i] != NULL) {
          if (shapesArray[i]->getName() == n) {
            cout << "Error: shape " << n << " exists" << endl;
            shouldCont = true;
            break;
          }
        }
      }
      if (shouldCont) continue;
      // CREATE-VALID NAME-CHECKED FOR ALL ERRORS

      string t;  // TYPE
                 // check if too few args
      if (lStream.eof()) {
        cout << "Error: too few arguments" << endl;
        continue;
      }
      lStream >> ws;
      lStream >> t;
      if (lStream.fail()) {
        cout << "Error: invalid argument" << endl;
        lStream.clear();
        continue;
      }
      if (t != shapeTypesList[0] && t != shapeTypesList[1] &&
          t != shapeTypesList[2] && t != shapeTypesList[3]) {
        cout << "Error: invalid shape type" << endl;
        continue;
      }
      // CREATE-VALID TYPE-CHECKED FOR ALL ERRORS

      int lx, ly;  // X-location
                   // check if too few args
      if (lStream.eof()) {
        cout << "Error: too few arguments" << endl;
        continue;
      }
      lStream >> ws;
      lStream >> lx;
      if (lStream.fail()) {
        cout << "Error: invalid argument" << endl;
        lStream.clear();
        continue;
      }

      if (lx < 0) {
        cout << "Error: invalid value" << endl;
        continue;
      }
      // CREATE-VALID X-LOCATION-CHECKED FOR ALL ERRORS

      // check if too few args
      if (lStream.eof()) {
        cout << "Error: too few arguments" << endl;
        continue;
      }
      lStream >> ws;
      lStream >> ly;  // Y-location
      if (lStream.fail()) {
        cout << "Error: invalid argument" << endl;
        lStream.clear();
        continue;
      }
      if (ly < 0) {
        cout << "Error: invalid value" << endl;
        continue;
      }
      // CREATE-VALID Y-LOCATION-CHECKED FOR ALL ERRORS

      int sx, sy;  // X-size
                   // check if too few args
      if (lStream.eof()) {
        cout << "Error: too few arguments" << endl;
        continue;
      }
      lStream >> ws;
      lStream >> sx;
      if (lStream.fail()) {
        cout << "Error: invalid argument" << endl;
        lStream.clear();
        continue;
      }

      if (sx < 0) {
        cout << "Error: invalid value" << endl;
        continue;
      }
      // CREATE-VALID X-SIZE-CHECKED FOR ALL ERRORS

      // check if too few args
      if (lStream.eof()) {
        cout << "Error: too few arguments" << endl;
        continue;
      }
      lStream >> ws;
      lStream >> sy;  // Y-size
      if (lStream.fail()) {
        cout << "Error: invalid argument" << endl;
        lStream.clear();
        continue;
      }

      if (sy < 0) {
        cout << "Error: invalid value" << endl;
        continue;
      }
      // CREATE-VALID Y-SIZE-CHECKED FOR ALL ERRORS

      if (t == shapeTypesList[0] && sx != sy) {
        cout << "Error: invalid value" << endl;
        continue;
      }
      // CREATE-VALID CIRCLE TYPE AND SIZE DIMENSIONS-CHECKED FOR ERROR
      lStream >> ws;
      if (lStream.peek() == '.') {
        cout << "Error: invalid argument" << endl;
        continue;
      }
      if (lStream.peek() != EOF) {
        cout << "Error: too many arguments" << endl;
        continue;
      }

      if (shapeCount >= max_shapes) {
        cout << "Error: shape array is full" << endl;
        continue;
      }
      shapesArray[shapeCount] =
          new Shape(n, t, lx, sx, ly, sy);  // CREATED A NEW OBJECT
      shapesArray[shapeCount]->setName(n);
      shapesArray[shapeCount]->setType(t);
      shapesArray[shapeCount]->setXlocation(lx);
      shapesArray[shapeCount]->setYlocation(ly);
      shapesArray[shapeCount]->setXsize(sx);
      shapesArray[shapeCount]->setYsize(sy);

      cout << "Created " << shapesArray[shapeCount]->getName() << ": "
           << shapesArray[shapeCount]->getType() << " "
           << shapesArray[shapeCount]->getXlocation() << " "
           << shapesArray[shapeCount]->getYlocation() << " "
           << shapesArray[shapeCount]->getXsize() << " "
           << shapesArray[shapeCount]->getYsize() << endl;
      shapeCount++;
    }

    else if (command == keyWordsList[3]) {  // MOVE
      int r = -1;
      // while (!lStream.eof() && index != 3) {
      string n;
      // check for too few arguments;
      if (lStream.eof()) {
        cout << "Error: too few arguments" << endl;
        continue;
      }  // NAME
      lStream >> ws;
      lStream >> n;  // HOW TO CHECK FOR WHITE SPACES IN NAME?
      if (lStream.fail()) {
        cout << "Error: invalid argument" << endl;
        lStream.clear();
        continue;
      }
      if (n == keyWordsList[0] || n == keyWordsList[1] ||
          n == keyWordsList[2] || n == keyWordsList[3] ||
          n == keyWordsList[4] || n == keyWordsList[5] ||
          n == keyWordsList[6] || n == shapeTypesList[0] ||
          n == shapeTypesList[1] || n == shapeTypesList[2] ||
          n == shapeTypesList[3]) {
        cout << "Error: invalid shape name" << endl;
        continue;
      }

      for (int i = 0; i < max_shapes; i++) {
        if (shapesArray[i] != NULL) {
          if (shapesArray[i]->getName() == n) {
            r = i;
            break;
          }
        }
      }
      if (r == -1) {
        cout << "Error: shape " << n << " not found" << endl;
        continue;
      }
      // MOVE-VALID NAME-CHECKED FOR ALL ERRORS

      int lx, ly;
      if (lStream.eof()) {
        cout << "Error: too few arguments" << endl;
        continue;
      }  // X-location
      lStream >> ws;
      lStream >> lx;
      if (lStream.fail()) {
        cout << "Error: invalid argument" << endl;
        continue;
      }
      if (lx < 0) {
        cout << "Error: invalid value" << endl;
        continue;
      }
      // MOVE-VALID X-LOCATION-CHECEKD FOR ALL ERRORS
      if (lStream.eof()) {
        cout << "Error: too few arguments" << endl;
        continue;
      }
      lStream >> ws;
      lStream >> ly;  // Y-location
      if (lStream.fail()) {
        cout << "Error: invalid argument" << endl;
        lStream.clear();
        continue;
      }
      if (ly < 0) {
        cout << "Error: invalid value" << endl;
        continue;
      }
      // MOVE-VALID Y-LOCATION-CHECKED FOR ALL ERRORS

      shapesArray[r]->setXlocation(lx);
      shapesArray[r]->setYlocation(ly);
      //}
      lStream >> ws;
      if (lStream.peek() == '.') {
        cout << "Error: invalid argument" << endl;
        continue;
      }
      if (lStream.peek() != EOF) {
        cout << "Error: too many arguments" << endl;
        continue;
      }
      cout << "Moved " << shapesArray[r]->getName() << " to "
           << shapesArray[r]->getXlocation() << " "
           << shapesArray[r]->getYlocation() << endl;
    }

    else if (command == keyWordsList[4]) {  // ROTATE
      int rotationAngle;
      int r = -1;

      string n;
      if (lStream.eof()) {
        cout << "Error: too few arguments" << endl;
        continue;
      }  // NAME
      lStream >> ws;
      lStream >> n;  // HOW TO CHECK FOR WHITE SPACES IN NAME?
      if (lStream.fail()) {
        cout << "Error: invalid argument" << endl;
        lStream.clear();
        continue;
      }
      if (n == keyWordsList[0] || n == keyWordsList[1] ||
          n == keyWordsList[2] || n == keyWordsList[3] ||
          n == keyWordsList[4] || n == keyWordsList[5] ||
          n == keyWordsList[6] || n == shapeTypesList[0] ||
          n == shapeTypesList[1] || n == shapeTypesList[2] ||
          n == shapeTypesList[3]) {
        cout << "Error: invalid shape name" << endl;
        continue;
      }

      for (int i = 0; i < max_shapes; i++) {
        if (shapesArray[i] != NULL) {
          if (shapesArray[i]->getName() == n) {
            r = i;
            break;
          }
        }
      }
      if (r == -1) {
        cout << "Error: shape " << n << " not found" << endl;
        continue;
      }
      // ROTATE-VALID NAME-CHECKED FOR ALL ERRORS

      int angle;
      if (lStream.eof()) {
        cout << "Error: too few arguments" << endl;
        continue;
      }  // angle
      lStream >> ws;
      lStream >> angle;
      if (lStream.fail()) {
        cout << "Error: invalid argument" << endl;
        lStream.clear();
        continue;
      }
      if (angle < 0 || angle > 360) {
        cout << "Error: invalid value" << endl;
        continue;
      }
      // ROTATE-VALID ANGLE-CHECKED FOR ALL ERRORS
      shapesArray[r]->setRotate(angle);
      rotationAngle = angle;
      lStream >> ws;
      if (lStream.peek() == '.') {
        cout << "Error: invalid argument" << endl;
        continue;
      }
      if (lStream.peek() != EOF) {
        cout << "Error: too many arguments" << endl;
        continue;
      }
      cout << "Rotated " << shapesArray[r]->getName() << " by " << rotationAngle
           << " degrees" << endl;
    }

    else if (command == keyWordsList[5]) {  // DRAW
      int r = -1;
      string n;
      if (lStream.eof()) {
        cout << "Error: too few arguments" << endl;
        continue;
      }  // NAME
      lStream >> ws;
      lStream >> n;  // HOW TO CHECK FOR WHITE SPACES IN NAME?
      if (lStream.fail()) {
        cout << "Error: invalid argument" << endl;
        lStream.clear();
        continue;
      }
      if (n == keyWordsList[1] || n == keyWordsList[2] ||
          n == keyWordsList[3] || n == keyWordsList[4] ||
          n == keyWordsList[5] || n == keyWordsList[6] ||
          n == shapeTypesList[0] || n == shapeTypesList[1] ||
          n == shapeTypesList[2] || n == shapeTypesList[3]) {
        cout << "Error: invalid shape name" << endl;
        continue;
      }
      if (n == keyWordsList[0]) {
        lStream >> ws;
        if (lStream.peek() != EOF) {
          cout << "Error: too many arguments" << endl;
          continue;
        }
        cout << "Drew all shapes " << endl;
        for (int i = 0; i < max_shapes; i++) {
          if (shapesArray[i] != NULL) {
            shapesArray[i]->draw();
          }
        }

        continue;
      }
      for (int i = 0; i < max_shapes; i++) {
        if (shapesArray[i] != NULL && shapesArray[i]->getName() == n) {
          r = i;
          break;
        }
      }
      if (r == -1) {
        cout << "Error: shape " << n << " not found" << endl;
        continue;
      }
      lStream >> ws;
      if (lStream.peek() != EOF) {
        cout << "Error: too many arguments" << endl;
        continue;
      }
      cout << "Drew ";
      shapesArray[r]->draw();  // cout<<endl;
    }

    else if (command == keyWordsList[6]) {  // DELETE
      string name;
      int r = -1;
      string n;
      if (lStream.eof()) {
        cout << "Error: too few arguments" << endl;
        continue;
      }  // NAME
      lStream >> ws;
      lStream >> n;  // HOW TO CHECK FOR WHITE SPACES IN NAME?
      if (lStream.fail()) {
        cout << "Error: invalid argument" << endl;
        lStream.clear();
        continue;
      }
      if (n == keyWordsList[1] || n == keyWordsList[2] ||
          n == keyWordsList[3] || n == keyWordsList[4] ||
          n == keyWordsList[5] || n == keyWordsList[6] ||
          n == shapeTypesList[0] || n == shapeTypesList[1] ||
          n == shapeTypesList[2] || n == shapeTypesList[3]) {
        cout << "Error: invalid shape name" << endl;
        continue;
      }
      if (n == keyWordsList[0]) {
        lStream >> ws;
        if (lStream.peek() != EOF) {
          cout << "Error: too many arguments" << endl;
          continue;
        }
        for (int i = 0; i < max_shapes; i++) {
          if (shapesArray[i] != NULL) {
            delete shapesArray[i];
            shapesArray[i] = NULL;
          }
        }
        cout << "Deleted: all shapes " << endl;
        continue;
      }

      for (int i = 0; i < max_shapes; i++) {
        if (shapesArray[i] != NULL) {
          if (shapesArray[i]->getName() == n) {
            r = i;
            break;
          }
        }
      }
      if (r == -1) {
        cout << "Error: shape " << n << " not found" << endl;
        continue;
      }
      lStream >> ws;
      if (lStream.peek() != EOF) {
        cout << "Error: too many arguments" << endl;
        continue;
      }
      name = shapesArray[r]->getName();
      delete shapesArray[r];
      shapesArray[r] = NULL;
      cout << "Deleted shape " << name << endl;
    }

    else if (command == keyWordsList[1]) {  // MAXSHAPES
      int v = 0;
      if (lStream.eof()) {
        cout << "Error: too few arguments" << endl;
        continue;
      }
      lStream >> ws;
      lStream >> v;
      if (lStream.fail()) {
        cout << "Error: invalid argument" << endl;
        lStream.clear();
        continue;
      }
      if (v < 0) {
        cout << "Error: invalid value" << endl;
        continue;
      }
      lStream >> ws;
      if (lStream.peek() == '.') {
        cout << "Error: invalid argument" << endl;
        continue;
      }
      if (lStream.peek() != EOF) {
        cout << "Error: too many arguments" << endl;
        continue;
      }

      if (isMaxShapecalled) {
        for (int i = 0; i < max_shapes; i++) {
          if (shapesArray[i] != NULL) {
            delete shapesArray[i];
            shapesArray[i] = NULL;
          }
        }
        delete[] shapesArray;
        shapeCount = 0;
      }
      max_shapes = v;
      shapesArray = new Shape*[max_shapes];  // initialising the array
      for (int i = 0; i < max_shapes; i++) {
        shapesArray[i] = NULL;
      }  // initialising the array
      isMaxShapecalled = true;
      cout << "New database: max shapes is " << max_shapes << endl;
    } else {
      cout << "Error: invalid command" << endl;
      continue;
    }

  }  // End input loop until EOF.
  for (int i = 0; i < max_shapes; i++) {
    delete shapesArray[i];
    shapesArray[i] = NULL;
  }
  delete[] shapesArray;
  return 0;
}