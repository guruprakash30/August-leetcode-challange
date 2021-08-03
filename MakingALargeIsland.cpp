class Solution {
public:
    void sizeexpandisland(int x,int y,vector<vector<int>>& grid,map<pair<int,int>,set<int>>& m,int n,int k,int& cnt){
        if(x<0 or y<0 or x>=n or y>=n or grid[x][y]==2 or grid[x][y]==k)return;
        else if(grid[x][y]==0){grid[x][y]=k;m[{x,y}].insert(k);}
        else if(grid[x][y]!=1){
            m[{x,y}].insert(k);
        }
        else{
            cnt++;
            grid[x][y]=2;
            sizeexpandisland(x+1,y,grid,m,n,k,cnt);
            sizeexpandisland(x,y+1,grid,m,n,k,cnt);
            sizeexpandisland(x-1,y,grid,m,n,k,cnt);
            sizeexpandisland(x,y-1,grid,m,n,k,cnt);
        }
        return;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int k=501;
        int cnt=0;
        int n=grid.size();
        map<pair<int,int>,set<int>>m;
        unordered_map<int,int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    sizeexpandisland(i,j,grid,m,n,k,cnt);
                    ans[k]=cnt;
                    cnt=0;
                    k++;
                }
            }
        }
        int req=INT_MIN;
        for(auto itr=m.begin();itr!=m.end();itr++){
            int dup=0;
            for(auto it=itr->second.begin();it!=itr->second.end();it++){
                dup+=(ans[*it]);
            }
            req=max(dup+1,req);
        }
        if(m.size()==0 and ans.size()!=0)return n*n;
        if(req==INT_MIN)return 1;
        else return req;
    }
};
