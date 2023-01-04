// TC = O(1)
// MC = O(1)

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    void deleteNode(ListNode* node) {
        auto copyNode = node->next;
        *(node) = *(node->next);
        delete (copyNode);
    }
};
