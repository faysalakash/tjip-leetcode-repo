// TC = O(N), N = max(|l1|, |l2|)
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prev = new ListNode(INT_MIN);  // dummyNode
        ListNode* head = prev;
        int sum = 0;

        while (l1 || l2 || sum > 0) {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            prev->next = new ListNode(sum % 10);
            ;
            prev = prev->next;
            sum /= 10;
        }

        return head->next;
    }
};
