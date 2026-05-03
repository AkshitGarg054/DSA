class Solution {
public:
    // pehle to position ke hisaab se sort kr lenge dono array ko combine krke
    // Then, we will firstly just calculate ki har ek car ko target pe pohanchne me kitna time lgega
    // and store these time in a separate time array
    // we will traverse that time array from back. 
    // (i mean, cars ek ek krke destination pe ayengi, aur jaisi hi aati jayengi we will update the fleets accordingly)

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();

        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) vec[i] = {position[i], speed[i]};

        sort(vec.begin(), vec.end()); // sort by position

        vector<float> time(n);
        for(int i = 0; i < n; i++) time[i] = (float)(target - vec[i].first) / vec[i].second; 

        // for(int i = 0; i < n-1; i++) {
        //     if(time[i] > time[i + 1]) count++; // aage wali car fast haii 
        // }

        int count = 0; 
        float guard = time[n - 1]; // car at the neareast position to the target will reach first
        // now we will compare all the incoming cars to this car

        for(int i = n - 2; i >= 0; i--) {
            float incoming = time[i];

            if(incoming > guard) {
                count++; // if the time of incoming car is greater then it will create a new fleet 
                guard = incoming;
            }
        }

        count++; // last fleet to reach target
        return count;
    }
};