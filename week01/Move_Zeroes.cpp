class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    // TC: O(N) N = nums size
    // MC: O(1)

    int firstZeroIndex = 0;

    for(int i = 0; i < nums.size(); i++){
      if(nums[i] != 0){
        swap(nums[firstZeroIndex], nums[i]);
        firstZeroIndex++;
      }
    }
  }
};