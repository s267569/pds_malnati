#include <iostream>
#include "lib.h"
#include <memory>

using namespace std;


class Object {

    string name;
public:
    Object():name("noname"){
        cout<<"obj created "<<name<<endl;
    }

    Object(const string &name):name(name){
        cout<<"obj created "<<name<<endl;
    }

    void doSomething() {
        cout<<"gotcha"<<endl;
    }

    ~Object() {
        cout<<"obj deleted "<<name<<endl;
    }

};

class DeallocationProblem {

    shared_ptr<DeallocationProblem> self;

public:
    DeallocationProblem(){
        self = shared_ptr<DeallocationProblem>(this);
        cout<<"obj created"<<endl;
    }

    ~DeallocationProblem(){
        cout<<"ref delete"<<endl;
    }

    void ref() {
        cout << "ref " << self.use_count() << endl;
    }
};

class MyWeakRef {

    weak_ptr<MyWeakRef> self;

    MyWeakRef(){};

public:

    static shared_ptr<MyWeakRef> makeMyWeakRef(){
        shared_ptr<MyWeakRef> obj(new MyWeakRef());
        obj->self = obj; // copy
        return obj;
    }

    void ref() {
        cout<<"ref "<<this->self.use_count()<<endl;
    }

    ~MyWeakRef(){
        cout<<"deleted"<<endl;
    }
};

unique_ptr<Object> unique_sample(){
    unique_ptr<Object> o1(new Object());
    // unique_ptr<Object> o2(o1); illegal!!!
    return o1;
}

shared_ptr<Object> shared_sample(){
    shared_ptr<Object> sp1 = make_shared<Object>("s1 object");
    shared_ptr<Object> sp2 = sp1;
    cout<<"use count: "<<sp1.use_count()<<endl;
    sp1->doSomething();
    sp2->doSomething();
    return sp2;
}

void weak_example(shared_ptr<Object> so) {
    cout<<"[ex 1] use count  : "<<so.use_count()<<endl;
    weak_ptr<Object> wp = so;
    cout<<"[ex 2] use count (weak): "<<wp.use_count()<<endl;
    so->doSomething();

    shared_ptr<Object> so2 = wp.lock();
    cout<<"[ex 3] use count (after lock): "<<wp.use_count()<<endl;

}

int main() {

    //unique_ptr<Object> up = unique_sample();
    //up->doSomething();

    shared_ptr<Object> so = shared_sample();
    cout<<"[main 1] use count: "<<so.use_count()<<endl;

    weak_example(so);
    cout<<"[main 2] use count: "<<so.use_count()<<endl;

    //DeallocationProblem t;
    //t.ref();

    //shared_ptr<MyWeakRef> wr = MyWeakRef::makeMyWeakRef();
    //wr->ref();


}
