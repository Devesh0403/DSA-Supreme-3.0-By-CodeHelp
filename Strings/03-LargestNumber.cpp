class Solution {
public:
    static bool cmp(int& a, int& b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
    string largestNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end(), cmp);

        vector<string>vec;
        for(auto a:nums){
            vec.push_back(to_string(a));
        }

        string ans;

        if(vec[0]=="0")return "0";
        for (auto a : vec) {
            ans += a;
        }

        return ans;
    }
};