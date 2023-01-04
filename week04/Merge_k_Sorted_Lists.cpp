
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        ListNode* dummyHead = new ListNode();
        ListNode* copyDummyHead = dummyHead;

        while (left && right) {
            int vLeft = left->val;
            int vRight = right->val;

            if (vLeft < vRight) {
                dummyHead->next = new ListNode(vLeft);
                left = left->next;
            } else {
                dummyHead->next = new ListNode(vRight);
                right = right->next;
            }

            dummyHead = dummyHead->next;
        }

        while (left) {
            int vLeft = left->val;
            dummyHead->next = new ListNode(vLeft);
            dummyHead = dummyHead->next;
            left = left->next;
        }

        while (right) {
            int vRight = right->val;
            dummyHead->next = new ListNode(vRight);
            dummyHead = dummyHead->next;
            right = right->next;
        }

        return copyDummyHead->next;
    }

    ListNode* helper(int L, int R, vector<ListNode*>& lists) {
        if (L > R) return NULL;
        if (L == R) return lists[L];

        int M = L + ((R - L) / 2);

        auto left = helper(L, M, lists);
        auto right = helper(M + 1, R, lists);

        return mergeTwoLists(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return helper(0, lists.size() - 1, lists);
    }
};