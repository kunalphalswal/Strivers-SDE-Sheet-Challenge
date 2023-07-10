class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        
        int m=matrix.size(),n=matrix[0].size();
        int marker_row=-1,marker_col=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(marker_row==-1){
                        marker_row=i;marker_col=j;

                    }else{
                        matrix[marker_row][j]=0;
                        matrix[i][marker_col]=0;
                    }
                }
            }
        }
        if(marker_row==-1) return;
        for(int j=0;j<n;j++){
            if(j==marker_col)continue;
            else{
                if(matrix[marker_row][j]==0){
                    for(int i=0;i<m;i++){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            if(matrix[i][marker_col]==0){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<m;i++)matrix[i][marker_col]=0;
    }
};
