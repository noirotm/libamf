#ifndef __NULL_HANDLER_HPP__
#define __NULL_HANDLER_HPP__

#include <amf/data.hpp>

namespace amf {

class null_impl: public data_impl {
public:
    null_impl():data_impl(TYPE_NULL) {}
    virtual ~null_impl() {}

    virtual std::string as_string() const {
        return std::string("null");
    }

    virtual int as_int() const {
        return 0;
    }

    virtual bool as_bool() const {
        return false;
    }

    virtual double as_double() const {
        return 0.0;
    }
};

} // amf

#endif //__NULL_HANDLER_HPP__
