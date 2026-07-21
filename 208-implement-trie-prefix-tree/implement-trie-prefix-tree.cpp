struct Node {
    Node* links[26];
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
            if(node -> links[ch - 'a'] == NULL) node -> links[ch - 'a'] = new Node();
            node = node -> links[ch - 'a']; // go to the next node to which word[i] points to.
        }

        node -> flag = true; // mark it as true
    }
    
    bool search(string word) {
        Node* node = root;

        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if(node -> links[ch - 'a'] == NULL) return false;
            node = node -> links[ch - 'a'];
        }

        if(node -> flag == true) return true;
        return false; 
    }
    
    bool startsWith(string prefix) {
        Node* node = root;

        for(int i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];
            if(node -> links[ch - 'a'] == NULL) return false;
            node = node -> links[ch - 'a'];
        } 

        return true; // if prefix is complete then just return true
    }
};
