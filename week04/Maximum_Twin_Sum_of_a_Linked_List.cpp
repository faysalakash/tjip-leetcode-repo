// TC = O(N), N = Number of elements in the list
// MC = O(1)

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        auto curr = head;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    int pairSum(ListNode* head) {
        auto leftList = head;
        auto slow = head;
        auto fast = head;

        while (fast) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto rightList = reverseList(slow);
        auto copyRightList = rightList;
        int maxTwinSum = INT_MIN;

        while (leftList->next) {
            maxTwinSum = max(maxTwinSum, leftList->val + rightList->val);
            leftList = leftList->next;
            rightList = rightList->next;
        }

        reverseList(copyRightList);

        return maxTwinSum;
    }
};
