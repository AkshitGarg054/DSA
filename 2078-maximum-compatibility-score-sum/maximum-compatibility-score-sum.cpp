class Solution {
public:
    int n; // number of students/mentors 
    int m; // number of questions
    int maxi = INT_MIN;

    int calc_score(vector<int> &v1, vector<int> &v2) {
        int score = 0;
        for(int i = 0; i < m; i++) {
            if(v1[i] == v2[i]) score++;
        }
        return score;
    }

    void solve(int row, int score, vector<vector<int>>& students, vector<vector<int>>& mentors, vector<int> &vis) {
        if(row == n) {
            maxi = max(maxi, score);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                vis[i] = 1;
                int dot_product = calc_score(students[row], mentors[i]);
                solve(row + 1, score + dot_product, students, mentors, vis);
                vis[i] = 0; // backtrack
            }
        }
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        n = students.size();
        m = students[0].size();

        vector<int> vis(n, 0);
        solve(0, 0, students, mentors, vis); // 0th row
        return maxi;
    }
};