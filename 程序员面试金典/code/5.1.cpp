class Sulotion{
public:
	int updateBits(int n, int m, int i, int j){
		return (n >> (j + 1) << (j + 1)) + (m << i) + (n & ((1 << i) - 1));
	}
	int updateBits2(int n, int m, int i, int j){
		int max = ~0;
		int left = max - ((1 << j) - 1);
		int right = ((1 << i) - 1);
		int mask = left | right;
		return (n&mask) | (m << i);
	}
};
