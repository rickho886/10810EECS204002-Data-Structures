#include <iostream>
#include <string>
using namespace std;
int row, col;
int lose;
int arr[41][16];

int T1[2][3] = {{1,1,1},
                {0,1,0}};

int T2[3][2] = {{0,1},
                {1,1},
                {0,1}};

int T3[2][3] = {{0,1,0},
                {1,1,1}};

int T4[3][2] = {{1,0},
                {1,1},
                {1,0}};

int L1[3][2] = {{1,0},
                {1,0},
                {1,1}};

int L2[2][3] = {{1,1,1},
                {1,0,0}};

int L3[3][2] = {{1,1},
                {0,1},
                {0,1}};

int L4[2][3] = {{0,0,1},
                {1,1,1}};

int J1[3][2] = {{0,1},
                {0,1},
                {1,1}};

int J2[2][3] = {{1,0,0},
                {1,1,1}};

int J3[3][2] = {{1,1},
                {1,0},
                {1,0}};

int J4[2][3] = {{1,1,1},
                {0,0,1}};

int S1[2][3] = {{0,1,1},
                {1,1,0}};

int S2[3][2] = {{1,0},
                {1,1},
                {0,1}};

int Z1[2][3] = {{1,1,0},
                {0,1,1}};

int Z2[3][2] = {{0,1},
                {1,1},
                {1,0}};

int I1[4][1] = {{1},
                {1},
                {1},
                {1},};

int I2[1][4] = {1,1,1,1};

int O[2][2] = {{1,1},
               {1,1}};

int searchMatrix(int c, int type);
void checkMatrix();
void eliminateLine(int i);
void printMatrix();
void matrixPlacement(int c, int type);
void checkLose();

