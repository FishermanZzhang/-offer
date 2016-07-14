class solution41_1{
public:
    bool findNumbersWithSum(const vector<int>& nums, int sum, pair<int, int>& pp){
        int left = 0;
        int right = nums.size() - 1;
        while (left < right){
            int s = nums[left] + nums[right];
            if (s == sum){
                pp.first = nums[left];
                pp.second = nums[right];
                return true;
            }
            else if (s > sum){
                --right;
            }
            else{
                ++left;
            }
        }
        return false;
    }
};
