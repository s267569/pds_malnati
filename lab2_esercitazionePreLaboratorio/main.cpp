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

class DeallocationProblem{
    std::shared_ptr<DeallocationProblem> self;
public:
    DeallocationProblem(){
        self = std::shared_ptr<DeallocationProblem>(this);
        std::cout << "obj created " << std::endl;
    }
    ~DeallocationProblem(){
        std::cout << "ref delete " << std::endl;
    }
    void ref(){
        std::cout << "ref " << self.use_count() << std::endl;
    }
};

class MyWeakRef{
    std::weak_ptr<MyWeakRef> self;

    MyWeakRef(){};
public:
    static std::shared_ptr<MyWeakRef> makeMyWeakRef(){
        std::shared_ptr<MyWeakRef> obj (new MyWeakRef());
        obj->self=obj; //copy
        return obj;
    }
    void ref(){
        std::cout << "ref " << this->self.use_count() << std::endl;
    }

    ~MyWeakRef(){
        std::cout << "deleted " << std::endl;
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

void weak_example(std::shared_ptr<Object> so){ //sono come smartPointer che si ottengono da essi attraverso copia
    std::cout << "[ex 1] use count: " << so.use_count() << std::endl;
    std::weak_ptr<Object> wp = so; //non mi incrementa lo use_count
    wp.expired(); //cerchiamo di capire se lo shared pointer a cui era associato non c'è più
    std::cout << "[ex 2] use count (weak): " << wp.use_count() << std::endl;
    so->doSomethig();

    std::shared_ptr<Object> so2 = wp.lock(); //lock crea lo shared pointer a partire dal weak se è ancora valido e incrementa use_count
    std::cout << "[ex 3] use count (after lock): " << wp.use_count() << std::endl;
}

int main() {
    //Object* o = new Object("prova");
    //delete o;


    //smart pointer è un oggetto che ci permette di gestire in maniera pulita il ciclo di vita di un puntatore
    //secondo delle regole definite

    //std::unique_ptr<Object> up = unique_sample();
    //up->doSomethig();

    //std::shared_ptr<Object> so = shared_sample();
    //std::cout << "[main 1] use count: " << so.use_count() << std::endl;

    //weak_example(so);
    //std::cout << "[main 2] use count: " << so.use_count() << std::endl;

    //Se ho bisogno di un riferimento a me stesso e metterlo dentro lo shared pointer
    //DeallocationProblem t;
    //t.ref();

    //Si usa questo trucco
    std::shared_ptr<MyWeakRef> wr = MyWeakRef::makeMyWeakRef();
    wr->ref();

    return 0;
}
