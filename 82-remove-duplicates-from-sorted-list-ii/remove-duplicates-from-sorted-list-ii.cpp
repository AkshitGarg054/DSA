class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr != NULL) {
            // if duplicate sequence starts
            if(curr -> next != NULL && curr -> val == curr -> next -> val) {
                int dupVal = curr -> val;
                while(curr != NULL && curr -> val == dupVal) curr = curr -> next;
                prev -> next = curr;
            }
            else {
                prev = curr;
                curr = curr -> next;
            }
        }

        return dummy -> next;
    }
};