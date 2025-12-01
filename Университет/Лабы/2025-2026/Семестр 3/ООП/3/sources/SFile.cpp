// author: Danila "akshin_" Axyonov

#include "SFile.hpp"
#include <fstream>
#include <string>
#include <stdexcept>

namespace Lab3
{


SFile::SFile(const std::string& filename) : fin_(filename) {
    if (not fin_.is_open())
        throw std::invalid_argument("File with name \"" + filename + "\" can't be opened.");
}

SFile::~SFile() {
    fin_.close();
}

int SFile::get() {
    int num;
    if (not (fin_ >> num))
        return EOF;
    return num;
}


}
