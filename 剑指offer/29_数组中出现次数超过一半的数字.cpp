// m1
class solutionsmoreThanHalf{
public:
    int moreThanHalf(vector<int>& nums){
        int t = INT_MIN;
        int cnt = 1;
        for (auto num : nums){
            cnt += static_cast<int>(num == t) * 2 - 1;
            if (cnt <= 0){
                t = num;
                cnt = 1;
            }
        }
        if (!checkMoreThanHalf(nums, t)){
            t = INT_MIN;
        }
        return t;
    }
private:
    bool checkMoreThanHalf(vector<int>& nums, int t){
        size_t cnt = 0;
        for (auto num : nums){
            cnt += static_cast<size_t>(num == t);
        }
        return cnt >= nums.size() / 2;
    }
};

// m2
class solutions2{
public:
  int moreThanHalf(vector<int>& nums){
    int mid = (nums.size() >> 1) + (nums.size() & 1);
    int start = 0;
    int end = nums.size() - 1;
    int index = -1;
    while (index != mid){
        if (index > mid) end = index - 1;
        else start = index + 1;
        index = partion(nums, start, end);
    }
    int t = nums[mid];
    if (!checkMoreThanHalf(nums, t)){
        t = INT_MIN;
    }
    return t;
  }
private:
  int partion(vector<int>& nums, int start, int end){
    int t = nums[start];
    while (start < end){
      while (start < end && nums[end] > t) --end;
      if (start < end){
          std::swap(nums[start++], nums[end]);
      }
      while (start < end && nums[start] < t) ++start;
      if (start < end){
          std::swap(nums[start], nums[end--]);
      }
    }
    nums[start] = t;
    return start;
  }
  bool checkMoreThanHalf(vector<int>& nums, int t){
      size_t cnt = 0;
      for (auto num : nums){
          cnt += static_cast<size_t>(num == t);
      }
      return cnt >= nums.size() / 2;
  }
};



// extend 超过1/3 或者 1/4
