func isValidSudoku(board [][]byte) bool {
    if len(board) != 9 { 
        return false;
    }

    //validate row
    for i:=0; i<9; i++ {
        check := []bool{false, false, false, false, false, false, false, false, false}

        for j:=0; j<9; j++ {
            item := board[i][j]

            if item != '.' && check[item - 0x31] == true {
                return false;
            } else if item != '.' {
                check[item - 0x31] = true;
            }
        }
    }

    //valid column
    for i:=0; i<9; i++ {
        check := []bool{false, false, false, false, false, false, false, false, false}

        for j:=0; j<9; j++ {
            item := board[j][i]

            if item != '.' && check[item - 0x31] == true {
                return false;
            } else if item != '.' {
                check[item - 0x31] = true;
            }
        }
    }

    //valid 3x3
    var starts [9][2]int = [9][2]int{
        {0, 0}, {0, 3}, {0, 6},
        {3, 0}, {3, 3}, {3, 6},
        {6, 0}, {6, 3}, {6, 6},
    }

    for i := 0; i < 9; i++ {
        check := []bool{false, false, false, false, false, false, false, false, false}

        for row := starts[i][0]; row < starts[i][0] + 3; row++ {
            for col := starts[i][1]; col < starts[i][1] + 3; col++ {
                item := board[row][col];

                if item != '.' && check[item - 0x31] == true {
                    return false;
                } else if item != '.' {
                    check[item - 0x31] = true;
                }
            }
        }
    }

    return true;
}