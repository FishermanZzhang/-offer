class Solution{
public:
	int fib(int n){
		int f_1 = 1;
		int f = 1;
		if (n <= 2) return 1;
		for (int i = 3; i <= n; ++i){
			f = f + f_1;
			f_1 = f - f_1;
		}
		return f;
	}
};
