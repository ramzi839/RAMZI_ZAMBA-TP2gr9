#include "CommandService.hpp"

using namespace std;

namespace server {
    CommandService::CommandService () : AbstractService("/command") {}
    HttpStatus CommandService::get (Json::Value& out, int id) const {
    out["command"] = "";
    return HttpStatus::OK;
    }
    HttpStatus CommandService::put (Json::Value& out, const Json::Value& in) const {}
    HttpStatus CommandService::remove (int id ) {}
}