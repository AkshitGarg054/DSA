class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode* temp = head;
        int counter = 0;

        while(temp != NULL) {
            counter++;
            temp = temp -> next;
        }

        int x = counter - n; // to remove (x + 1)th node from start

        if(x == 0) { // deleting first node
            ListNode* to_del = head;
            head = head->next;
            delete to_del;
            return head;
        }

        temp = head;
        for(int i = 0; i < x-1; i++) temp = temp -> next;

        ListNode* to_del = temp -> next;
        temp -> next = to_del -> next;
        delete(to_del);

        return head;
    }
};