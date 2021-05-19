//
// Created by Domenico Cefalo on 16/05/21.
//

#ifndef LAB2_SMARTPOINTER_DIRECTORY_H
#define LAB2_SMARTPOINTER_DIRECTORY_H
#include "Base.h"
#include "File.h"
#include <memory>
#include <map>

class Directory : public Base {
    static Directory* root;
    std::map<std::string, std::shared_ptr<Base>> children;
    std::weak_ptr<Directory> parent;
    std::weak_ptr<Directory> self;
    Directory() = delete;

public:
    //explicit è semplicemente per marcare un costruttore che ha un solo parametro per rendere chiara la sintassi
    explicit Directory(std::string name);
    ~Directory() noexcept;
    static std::shared_ptr<Directory> getRoot();
    std::shared_ptr<Directory> addDirectory(const std::string& name);
    std::shared_ptr<File> addFile(const std::string & name, uintmax_t size, uintmax_t data);
    std::shared_ptr<Base> get(const std::string & name);
    std::shared_ptr<Directory> getDirectory(const std::string & name);
    std::shared_ptr<File> getFile(const std::string & name);
    bool remove(const std::string & name);
    bool move(const std::string &name, std::shared_ptr<Directory> dest);
    bool copy(const std::string& nome, std::shared_ptr<Directory> dest);
    void ls(int indent) const override;
};
#endif //LAB2_SMARTPOINTER_DIRECTORY_H
