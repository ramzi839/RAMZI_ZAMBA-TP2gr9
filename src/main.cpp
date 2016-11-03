#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


#include "state.hpp"
#include "render.h"
#include "engine/Engine.h"


using namespace engine;




int main()
{
    Engine engine;
    
    engine.run();
    


    return 0;
}