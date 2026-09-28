class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Single Pass solution. Consider 2-D array as single flatten array and apply binary search. complexity o(log(m*n))
        int rows = matrix.size();
        int columns = matrix[0].size();
        int l=0, r= rows*columns-1;
        while(l <= r)
        {
            int m = l + (r-l)/2;
            int ri = m/columns;
            int ci = m%columns;
            if(target == matrix[ri][ci])
                return true;
            else if(target > matrix[ri][ci])
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
