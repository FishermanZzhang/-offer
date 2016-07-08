class quicksort{
	public:
		int partiton(vector<int>& nums, int start, int end){
			int t = nums[start];;
			while (start < end){
				while (start < end && nums[end] > t)
					--end;
				if (start < end){
					nums[start++] = nums[end];
				}
				while (start < end && nums[start] < t)
					++start;
				if (start < end)
					nums[end--] = nums[start];
			}
			nums[start] = t;
			return start;
		}
		void quicksort(vector<int>& nums, int start, int end){
			if (start < end){
				int poi = partiton(nums, start, end);
				quicksort(nums, start, poi - 1);
				quicksort(nums, poi + 1, end);
			}
		}
		void quicksort(vector<int>& nums){
			quicksort(nums, 0, nums.size() - 1);
		}
};
