class Solution {
public:
    // Rotate left by 90 degree : (x, y) --> (-y, x) 
    // Rotate right by 90 degree : (x, y) --> (y, -x)

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        set<pair<int, int>> st;
        for(auto it : obstacles) st.insert({it[0], it[1]}); // for fast lookup

        int x = 0, y = 0; // start point
        pair<int, int> dir = {0, 1}; // north initially
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            if(commands[i] == -2) dir = {-dir.second, dir.first}; // left by 90 degree 
            else if(commands[i] == -1) dir = {dir.second, -dir.first}; // right by 90 degree
            else {
                for(int step = 0; step < commands[i]; step++) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;

                    if(st.count({nx, ny})) break; // if obstacle found
                    else x = nx, y = ny; // go to next coordinate
                }
            }

            maxi = max(maxi, x*x + y*y);
        }

        return maxi;
    }
};