class Solution {
   public:
    // TC: O(N) N = |s|
    // MC: O(1), As we're using a vector of constant size only

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> v(26, 0);  // For unicode characters we can maintain an unordered_map

        for (auto i : s) {
            v[i - 'a']++;
        }

        for (auto i : t) {
            v[i - 'a']--;
        }

        for (auto i : v) {
            if (i != 0) return false;
        }

        return true;
    }
};