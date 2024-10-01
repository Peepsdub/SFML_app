#pragma once
#ifndef BUSPOINT_H
#define BUSPOINT_H

#include <vector>
#include <string>
#include <fstream>
#include <SFML\Graphics.hpp>
#include "Animation.h"

using namespace std;

class BusPoint {
private:
    int id;
    static int nextId;
    bool writeData = false;

    float parseFloat(string& text);
    int parseInt(const string& str);

    RectangleShape point;
    Animation animation;

public:
    vector<float> pressureValues;

    BusPoint(Texture* texture, Vector2u imageCount, float switchTime, float posX, float posY);

    void showPressures();

    int getId() const;
    static int getNextId();

    void Update(float deltaTime);
    void Draw(RenderWindow& window);
    void setPosition(float posX, float posY);
};

#endif // BUSPOINT_H
