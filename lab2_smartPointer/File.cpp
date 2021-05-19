//
// Created by Domenico Cefalo on 16/05/21.
//
#include "File.h"


File::File(std::string name, uintmax_t size, uintmax_t date) :Base(name),  size(size), date(date){}

File::File(const File& source): Base(source.getName()){
    this->date = source.date;
    this->size = source.size;
}

File::File(File&& source): Base(source.getName()){
    this->date = source.date;
    this->size = source.size;
}

File::~File() noexcept{};

uintmax_t File::getSize() const{
    return size;
}
uintmax_t File::getDate() const{
    return date;
}
int File::mType() const {
    return 1;
}
void File::ls(int indent) const{
    for(int i=0; i<indent*Base::level; i++){
        std::cout << " ";
    }
    std::cout << this->getName();
}
