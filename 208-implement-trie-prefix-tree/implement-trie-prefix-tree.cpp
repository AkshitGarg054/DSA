struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        if(links[ch - 'a'] != NULL) return true;
        return false;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node; 
        return;
    }

    Node* get(char ch) { // to go to the referencing node attached to ch.
        return links[ch - 'a'];
    }
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
            if(!node -> containsKey(word[i])) node -> put(word[i], new Node());
            node = node -> get(word[i]); // go to the next node to which word[i] points to.
        }

        node -> flag = true; // mark it as true
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node -> containsKey(word[i])) return false;
            node = node -> get(word[i]);
        }

        if(node -> flag == true) return true;
        return false; 
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++) {
            if(!node -> containsKey(prefix[i])) return false;
            node = node -> get(prefix[i]);
        } 

        return true; // if prefix is complete then just return true
    }
};