int searchMatrix(int c, int type) {
    int i, j, k;
    int tetris_row, tetris_col;
    int flag = 0;
    if(type == 1) {
        tetris_row = 2;
        tetris_col = 3;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + T1[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
                /*if(arr[i+j][c+k-1]) {
                    cout << i << " " << c << endl;
                    cout << "aneh wew";
                    flag = 1;
                    break;
                }*/
            }
            if(flag) {
                cout << i << " " << j << " " << endl;
                return i-1;
            }
        }
    } else if(type == 2) {
        tetris_row = 3;
        tetris_col = 2;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + T2[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
                /*if(arr[i+j][c+k-1]) {
                    cout << i << " " << c << endl;
                    cout << "aneh wew";
                    flag = 1;
                    break;
                }*/
            }
            if(flag) {
                cout << i << " " << j << " " << endl;
                return i-1;
            }
        }
    } else if(type == 3) {
        tetris_row = 2;
        tetris_col = 3;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + T3[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
                /*if(arr[i+j][c+k-1]) {
                    cout << i << " " << c << endl;
                    cout << "aneh wew";
                    flag = 1;
                    break;
                }*/
            }
            if(flag) {
                cout << i << " " << j << " " << endl;
                return i-1;
            }
        }
    } else if(type == 4) {
        tetris_row = 3;
        tetris_col = 2;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + T4[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
                /*if(arr[i+j][c+k-1]) {
                    cout << i << " " << c << endl;
                    cout << "aneh wew";
                    flag = 1;
                    break;
                }*/
            }
            if(flag) {
                cout << i << " " << j << " " << endl;
                return i-1;
            }
        }
    } else if(type == 5) {
        tetris_row = 3;
        tetris_col = 2;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + L1[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) {
                cout << i << " " << j << " " << endl;
                return i-1;
            }
        }
    } else if(type == 6) {
        tetris_row = 2;
        tetris_col = 3;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + L2[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) {
                cout << i << " " << j << " " << endl;
                return i-1;
            }
        }
    } else if(type == 7) {
        tetris_row = 3;
        tetris_col = 2;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + L3[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) {
                cout << i << " " << j << " " << endl;
                return i-1;
            }
        }
    } else if(type == 8) {
        tetris_row = 2;
        tetris_col = 3;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + L4[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) {
                cout << i << " " << j << " " << endl;
                return i-1;
            }
        }
    } else if(type == 9) {
        tetris_row = 3;
        tetris_col = 2;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + J1[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) {
                cout << i << " " << j << " " << endl;
                return i-1;
            }
        }
    } else if(type == 10) {
        tetris_row = 2;
        tetris_col = 3;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + J2[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) {
                cout << i << " " << j << " " << endl;
                return i-1;
            }
        }
    } else if(type == 11) {
        tetris_row = 3;
        tetris_col = 2;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + J3[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) {
                cout << i << " " << j << " " << endl;
                return i-1;
            }
        }
    } else if(type == 12) {
        tetris_row = 2;
        tetris_col = 3;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + J4[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) {
                cout << i << " " << j << " " << endl;
                return i-1;
            }
        }
    } else if(type == 13) {
        tetris_row = 2;
        tetris_col = 3;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + S1[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
                /*if(arr[i+j][c+k-1]) {
                    cout << i << " " << c << endl;
                    cout << "aneh wew";
                    flag = 1;
                    break;
                }*/
            }
            if(flag) {
                cout << i << " " << j << " " << endl;
                return i-1;
            }
        }
    } else if(type == 14) {
        tetris_row = 3;
        tetris_col = 2;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + S2[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
                /*if(arr[i+j][c+k-1]) {
                    cout << i << " " << c << endl;
                    cout << "aneh wew";
                    flag = 1;
                    break;
                }*/
            }
            if(flag) {
                cout << i << " " << j << " " << endl;
                return i-1;
            }
        }
    } else if(type == 15) {
        tetris_row = 2;
        tetris_col = 3;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + Z1[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
                /*if(arr[i+j][c+k-1]) {
                    cout << i << " " << c << endl;
                    cout << "aneh wew";
                    flag = 1;
                    break;
                }*/
            }
            if(flag) {
                cout << i << " " << j << " " << endl;
                return i-1;
            }
        }
    } else if(type == 16) {
        tetris_row = 3;
        tetris_col = 2;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + Z2[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
                /*if(arr[i+j][c+k-1]) {
                    cout << i << " " << c << endl;
                    cout << "aneh wew";
                    flag = 1;
                    break;
                }*/
            }
            if(flag) {
                cout << i << " " << j << " " << endl;
                return i-1;
            }
        }
    } else if(type == 17) {
        tetris_row = 4;
        tetris_col = 1;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + I1[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
                if(arr[i+j][c+k-1]) {
                    cout << i << " " << c << endl;
                    cout << "aneh wew";
                    flag = 1;
                    break;
                }
            }
            if(flag) {
                return i-1;
            }
        }
    } else if(type == 18) {
        tetris_row = 1;
        tetris_col = 4;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + I2[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
                if(arr[i+j][c+k-1]) {
                    cout << i << " " << c << endl;
                    cout << "aneh wew";
                    flag = 1;
                    break;
                }
            }
            if(flag) {
                return i-1;
            }
        }
    } else if(type == 19) {
        tetris_row = 2;
        tetris_col = 2;
        if(tetris_col + c > col) {
            return -1;
        }
        for(i = 1; i < row; i++) {
            for(j = 0; j < tetris_row; j++) {
                for(k = 0; k < tetris_col; k++) {
                    if(arr[i+j][c+k] + O[j][k] > 1) {
                        flag = 1;
                        cout << "aneh : " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                if(flag) break;
                if(arr[i+j][c+k-1]) {
                    cout << i << " " << c << endl;
                    cout << "aneh wew";
                    flag = 1;
                    break;
                }
            }
            if(flag) {
                return i-1;
            }
        }
    }
    return i-tetris_row;
}

void matrixPlacement(int c, int type) {
    int place = 0;
    int i = searchMatrix(c, type);
    if(type == 1) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += T1[j][k];
            }
        }
    } else if(type == 2) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 2; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += T2[j][k];
            }
        }
    } else if(type == 3) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += T3[j][k];
            }
        }
    } else if(type == 4) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 2; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += T4[j][k];
            }
        }
    } else if(type == 5) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 2; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += L1[j][k];
            }
        }
    } else if(type == 6) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += L2[j][k];
            }
        }
    } else if(type == 7) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 2; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += L3[j][k];
            }
        }
    } else if(type == 8) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += L4[j][k];
            }
        }
    } else if(type == 9) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 2; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += J1[j][k];
            }
        }
    } else if(type == 10) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += J2[j][k];
            }
        }
    } else if(type == 11) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 2; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += J3[j][k];
            }
        }
    } else if(type == 12) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += J4[j][k];
            }
        }
    } else if(type == 13) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += S1[j][k];
            }
        }
    } else if(type == 14) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 2; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += S2[j][k];
            }
        }
    } else if(type == 15) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += Z1[j][k];
            }
        }
    } else if(type == 16) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 2; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += Z2[j][k];
            }
        }
    } else if(type == 17) {
        for(int j = 0; j < 4; j++) {
            if(!(arr[i+j][c]))
                arr[i+j][c] += I1[j][0];
        }
    } else if(type == 18) {
        for(int j = 0; j < 4; j++) {
            if(!(arr[i][c+j]))
                arr[i][c+j] += I2[0][j];
        }
    } else if(type == 19) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                if(!(arr[i+j][c+k]))
                    arr[i+j][c+k] += O[j][k];
            }
        }
    }
    checkMatrix();
    checkLose();
}

