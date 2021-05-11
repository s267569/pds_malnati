//
// Created by Domenico Cefalo on 09/05/21.
//
#include "File.h"


File::File(std::string name, uintmax_t size, uintmax_t date) :Base(name),  size(size), date(date){}
uintmax_t File::getSize() const{
    return size;
}
uintmax_t File::getDate() const{
    return date;
}
int File::mType() const const{
    return 1;
}
void File::ls(int indent) const{
    for(int i=0; i<indent; i++){
        std::cout << " ";
    }
    std::cout << this->getName();
}