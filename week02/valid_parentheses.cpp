class Solution {
   public:
    // TC: O(N)
    // MC: O(N) N = Size of the input string

    bool isMatched(char c1, char c2) {
        bool isRoundMatched = (c1 == '(' && c2 == ')');
        bool isCurlyMatched = (c1 == '{' && c2 == '}');
        bool isBoxMatched = (c1 == '[' && c2 == ']');

        return isRoundMatched || isCurlyMatched || isBoxMatched;
    }

    bool isValid(string s) {
        stack<char> parentheses;

        for (auto i : s) {
            if (i == '(' || i == '{' || i == '[') {
                parentheses.push(i);
            } else if (!parentheses.empty()) {
                char top = parentheses.top();

                if (isMatched(top, i)) {
                    parentheses.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        if (parentheses.empty()) return true;

        return false;
    }
};
