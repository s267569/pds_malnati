#include <iostream>
#include <thread>
#include <future>

template <class F>
class MyPackagedTask{
    F _f;
    using R = decltype(_f());
    std::promise<R> *p;
public:
    MyPackagedTask & operator=(MyPackagedTask &&pt){
        if (this != &pt){
            delete this->p;
            this->_f= std::move(pt._f);
            this->p = pt.p;
            pt.p = nullptr;
        }
        return *this;
    }

    MyPackagedTask(F && fun): _f(fun){
        p = new std::promise<R>();
    }

    std::future<R> get_future(){
        std::future<R> f = p->get_future();
        return f;
    }
    void operator() (){
        R result = _f();
        p->set_value(std::move(result));
    }
    void reset(){
        delete p;
        p = new std::promise<R>();
    }

    ~MyPackagedTask(){
        delete p;
    }

};

int main() {
    auto add = [](int a, int b){return a+b;};
    MyPackagedTask pt1(std::bind(add, 2, 3));
    std::future f = pt1.get_future();
    std::thread t([&pt1](){
        pt1();
    });
    t.detach();
    std::cout <<"res: "<<f.get() << std::endl;
    pt1.reset();


    std::future f2 = pt1.get_future();
    std::thread t2([&pt1](){
        pt1();
    });
    t2.detach();
    std::cout <<"res: "<<f2.get() << std::endl;
    return 0;
}
