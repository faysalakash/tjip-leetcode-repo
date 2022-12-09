class Solution {
public:
  int singleNumber(vector<int>& nums) {
    // TC: O(N) N = nums size
    // MC: O(1)

    int ans = 0;

    for(auto i : nums) ans ^= i;

    return ans;
  }
};