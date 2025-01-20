public class Sudoku {

    static void solveSudoku(char[][] table) {
        boolean[][] ca = new boolean[9][9];
        boolean[][] cb = new boolean[9][9];
        boolean[][] cc = new boolean[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = table[i][j];
                if (ch != '.') {
                    ca[i][ch - '1'] = true;
                    cb[j][ch - '1'] = true;
                    cc[i / 3 * 3 + j / 3][ch - '1'] = true;
                }
            }
        }
        dfs(0, 0, table, ca, cb, cc)
    }

    static boolean dfs(int i, int j, char[][] table, boolean[][] ca, boolean[][] cb, boolean[][] cc) {
        while (table[i][j] != '.') {
            if (++j >= 9) {
                j = 0;
                i++;
            }
            if (i >= 9) {
                return true;
            }
        }
        for (int x = 1; x <= 9; x++) {
            if (ca[i][x - 1] || cb[j][x - 1] || cc[i / 3 * 3 + j / 3][x - 1]) {
                continue;
            }
            table[i][j] = (char)(x + '0');
            ca[i][x - 1] = cb[j][x - 1] = cc[i / 3 * 3 + j / 3][x - 1] = true;
            if (dfs(i, j, table, ca, cb, cc)) {
                return true;
            }
            ca[i][x - 1] = cb[j][x - 1] = cc[i / 3 * 3 + j / 3][x - 1] = false;
            table[i][j] = '.';
        }
        return false;
    }
}

