#include "BusPoint.h"
#include <string>

// Initialize the static member variable
int BusPoint::next_id = 1;

BusPoint::BusPoint() {
    id = next_id++;

    string data;
    ifstream ReadFile("filename.txt");

    // Instantiate the pressure_values from .txt based on the passed id number
    while (getline(ReadFile, data)) {
        if (data.find("Bus") != string::npos && stoi(data) == id) {
            write_data = true;
        }

        else if (data.find("Pressure reading:") != string::npos && write_data) {
            pressure_values.push_back(extract_float(data));
            write_data = false;
        }
    }
}


float BusPoint::extract_float(string& text) {
    string temp;
    for (char& ch : text) {
        if ((int(ch) > 47 && int(ch) < 58) || int(ch) == 46) {
            temp += ch;
        }
    }
    return stof(temp);
}

int BusPoint::get_id() const {
    return id;
}

int BusPoint::get_next_id() {
    return next_id;
}
