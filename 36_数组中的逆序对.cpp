//hard
//
class solution_36{
    public:
        int inversePairs(vector<int>& nums){
            return mergesort(nums, 0, nums.size() - 1);
        }
    private:
        int mergesort(vector<int>& nums, int start, int end){
            if (start < end){
                int mid = start + ((end - start) >> 1);
                int c1 = mergesort(nums, start, mid);
                int c2 = mergesort(nums, mid + 1, end);
                int c3 = merge(nums, start, mid, end);
                return c1 + c2 + c3;
            }
            return 0;
        }
        int merge(vector<int>& nums, int start, int mid, int end){
            int cnt = 0;
            vector<int> tmp(end - start + 1, 0);
            int i = start, j = mid + 1, m = mid, n = end;
            int k = 0;
            while (i <= m && j <= n){
                if (nums[j] < nums[i]){
                    cnt += mid - i + 1;
                    tmp[k++] = nums[j++];
                }
                else{
                    tmp[k++] = nums[i++];
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
            return cnt;
        }
};
