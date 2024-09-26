#pragma once
#ifndef BUSPOINT_H
#define BUSPOINT_H

#include <vector>
#include <string>
#include <fstream>

using namespace std;

class BusPoint {
private:
    int id;
    static int nextId;
    bool writeData = false;

    float extractFloat(string& text);
    int parseForInt(const string& str);

public:
    vector<float> pressureValues;

    BusPoint();

    void showPressures();

    int getId() const;
    static int getNextId();
};

#endif // BUSPOINT_H
