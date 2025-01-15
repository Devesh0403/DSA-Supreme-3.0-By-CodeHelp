class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string>q;
        unordered_set<string>visited;
        
        unordered_set<string> st{bank.begin(),bank.end()};

        q.push(startGene);
        visited.insert(startGene);
        int ans=0;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==endGene)return ans;

                for(char ch:"ACGT"){
                    for(int i=0;i<8;i++){
                        string nbr=curr;
                        nbr[i]=ch;
                        if(st.find(nbr)!=st.end()&&visited.find(nbr)==visited.end()){
                            q.push(nbr);
                            visited.insert(nbr);
                        }
                    }
                }


            }
            ans++;
        }
        return -1;
        
    }
};