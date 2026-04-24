class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int underscores = 0, rights = 0, lefts = 0;

        for(int i = 0; i < n; i++) {
            if(moves[i] == '_') underscores++;
            else if(moves[i] == 'L') lefts++;
            else rights++;
        }

        // L_RL__R --> L = 2, R = 2 
        return abs(rights - lefts) + underscores; // remove the intersection part, coz L and R will balance each other
    }
};