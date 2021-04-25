#include <iostream>
#include <memory>

class Object{
    std::string name;
public:
    Object(): name("noname"){
        std::cout << "obj created " << std::endl;
    }
    Object(const std::string &name): name(name){
        std::cout << "obj created " << std::endl;
    }
    void doSomethig(){
        std::cout << "gotcha" << std::endl;
    }
    ~Object(){
        std::cout << "obj deleted " << std::endl;
    }
};

std::unique_ptr<Object> unique_sample(){
    std::unique_ptr<Object> o1(new Object()); //passiamo un puntatore ad Object
    //std::unique_ptr<Object> o2(o1); illegale!!!
    return o1;
}

std::shared_ptr<Object> shared_sample(){
    std::shared_ptr<Object> sp1 =std::make_shared<Object> ("s1 object");
    std::shared_ptr<Object> sp2 = sp1;
    std::cout << "use count: " << sp1.use_count() << std::endl;
    sp1->doSomethig();
    sp2->doSomethig();
    return sp2;

}

std::weak_ptr<Object> weak_example(){ //sono come smartPointer che si ottengono da essi attraverso copia

}

int main() {
    //Object* o = new Object("prova");

    //smart pointer è un oggetto che ci permette di gestire in maniera pulita il ciclo di vita di un puntatore
    //secondo delle regole definite

    //std::unique_ptr<Object> up = unique_sample();
    //up->doSomethig();

    //std::shared_ptr<Object> so = shared_sample();
    //std::cout << "[main 1] use count: " << so.use_count() << std::endl;

    weak_example(so);
    std::cout << "[main 2] use count: " << so.use_count() << std::endl;
    return 0;
}
