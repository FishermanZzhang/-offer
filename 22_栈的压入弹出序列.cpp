bool isPopOrder(vector<int>& pPush, vector<int>& pPop){
	assert(pPush.size() == pPop.size());
	std::stack<int> st;
	st.push(INT_MIN);
	size_t i = 0;
	size_t j = 0;
	while (1){
		while (j < pPop.size() && st.top() == pPop[j]){
			st.pop();
			++j;
		}
		if (i < pPush.size())
			st.push(pPush[i++]);
		else
			break;
	}
	return st.size() == 1;
}
