#define SIZE 9
#define BOX_SIZE 3

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    if(boardSize != 9 || *boardColSize != 9) {
        return false;
    }

    //Valid row
    for(int i = 0; i < SIZE; i++) {
        bool check[SIZE] = {false};
        for (int j = 0; j < 9; j++) {
            char item = board[i][j];
            if (item != '.' && check[item - 0x31] == true) {
                return false;
            } else if(item != '.'){
                check[item - 0x31] = true;
            }
        }
    }

    //Valid column
    for(int i = 0; i < SIZE; i++)
    {
        bool check[SIZE] = {false};

        for (int j = 0; j < 9; j++) {

            char item = board[j][i];

            if (item != '.' && check[item - 0x31] == true) {
                return false;
            } else if(item != '.'){
                check[item - 0x31] = true;
            }
        }
    }

    //Valid 3x3
    int starts[9][2] = {
        {0, 0}, {0, 3}, {0, 6},
        {3, 0}, {3, 3}, {3, 6},
        {6, 0}, {6, 3}, {6, 6}
    };

    for(int i = 0; i < SIZE; i++)
    {
        bool check[SIZE] = {false};

        for (int row = starts[i][0]; row < starts[i][0] + 3; row++)
        {
            for (int col = starts[i][1]; col < starts[i][1] + 3; col++)
            {
                char item = board[row][col];

                if (item != '.' && check[item - 0x31] == true) {
                    return false;
                } else if(item != '.'){
                    check[item - 0x31] = true;
                }
            }
        }
    }

    return true;
}
