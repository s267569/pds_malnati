//
// Created by Domenico Cefalo on 16/05/21.
/
#include "Directory.h"
#include <iostream>
#include <iomanip>

//Questo perché Base è la classe da cui eredito, quindi si usa mettere Base.
//Usiamo il costruttore di Base perché il nome è una var privata di Base
Directory::Directory(std::string name) : Base(name){}

Directory::Directory(const Directory& source) : Base(source.getName()){
    this->parent = source.parent;
    for(auto child:source.children) {
        std::shared_ptr<Base> base_child = child.second;
        if (base_child->mType() == 1){
            std::shared_ptr<File> file_child = dynamic_pointer_cast<File>(base_child);
            std::shared_ptr<File> dest_file_child = std::make_shared<File>(*file_child);
            std::shared_ptr<Base> dest_child = static_pointer_cast<Base>(dest_file_child);
            this->children.insert(std::pair<std::string, std::shared_ptr<Base>>(base_child->getName(), dest_child));
        } else {
            std::shared_ptr<Directory> dir_child = dynamic_pointer_cast<Directory>(base_child);
            std::shared_ptr<Directory> dest_dir_child = std::make_shared<Directory>(*dir_child);
            dest_dir_child->self = dest_dir_child;
            std::shared_ptr<Base> dest_child = static_pointer_cast<Base>(dest_dir_child);
            this->children.insert(std::pair<std::string, std::shared_ptr<Base>>(base_child->getName(), dest_child));
        }
    }
}

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
    if(it!= children.end()) return std::shared_ptr<File>(nullptr);

    std::shared_ptr<File> child = std::make_shared<File>(name, size, data);
    //dobbimo fare un cast
    std::shared_ptr<Base> base_child = static_pointer_cast<Base>(child);
    //aggiungiamo a questo punto nella mappa
    this->children.insert(std::pair<std::string, std::shared_ptr<Base>>(name, base_child));
    return child;
}

std::shared_ptr<Base> Directory::get(const std::string & name){
    if (name == "."){
        std::shared_ptr<Directory> s_self = self.lock(); //non c'è bisogno di controllare che sia scaduto xk ci sono io quindi sicuro c'è
        return static_pointer_cast<Base> (s_self);
    }
    if (name == "..") {
        std::shared_ptr<Directory> s_parent = parent.lock();
        return static_pointer_cast<Base> (s_parent);
    }
    auto it = children.find(name); //ricorda che con C++ puoi usare anche la funzione contains
    if(it!= children.end())
        return std::shared_ptr<Base>(nullptr);
    return it->second;
}
std::shared_ptr<Directory> Directory::getDirectory(const std::string & name){
    std::shared_ptr<Base> found = this->get(name);
    return dynamic_pointer_cast<Directory>(found);
}
std::shared_ptr<File> Directory::getFile(const std::string & name){
    if (name == "." || name == "..") return std::shared_ptr<File> (nullptr);

    std::shared_ptr<Base> found = this->get(name);
    return dynamic_pointer_cast<File>(found);
}
bool Directory::remove(const std::string & name){
    if(name == "." || name == "..") return false;
    auto it = children.find(name);
    if(it == children.end()) return false;
    children.erase(it);
    return true;
}
bool Directory::move(const std::string &name, std::shared_ptr<Directory> dest){
    if(name == "." || name == "..") return false;
    auto it = this->children.find(name);
    if(it == this->children.end()) return false;

    //il padre di mio figlio sarà destinazione
    std::shared_ptr<Base> base_child = it->second;
    if(base_child->mType()!=1){
        std::shared_ptr<Directory> child = static_pointer_cast<Directory>(base_child);
        child->parent = dest; //qui andrebbe bene anche usare dest->self, lui capisce lo stesso perché in questo caso dest è uno shared_ptr e va bene, se avessimo avuto un Directory* come prima allora avremmo dovuto mettere dest->self
    }
    dest->children.insert(std::pair<std::string, std::shared_ptr<Base>>(name, base_child));
    this->children.erase(it);
    return true;
}

bool Directory::copy(const std::string& name, std::shared_ptr<Directory> dest){
    if(name == "." || name == "..") return false;
    auto it = this->children.find(name);
    if(it == this->children.end()) return false;

    //il padre di mio figlio sarà destinazione
    std::shared_ptr<Base> base_child = it->second;
    if(base_child->mType()==1){
        std::shared_ptr<File> source_child = dynamic_pointer_cast<File>(base_child);
        //File* f = source_child.get(); //ritorna il puntatore nativo al tipo
        std::shared_ptr<File> dest_child = std::make_shared<File>(*source_child); //make_shared chiama sempre il costruttore di ciò che specifichiamo nella make_shared
        std::shared_ptr<Base> child = static_pointer_cast<Base>(dest_child);
        dest->children.insert(std::pair<std::string, std::shared_ptr<Base>>(name, child));
    } else {
        std::shared_ptr<Directory> source_child = dynamic_pointer_cast<Directory>(base_child);
        std::shared_ptr<Directory> dest_child = std::make_shared<Directory>(*source_child);
        dest_child->self = dest_child;
        dest_child->parent = dest;
        std::shared_ptr<Base> child = static_pointer_cast<Base>(dest_child);
        dest->children.insert(std::pair<std::string, std::shared_ptr<Base>>(name, child));
    }
}
void Directory::ls(int indent) const{

}