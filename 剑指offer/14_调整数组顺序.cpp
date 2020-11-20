void reorderOddEven(vector<int>& nums){
    int left = 0;
    int right = nums.size() - 1;
    while (left < right){
        while (left < right && !(nums[left] & 1)) ++left;
        while (left < right && (nums[right] & 1)) --right;
        if (left < right) std::swap(nums[left++], nums[right--]);
    }
}

void reorder(vector<int>& nums, bool (*f)(int)){

}
void reorderOddEven(vector<int>& nums){

}
