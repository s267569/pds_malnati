#include "Directory.h"

Directory* Directory::root;

Directory::Directory(std::string name): Base(name){}

Directory* Directory::getRoot(){
    if(root == nullptr) {
        root = new Directory("/");
        root->self = root;
        root->parent = nullptr;
    }

}
Directory* Directory::addDirectory(const std::string& name){
    Base* child;
    auto _iter_child = children.find(name);
    if(_iter_child != children.end()){
        child = _iter_child ->second;
        if (child->mType() == 1) { //1 è file
            return nullptr;
        } else {
            return dynamic_cast<Directory*> (child);
        }
    } else{
        child = new Directory(name);
        Directory* child = dynamic_cast<Directory*>(child);
        this->children.insert(std::pair<std::string, Base*>(name, child));
        child->parent = this;
        child->self = child;
        return child;
    }
}
File* addFile(const std::string & name, uintmax_t size, uintmax_t data);
Base* get(const std::string & name);
Directory* getDirectory(const std::string & name);
File* getFile(const std::string & name);
bool remove(const std::string & name);
bool move(const std::string name);
int mType() const override;
void ls(int indent) const override;

#include "Directory.h"
