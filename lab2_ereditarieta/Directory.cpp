#include "Directory.h"

Directory* Directory::root;

int Base::level=0;

Directory::Directory(std::string name): Base(name){}

Directory::~Directory() noexcept{
    this->parent = nullptr;
    this->self = nullptr;
    for (auto child_:children){
        Base* child = child_.second;
        delete child;
    }
    children.clear();
}

bool Directory::removeRoot(){
    if (root != nullptr) {
        delete root;
        return true;
    }
    return false;
}

Directory* Directory::getRoot(){
    if(root == nullptr) {
        root = new Directory("/");
        root->self = root;
        root->parent = nullptr;
    }
    return root;
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
File* Directory::addFile(const std::string & name, uintmax_t size, uintmax_t data){
    auto _iter_child = children.find(name);
    if (_iter_child != children.end()){
        return nullptr;
    }
    File* child = new File(name, size, data);
    children.insert(std::pair<std::string, Base*> (name, child));
    return child;
}
Base* Directory::get(const std::string & name){
    if (name == ".."){
        return parent; //per essere ancora più precisi: static_cast<Base*>( parent)
    }
    auto _iter_child = children.find(name);
    if(_iter_child == children.end()){
        return nullptr;
    }
    return _iter_child->second;
}
Directory* Directory::getDirectory(const std::string & name){
    Base* child = this->get(name);
    if (child == nullptr) return nullptr;
    if (child->mType() == 1) return nullptr;
    else return dynamic_cast<Directory *>(child);
}
File* Directory::getFile(const std::string & name){
    Base* child = this->get(name);
    if (child == nullptr) return nullptr;
    if (child->mType() == 0) return nullptr;
    else return dynamic_cast<File *>(child); //qui abbiamo la certezza che sia file (xk usiamo mType), possiamo evitare il dynamic_cast ma usare static_cast che è più efficiente
}
bool Directory::remove(const std::string & name){
    auto _iter_child = children.find(name);
    if (name == ".." || name == ".") return false;
    if (_iter_child == children.end()) return false;
    auto it = children.erase(_iter_child);
    delete it->second; //xk noi rimuoviamo prima solo l'oggetto dalla mappa, ma ora dobbiamo rimuovere dalla memoria
    return true;
}
bool Directory::move(const std::string &name, Directory* target){
    Directory* child = this->getDirectory(name);
    if (child == nullptr) return false;
    if(target == nullptr) return false;

    child->parent = target;

    auto  _iter_child = children.find(name);
    children.erase(_iter_child);

    target->children.insert(std::pair<std::string, Base*>(name, child)); //_iter_child->second sarebbe stato leggermente sbagliato
                                                        //perché la modifica la funzione erase
    return true;
}
int Directory::mType() const {
    return 0;
}
void Directory::ls(int indent) const {
    for(int i=0; i<indent*Base::level; i++){
        std::cout << " ";
    }
    std::cout << this->getName();
    Base::level++;
    for (auto child = children.begin(); child != children.end(); ++child){
        child->second->ls(indent);
    }
    Base::level--;
}