class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        
        while(tx >= sx && ty >= sy) {

            if(tx == sx) {
                int diff = ty - sy;
                if(diff % tx == 0) return true; // because ty only decrease by tx everytime
                return false;  
            }

            if(ty == sy) {
                int diff = tx - sx;
                if(diff % ty == 0) return true;
                return false;
            }

            if(tx > ty) tx = tx % ty; // modulo is take to bypass multiple subtractions
            else ty = ty % tx; 
        }

        return false;
    }
};