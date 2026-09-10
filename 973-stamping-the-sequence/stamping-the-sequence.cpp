class Solution {
public:
    // The trick here is to process the target in reverse and make it "???.."
    // For example: stamp = "abc" , target = "ababc" --> "ab???" --> "?????"
    // Why "ab???" --> "?????" and not "ab???" --> "??c??"
    // Because the ? in "ab???" are already undone by the later stamp, so it does not matter what char was present there.
    // "ab???" --> I interpret it as a state that could have resulted from stamping abc at this position, where the c position has already been turned into ? by undoing a later stamp.
    // Try to visualize it by assuming some chits are getting placed on top of each other.
    // Refer: https://youtu.be/j0x0uxJnz3Q?si=5CW6E1iQyskXGbt8

    bool canReplace(string &target, string &stamp, int pos) {
        int n = target.size();
        int m = stamp.size();
        for(int i = 0; i < m; i++) {
            if(target[pos + i] != '?' && target[pos + i] != stamp[i]) return false;
        }
        return true;
    }

    int replace(string &target, string &stamp, int pos) {
        int n = target.size();
        int m = stamp.size();
        int count = 0;

        for(int i = 0; i < m; i++) {
            if(target[pos + i] != '?') {
                target[pos + i] = '?';
                count++;
            }
        }
        return count;
    }

    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size();
        int m = stamp.size();

        vector<int> ans;
        vector<int> vis(n, 0); // to mark the starting positions which are converted
        int converted = 0;

        while(converted < n) {
            bool flag = false; 

            for(int i = 0; i <= n - m; i++) {
                if(!vis[i] && canReplace(target, stamp, i)) {
                    vis[i] = 1;
                    converted += replace(target, stamp, i);
                    flag = true;
                    ans.push_back(i);
                    if(converted == n) break;
                }
            }

            if(!flag) return {};
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};