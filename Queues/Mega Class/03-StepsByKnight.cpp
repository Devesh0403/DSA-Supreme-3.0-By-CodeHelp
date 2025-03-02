

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    pair<int,int>src={KnightPos[0]-1,KnightPos[1]-1};
	    pair<int,int>dest={TargetPos[0]-1,TargetPos[1]-1};
	    
	    vector<pair<int, int>> directions = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
	        
	    };

	    
	    if(src == dest) return 0;
	    queue<pair<pair<int,int>,int>>q;
	    
	    q.push({src,0});
	    
	    vector<vector<bool>>vis(N,vector<bool>(N,false));
	    
	    vis[src.first][src.second] = true;
	    
	    while(!q.empty()){
	        auto front = q.front();
            q.pop();
        
            pair<int, int> position = front.first;
            int steps = front.second;
            
            for (auto& direction : directions) {
            int newRow = position.first + direction.first;
            int newCol = position.second + direction.second;

            // Check if the new position is within bounds and not visited
            if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N && !vis[newRow][newCol]) {
                // If we reached the destination, return the step count
                if (newRow == dest.first && newCol == dest.second) {
                    return steps + 1;
                }

                // Otherwise, mark the position as visited and push to the queue
                vis[newRow][newCol] = true;
                q.push({{newRow, newCol}, steps + 1});
            }
        }
	    }
	    
	    
	}
};
