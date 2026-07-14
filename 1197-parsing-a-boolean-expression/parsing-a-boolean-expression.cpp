class Solution {
public:
    bool solve(int &index, string &s) {
        char ch = s[index];

        char op;
        if(ch == '|' || ch == '!' || ch == '&') {
            op = ch;
            index++; // Consume the operator 
            index++; // Consume '('
        }

        bool ans;
        if (op == '!') ans = false; // Will be overwritten anyway
        else if (op == '&') ans = true;  // AND needs to start as true
        else if (op == '|') ans = false; // OR needs to start as false

        while (s[index] != ')') {
            
            bool next;
            if(s[index] == 'f') {
                next = false;
                index++;
            }
            else if(s[index] == 't') {
                next = true;
                index++;
            }
            else next = solve(index, s);

            if (op == '!') ans = !next;
            else if (op == '&') ans = ans && next;
            else if (op == '|') ans = ans || next;

            if (s[index] == ',') index++;
        }

        index++; // Consume ')'
        return ans;
    }

    bool parseBoolExpr(string expression) {
        if(expression == "f") return false;
        if(expression == "t") return true;
        
        int index = 0;
        return solve(index, expression);
    }
};