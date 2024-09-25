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
    static int next_id;
    bool write_data = false;

    float extract_float(string& text);

public:
    vector<float> pressure_values;

    BusPoint();
    ~BusPoint();

    int get_id() const;
    static int get_next_id();
};

#endif // BUSPOINT_H
