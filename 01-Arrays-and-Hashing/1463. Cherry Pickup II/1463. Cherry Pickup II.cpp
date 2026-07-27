class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=size(grid); 
        int m=size(grid[0]); 
        

        // RECURSIVE 

        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1))); 

        // // i,j,k; i row, j col1, k=col2 
        // function<int(int,int,int)>dfs=[&](int i,int j,int k)->int{
           
        //     if(i==n-1)return 0; 
        //     int &ans=dp[i][j][k]; 
        //     if(ans!=-1)return ans; 

        //     ans=0;  
        //     for(int f=-1;f<=1;f++){
        //         for(int s=-1;s<=1;s++){
        //            int c1=j+f,c2=k+s; 
        //            if(c1<0 or c2<0 or c1==m or c2==m )continue; 
        //            int curr=grid[i+1][c1]; 
        //            if(c1!=c2) curr+=grid[i+1][c2];
        //            ans=max(ans,curr+dfs(i+1,c1,c2)); 
        //         }
        //     }

        //     return ans; 
        // };

        // int ans=dfs(0,0,m-1)+grid[0][0];
        // if(m!=1)ans+=grid[0][m-1];  
        // return ans; 
         
        //  Iterative 
        vector<vector<int>>dp(m,vector<int>(m,0)); 
        vector<vector<int>>ndp(m,vector<int>(m,0)); 

        for(int r=n-1; r>=0; r--){

            for(int c1=0; c1<m; c1++){
                for(int c2=0; c2<m; c2++){

                    int &mx=ndp[c1][c2]; 
                    mx=0; 

                    for(int f=-1; f<=1; f++){
                        for(int s=-1; s<=1; s++){

                            int C1=c1+f, C2=c2+s; 
                            if(C1<0 or C2<0 or C1==m or C2==m)continue; 
                            mx=max(mx,dp[C1][C2]); 

                        }
                    }

                    int curr=grid[r][c1];
                    if(c1!=c2) curr+=grid[r][c2]; 
                    mx+=curr;  
                }
            }

            dp.swap(ndp); 
        }

        return dp[0][m-1]; 

    }
};