#ifndef __AMF_DATA_HPP__
#define __AMF_DATA_HPP__

#include <string>

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
    TYPE_XML_DOCUMENT
};

/**
    Base AMF data class
*/
class data {
public:
    type getType() const {
        return type_;
    }

    virtual ~data() {
    }

    virtual bool operator==(const data & rsh) const {
        return rsh.type_ == type_;
    }

    virtual bool operator!=(const data & rsh) const {
        return !(*this == rsh);
    }

protected:
    type type_;

    data(type t): type_(t) {
    }
};

/**
    Class representing an `undefined' AMF value
*/
class undefined: public data {
public:
    undefined(): data(TYPE_UNDEFINED) {
    }

};

/**
    Class representing a `null' AMF value
*/
class null: public data {
public:
    null(): data(TYPE_NULL) {
    }
};

/**
    Template class representing a simple native value
*/
template <typename T, type t>
class native_data: public data {
public:
    native_data(): data(t) {
    }

    native_data(T v): data(t), value_(v) {
    }

    operator T() const {
        return value_;
    }

    const native_data<T,t> & operator=(T v) {
        value_ = v;
        return *this;
    }

    virtual bool operator==(const data & rsh) const {
        return rsh.getType() == t
            && value_ == static_cast<const native_data<T,t>&>(rsh).value_;
    }

private:
    T value_;
};

/**
    Class representing a boolean value
*/
typedef native_data<bool, TYPE_BOOLEAN> boolean;

/**
    Class representing an integer value
*/
typedef native_data<int, TYPE_INTEGER> integer;

/**
    Class representing a double value
*/
typedef native_data<double, TYPE_NUMBER> number;

/**
    Class representing a string value
*/
typedef native_data<std::string, TYPE_STRING> string;
typedef native_data<std::string, TYPE_XML_DOCUMENT> xml_document;

}

#endif //__AMF_DATA_HPP__
