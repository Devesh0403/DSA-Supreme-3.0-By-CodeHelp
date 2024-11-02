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
