#ifndef __NULL_HANDLER_HPP__
#define __NULL_HANDLER_HPP__

#include <amf/data_handler.hpp>

namespace amf {

class null_handler: public data_handler {
public:
    null_handler();
};

} // amf

#endif //__NULL_HANDLER_HPP__
