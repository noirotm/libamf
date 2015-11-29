#ifndef __AMF_DATA_HPP__
#define __AMF_DATA_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <memory>

namespace amf {

/**
    AMF basic types
*/
enum data_type {
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
    This is the basis of all classes that represent
    the internal data types of AMF data.
*/
class data_impl {
protected:
    data_type m_type;

public:
    data_impl(data_type t): m_type(t) {}
    virtual ~data_impl() {}

    virtual data_type type() const {
        return m_type;
    }

    virtual std::string as_string() const = 0;
    virtual int as_int() const = 0;
    virtual bool as_bool() const = 0;
    virtual double as_double() const = 0;
};

/**
    AMF data
*/
class data {
private:
    std::unique_ptr<data_impl> m_data_impl;
public:
    data();
    ~data();
    
    data(data_type t);
    data(bool);
    data(int);
    data(const std::string &);
    data(const char *);

    data_type type() const;

    std::string as_string() const;
    int as_int() const;
    bool as_bool() const;
    double as_double() const;
};


} // namespace amf

#endif //__AMF_DATA_HPP__
