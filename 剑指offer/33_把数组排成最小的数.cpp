struct cmp{
    bool operator()(int a, int b){
        string stra = to_string(a);
        string strb = to_string(b);
        return stra + strb < strb + stra;
    }
};

class solution33{
    public:
        void printMinNumber(vector<int>& nums){
            sort(nums.begin(), nums.end(), cmp());
            string res = "";
            for (auto n : nums){
                res += to_string(n);
            }
            cout << res;
        }
};
