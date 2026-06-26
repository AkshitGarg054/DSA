class Solution {
public:
    unordered_map<Node*, Node*> mp; // In map, we will store the cloned node for every node

    void solve(Node* node, Node* cloned_node) {
        for(auto n: node -> neighbors) {
            if(!mp.count(n)) {
                Node* cloned = new Node(n -> val);
                mp[n] = cloned;
                cloned_node -> neighbors.push_back(cloned);
                solve(n, cloned);
            }
            else cloned_node -> neighbors.push_back(mp[n]);
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        Node* cloned_node = new Node(node -> val);
        mp[node] = cloned_node;

        // Now, clone its neighbors and recursively their neighbors
        // But if a node reappears, then we need to access that cloned node using map.
        // So, we stored each cloned node in a map.
        solve(node, cloned_node);
        return cloned_node;
    }
};