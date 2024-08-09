class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int ans=0;
        for(int i=0; i<n-2; i++){
            for(int j=0; j<m-2; j++){
                int sum=0; 
                for(int ii=i; ii<i+3; ii++) sum += grid[ii][j];
                int temp=0, flag=0;
                //sum rows
                for(int ii=i; ii<i+3; ii++){
                    temp=0;
                    for(int jj=j; jj<j+3; jj++){
                        temp += grid[ii][jj];
                    }
                    if(temp != sum){
                        flag=1; break;
                    } 
                }
                //sum cols
                for(int jj=j; jj<j+3; jj++){
                    temp=0;
                    for(int ii=i; ii<i+3; ii++){
                        temp += grid[ii][jj];
                    }
                    if(temp != sum){
                        flag=1; break;
                    } 
                }
                // sum diagonals
                temp=0;
                for(int ii=i, jj=j; ii<i+3 && jj<j+3; ii++, jj++)
                    temp += grid[ii][jj];  
                if(temp != sum) flag=1;
                
                temp=0;
                for(int ii=i, jj=j+2; ii<i+3 && jj>=j; ii++, jj--)
                    temp += grid[ii][jj];  
                if(temp != sum) flag=1; 

                if(flag) continue;

                map<int, int> mp;
                for(int ii=i; ii<i+3; ii++)
                    for(int jj=j; jj<j+3; jj++)
                        mp[grid[ii][jj]]++;
                int cnt=0;
                for(int ii=1; ii<=9; ii++) 
                    if(mp[ii]) cnt++;
                if(cnt == 9) ans++;
            }
        }
        return ans;
    }
};