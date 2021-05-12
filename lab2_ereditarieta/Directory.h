//
// Created by Domenico Cefalo on 09/05/21.
//

#ifndef LAB2_EREDITARIETA_DIRECTORY_H
#define LAB2_EREDITARIETA_DIRECTORY_H

#include "Base.h"
#include "File.h"
#include <map>

class Directory : public Base {
    static Directory* root;
    std::map<std::string, Base*> children;
    Directory* parent;
    Directory* self;
    Directory() = delete;
public:
    //explicit è semplicemente per marcare un costruttore che ha un solo parametro per rendere chiara la sintassi
    explicit Directory(std::string name);
    ~Directory() noexcept;
    static Directory* getRoot();
    static bool removeRoot();
    Directory* addDirectory(const std::string& name);
    File* addFile(const std::string & name, uintmax_t size, uintmax_t data);
    Base* get(const std::string & name);
    Directory* getDirectory(const std::string & name);
    File* getFile(const std::string & name);
    bool remove(const std::string & name);
    bool move(const std::string &name, Directory* target);
    int mType() const override;
    void ls(int indent) const override;
};
#endif //LAB2_EREDITARIETA_DIRECTORY_H
