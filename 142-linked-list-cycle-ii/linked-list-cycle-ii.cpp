class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        bool found = false;
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) {
                found = true;
                slow = head;
                break;
            }
        }

        if(found == true) {
            while(slow != fast) {
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow;
        }
        else return NULL;
    }
};