class sulutionsearch{
    public:
        bool search(vector<vector<int>>& nums, int target){
            int N = nums.size();
            if (N <= 0) return false;
            int M = nums[0].size();
            if (M <= 0) return false;
            int n = 0, m = M - 1;
            while (n < N && m >= 0){
                if (nums[n][m] == target)
                    return true;
                if (nums[n][m] < target){
                    ++n;
                }
                else{
                    --m;
                }
            }
            return false;
        }
};
