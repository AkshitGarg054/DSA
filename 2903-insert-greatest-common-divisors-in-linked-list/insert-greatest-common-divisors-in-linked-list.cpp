class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        ListNode* next_node = head -> next;

        while(curr != NULL && next_node != NULL) {
            int val1 = curr -> val;
            int val2 = next_node -> val;
            int gcd = __gcd(val1, val2);

            ListNode* temp = new ListNode(gcd);
            temp -> next = curr -> next;
            curr -> next = temp;

            next_node = next_node -> next;
            curr = curr -> next -> next;
        }

        return head;
    }
};