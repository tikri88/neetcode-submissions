class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Complexity, o(log m) + o(log n), log m for searching row where target might be present, log n to check if target really exist in that row.
        int top=0, bot=matrix.size()-1;
        int columns = matrix[0].size()-1;
        while(top <= bot)
        {
            int r = top + (bot-top)/2;
            if(target > matrix[r][columns])
                top = r+1;
            else if(target < matrix[r][0])
                bot = r-1;
            else
                break;
        }
        //It may happend element is not present in any of the row
        if(!(top <= bot))
            return false;
        //Now we have located row, which contains the element. Now we just need to search element in 1-D array
        int row = (top+bot)/2;
        int l=0, r=columns;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(matrix[row][m] == target)
            {
                return true;
            }
            else if(matrix[row][m] < target)
            {
                l = m+1;
            }
            else
            {
                r = m-1;
            }
        }
        return false;
        
    }
};
