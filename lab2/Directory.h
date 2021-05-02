//
// Created by Domenico Cefalo on 25/04/21.
//

#ifndef LAB2_DIRECTORY_H
#define LAB2_DIRECTORY_H
#include <string>
class Directory{
    std::string name;
    Directory* padre;
    Directory** figli;
private:
    static Directory* root;
public:
    Directory(std::string name);
    static Directory* getRoot();
    Directory* addDirectory(const std::string& name);
    Directory* get(const std::string& name);
    bool remove(const std::string& name);
    bool move(const std::string &name, Directory* target);
    bool copy(const std::string& name, Directory* target);
    void ls(int indenet);
};

#endif //LAB2_DIRECTORY_H
