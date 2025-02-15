// BRUTE FORCE - USING 2 LOOPS
class Solution{
    public:
    
        vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
            //write your code here
            vector<int>count(n,-1);
            for(int i=0;i<arr.size();i++){
                int cnt=0;
                for(int j=i+1;j<arr.size();j++){
                    if(arr[j]>arr[i])cnt++;
                    
                }
                count[i]=cnt;
            }
            vector<int>ans;
            for(int i=0;i<queries;i++){
                ans.push_back(count[indices[i]]);
            }
            return ans;
            
           
        }
    
    };
// TC - O(N^2)
// SC - O(2*N) 