void printMatrix() {
    //freopen("tetris.final", "w", stdout);
    for(int i = 1; i < row; i++) {
        for(int j = 1; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void eliminateLine(int i) {
    for(int j = i; j > 0; j--) {
        for(int k = 0; k < col; k++) {
            arr[j][k] = arr[j-1][k];
        }
    }
}

void checkMatrix() {
    int i;
    /*for(i = row-1; i > 1 ; i--) {
        int eliminate = 1;
        for(int j = 1; j < col; j++) {
            if(arr[i][j] == 0) {
                eliminate = 0;
                break;
            }
        }
        if(eliminate) {
            eliminateLine(i);
            i++;
        }
    }*/
    for(i = 1; i < row; i++) {
        int eliminate = 1;
        for(int j = 1; j < col; j++) {
            if(arr[i][j] == 0) {
                eliminate = 0;
                break;
            }
        }
        if(eliminate) {
            eliminateLine(i);
        }
    }
}

void checkLose() {
    for(int i = 1; i < col; i++) {
        if(arr[0][i] == 1) {
            lose = 1;
        }
    }
}

int main()
{
    int c;
    string com;
    lose = 0;
    cin >> row >> col;
    row++; col++;
    while(1) {
        if(lose) {
            //cout << "You Lose!" << endl;
            break;
        }
        cin >> com;
        if(com == "End") {
            break;
        } else if(com == "print") {
            printMatrix();
        } else {
            cin >> c;
            //if(c > col-1) {
            //    cout << "Please input the right column!";
            //   return 0;
            //}
        }
        if(com == "T1") {
            matrixPlacement(c, 1);
        } else if(com == "T2") {
            matrixPlacement(c, 2);
        } else if(com == "T3") {
            matrixPlacement(c, 3);
        } else if(com == "T4") {
            matrixPlacement(c, 4);
        } else if(com == "L1") {
            matrixPlacement(c, 5);
        } else if(com == "L2") {
            matrixPlacement(c, 6);
        } else if(com == "L3") {
            matrixPlacement(c, 7);
        } else if(com == "L4") {
            matrixPlacement(c, 8);
        } else if(com == "J1") {
            matrixPlacement(c, 9);
        } else if(com == "J2") {
            matrixPlacement(c, 10);
        } else if(com == "J3") {
            matrixPlacement(c, 11);
        } else if(com == "J4") {
            matrixPlacement(c, 12);
        } else if(com == "S1") {
            matrixPlacement(c, 13);
        } else if(com == "S2") {
            matrixPlacement(c, 14);
        } else if(com == "Z1") {
            matrixPlacement(c, 15);
        } else if(com == "Z2") {
            matrixPlacement(c, 16);
        } else if(com == "I1") {
            matrixPlacement(c, 17);
        } else if(com == "I2") {
            matrixPlacement(c, 18);
        } else if(com == "O") {
            matrixPlacement(c, 19);
        }
    }
    printMatrix();
}
