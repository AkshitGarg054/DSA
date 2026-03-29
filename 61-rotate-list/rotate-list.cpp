class Solution {
public:
    // whenever we need to rotate a LL by k right, then instead,
    // rotate it by (n - k) left.

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL || k == 0) return head;

        ListNode* temp = head;
        int count = 0;

        while(temp != NULL) {
            count++;
            temp = temp -> next;
        }

        if(k >= count) k = k % count;
        if(k == 0) return head;

        int x = count - k;
        temp = head;
        for(int i = 0; i < x-1; i++) temp = temp -> next;

        ListNode* head1 = temp -> next;
        temp -> next = NULL;

        ListNode* temp1 = head1;
        while(temp1 -> next != NULL) temp1 = temp1 -> next;
        temp1 -> next = head;

        return head1;
    }
};