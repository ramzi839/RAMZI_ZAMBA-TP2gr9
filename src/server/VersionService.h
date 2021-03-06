// Generated by dia2code
#ifndef SERVER__VERSIONSERVICE__H
#define SERVER__VERSIONSERVICE__H

#include <json/json.h>

namespace server {
  class AbstractService;
}

#include "HttpStatus.h"
#include "AbstractService.h"

namespace server {

  /// class VersionService - 
  class VersionService : public server::AbstractService {
    // Operations
  public:
    VersionService ();
    HttpStatus  get (Json::Value& out, int id) const;
  };

};

#endif
