class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [&](ListNode* a, ListNode* b) {
            return a -> val > b -> val; // a upar hoga, b niche
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for(auto &head: lists) {
            if(head != NULL) pq.push(head);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            temp -> next = curr;
            temp = temp -> next;

            if(curr -> next) pq.push(curr -> next);
        }

        return dummy -> next;
    }
};