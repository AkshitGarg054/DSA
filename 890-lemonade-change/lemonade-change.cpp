class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int count5 = 0;
        int count10 = 0;
        int count20 = 0;

        for(int i = 0; i < n; i++) {
            if(bills[i] == 5) count5++;
            else if(bills[i] == 10) {
                if(count5 < 1) return false;
                count10++;
                count5--;
            } 
            else if(bills[i] == 20) { // either return 10+5 or 5+5+5
                if(count5 < 1) return false;
                if(count5 < 3 && count10 < 1) return false;

                if(count10 >= 1) {
                    count10--;
                    count5--;
                    count20++;
                }  
                else if(count5 >= 3) {
                    count5 -= 3;
                    count20++;
                }
            }
        }

        return true;
    }
};

