class Solution {
public:

    bool DFSTraversal(vector<vector<int>>& graph,int i,unordered_map<int,bool>&visited,unordered_map<int,bool>&path,vector<int>&check){
        visited[i]=true;
        path[i]=true;
        check[i]=0;
        
        for(auto nbr:graph[i]){
            if(!visited[nbr]){
                bool ans=DFSTraversal(graph,nbr,visited,path,check);
                if(ans==true)return true;
            }
            
            else if(visited[nbr]&&path[nbr])return true;
        }
        check[i]=1;
        path[i]=false;
        return false;


    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        unordered_map<int,bool>visited;
        unordered_map<int,bool>path;
        vector<int>check(graph.size());
        vector<int>safeNodes;


        for(int i=0;i<graph.size();i++){
            if(!visited[i]){
                DFSTraversal(graph,i,visited,path,check);
            }
        }

        for(int i=0;i<graph.size();i++){
            if(check[i]==1){
                safeNodes.push_back(i);
                
            }
        }
        return safeNodes;
        
    }
};