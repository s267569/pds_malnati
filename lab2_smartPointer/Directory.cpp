//
// Created by Domenico Cefalo on 16/05/21.
//

#include "Directory.h"
#include <iostream>
#include <iomanip>

//Questo perché Base è la classe da cui eredito, quindi si usa mettere Base.
//Usiamo il costruttore di Base perché il nome è una var privata di Base
Directory::Directory(std::string name) : Base(name){}

std::shared_ptr<Directory> Directory::getRoot(){
    if (root == nullptr){
        root = new Directory("/");
        std::shared_ptr<Directory> _shared_root_ = std::shared_ptr<Directory>(root);
        root->parent = std::shared_ptr<Directory>(nullptr); //oppure root->parent=nullptr;
        root->self = _shared_root_;
        return _shared_root_;
    }
    return root->self.lock();
}
std::shared_ptr<Directory> Directory::addDirectory(const std::string& name){
    if(name == "." || name == "..") return std::shared_ptr<Directory>(nullptr);
    auto it = children.find(name);
    if(it!= children.end())return std::shared_ptr<Directory>(nullptr);

    std::shared_ptr<Directory> child = std::make_shared<Directory>(name);
    child->parent = this->self; //dico a mio figlio che il padre sono io
    child->self = child;

    //dobbimo fare un cast
    std::shared_ptr<Base> base_child = static_pointer_cast<Base>(child);
    //aggiungiamo a questo punto nella mappa
    this->children.insert(std::pair<std::string, std::shared_ptr<Base>>(name, base_child));
    return child;
}

std::shared_ptr<File> Directory::addFile(const std::string & name, uintmax_t size, uintmax_t data){
    if(name == "." || name == "..") return std::shared_ptr<File>(nullptr);
    auto it = children.find(name);
    if(it!= children.end())return std::shared_ptr<File>(nullptr);

    std::shared_ptr<File> child = std::make_shared<File>(name, size, data);
    //dobbimo fare un cast
    std::shared_ptr<Base> base_child = static_pointer_cast<Base>(child);
    //aggiungiamo a questo punto nella mappa
    this->children.insert(std::pair<std::string, std::shared_ptr<Base>>(name, base_child));
    return child;
}

std::shared_ptr<Base> Directory::get(const std::string & name){

}
std::shared_ptr<Directory> Directory::getDirectory(const std::string & name){

}
std::shared_ptr<File> Directory::getFile(const std::string & name){

}
bool Directory::remove(const std::string & name){

}
bool Directory::move(const std::string &name, Directory* target){

}
int mType() const override;
void ls(int indent) const override;