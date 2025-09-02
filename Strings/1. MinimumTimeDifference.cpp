class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        // Making a new vector containing time in minutes
        int ans = INT_MAX;
        vector<int> time;
        for (int i = 0; i < timePoints.size(); i++) {
            int hours =
                (timePoints[i][0] - '0') * 10 + (timePoints[i][1] - '0');
            int minutes =
                (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0');
            cout << hours << " " << minutes << endl;

            time.push_back(hours * 60 + minutes);
        }
        // Sorting the vector according to the time
        sort(time.begin(), time.end());

        // The minimum time between two time frames can be found using 2 steps
        // 1. Comparing 2 consecutive indexes in the time vector
        // 2. comparing the last and first time

        for (int i = 0; i < timePoints.size() - 1; i++) {
            ans = min(ans, time[i + 1] - time[i]);
        }
        ans = min(ans, time[0] + 1440 - time[time.size() - 1]);

        return ans;
    }
};