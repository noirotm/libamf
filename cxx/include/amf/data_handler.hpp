#ifndef __DATA_HANDLER_HPP__
#define __DATA_HANDLER_HPP__

namespace amf {

/**
    AMF basic types
*/
enum type {
    TYPE_UNDEFINED,
    TYPE_NULL,
    TYPE_INTEGER,
    TYPE_BOOLEAN,
    TYPE_NUMBER,
    TYPE_STRING,
    TYPE_XML_DOCUMENT,
    TYPE_ARRAY,
    TYPE_OBJECT,
    TYPE_BYTE_ARRAY
};

/**
    This is the basis of all classes that need to handle
    the internals of AMF data.
*/
class data_handler {
protected:
    type type_;

public:
    data_handler(type t): type_(t) {}
    virtual ~data_handler() {}

    virtual type getType() {
        return type_;
    }
};

} // namespace amf

#endif //__DATA_HANDLER_HPP__
