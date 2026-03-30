class Solution {
public:
    // entirely a different question : Find middle node in a linked list
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next; // important change (coz, in 1 -> 2, we need to return 1 as mid)

        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }

    // entirely a different question : Merge two sorted lists
    ListNode* mergeLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(list1 != NULL && list2 != NULL) {
            if(list1 -> val < list2 -> val) {
                temp -> next = list1;
                list1 = list1 -> next;
            }
            else {
                temp -> next = list2;
                list2 = list2 -> next;
            }

            temp = temp -> next;
        }

        if(list1 != NULL) temp -> next = list1;
        else temp -> next = list2;

        return dummy -> next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;

        ListNode* middle = findMiddle(head);
        ListNode* left = head;
        ListNode* right = middle -> next;
        middle -> next = NULL;

        left = sortList(left);
        right = sortList(right);

        head = mergeLists(left, right);
        return head;
    }
};