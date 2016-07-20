//merge sort
class solution_mergesort{
public:
    void mergesort(vector<int>& nums){
        mergesort(nums, 0, nums.size() - 1);
    }
private:
    void mergesort(vector<int>& nums, int start, int end){
        if (start < end){
            int mid = start + ((end - start) >> 1);
            mergesort(nums, start, mid);
            mergesort(nums, mid + 1, end);
            merge(nums, start, mid, end);
        }
    }
    void merge(vector<int>& nums, int start, int mid, int end){
        vector<int> tmp(end - start + 1, 0);
        int i = start, j = mid + 1, m = mid, n = end;
        int k = 0;
        while (i <= m && j <= n){
            if (nums[i] < nums[j]){
                tmp[k++] = nums[i++];
            }
            else{
                tmp[k++] = nums[j++];
            }
        }
        while (i <= m){
            tmp[k++] = nums[i++];
        }
        while (j <= n){
            tmp[k++] = nums[j++];
        }
        for (int i = start; i <= end; ++i){
            nums[i] = tmp[i - start];
        }
    }
};
