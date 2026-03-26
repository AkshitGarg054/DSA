class Solution {
public:
    // to minimize boats, we need to handle fat people.
    // try to pair fattest with thinnest as much as possible.

    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end()); // important

        int l = 0, r = n-1;
        int boats = 0;

        while(l <= r) {
            int weight = people[l] + people[r];
            if(l == r) weight = weight / 2;

            if(weight > limit) {
                boats++; // get rid of the fattest person alone
                r--;
            }
            else boats++, l++, r--;
        }

        return boats;
    }
};