class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long count = 0;

        int min_child1 = max(0, n - 2*limit); // assign "limit" candies to other two.
        int max_child1 = min(n, limit);

        for(int i = min_child1; i <= max_child1; i++) {
            int N = (n - i); // for child2 and child3

            int min_child2 = max(0, N - limit);
            int max_child2 = min(N, limit);
            count += (max_child2 - min_child2 + 1);
        }

        return count;
    }
};