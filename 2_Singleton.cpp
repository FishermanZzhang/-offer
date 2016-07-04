//m1 恶汉
class Singleton{
    public:
        static Singleton* getSingleton();
    private:
        Singleton(){}
    private:
        static Singleton* sing_;
};
Singleton* Singleton:: sing_ = new Singleton();

// m2 恶汉
class Singleton{
    public:
        static Singleton* getSingleton(){
            return &sing_;
        }
    private:
        Singleton(){}
    private:
        static Singleton sing_;

};
Singleton Singleton::sing_;

// m3 懒汉
class Singleton{
    public:
        static Singleton* get(){
            if (sing_ == NULL){
                sing_ = new Singleton;
            }
            return sing_;
        }
    private:
        Singleton(){}
    private:
        static Singleton* sing_ ;

};
Singleton* Singleton::sing_ = NULL;
