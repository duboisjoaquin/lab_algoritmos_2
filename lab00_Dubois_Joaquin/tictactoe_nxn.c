/*gcc -Wall -Wextra -Werror -std=c99 archivo.c -o ejecutable*/

#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

int tam = 5;

#define CELL_MAX (tam * tam - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[tam][tam])
{
    int cell = 0;

    print_sep(tam);
    for (int row = 0; row < tam; ++row) {
        for (int column = 0; column < tam; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(tam);
    }
}

char get_winner(char board[tam][tam])
{
    char winner = '-';

    bool win_exist = 0; 

    int contX,contO,i,j;
    

//check row

    for (i=0; i<tam && win_exist==0 ; i++){
        contX = 0;
        contO = 0;
        for (j=0; j<tam && win_exist==0; j++){
            
            if (board[i][j] == 'X' && win_exist == 0){
                contX = contX+1;
            }
            else if (board[i][j] == 'O' && win_exist == 0){
                contO = contO+1;
            }
            
        }
        if (contO == tam){
            win_exist = 1;
            winner = 'O';
        }
        else if (contX == tam){
            win_exist = 1;
            winner = 'O';
        }
        else{
            contX = 0, contO = 0;
        }
        
        
    }


//check column

    for (i=0; i<tam && win_exist==0 ; i++){
        contX = 0;
        contO = 0;
        for (j=0; j<tam && win_exist==0; j++){
            
            if (board[j][i] == 'X'){
                contX = contX+1;
            }
            else if (board[j][i] == 'O'){
                contO = contO+1;
            }
            
        }
        if (contO == tam){
            win_exist = 1;
            winner = 'O';
        }
        else if (contX == tam){
            win_exist = 1;
            winner = 'X';
        }
        else{
            contX = 0, contO = 0;
        }
        
    }

//check principal diagonal

contX = 0, contO = 0;
    for (i=0; i<tam && win_exist==0; i++){
        if (board[i][i]=='X'){
            contX++;
        }
        else if (board[i][i]=='O'){
            contO++;        
        }
        if (contX==tam){
            win_exist = 1;
            winner = 'X';
        }
        else if (contO==tam){
            win_exist = 1;
            winner='O';        
        }
    }

//check sec diagonal

    contX = 0, contO = 0;
    j = tam-1;
    for (i=0; i<tam && win_exist==0; i++){
        if (board[i][j]=='X'){
            contX++;
        }
        else if(board[i][j]=='O'){
            contO++;
        }
        if (contX==tam){
            win_exist = 1;
            winner = 'X';
        }
        else if (contO==tam){
            win_exist = 1;
            winner='O';        
        }
        j = j-1;
    }
    return winner;

    }

bool has_free_cell(char board[tam][tam])
{
    bool free_cell= 1;

    int i,j;
    int cont = 0;

    for (i=0; i<tam; i++){
        for (j=0; j<tam; j++){
            if (board[i][j] != '-'){
                cont = cont + 1;
            }
        }
    }

    if (cont == (tam*tam)){
        free_cell = 0;
    }
    
    return free_cell;
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[tam][tam];
    int i,j;
    for (i=0;i<tam;i++){
        for (j=0;j<tam;j++){
            board[i][j]='-';
        }
    }

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
            int row = cell / tam;
            int colum = cell % tam;
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
