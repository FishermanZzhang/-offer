template <typename T>
class myqueue{
    public:
        myqueue(){
            si = 0;
        }
        ~myqueue(){
        }
        void push(T x){
            ++si;
            st1.push(x);
        }
        void pop(){
            assert(si > 0);
            --si;
            if (st2.empty()){
                while (!st1.empty()){
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            st2.pop();
        }
        T front(){
            if (!st2.empty()) return st2.top();
            while (!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            assert(!st2.empty());
            return st2.top();
        }
        size_t size(){
            return si;
        }
    private:
        stack<T> st1;
        stack<T> st2;
        size_t si;
};
