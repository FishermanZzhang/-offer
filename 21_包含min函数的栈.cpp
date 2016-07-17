template<typename T>
class minStack{
public:
	minStack() : min_(INT_MAX){
	}
	void push(const T& t){
		if (min_ > t){
			stack_.push(min_);
			min_ = t;
		}
		stack_.push(t);
	}
	const T& top() const{
		return stack_.top();
	}
	const T& min() const{
		return min_;
	}
	void pop(){
		if (min_ == stack_.top()){
			stack_.pop();
			min_ = stack_.top();			
		}
		stack_.pop();
	}
private:
	T min_;
	std::stack<T> stack_;
};
