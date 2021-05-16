//
// Created by Domenico Cefalo on 16/05/21.
//

#ifndef LAB2_SMARTPOINTER_FILE_H
#define LAB2_SMARTPOINTER_FILE_H
#include "Base.h"

class File : public Base{
    uintmax_t size;
    uintmax_t date;
public:
    File(std::string name, uintmax_t size, uintmax_t date);
    ~File() noexcept;
    uintmax_t getSize() const;
    uintmax_t getDate() const;
    int mType() const override;
    void ls(int indent) const override;

};

#endif //LAB2_SMARTPOINTER_FILE_H
