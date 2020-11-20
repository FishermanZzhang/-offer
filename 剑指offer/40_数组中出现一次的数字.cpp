class solution40{
    public:
        pair<int, int> findTheTwoNumberAppearOnce(vector<int>& nums){
            int tmp = 0;
            for (auto num : nums){
                tmp ^= num;
            }
            while (tmp & (tmp - 1)){
                tmp &= tmp - 1;
            }
            int x = 0, y = 0;
            for (auto num : nums){
                if (num & tmp){
                    x ^= num;
                }
                else{
                    y ^= num;
                }
            }
            return make_pair(x, y);
        }
};
