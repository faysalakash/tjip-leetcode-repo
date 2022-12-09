class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		// TC: O(N) N = nums size
		// MC: O(N)

		unordered_map<int, int> mp;

		for(int i = 0; i < nums.size(); i++){
			if(mp.count(nums[i]) == 1){
				return {mp.at(nums[i]), i};
			}

			mp[target - nums[i]] = i;
		}

		return {};
	}
};