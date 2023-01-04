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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto first = head;
        auto second = head;

        while (n--) {
            first = first->next;
        }

        if (!first) return head->next;  // return NULL if there's only one element

        while (first->next) {
            first = first->next;
            second = second->next;
        }

        auto nodeToDelete = second->next;
        second->next = second->next->next;
        delete (nodeToDelete);

        return head;
    }
};
