class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();

        int i = 0, j = 0;
        while(i < n && j < m) {
            string r1, r2;
            
            int k = i;
            while(k < n && version1[k] != '.') k++;
            r1 = version1.substr(i, k - i);
            i = k + 1;

            k = j;
            while(k < m && version2[k] != '.') k++;
            r2 = version2.substr(j, k - j);
            j = k + 1;

            if(stoi(r1) < stoi(r2)) return -1;
            else if(stoi(r1) > stoi(r2)) return 1;
        }

        while(i < n) {
            int k = i;
            while(k < n && version1[k] != '.') k++;
            string r1 = version1.substr(i, k - i);
            i = k + 1;
            if(stoi(r1) > 0) return 1;
        }
        
        while(j < m) {
            int k = j;
            while(k < m && version2[k] != '.') k++;
            string r2 = version2.substr(j, k - j);
            j = k + 1;
            if(stoi(r2) > 0) return -1;
        }

        return 0;
    }
};