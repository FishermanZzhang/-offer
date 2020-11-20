//stack
template<typename T>
class mystack{
    public:
        mystack();
        ~mystack();
        T& top();
        void push(const T& t);
        void pop();
        size_t size();
        bool empty();
    private:
        queue<T> que1;
        queue<T> que2;
};
template<typename T>
mystack<T>::mystack(){}

template<typename T>
mystack<T>::~mystack(){}

template<typename T>
void mystack<T>::push(const T& t){
    if (!que2.empty()){
        que2.push(t);
    }
    else{
        que1.push(t);
    }
}

template<typename T>
void mystack<T>::pop(){
    queue<T>* quehave = &que1;
    queue<T>* queempty = &que2;
    if (!que2.empty()){
        quehave = &que2;
        queempty = &que1;
    }
    while (quehave->size() > 1){
        queempty->push(quehave->front());
        quehave->pop();
    }
    quehave->pop();
}

template<typename T>
T& mystack<T>::top(){
    if (!que2.empty()){
        return que2.back();
    }
    else{
        return que1.back();
    }
}

template<typename T>
size_t mystack<T>::size(){
    return que1.size() + que2.size();
}

template<typename T>
bool mystack<T>::empty(){
    return size() == 0;
}
