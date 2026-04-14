class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        if(grid.empty()) return 0;

        int m = grid.size();
        int n= grid[0].size();

        int days =0; //number of minutees passed
        int tot =0;  //total number of oranges (fresh + rotten)
        int cnt =0;  //how many oranges become rotten during the process

        queue<pair<int , int>> rotten;

        //traverse the grid to count total oranges and push rotten one to the queue
        for(int i =0; i<m; i++){
            for(int j =0 ; j<n ; j++){

                if(grid[i][j] !=0){
                    tot++;     //count it as a valid orange
                }

                if(grid[i][j] ==2){
                    rotten.push({i,j});
                }
            }
        }

        //arrays to explore the 4 directions: right, left , down , up
        int dx[4] = {0 ,0 , 1,-1};
        int dy[4] = {1 , -1 , 0 , 0};

        while(!rotten.empty()){

            int k = rotten.size();
            cnt += k; //add these many oranges to the count of rotted oranges

            while(k--){
                int x = rotten.front().first;
                int y = rotten.front().second;

                rotten.pop();

                for(int i =0; i<4; i++){
                    int nx = x + dx[i];   //new x - coordinate
                    int ny = y + dy[i];   // new y-coordinate

                    //skip invalid coordinates or already rotten/empty cells
                    if(nx <0 || ny <0 || nx >=m || ny >=n || grid[nx][ny] != 1){
                        continue;
                    }

                    grid[nx][ny] =2;  //mark the fresh orange as rotten

                    rotten.push({nx , ny});
                }
            }
            
            //if new oranges were added to the queue, increase the time
            if(!rotten.empty()){
                days++;
            }
        }
        return tot == cnt ? days : -1;
    }
};