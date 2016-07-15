class solution42_1{
public:
	void reverseSentence(string& str){
		reverse(str, 0, str.size() - 1);
		int start = 0;
		for (size_t i = 0; i < str.size(); ++i){
			if (str[i] == ' ' || i == str.size() - 1){
				reverse(str, start, i - 1);
				start = i + 1;
			}
		}
	}
private:
	void reverse(string& str, int start, int end){
		while (start < end){
			std::swap(str[start++], str[end--]);
		}
	}
};
