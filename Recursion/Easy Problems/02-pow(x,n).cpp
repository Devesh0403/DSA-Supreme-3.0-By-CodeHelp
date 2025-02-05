// METHOD 1 - ITERATIVE METHOD

using namespace std;
double myPow(double x, int n) {
      double ans = 1.0;
      for (int i = 0; i < n; i++) {
        ans = ans * x;
      }
      return ans;
}
// TC - O(N)
// SC - O(1)



// METHOD 2 - RECURSIVE BINARY EXPONENTIATION

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        if (n < 0) return (double)1.0/x * myPow((double)1.0/x, -(++n));
        
        double temp=myPow(x,n/2);

        if(n%2==0)return temp*temp;

        else return temp*temp*x;

        
    }
};
// TC - O(N)
// SC - O(N)


// METHOD 3 - ITERATIVE BINARY EXPONENTIATION
class Solution {
public:
    double myPow(double x, int n) {
        long long nn=n;
        if(nn<0)nn=-1*nn;
        double ans = 1.0;

        while(nn){
            if(nn%2){
                ans=ans*x;
                nn--;

            }
            else{
                x=x*x;
                nn/=2;
            }
        }
        if (n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};
// TC - O(LOGN)
// SC - O(1)






