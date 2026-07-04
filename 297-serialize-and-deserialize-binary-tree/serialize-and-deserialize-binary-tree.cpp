class Codec {
public:
    void preorder(TreeNode* root, string &s) {
        if(root == NULL) {
            s += "#,";
            return;
        }

        s += to_string(root -> val) + ","; 
        preorder(root -> left, s);
        preorder(root -> right, s);
    }

    TreeNode* build(int &index, vector<string> &vec) {
        if(vec[index] == "#") {
            index++; // increment only when the condition met
            return NULL;
        }

        int value = stoi(vec[index++]);
        TreeNode* root = new TreeNode(value);
        root -> left = build(index, vec);
        root -> right = build(index, vec);

        return root;
    }

    string serialize(TreeNode* root) {
        string s = "";
        preorder(root, s);
        return s;
    }

    TreeNode* deserialize(string data) {
        int n = data.size();
        vector<string> vec;

        int i = 0;
        while(i < n) {
            string temp = "";
            int j = i;
            while(j < n && data[j] != ',') {
                temp += data[j];
                j++;
            }

            vec.push_back(temp);
            i = j + 1;
        }

        int index = 0;
        TreeNode* root = build(index, vec);
        return root;
    }
};