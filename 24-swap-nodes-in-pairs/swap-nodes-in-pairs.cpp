class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;
        ListNode* dummy = new ListNode(-1);

        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* nextNode = curr -> next;

        while(curr != NULL && curr -> next != NULL) {
            curr -> next = nextNode -> next;
            nextNode -> next = curr;
            prev -> next = nextNode;

            prev = curr;
            curr = curr -> next;
            if(curr != NULL) nextNode = curr -> next;
        }

        return dummy -> next;
    }
};