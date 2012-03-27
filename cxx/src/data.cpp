#include <amf/data.hpp>

#include "null_handler.hpp"

using namespace amf;

data::data(): handler_(new null_handler) {
    // default type is null
}

data::data(type t) {
    switch (t) {
    case TYPE_UNDEFINED:
    default: handler_(new null_handler); break;
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

type data::getType() const {
    return handler_->getType();
}

data::~data() {
}
