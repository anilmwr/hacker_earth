// https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/tutorial/

#include <stdio.h>
#include <stdlib.h>

int is_attacked(int x, int y, int **chess_board, int chess_board_size) {
    for (int i=0; i<chess_board_size; i++) { // check if other Queens are in same row or column
        if (chess_board[x][i] || chess_board[i][y]) {
            return 1;
        }
    }
    for (int i=0; i<chess_board_size; i++) {
        for (int j=0; j<chess_board_size; j++) {
            if ((x+y == i+j) || (x-y == i-j)) {
                if (i == x && j == y) {
                    continue;
                }
                if (chess_board[i][j] == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int n_queens(int **chess_board, int chess_board_size, int queens_count) {
    if (queens_count == 0) {
        return 1;
    }
    
    for (int i=0; i<chess_board_size; i++) {
        for (int j=0; j<chess_board_size; j++) {
            if ((!is_attacked(i, j, chess_board, chess_board_size)) && (chess_board[i][j] != 1)) {
                chess_board[i][j] = 1;
                if (n_queens(chess_board, chess_board_size, queens_count-1)) {
                    return 1;
                }
                chess_board[i][j] = 0;
            }
        }
    }
    return 0;
}

int main(){
	int n, **chess_board;
	scanf("%d", &n);
	
    chess_board = (int **) calloc(n, sizeof(int **));
    for (int i=0; i<n; i++) {
        chess_board[i] = (int *) calloc(n, sizeof(int *));
    }
	if (chess_board == NULL) {
	    printf("calloc failed\n");
	    return 1;
	}
	
	if (n_queens(chess_board, n, n)) {
	    printf("YES\n");
	    for (int i=0; i<n; i++) {
	        for (int j=0; j<n; j++) {
	            printf("%d ", chess_board[i][j]);
	        }
	        printf("\n");
	    }
	} else {
	    printf("NO\n");
	}
}
