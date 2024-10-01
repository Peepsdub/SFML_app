#include "BusPoint.h"
#include <string>
#include <iostream>
#include <limits>
#include <cctype>

// Initialize the static member variable
int BusPoint::nextId = 1;

BusPoint::BusPoint(Texture* texture, Vector2u imageCount, float switchTime, float posX, float posY) :
    animation(texture, imageCount, switchTime)
{
    id = nextId++;

    string data;
    ifstream readFile("data.txt");

    // Instantiate the pressure_values from .txt based on the passed id number
    while (getline(readFile, data)) {
        if (data.find("Bus") != string::npos && parseInt(data) == id) {
            writeData = true;
        }

        else if (data.find("Pressure reading:") != string::npos && writeData) {
            pressureValues.push_back(parseFloat(data));
            writeData = false;
        }
    }
    readFile.close();

    // BusPoint Graphics Setup
    point.setSize(Vector2f(100.0f, 100.0f));
    point.setOrigin(50.0f, 50.0f);
    point.setPosition(posX, posY);
    point.setTexture(texture);
}


float BusPoint::parseFloat(string& text) {
    string temp;
    for (char& ch : text) {
        if ((int(ch) > 47 && int(ch) < 58) || int(ch) == 46) {
            temp += ch;
        }
    }
    return stof(temp);
}

int BusPoint::parseInt(const string& str) {
    long long result = 0; // Use long long to avoid overflow for large integers

    for (char ch : str) {
        // Check if the character is a digit
        if (std::isdigit(ch)) {
            result = result * 10 + (ch - '0'); // Build the integer
        }
    }

    // Handle potential overflow
    if (result > numeric_limits<int>::max()) {
        return numeric_limits<int>::max();
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

void BusPoint::Update(float deltaTime) {
    animation.Update(deltaTime);
    point.setTextureRect(animation.uvRect);
}

void BusPoint::Draw(RenderWindow& window) {
    window.draw(point);
}

void BusPoint::setPosition(float posX, float posY) {
    point.setPosition(posX, posY);
}
