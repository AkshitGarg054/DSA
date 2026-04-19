class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);
        string word;
        string result = "";

        while(ss >> word) {
            string prefix = "";
            string replacement = word;

            for(int i = 0; i < word.size(); i++) {
                prefix += word[i];

                if(st.count(prefix)) {
                    replacement = prefix;  // shortest match
                    break;
                }
            }

            result += replacement + " ";
        }

        result.pop_back(); // remove last space
        return result;
    }
};