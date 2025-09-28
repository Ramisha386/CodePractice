class Solution {
    public:
        vector<int> compute(vector<vector<int>>& matrix)
        {
            int i=0;
            int j=0;
            int row=matrix.size();
            int col=matrix[0].size();
            int sr,sc;
            int totalEl=row*col;
            int count=0;
            vector<int>ans;
            while(count!=totalEl)
            {
                 //HR-->
                sr=i;
                sc=j;
               
                for(int m=sc;m<col;m++)
                {
                    ans.push_back(matrix[sr][m]);
                    count++;
                    if(count==totalEl) return ans;
                }
    
                //DD -->
    
                sc=col-1;
                for(int m=sr+1;m<row;m++)
                {
                    ans.push_back(matrix[m][sc]);
                    count++;
                    if(count==totalEl) return ans;
                }
    
                //HL-->
    
                sr=row-1;
                for(int m=sc-1;m>=j;m--)
                {
                    ans.push_back(matrix[sr][m]);
                    count++;
                    if(count==totalEl) return ans;
                }
    
                //DU-->
    
                sc=j;
                for(int m=sr-1;m>i;m--)
                {
                    ans.push_back(matrix[m][sc]);
                    count++;
                    if(count==totalEl) return ans;
                }
                i++;
                j++;
                row--;col--;
             
    
            }
            return ans;
    
            
        }
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> result;
    
            result=compute(matrix);
            return result;
            
        }
    };
    