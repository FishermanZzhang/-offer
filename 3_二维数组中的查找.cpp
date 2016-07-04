class Solution{
    public:
        bool has(vector<vector<int>>& nums, int target){
            int rows = nums.size();
            if(rows <= 0) return false;
            int cols = nums[0].size();
            int c = cols - 1;
            int r = 0;
            while(c >= 0 && r < rows){
                if(nums[r][c] == target) return true;
                if(nums[r][c] > target) --c;
                else ++r;
            }
            return false;
        }
};
