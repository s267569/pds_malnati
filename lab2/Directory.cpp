//
// Created by Domenico Cefalo on 25/04/21.
//

#include "Directory.h"

Directory* Directory::root;
int Directory::livello = 0;

Directory::Directory(std::string name){
    this->name = name;
    this->figli = new Directory*[10];
}

Directory* Directory::getRoot(){
    if(root == nullptr)
        root = new Directory("/");
    return root;
}

Directory* Directory::addDirectory(const std::string& name){
    int i;
    for(i=0; i<10; i++){
        if (this->figli[i] == nullptr){
            this->figli[i] = new Directory(name);
            this->figli[i]->padre = this;
            break;
        }
    }
    return this->figli[i];
}
Directory* Directory::get(const std::string& name){
    if (name == ".."){
        return this->padre;
    }
    for (int i=0; i<10; i++){
        if(this->figli[i]->name == name)
            return this->figli[i];
    }
    return nullptr;
}

bool Directory::remove(const std::string& name){
    if (name == ".." || name == "."){
        return false;
    }
    for (int i=0; i<10; i++){
        if(this->figli[i]->name == name){
            delete this->figli[i];
            this->figli[i] = nullptr; //ATTENZIONE
            return true;
        }
    }
    return false;
}

bool Directory::move(const std::string &name, Directory* target){
    bool flag=false;
    for (int i=0; i<10; i++){
        if(this->figli[i]->name == name){
            for (int j=0; j<10; j++){
                if(target->figli[j] == nullptr){
                    this->figli[i]->padre = target; //il padre di mio figlio ora è TARGET
                    target->figli[j] = this->figli[i]; //mio figlio ora è il figlio di TARGET
                    this->figli[i] = nullptr; //non una delete, perché lo ammazzerei del tutto
                    flag = true;
                    return  true;
                }
            }
            if (flag == false)
                return false;
        }
    }
    return false;
}

Directory& Directory::operator=(const Directory& source){
    if(this!=&source){
        this->name = source.name;
        padre = source.padre;
        for (int i=0; i<10; i++){
            delete this->figli[i];
            this->figli[i] = nullptr;
        }
        for (int i=0; i<10; i++){
            if (source.figli[i] != nullptr){
                this->figli[i] = new Directory(*(source.figli[i]));
            }
        }

    }
    return *this;
}
Directory::Directory(const Directory& source){
    this->name = source.name;
    this->padre = source.padre;
    this->figli = new Directory*[10];
    for(int i=0; i<10; i++){
        this->figli[i] = new Directory(*(source.figli[i]));
    }
}

bool Directory::copy(const std::string& name, Directory* target){
    bool flag=false;
    for (int i=0; i<10; i++){
        if(this->figli[i]->name == name){
            for (int j=0; j<10; j++){
                if(target->figli[j] == nullptr){
                    target->figli[j] = new Directory(*(this->figli[i]));
                    flag = true;
                    return  true;
                }
            }
            if (flag == false)
                return false;
        }
    }
    return false;
}

void Directory::ls(int indenet){
    for (int j = 0; j < indenet*livello; j++) {
        std::cout << " ";
    }
    std::cout << this->name << std::endl;
    for (int i=0; i<10; i++){
        if (this->figli[i]!= nullptr) {
            livello++;
            this->figli[i]->ls(indenet);
            livello--;
        }
    }

}