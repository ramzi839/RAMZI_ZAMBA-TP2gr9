// Generated by dia2code
#ifndef SERVER__SERVICEEXCEPTION__H
#define SERVER__SERVICEEXCEPTION__H

#include <string>

namespace server {
  class AbstractService;
}

#include "HttpStatus.h"
#include "AbstractService.h"

namespace server {

  /// class ServiceException - 
  class ServiceException {
    // Associations
    server::HttpStatus httpStatus;
    // Attributes
  public:
    std::string msg;
    // Operations
  public:
    ServiceException (HttpStatus status, std::string msg);
    HttpStatus status () const;
    const char* what () const;
  };

};

#endif
