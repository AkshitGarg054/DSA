class Solution {
public:
    ListNode* reverseList(ListNode *head) {
        ListNode *prev = NULL;
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

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* head1 = NULL;
        if(fast == NULL) { // even length linked list
            head1 = slow;
        }
        else if(fast -> next == NULL) {
            head1 = slow -> next; // odd length linked list
            slow -> next = NULL;
        }

        head1 = reverseList(head1);

        // now, compare linkedlists head and head1
        while(head != NULL && head1 != NULL) {
            if(head -> val != head1 -> val) return false;
            head = head -> next;
            head1 = head1 -> next;
        }

        return true;
    }
};