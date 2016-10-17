#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
<<<<<<< HEAD
=======

void testSFML() {
    sf::Texture texture;
}
>>>>>>> a56ed150aed3f1fc52392e7202436d73a613a0f3

// Fin test SFML

#include "state.hpp"

using namespace std;

int main()
{
<<<<<<< HEAD
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::RectangleShape background(sf::Vector2f(800,600));	
    sf::RectangleShape goku_image(sf::Vector2f(100,90));
    sf::Texture backgroundTexture[5];
    sf::Texture goku_pic;
    backgroundTexture[0].loadFromFile("../res/Background/Map0.png");
    backgroundTexture[1].loadFromFile("../res/Background/Map1.png");
    backgroundTexture[2].loadFromFile("../res/Background/Map2.png");
    backgroundTexture[3].loadFromFile("../res/Background/Map3.png");
    backgroundTexture[4].loadFromFile("../res/Background/Map4.png");
    int i=0;
    background.setTexture(&backgroundTexture[0]);
    window.setFramerateLimit(2);	
	goku_pic.loadFromFile("../res/Players/sangoku_profil.jpg");
	goku_image.setTexture(&goku_pic);
	//goku_pic.loadFromImage(&goku,rect=IntRect());
	
    // run the program as long as the window is open
    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
           
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        window.clear(sf::Color::Blue);
	if ( i<5) { background.setTexture(&backgroundTexture[i]); i++;}
	else i=0;

         window.draw(background);
         window.draw(goku_image);
		
        
        window.display();

    }

=======

    //cout << "It works !!!" << endl;
>>>>>>> a56ed150aed3f1fc52392e7202436d73a613a0f3
    return 0;
}
