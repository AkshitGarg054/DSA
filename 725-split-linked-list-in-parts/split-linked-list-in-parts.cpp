class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;

        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        vector<ListNode*> ans;

        int size = count / k;     // minimum nodes in each part
        int extra = count % k;    // first 'extra' parts get 1 extra node

        temp = head;

        for(int i = 0; i < k; i++) {
            if(temp == NULL) {
                ans.push_back(NULL);
                continue;
            }

            ListNode* start = temp;
            int currSize = size + (extra > 0 ? 1 : 0);

            // move temp to last node of this part
            for(int j = 1; j < currSize; j++) {
                temp = temp->next;
            }

            ListNode* nextPart = temp->next;
            temp->next = NULL;
            ans.push_back(start);

            temp = nextPart;

            if(extra > 0) extra--;
        }

        return ans;
    }
};