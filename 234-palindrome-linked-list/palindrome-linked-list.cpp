class Solution {
public:
    ListNode* copyList(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode* newHead = NULL;
        ListNode* newNode = NULL;
        
        while(head != NULL) {
            ListNode* temp = new ListNode(head -> val);
            head = head -> next;

            if(newHead == NULL) {
                newHead = temp;
                newNode = temp;
            }
            else {
                newNode -> next = temp;
                newNode = temp;
            }
        }

        return newHead;
    }

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
        ListNode* copiedHead = copyList(head); // make copy
        ListNode* reverse_head = reverseList(copiedHead); // reverse the copy

        while(head != NULL) {
            int val1 = head -> val;
            int val2 = reverse_head -> val;
            if(val1 != val2) return false;

            head = head -> next;
            reverse_head = reverse_head -> next;
        }

        return true;
    }
};