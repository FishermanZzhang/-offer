#include <stack>
#include <assert.h>
using std::stack;

template<typename T>
class myqueue{
    public:
        myqueue();
        ~myqueue();
        void push(const T& t);
        void pop();
        T& front();
        T& back();
        size_t size();
        bool empty();
    private:
        std::stack<T> stack1;
        std::stack<T> stack2;
        T back_;
};

template<typename T>
myqueue<T>::myqueue(){}

template<typename T>
myqueue<T>::~myqueue(){};

template<typename T>
void myqueue<T>::push(const T& t){
    stack1.push(t);
}

template<typename T>
void myqueue<T>::pop(){
    if (stack2.empty()){
        assert(!stack1.empty());
        back_ = stack1.top();
        while (!stack1.empty()){
            T tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
    }
    assert(!stack2.empty());
    stack2.pop();
}

template<typename T>
T& myqueue<T>::front(){
    if (stack2.empty()){
        assert(!stack1.empty());
        back_ = stack1.top();
        while (!stack1.empty()){
            T tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
    }
    return stack2.top();
}
template<typename T>
T& myqueue<T>::back(){
    if (!stack1.empty())
        return stack1.top();
    return back_;
}

template<typename T>
size_t myqueue<T>::size(){
    return stack1.size() + stack2.size();
}

template<typename T>
bool myqueue<T>::empty(){
    return size() == 0;
}
