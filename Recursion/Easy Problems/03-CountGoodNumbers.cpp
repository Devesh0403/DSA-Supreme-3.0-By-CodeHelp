class Solution {
public:
    int mod = 1e9+7;
    long long  power(long long x,long long n){
        if(n==0)return 1;
        long long temp=power(x,n/2);
        if(n%2==0){
            return (temp*temp)%mod;
        }
        return (temp * temp % mod * x) % mod;

    }
    int countGoodNumbers(long long n) {
        return (power(5,(n+1)/2)*power(4,n/2))%mod;
        
    }
};