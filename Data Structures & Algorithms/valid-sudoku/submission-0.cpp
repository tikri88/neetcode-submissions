class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 3 step solution
        // Validate Row, column and 3*3 boxes for duplicates
        for(int r=0; r<9;r++)
        {
            set<int>rowDuplicates;
            for(int c=0; c<9;c++)
            {
                if(rowDuplicates.contains(board[r][c]))
                {
                    return false;
                }
                else if(board[r][c] != '.')
                {
                    rowDuplicates.insert(board[r][c]);
                }
            }
        }

        //validate columns
        for(int r=0; r<9;r++)
        {
            set<int>rowDuplicates;
            for(int c=0; c<9;c++)
            {
                if(rowDuplicates.contains(board[c][r]))
                {
                    return false;
                }
                else if(board[c][r] != '.')
                {
                    rowDuplicates.insert(board[c][r]);
                }
            }
        }

        //Tricky part, validate 3*3 boxes
        vector<pair<int, int>>boxesCordinates = {{0, 0}, {0,3}, {0,6}, {3, 0}, {3, 3}, {3,6}, {6,0},{6,3},{6,6}};

        for(auto val : boxesCordinates)
        {
            set<int>boxDuplicates;
            int row = val.first;
            int col = val.second;
            for(int i=row; i<row+3; i++)
            {
                for(int j=col; j<col+3; j++)
                {
                    if(boxDuplicates.contains(board[i][j]))
                    {
                        return false;
                    }
                    else if(board[i][j] != '.')
                    {
                        boxDuplicates.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
        
    }
};
