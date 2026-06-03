class Solution {
public:
    // It's just the reverse of "Next permutation".
    // step 1: Find the first index i from the right such that nums[i] > nums[i + 1]
    // step 2: Now, find the rightmost element smaller than nums[i] in the suffix. (that is, we need the largest value smaller than nums[i], from the suffix. ...and this value will be taken from rightmost because suffix is sorted in increasing order.)
    // step 3: swap them
    // step 4: reverse the suffix (as there is only one swap allowed, so we will not do this last step)

    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();

        int index = -1;
        for(int i = n-2; i >= 0; i--) {
            if(arr[i] > arr[i + 1]) {
                index = i;
                break;
            }
        }

        if(index == -1) return arr;

        int ele = arr[index];
        int desired = arr[index + 1];
        int desired_index = index + 1;

        for(int i = n - 1; i >= index + 2; i--) {
            if(arr[i] < ele) {
                desired_index = i;
                // we want the leftmost occurence among equal candidates.
                while(desired_index - 1 > index && arr[desired_index - 1] == arr[desired_index]) desired_index--;
                desired = arr[i];
                break;
            }
        }

        swap(arr[index], arr[desired_index]);
        return arr;
    }
};