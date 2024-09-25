#include <SFML/Graphics.hpp>
using namespace sf;

//#include "./BusPoint.cpp"

#include <String>
#include <iostream>
#include <fstream>
using namespace std;



int main()
{
    RenderWindow window(VideoMode(512, 512), "SFML works!", Style::Close | Style::Resize);
    RectangleShape player(Vector2f(100.0f, 100.0f));
    player.setOrigin(50.0f, 50.0f);
    player.setPosition(256.0f, 256.0f);
    Texture playerTexture;
    playerTexture.loadFromFile("C:/Users/Peeps/source/repos/SFML_app/SFML_app/colour_map.png");
    player.setTexture(&playerTexture);

    // Vector2u textureSize = playerTexture.getSize();
    // textureSize.x /= 10;
    // textureSize.y /= 10;

    // player.setTextureRect(IntRect(textureSize.x*9, textureSize.y*9, textureSize.x, textureSize.y));
    //BusPoint rear_wing;


    while (window.isOpen())
    {
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

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}