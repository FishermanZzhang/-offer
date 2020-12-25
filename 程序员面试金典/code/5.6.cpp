class Solution{
public:
	int swapOddEvenBits(int x){
		int b = 0x55555555;
		return ((x >> 1) & b) | ((x << 1) &(b << 1));
	}
};
