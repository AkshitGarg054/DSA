class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        int n = cpdomains.size();
        unordered_map<string, int> mp; // domain frequency

        for(auto &s: cpdomains) {
            // each string has two parts: number and domain
            string num = "";
            int i = 0;
            while(s[i] != ' ') num += s[i++];

            int number = stoi(num);
            i++; // skip space
            string domain = s.substr(i);

            // extract subdomains
            mp[domain] += number;

            i = domain.size() - 1; 
            while(i >= 0) {
                if(domain[i] == '.') {
                    string subdomain = domain.substr(i + 1);
                    mp[subdomain] += number;
                }
                i--;
            }
        }

        vector<string> ans;

        for(auto &[str, count]: mp) {
            string temp = "";
            temp += to_string(count);
            temp += ' ';
            temp += str;
            ans.push_back(temp);
        }

        return ans;
    }
};