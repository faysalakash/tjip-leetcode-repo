class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // TC: O(m+n)
    // MC: O(1)

    int i1 = m - 1;
    int i2 = n - 1;

    while(i1 >= 0 && i2 >= 0){
      int ix = i1 + i2 + 1;

      if(nums1[i1] >= nums2[i2]){
        nums1[ix] = nums1[i1--];
      }else{
        nums1[ix] = nums2[i2--];
      }
    }

    while(i2 >= 0) {
      nums1[i2] = nums2[i2];
      i2--;
    }
  }
};