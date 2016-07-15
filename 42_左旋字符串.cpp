class solution42_2{
public:
	void leftRotateString(string& str, unsigned n){
		n %= str.size();
		std::reverse(str.begin(), str.begin() + n);
		std::reverse(str.begin() + n, str.end());
		std::reverse(str.begin(), str.end());
	}
private:
};
