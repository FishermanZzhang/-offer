class solution38{
public:
    int getNumberOfK(vector<int>& nums, int k){
        int left = 0;
        int right = nums.size() - 1;
        int index1 = binary_search(nums, left, right, k + .5);
        int index2 = binary_search(nums, left, std::min(index1,right), k - .5);
        return index1 - index2;
    }
private:
    int binary_search(vector<int>& nums, int left, int right, float k){
        int mid = -1;
        while (left <= right){
            mid = left + ((right - left) >> 1);
            if (nums[mid] > k){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};
