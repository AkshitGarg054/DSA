class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        int carry = 0;
        while(l1 != NULL && l2 != NULL) {
            int num1 = l1 -> val;
            int num2 = l2 -> val;
            
            int sum = num1 + num2 + carry;
            int value = sum % 10;
            carry = sum / 10;

            temp -> next = new ListNode(value);
            temp = temp -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        while(l1 != NULL) {
            int num1 = l1 -> val;
            
            int sum = num1 + carry;
            int value = sum % 10;
            carry = sum / 10;

            temp -> next = new ListNode(value);
            temp = temp -> next;
            l1 = l1 -> next;
        }

        while(l2 != NULL) {
            int num2 = l2 -> val;
            
            int sum = num2 + carry;
            int value = sum % 10;
            carry = sum / 10;

            temp -> next = new ListNode(value);
            temp = temp -> next;
            l2 = l2 -> next;
        }

        if(carry != 0) temp -> next = new ListNode(carry);
        return dummy -> next;
    }
};