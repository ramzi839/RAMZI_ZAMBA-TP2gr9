// Generated by dia2code
#ifndef STATE__OBSERVABLE__H
#define STATE__OBSERVABLE__H

#include <vector>

namespace state {
  class PlayerObserver;
}

#include "PlayerEvent.h"
#include "PlayerObserver.h"

namespace state {

  /// class Observable - 
  class Observable {
    // Associations
    // Attributes
  public:
    std::vector<state::PlayerObserver*> observers;
    // Operations
  public:
    void addObserver (PlayerObserver* );
    void removeObserver (PlayerObserver* );
    virtual void notifyObservers (state::PlayerEvent );
  };

};

#endif
