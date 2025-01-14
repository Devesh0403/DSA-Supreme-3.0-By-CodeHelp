class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        
        for (auto ch : s) {
            mp[ch]++;
        }

        for (auto num : mp) {
            pq.push({num.second, num.first});
        }

        string ans = "";

        while (pq.size() >= 2) {
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();

            ans.push_back(top1.second);
            top1.first--;
            ans.push_back(top2.second);
            top2.first--;

            if (top1.first > 0) pq.push(top1);
            if (top2.first > 0) pq.push(top2);
        }

        // If there's one element left in the heap
        if (!pq.empty()) {
            if (pq.top().first > 1) return "";  // Impossible to reorganize
            ans.push_back(pq.top().second);
        }

        return ans;
    }
};
