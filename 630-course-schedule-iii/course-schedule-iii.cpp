class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        priority_queue<int> pq; // max heap

        sort(courses.begin(), courses.end(), [&](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int count = 0;
        int consumed_days = 0;

        for(auto &course : courses) {
            int duration = course[0];
            int deadline = course[1];

            if(consumed_days + duration <= deadline) {
                consumed_days += duration;
                count++;
                pq.push(duration);
            }
            else if(!pq.empty() && pq.top() > duration) { // available days exceeds the current deadline: try to exchange this current duration with the longest past duration that we selected 
                consumed_days -= pq.top();
                pq.pop();

                consumed_days += duration;
                pq.push(duration);
            }
        }

        return count;
    }
};