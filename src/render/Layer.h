// Generated by dia2code
#ifndef RENDER__LAYER__H
#define RENDER__LAYER__H

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/Window.hpp"
#include <string>

namespace state {
  class Player;
  class PlayerObserver;
}

#include "state/PlayerEvent.h"
#include "state/PlayerObserver.h"

namespace render {

  /// class Layer - 
  class Layer : public state::PlayerObserver, public sf::Transformable, public sf::Drawable {
    // Attributes
  public:
    sf::Texture texture;
    sf::Sprite sprite;
    state::Player* player;
    std::string name;
    sf::RectangleShape rect_health;
    // Operations
  public:
    Layer ();
    Layer (state::Player* );
    void update (state::PlayerEvent );
    void draw (sf::RenderTarget& , sf::RenderStates ) const;
    void setTexture ();
    void setSprite ();
  };

};

#endif
