#ifndef __AMF_DATA_HPP__
#define __AMF_DATA_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <amf/data_handler.hpp>

namespace amf {

/**
    AMF data
*/
class data {
public:
    data();
    data(type t);
    data(bool);
    data(int);
    data(const std::string &);
    data(const char *);

    ~data();

    type getType() const;

private:
    std::unique_ptr<data_handler> handler_;
};


} // namespace amf

#endif //__AMF_DATA_HPP__
