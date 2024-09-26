#include <SFML/Graphics.hpp>
using namespace sf;


#include "Animation.h"
#include "BusPoint.h"

#include <String>
#include <iostream>
#include <fstream>
using namespace std;



int main()
{
    RenderWindow window(VideoMode(1024, 1024), "SFML App", Style::Close | Style::Resize);
    RectangleShape player(Vector2f(100.0f, 100.0f));
    player.setOrigin(50.0f, 50.0f);
    player.setPosition(512.0f, 512.0f);
    Texture playerTexture;
    playerTexture.loadFromFile("C:/Users/Peeps/source/repos/SFML_app/SFML_app/colour_map.png");
    player.setTexture(&playerTexture);

    Animation animation(&playerTexture, Vector2u(10, 10), 0.05f);

    float deltaTime = 0.0f;
    Clock clock;
    
    BusPoint rearWing;
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
            player.setPosition((float)mousePos.x, (float)mousePos.y);
        }

        animation.Update(deltaTime);
        player.setTextureRect(animation.uvRect);

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}