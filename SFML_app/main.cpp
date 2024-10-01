#include <SFML/Graphics.hpp>
using namespace sf;


#include "BusPoint.h"

#include <String>
#include <iostream>
#include <fstream>
using namespace std;

void genTestData(int n);

int main()
{
    RenderWindow window(VideoMode(1024, 1024), "SFML App", Style::Close | Style::Resize);
    
    Texture pointTexture;
    pointTexture.loadFromFile("C:/Users/Peeps/source/repos/SFML_app/SFML_app/colour_map.png");

    genTestData(50);

    BusPoint rearWing(&pointTexture, Vector2u(10, 10), 2.0f, 512.0f, 512.0f);

    float deltaTime = 0.0f;
    Clock clock;
    
    rearWing.showPressures();


    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case (Event::Closed):
                window.close();
                break;
            }
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            Vector2i mousePos = Mouse::getPosition(window);
            rearWing.setPosition((float)mousePos.x, (float)mousePos.y);
        }

        rearWing.Update(deltaTime);
        

        window.clear();
        rearWing.Draw(window);
        window.display();
    }

    return 0;
}

void genTestData(int n) {
    ofstream data("data.txt");
    int seconds = 0;
    int minutes = 0;
    int hours = 1;

    for (int i = 0; i < n; i++) {
        data << "Bus " << 1 + (rand() % 5) << endl;
        data << "Pressure reading: " << (rand() % 30) + ((float)(rand()) / (float)(RAND_MAX)) << endl;
        data << "2024/10/1 (Tuesday) " << hours << ":" << minutes << ":" << seconds << endl;
        data << endl;

        if (i % 5 == 0)
            seconds++;
        if (seconds == 60) {
            seconds = 0;
            minutes++;
        }
        if (minutes == 60) {
            minutes = 0;
            hours++;
        }
    } 
    data.close();
}