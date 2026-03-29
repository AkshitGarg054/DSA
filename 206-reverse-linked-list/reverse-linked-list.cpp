class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(head != NULL) {
            next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
        }

        head = prev;
        return head;
    }
};