//
class solutions30{
public:
    vector<int> getLeastKNumbers(vector<int>& nums, int k){
        if (nums.size() <= k) return nums;
        int index = -1;
        int start = 0;
        int end = nums.size() - 1;
        while (index != k){
            if (index > k) end = index - 1;
            else start = index + 1;
            index = partition(nums, start, end);
        }
        vector<int> res(nums.begin(), nums.begin() + k);
        return res;
    }
private:
    int partition(vector<int>& nums, int left, int right){
        int t = nums[left];
        while (left < right){
            while (left < right && nums[right] > t) --right;
            if (left < right){
                std::swap(nums[left++], nums[right]);
            }
            while (left < right && nums[left] < t) ++left;
            if (left < right){
                std::swap(nums[left], nums[right--]);
            }
        }
        nums[left] = t;
        return left;
    }
};


class solutions30_2{
public:
    vector<int> getLeastKNumbers(vector<int>& nums, int k){
        if (nums.size() <= k) return nums;
        priority_queue<int, vector<int>, std::less<int>> heap;
        for (int i = 0; i < k; ++i){
            heap.push(nums[i]);
        }
        for (int i = k; i < nums.size(); ++i){
            int x = heap.top();
            if (x > nums[i]){
                heap.pop();
                heap.push(nums[i]);
            }
        }
        vector<int> res(k);
        for (int i = k - 1; i >= 0; --i){
            res[i] = heap.top();
            heap.pop();
        }
        return res;
    }
private:
};
