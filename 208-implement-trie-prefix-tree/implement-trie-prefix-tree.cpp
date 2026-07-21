struct Node {
    unordered_map<char, Node*> mp;
    bool flag = false;
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;

        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if(!node -> mp.count(ch)) node -> mp[ch] = new Node();
            node = node -> mp[ch]; // go to the next node to which word[i] points to.
        }

        node -> flag = true; // mark it as true
    }
    
    bool search(string word) {
        Node* node = root;

        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if(!node -> mp.count(ch)) return false;
            node = node -> mp[ch];
        }

        if(node -> flag == true) return true;
        return false; 
    }
    
    bool startsWith(string prefix) {
        Node* node = root;

        for(int i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];
            if(!node -> mp.count(ch)) return false;
            node = node -> mp[ch];
        } 

        return true; // if prefix is complete then just return true
    }
};
