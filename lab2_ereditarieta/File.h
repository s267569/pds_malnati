//
// Created by Domenico Cefalo on 09/05/21.
//

#ifndef LAB2_EREDITARIETA_FILE_H
#define LAB2_EREDITARIETA_FILE_H
#include "Base.h"
class File : public Base{ //qualche esterno (anche il main) può vedere che ereditiamo da Base in modo
                            //pubblico e posso chiamare direttamente le funzioni
    uintmax_t size;
    uintmax_t date;
public:
    File(std::string name, uintmax_t size, uintmax_t date);
    uintmax_t getSize() const;
    uintmax_t getDate() const;
    int mType() const override;
    void ls(int indent) const override;

};


#endif //LAB2_EREDITARIETA_FILE_H
