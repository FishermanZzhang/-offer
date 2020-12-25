class Sulotion{
public:
	int bitSwapRequired(int a, int b){
		int x = a^ b;
		int c = 0;
		while (x){
			++c;
			x &=(x - 1);
		}
		return c;
	}
	int bitSwapRequired2(int a, int b){
		int c = 0;
		for (int cc = a ^ b; cc != 0; cc = cc >> 1){
			c += cc & 1;
		}
		return c;
	}
};
