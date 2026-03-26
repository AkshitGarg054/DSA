class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children) return -1;
        money = money - children; // give 1 money to all
        if(money < 7) return 0;

        int n = children;

        int count = 0;
        while(money >= 7 && n > 0) {
            money -= 7;
            count++;
            n--; 
        }

        if(money == 3 && count == children-1) return count - 1; // 1 money is already given
        if(count == children && money > 0) return count - 1; 
        return count;
    }
};