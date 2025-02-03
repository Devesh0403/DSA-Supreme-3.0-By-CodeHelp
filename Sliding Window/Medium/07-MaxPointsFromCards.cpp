class Solution {
public:
    int findMax(vector<int>& cardPoints, int k){
        int lsum=0;
        int rsum=0;

        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        int maxSum=lsum;
        int rIndex=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[rIndex];
            rIndex--;
            maxSum=max(maxSum,lsum+rsum);
        }
        return maxSum;

    }
    int maxScore(vector<int>& cardPoints, int k) {
        return findMax(cardPoints,k);

        
    }
};