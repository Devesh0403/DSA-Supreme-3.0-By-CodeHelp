
class Solution {
  public:
    
    void insertionSort(vector<int>& arr) {
        
        for(int i=1;i<arr.size();i++){
            int key=arr[i];
            int j=i-1;
            
            while(j>=0&&arr[j]>key){
                arr[j+1]=arr[j];
                j=j-1;
            }
            arr[j + 1] = key;
            
        }
        return;
    }
};

