//
// Created by Domenico Cefalo on 16/05/21.
//

#include "Directory.h"
#include <iostream>
#include <iomanip>

Directory* Directory::root;

Directory* Directory::getRoot() {
    if (root == nullptr)
        root = new Directory("/", nullptr);
    return root;
}

Directory::Directory(std::string name, Directory* father):Base(name),father(father),self(this) {
    std::cout << "constructor @" << this << std::endl;
}

Directory* Directory::addDirectory(const std::string& name) {
    return children.count(name) == 0 ?
           children.emplace(std::make_pair(name, new Directory(name, this))).first->second :
           children.find(name)->second;
}

Directory* Directory::get(const std::string& name) {
    return name == "." ? this->self :
           (name == ".." && getName() != "/") ? this->father :
           children.count(name) == 1 ? children.find(name)->second : nullptr;
}

bool Directory::remove(const std::string& name) {
    if (children.count(name) == 1) {
        auto it = children.find(name);
        delete it->second;
        children.erase(it);
        return true;
    }
    return false;
}

bool Directory::move(const std::string& name, Directory* target) {
    if (children.count(name) == 1) {
        Directory* tmp = children.find(name)->second;
        if (target->children.count(name) == 0) {
            tmp->father = target;
            target->children.insert(std::make_pair(name, tmp));
            //children.find(name)->second = nullptr;
            children.erase(name); // remove entry containing pointer to target
            return true;
        }

    }
    return false;
}

bool Directory::copy(const std::string& name, Directory* target) {
    if (children.count(name) == 1) {
        Directory* source = children.find(name)->second;
        if (target->children.count(name) == 0) {
            Directory* tmp = new Directory(name, target);
            for (auto it = source->children.cbegin(); it != source->children.cend(); ++it)
                tmp->children.insert(std::make_pair(it->first, it->second));
            target->children.insert(std::make_pair(name, tmp));
            return true;
        }
    }
    return false;
}

int Directory::mType() const {
    return 0;
}


void Directory::ls(int indent) const {
    std::cout << (getName()!="/"?std::string(indent,' '):"") <<"[+] " <<  getName() << std::endl;
    for (auto it = children.cbegin(); it != children.cend(); ++it)
        it->second->ls(indent*2);

}

Directory::~Directory() {
    std::cout << "destructor @" << this << std::endl;
    for (auto it = children.begin(); it != children.end(); ++it) {
        delete it->second;
    }
}
