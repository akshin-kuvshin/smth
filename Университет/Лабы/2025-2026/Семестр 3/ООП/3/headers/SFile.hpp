// author: Danila "akshin_" Axyonov

#ifndef SFILE__
#define SFILE__

#include "SBase.hpp"
#include <fstream>
#include <string>

namespace Lab3
{


class SFile : public SBase {
private:
    std::ifstream fin_;

public:
    SFile(const std::string& filename);
    SFile(const SFile& obj) = delete;
    ~SFile();
    void operator=(const SFile& obj) = delete;
    int get() override;
};


}

#endif
