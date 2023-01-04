class MyLinkedList {
   public:
    class Node {
       public:
        int val;
        Node* next;

        Node(int val, Node* next) {
            this->val = val;
            this->next = next;
        }
    };

    const static int DUMMY_VALUE = INT_MIN;
    Node* head = NULL;
    int len;

    MyLinkedList() {
        head = new Node(DUMMY_VALUE, NULL);
        len = 0;
    }

    Node* getDesiredNode(int index) {
        Node* node = head;

        while (index--) {
            node = node->next;
        }

        return node;
    }

    int get(int index) {
        if (index < 0 || index >= len) return -1;

        auto currentNode = getDesiredNode(index);

        return currentNode->next->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(len, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > len) return;

        auto currentNode = getDesiredNode(index);
        auto newNode = new Node(val, currentNode->next);
        currentNode->next = newNode;
        len++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= len) return;

        auto currentNode = getDesiredNode(index);
        auto next = currentNode->next;
        currentNode->next = currentNode->next->next;
        delete (next);
        len--;
    }
};
