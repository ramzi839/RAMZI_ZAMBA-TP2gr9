// Generated by dia2code
#ifndef STATE__PLAYER__H
#define STATE__PLAYER__H

#include <string>
#include <vector>

namespace state {
  class Combo;
  class Health;
  class Element;
  class Gauge;
}

#include "Combo.h"
#include "Health.h"
#include "Side.h"
#include "PlayerStatus.h"
#include "Element.h"
#include "Gauge.h"

namespace state {

  /// class Player - 
  class Player : public state::Element {
    // Associations
    state::Side direction;
    // Attributes
  public:
    Combo combo;
  protected:
    std::string name;
    Health health;
    std::vector<std::string> listAttack;
    Side side;
    PlayerStatus status;
    // Operations
  public:
    Player (std::string name);
    ~Player ();
    PlayerStatus getStatus ();
    void setStatus (PlayerStatus s);
    void attack (std::string str);
    /// 						
    /// @param 		(???) 
    void defend ( );
    /// 	
    /// @param s		(???) 
    void setSide (Side s);
    Side getSide ();
    std::string getName ();
    /// 				
    /// @param s		(???) 
    void setName (std::string s);
    bool  isMoving ();
    bool isAttacking ();
    bool  isDefending ();
  };

};

#endif