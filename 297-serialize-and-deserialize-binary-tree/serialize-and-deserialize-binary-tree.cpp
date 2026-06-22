class Codec {
public:
    // we can't traverse the nodes array using (2*i + 1) and (2*i + 2) indices coz 
    // these indices are only used when we are given the level-order / complete-binary-tree array.
    // but here, we have calcuated the preorder traversal.
    // To serialize, we use Preorder traversal with NULL marking.
 
    void preorder(TreeNode* root, string &s) {
        if(root == NULL) {
            s += "#,";
            return;
        }

        s += to_string(root -> val) + ",";
        preorder(root -> left, s);
        preorder(root -> right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    TreeNode* build(int &index, vector<string> &nodes) {
        if(nodes[index] == "#") {
            index++; // increment only when the condition met
            return NULL;
        }

        int value = stoi(nodes[index++]);
        TreeNode* root = new TreeNode(value);

        root -> left = build(index, nodes);
        root -> right = build(index, nodes);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes; 
        string temp;

        for(auto ch: data) { // to extract nodes from the input string
            if(ch == ',') {
                nodes.push_back(temp);
                temp.clear();
            }
            else temp += ch;
        }

        int index = 0;
        return build(index, nodes);
    }
};
