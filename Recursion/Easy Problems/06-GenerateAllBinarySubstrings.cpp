class Solution{
public:
    vector<string>ans;
    void generate(int num,string curr,int last){
        if(num==curr.size()){
            ans.push_back(curr);
            return;}
        
        if(last)generate(num,curr+'0',0);
        else{
            generate(num,curr+'0',0);
            generate(num,curr+'1',1);
            
        }
        return;
    }
    vector<string> generateBinaryStrings(int num){
        
        generate(num,"0",0);
        generate(num,"1",1);
        return ans;
        
        
    }
};
// TC - O(2^N)
// SC - O(N)