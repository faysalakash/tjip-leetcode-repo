class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    // TC: O(N^2) N = nums size
    // MC: O(N)

    vector< vector<int> > triplets;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){
      int a = nums[i];
      int target = -a;
      int L = i + 1;
      int R = nums.size() - 1;

      while(L < R){
        int b = nums[L];
        int c = nums[R];
        int currentSum = b + c;

        if(currentSum > target) R--;
        else if(currentSum < target) L++;
        else {
            while(L + 1 < R && nums[L + 1] == b) L++;
            while(R - 1 > L && nums[R - 1] == c) R--;
            triplets.push_back({a, b, c});
            L++;
            R--;
        }
      }

      while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
    }

    return triplets;
  }
};