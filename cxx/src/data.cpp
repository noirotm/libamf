#include <amf/data.hpp>

#include "null.hpp"

using namespace amf;

data::data(): m_data_impl(new null_impl) {
    // default type is null
}

data::~data() {
    // the unique_pointer class automatically destroys the object
}

data::data(data_type t) {
    switch (t) {
    case TYPE_UNDEFINED:
    case TYPE_NULL:
    default: m_data_impl.reset(new null_impl); break;
    }
}

data::data(bool b) {
}

data::data(int i) {
}

data::data(const std::string & str) {
}

data::data(const char * buf) {
}

data_type data::type() const {
    return m_data_impl->type();
}

std::string data::as_string() const {
    return m_data_impl->as_string();
}

int data::as_int() const {
    return m_data_impl->as_int();
}

bool data::as_bool() const {
    return m_data_impl->as_bool();
}

double data::as_double() const {
    return m_data_impl->as_double();
}
