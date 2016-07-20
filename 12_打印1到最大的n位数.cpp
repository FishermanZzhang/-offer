// no idea
class solution12{
public:
	void print1ToMaxofNDigits(int n){
		string str(n, '\0');
		for (int i = 1; i <= n; ++i){
			gen(str, 0, i);
			//for (int j = 1; j < 10; ++j){
				//str[0] = '0' + j;
				//gen(str, 1, i);
			//}
		}
	}
	void gen(string& str, int pos,int n){
		if (pos == n){
			//cout << str;
			if (str[0] != '0'){
				cout << str << endl;
			}
			return;
		}
		for (int i = 0; i < 10; ++i){
			str[pos] = '0' + i;
			gen(str, pos + 1, n);
		}
	}
};
