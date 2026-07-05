class Solution {
public:
    // i think we can reverse each sublist and then join the last node of reversed sublist to the remaining list.

    ListNode* reverse(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = head -> next;

        while(curr != NULL) {
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
            if(nextNode != NULL) nextNode = nextNode -> next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;

        ListNode* tempHead = head;
        ListNode* prevNode = dummy;

        while(tempHead != NULL) {
            int count = 1;
            ListNode* node = tempHead;
            while(count < k && node -> next != NULL) {
                node = node -> next;
                count++;
            }

            if(count < k) break;

            ListNode* nextNode = node -> next;
            node -> next = NULL; // a subList has is created

            ListNode* prevHead = tempHead; 
            ListNode* newHead = reverse(tempHead);
            prevHead -> next = nextNode;
            prevNode -> next = newHead;

            prevNode = prevHead;
            tempHead = nextNode;
        }

        return dummy -> next;
    }
};