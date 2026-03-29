class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL;

        int carry = 0;
        while(l1 != NULL && l2 != NULL) {
            int num1 = l1 -> val;
            l1 = l1 -> next;
            int num2 = l2 -> val;
            l2 = l2 -> next;

            int sum = num1 + num2 + carry;
            int node_val = sum % 10;
            carry = sum / 10;

            ListNode* temp = new ListNode(node_val);
            if(ans == NULL) ans = temp;
            else {
                ListNode* head = ans;
                while(head -> next != NULL) head = head -> next;
                head -> next = temp;
            }
        }

        while(l1 != NULL) {
            int num = l1 -> val;
            l1 = l1 -> next;

            int sum = num + carry;
            int node_val = sum % 10;
            carry = sum / 10;

            ListNode* temp = new ListNode(node_val);
            ListNode* head = ans;
            while(head -> next != NULL) head = head -> next;
            head -> next = temp;
        }

        while(l2 != NULL) {
            int num = l2 -> val;
            l2 = l2 -> next;

            int sum = num + carry;
            int node_val = sum % 10;
            carry = sum / 10;

            ListNode* temp = new ListNode(node_val);
            ListNode* head = ans;
            while(head -> next != NULL) head = head -> next;
            head -> next = temp;
        }

        if(carry != 0) {
            ListNode* temp = new ListNode(carry);
            ListNode* head = ans;
            while(head -> next != NULL) head = head -> next;
            head -> next = temp;
        }

        return ans;
    }
};