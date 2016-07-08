unsigned fib(unsigned n){
	unsigned f_1 = 0;
	unsigned f = 1;
	for (int i = 1; i <= n; ++i){
		f += f_1;
		f_1 = f - f_1;
	}
	return f_1;
}

unsigned fib2(unsigned n, int k){
	if (n <= 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	vector<int> record(n + 1, 0);
	record[0] = 0;
	record[1] = 1;
	record[2] = 2;
	for (int i = 3; i <= n; ++i){
		for (int j = 1; j <= std::min(i, k); ++j){
			record[i] += record[i - j];
		}
	}
	return record[n];
}
