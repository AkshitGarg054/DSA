class Solution {
public:
    // In this ques, we can build two different graphs: Bus Graph or Stop graph
    // Each node is a bus. Two buses are connected if they share a common stop.     
    // create a map which stops: stop -> buses visiting it

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        if(source == target) return 0;
        unordered_map<int, vector<int>> mp;

        for(int bus = 0; bus < n; bus++) {
            for(int i = 0; i < routes[bus].size(); i++) {
                int stop = routes[bus][i];
                mp[stop].push_back(bus);
            }
        }

        vector<int> busVis(n, 0); // we should not take the bus that is already taken
        unordered_set<int> stopVis; // we don't to visit any stop again
        stopVis.insert(source);

        // now start from source stop
        queue<int> q;
        for(auto &bus: mp[source]) {
            q.push(bus); // try taking every bus starting from source
            busVis[bus] = 1;
        }

        int steps = 1; 

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                int bus = q.front(); // now, try to visit every stop of this bus
                q.pop();

                for(auto &stop: routes[bus]) {
                    if(stopVis.count(stop)) continue;
                    if(stop == target) return steps;
                    else { // take every bus from this stop
                        for(auto &bus: mp[stop]) {
                            if(!busVis[bus]) {
                                q.push(bus);
                                busVis[bus] = 1;
                            }
                        }
                    }

                    stopVis.insert(stop);
                }
            }

            steps++;
        }

        return -1;
    }
};