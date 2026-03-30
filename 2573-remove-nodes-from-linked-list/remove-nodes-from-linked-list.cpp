class Solution {
public:
    // Linkedlist ke questions me jb bhi hme right wali nodes ki zrurt pde, then hmesha list ko reverse krne ki socho ek baar
    // Reverse the linked list
    // Then keep only nodes which are greater than or equal to the maximum seen so far
    // Then reverse it back.

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

    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);

        int maxi = head -> val;
        ListNode* curr = head;

        while(curr != NULL && curr -> next != NULL) {
            if(curr -> next -> val < maxi) {
                curr -> next = curr -> next -> next; // delete node
            }
            else {
                curr = curr -> next;
                maxi = curr -> val;
            }
        }

        return reverseList(head);
    }
};