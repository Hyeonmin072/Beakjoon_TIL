#define MAX_SIZE 101
#include<stdio.h>
#include<algorithm>
using namespace std;

int sudoku[9][9];
int N;

bool check(int row, int col, int num) {
    // 행 검사
    for(int i=0; i<9; i++)
        if(sudoku[row][i] == num) return false;
    
    // 열 검사
    for(int i=0; i<9; i++)
        if(sudoku[i][col] == num) return false;
    
    // 3x3 박스 검사
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(sudoku[startRow + i][startCol + j] == num) return false;
    
    return true;
}

bool sdk(int row, int col) {
    if(col == 9) {
        row++;
        col = 0;
    }
    
    if(row == 9)
        return true;  // 스도쿠 완성
    
    if(sudoku[row][col] != 0)
        return sdk(row, col + 1);
    
    for(int num = 1; num <= 9; num++) {
        if(check(row, col, num)) {
            sudoku[row][col] = num;
            if(sdk(row, col + 1))
                return true;
            sudoku[row][col] = 0;  // 백트래킹
        }
    }
    
    return false;
}

int main() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }

    if(sdk(0, 0)) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists\n");
    }

    return 0;
}