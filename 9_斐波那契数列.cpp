unsigned fib(unsigned n){
	unsigned f_1 = 0;
	unsigned f = 1;
	for (int i = 1; i <= n; ++i){
		f += f_1;
		f_1 = f - f_1;
	}
	return f_1;
}
