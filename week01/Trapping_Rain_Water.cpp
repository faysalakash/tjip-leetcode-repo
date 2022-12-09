class Solution {
public:
  int trap(vector<int>& height) {
    // TC: O(N) N = height size
    // MC: O(1)

    int L = 0, R = height.size() - 1;
    int L_Max = 0, R_Max = 0;

    int totalTrappedWater = 0;

    while(L < R){
      L_Max = max(L_Max, height[L]);
      R_Max = max(R_Max, height[R]);

      if(height[L] < height[R]){
        totalTrappedWater += L_Max - height[L];
        L++;
      }else{
        totalTrappedWater += R_Max - height[R];
        R--;
      }
    }

    return totalTrappedWater;
  }
};