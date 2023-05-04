/*gcc -Wall -Wextra -Werror -std=c99 archivo.c -o ejecutable*/

#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (3 * 3 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[3][3])
{
    int cell = 0;

    print_sep(3);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}

char get_winner(char board[3][3])
{
    char winner = '-';

    bool win_exist = 0; 
    

//check row

    int i = 0;

    while (i<3 && win_exist==0){
        if (board[i][0] == board[i][1] && board[i][1]==board[i][2]){
        
            winner = board[i][1];

            if(winner != '-'){
                win_exist = 1;
        }
    }

    i=i+1;
}


//check column

int j = 0;

while (j<3 && win_exist==0)
{
    if (board[0][j] == board[1][j] && board[1][j]==board[2][j]){
        
        winner = board[1][j];

        if(winner != '-'){
            win_exist = 1;
        }
    }

    j=j+1;
}

//check diagonal

    if (board[0][0] == board [1][1] && board[1][1] == board [2][2]){
        winner = board[1][1];

        if (winner != '-'){
            win_exist = 1;
        }
    }

    if (board[0][2] == board [1][1] && board[1][1] == board [2][0]){
        winner = board[1][1];

        if (winner != '-'){
            win_exist = 1;
        }
    }

    return winner;

    }

bool has_free_cell(char board[3][3])
{
    bool free_cell= 1;

    int i,j;
    int cont = 0;

    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            if (board[i][j] != '-'){
                cont = cont + 1;
            }
        }
    }

    if (cont == (9)){
        free_cell = 0;
    }
    
    return free_cell;
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[3][3] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn, CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 3;
            int colum = cell % 3;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
