// Generated by dia2code
#ifndef ENGINE__ACTION__H
#define ENGINE__ACTION__H


namespace state {
  class State;
}

namespace engine {

  /// class Action - 
  class Action {
    // Operations
  public:
    virtual void apply (state::State * ) = 0;
  };

};

#endif