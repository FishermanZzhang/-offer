int numberOf1(int n){
	int cnt = 0;
	while (n){
		++cnt;
		n &= (n - 1);
	}
	return cnt;
}
int numberOf1_3(int n){
	int cnt = 0;
	for (int i = 0; i < 32; ++i){
		cnt += static_cast<int>((n &(1 << i)) != 0);
	}
	return cnt;
}
int numberOf1_2(int n){
	int cnt = 0;
	for (int i = 0; i < 32; ++i){
		cnt += n & 1;
		n >>= 1;
	}
	return cnt;
}
