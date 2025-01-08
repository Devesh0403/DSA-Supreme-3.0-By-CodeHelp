
class Solution {
  public:
  void topoBFS(int n,unordered_map<int,list<int>>adj,vector<int>&topo){
        unordered_map<int,int>indegree;
        queue<int>q;
        
        for(int src=0;src<n;src++){
            for(auto nbr:adj[src]){
                indegree[nbr]++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int front=q.front();
            topo.push_back(front);
            
            for(auto nbr:adj[front]){
                indegree[nbr]--; 
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
            q.pop();
            
        }
    }
    string findOrder(vector<string> dict, int k) {
        
        unordered_map<int,list<int>>adj;
        
        for(int k=0;k<dict.size()-1;k++){
            string str1=dict[k];
            string str2=dict[k+1];
            
            int i=0,j=0;
            
            while(i<str1.size()&&j<str2.size()){
                if(str1[i]!=str2[j]){
                     adj[str1[i]-'a'].push_back(str2[j]-'a');
                     break;
                }
                i++;
                j++;
            }
        }
        
        vector<int>topo;
        
        
        topoBFS(k,adj,topo);
        string ans="";
        for(auto num:topo){
            ans+=char(num+'a');
        }
        return ans;
        
        
        
        
        
        
        // code here
    }
};


