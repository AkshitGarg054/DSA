class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        if(n % 2 != 0) return false;

        pair<int, int> pos = {0, 0};

        for(int i = 0; i < n; i++) {
            int x = pos.first;
            int y = pos.second;

            if(moves[i] == 'L') pos = {x, y - 1};
            if(moves[i] == 'R') pos = {x, y + 1};
            if(moves[i] == 'U') pos = {x - 1, y};
            if(moves[i] == 'D') pos = {x + 1, y};
        }

        if(pos.first == 0 && pos.second == 0) return true;
        return false;
    }
};