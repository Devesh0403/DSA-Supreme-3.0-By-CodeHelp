//GFG SOLUTION

#include<iostream>
using namespace std;
#include<queue>

// Function to find the maximum element in each sliding
// window of size k
vector<int> maxSlidingWindow(vector<int>& arr, int k)
{
    vector<int> ans;
    priority_queue<pair<int, int> > heap;

    // Initialize the heap with the first k elements
    for (int i = 0; i < k; i++)
        heap.push({ arr[i], i });

    // The maximum element in the first window
    ans.push_back(heap.top().first);

    // Process the remaining elements
    for (int i = k; i < arr.size(); i++) {

        // Add the current element to the heap
        heap.push({ arr[i], i });

        // Remove elements that are outside the current
        // window
        while (heap.top().second <= i - k)
            heap.pop();

        // The maximum element in the current window
        ans.push_back(heap.top().first);
    }

    return ans;
}

int main()
{
    vector<int> arr = { 2, 3, 7, 9, 5, 1, 6, 4, 3 };
    int k = 3;
    vector<int> result = maxSlidingWindow(arr, k);
    for (auto i : result)
        cout << i << " ";
    return 0;
}


// LEETCODE SOLUTION

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int>dq;

        vector<int>ans;

        //process first window
        for(int i=0;i<k;i++){
            int element=nums[i];
            // will get inseerted in queue irrespectively
            //check if the elements inserted are smaller than the current element 
            
            while(!dq.empty() && nums[dq.back()]<element){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        int index=dq.front();
        int element=nums[index];

        ans.push_back(element);

        //process remaining windows
        for(int i=k;i<nums.size();i++){

            if(!dq.empty()&& dq.front()<i-k+1){
                dq.pop_front();
            }

            int element=nums[i];
            // will get inseerted in queue irrespectively
            //check if the elements inserted are smaller than the current element 
            
            while(!dq.empty() && nums[dq.back()]<element){
                dq.pop_back();
            }
            
            
            dq.push_back(i);

            index=dq.front();
            element=nums[index];

            ans.push_back(element);


        }
        return ans;






        
    }
};
