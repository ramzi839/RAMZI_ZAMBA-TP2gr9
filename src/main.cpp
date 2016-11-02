#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


#include "state.hpp"
#include "render.h"




using namespace render;




int main()
{
    
    Scene scene;
    scene.update();


    return 0;
}