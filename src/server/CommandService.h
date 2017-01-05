// Generated by dia2code
#ifndef SERVER__COMMANDSERVICE__H
#define SERVER__COMMANDSERVICE__H

#include <json/json.h>

namespace server {
  class AbstractService;
}

#include "HttpStatus.h"
#include "AbstractService.h"

namespace server {

  /// class CommandService - 
  class CommandService : public server::AbstractService {
    // Operations
  public:
    CommandService ();
    HttpStatus get (Json::Value& out, int id) const;
    HttpStatus put (Json::Value& out, const Json::Value& in) const;
    HttpStatus remove (int id );
  };

};

#endif