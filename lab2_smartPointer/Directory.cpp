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
