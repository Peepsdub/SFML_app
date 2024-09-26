#include "BusPoint.h"
#include <string>
#include <iostream>
#include <limits>
#include <cctype>

// Initialize the static member variable
int BusPoint::nextId = 1;

BusPoint::BusPoint() {
    id = nextId++;

    string data;
    ifstream readFile("data.txt");

    // Instantiate the pressure_values from .txt based on the passed id number
    while (getline(readFile, data)) {
        if (data.find("Bus") != string::npos && parseForInt(data) == id) {
            writeData = true;
        }

        else if (data.find("Pressure reading:") != string::npos && writeData) {
            pressureValues.push_back(extractFloat(data));
            writeData = false;
        }
    }
    readFile.close();
}


float BusPoint::extractFloat(string& text) {
    string temp;
    for (char& ch : text) {
        if ((int(ch) > 47 && int(ch) < 58) || int(ch) == 46) {
            temp += ch;
        }
    }
    return stof(temp);
}

int BusPoint::parseForInt(const string& str) {
    long long result = 0; // Use long long to avoid overflow for large integers

    for (char ch : str) {
        // Check if the character is a digit
        if (std::isdigit(ch)) {
            result = result * 10 + (ch - '0'); // Build the integer
        }
    }

    // Handle potential overflow
    if (result > std::numeric_limits<int>::max()) {
        return std::numeric_limits<int>::max();
    }

    return static_cast<int>(result);
}

void BusPoint::showPressures() {
    for (int i = 0; i < pressureValues.size(); i++) {
        cout << "Pressure " << i << ": " << pressureValues[i] << endl;
        
    }
}

int BusPoint::getId() const {
    return id;
}

int BusPoint::getNextId() {
    return nextId;
}
