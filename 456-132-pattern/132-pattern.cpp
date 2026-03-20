class Solution {
public:
    // we want : i < j < k , and nums[j] > nums[i] && nums[j] > nums[k]
    // that is, agar koi triplet haii, to usme hme beech wala element sbse bda chahiye, like 1, 4, 2
    // smaller number, big number, medium number
    // where 1, 4, 2 are occuring in this same order in the array
    // why stack in this??
    // because we have three elements to see here. We can traverse for one element in O(n), and for other two elements --
    // we need to store them somewhere --> one ele can be stored in stack and other can be stored in a variable

    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;

        stack<int> st;
        int third_ele = INT_MIN; // to store medium element, nums[k]

        for(int i = n-1; i >= 0; i--) { 
            if(nums[i] < third_ele) return true;
            while(!st.empty() && st.top() < nums[i]) { 
                third_ele = st.top(); 
                st.pop(); 
            }
            st.push(nums[i]); // storing the greatest element in the stack 
        }

        return false;
    }
};