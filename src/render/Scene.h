// Generated by dia2code
#ifndef RENDER__SCENE__H
#define RENDER__SCENE__H

#include <vector>

namespace render {
  class Layer;
};
namespace state {
  class StateObserver;
}

#include "state/StateEventId.h"
#include "state/StateObserver.h"
#include "Layer.h"

namespace render {

  /// class Scene - 
  class Scene : public state::StateObserver {
    // Associations
    // Attributes
  public:
    int width;
    int height;
    std::vector<Layer*> layers;
    // Operations
  public:
    Scene ();
    void stateChanged (state::StateEventId e);
    void setBackground ();
  };

};

#endif
