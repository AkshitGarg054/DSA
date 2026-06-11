class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if(finalSum % 2 != 0) return {};
        
        for(int i = 2; i <= finalSum; i += 2) {
            if(finalSum >= i) { // so we can subtract i
                ans.push_back(i);
                finalSum -= i;
            }
            else break;
        }

        long long remaining = finalSum;   
        int sz = ans.size();
        ans[sz - 1] = ans[sz - 1] + remaining;

        return ans;
    }
};