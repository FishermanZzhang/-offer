int min(vector<int>& nums){
	int left = 0;
	int right = nums.size() - 1;
	while (left < right){
		int mid = left + (right - left) / 2;
		if (nums[mid] > nums[right]){
			left = mid + 1;
		}
		else{
			right = mid;
		}
	}
	return nums[left];
}

int min2(vector<int>& nums){
	int left = 0;
	int right = nums.size() - 1;
	auto linearsearch = [](vector<int>& nums, int left, int right){
		int mi = nums[left];
		for (; left <= right; ++left){
			mi = std::min(mi, nums[left]);
		}
		return mi;
	};
	while (left < right){
		int mid = left + (right - left) / 2;
		if (nums[left] == nums[mid] && nums[mid] == nums[right]){
			return linearsearch(nums, left, right);
		}
		if (nums[mid] > nums[right]){
			left = mid + 1;
		}
		else{
			right = mid;
		}
	}
	return nums[left];
}
