class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;

        vector<string>ans(numRows);
        int row=0;
        bool direction =1;
        int i=0;



        while(true){

            if(direction){
                while(i<s.size()&& row<numRows){

                ans[row].push_back(s[i]);
                i++;
                row++;
                }
                row=numRows-2;
            }

            else{
                while(i<s.size()&& row>=0){

                ans[row].push_back(s[i]);
                row--;
                i++;
                }
                row=1;


            }
            if(i>=s.size())break;
            direction=!direction;


        }
        string finalAns="";
        for(auto str:ans){
            finalAns+=str;
        }
        return finalAns;
        
    }
};