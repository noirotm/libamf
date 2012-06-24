#include <amf/data.hpp>

#include "null.hpp"

using namespace amf;

data::data(): m_data_impl(new null_impl) {
    // default type is null
}

data::data(data_type t) {
    switch (t) {
    case TYPE_UNDEFINED:
    default: m_data_impl(new null_impl); break;
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

data::~data() {
    // the unique_pointer class automatically destroys the object
}
