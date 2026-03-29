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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL || k == 1) return head;

        ListNode* temp = head;
        int count = 0;
        while(temp != NULL) {
            count++;
            temp = temp -> next;
        }

        int groups = count / k;

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* prev = dummy; // prev pointer points to the end of prev segment
        ListNode* curr = head; //points to the current segment that is to be reversed
        ListNode* next = NULL; //points to the start of next segment of current segment

        while(groups) {
            ListNode* start = head; //starting node of a segment
            ListNode* end = head; // end node of a segment
            for(int i = 0; i < k-1; i++) end = end -> next;

            next = end -> next;
            end -> next = NULL;
            prev -> next = reverseList(start);

            start -> next = next;
            prev = start;
            curr = next;
            head = next; 

            groups--;
        }

        return dummy -> next;
    }
};