class NumArray {
public:
    vector<int> nums;
    vector<int> blocks;
    int n, b;

    NumArray(vector<int>& nums) {
        this -> nums = nums;
        n = nums.size();

        b = ceil(sqrt(n));
        blocks.resize(b, 0);

        for(int i = 0; i < n; i++) {
            int block_index = i / b;
            blocks[block_index] += nums[i];
        }
    }
    
    void update(int index, int val) {
        int block_index = index / b;
        blocks[block_index] -= nums[index]; // remove previous value of nums[index]
        nums[index] = val; // update nums[index]
        blocks[block_index] += nums[index]; // add new updated value of nums[index] 
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        int startb = left / b;
        int endb = right / b;

        // case 1 : both left and right are in same block
        if(startb == endb) {
            for(int i = left; i <= right; i++) {
                sum += nums[i];
            }

            return sum;
        }
        
        // case 2 : left and right in different blocks

        // left partial block : left to end of start block
        int end_of_start_block = ((startb + 1) * b) - 1;
        for(int i = left; i <= end_of_start_block; i++) {
            sum += nums[i];
        }

        // middle full blocks
        for(int i = startb + 1; i <= endb - 1; i++) {
            sum += blocks[i];
        }

        // right partial block : start of end block to right
        int start_of_end_block = endb * b;
        for(int i = start_of_end_block; i <= right; i++) {
            sum += nums[i];
        }

        return sum;
    }
};