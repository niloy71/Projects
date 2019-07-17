#include <stdio.h>

void drawBoard(char board[10])
{
    printf(" %c | %c | %c\n",board[1],board[2],board[3]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",board[4],board[5],board[6]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",board[7],board[8],board[9]);
}

void drawMainBoard()
{
    printf("\nBoard:\n");
    printf(" 1 | 2 | 3\n");
    printf("---+---+---\n");
    printf(" 4 | 5 | 6\n");
    printf("---+---+---\n");
    printf(" 7 | 8 | 9\n");
    printf("\nInput the value of the Square in which you want to play.\n\n");
}
int checkWin(char board[10])
{
    int wins[8][3] = {{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}}, i;
    for(i = 0; i < 8; ++i) {
        if(board[wins[i][0]] != ' ' &&
           board[wins[i][0]] == board[wins[i][1]] &&
           board[wins[i][0]] == board[wins[i][2]])
            return 1;
    }
    return 0;
}

int checkValid(char board[10], int move)
{
    if(move < 1 || move > 9 || board[move] != ' '){
        printf("\nInvalid move!! Please, Try a valid square: ");
        return 1;
    }
    else
        return 0;
}

int backtrack(char board[10], int player)
{
    if(checkWin(board) == 1){
        return -1;
    }
    int i, tmp, move = 0, score = -2;
    for(i = 1; i <= 9; i++){
        if(board[i] == ' '){
            if(player == 1)
                board[i] = 'O';
            else
                board[i] = 'X';
            tmp = -backtrack(board, player*-1);
            if(tmp > score){
                score = tmp;
                move = i;
            }
            board[i] = ' ';
        }
    }
    if(move == 0)
        return 0;
    else
        return score;
}
int playerMove(char board[10])
{
    int move;
    drawBoard(board);
    scanf("%d", &move);
    while(checkValid(board, move)){
        scanf("%d", &move);
    }
    board[move] = 'O';
}

int computerMove(char board[10])
{
    int i, tmp, move, score = -2;
    for(i = 1; i <= 9; i++){
        if(board[i] == ' '){
            board[i] = 'X';
            tmp = -backtrack(board, 1);
            if(tmp > score){
                score = tmp;
                move = i;
            }
            board[i] = ' ';
        }
    }
    board[move] = 'X';
}
int multiPlayer()
{
     printf("----------------------------------------------------------------------------\nWelcome to Multi-Player Mode.\n");
    drawMainBoard();
    char board[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int i, player, move, draw = 1;
    for(i = 0; i < 9; i++){
        player = (i % 2) + 1;
        printf("Player %d Move: ", player);
        scanf("%d", &move);

        while(1 == checkValid(board, move)){
            scanf("%d", &move);
        }
        if(player == 1)
            board[move] = 'O';
        else
            board[move] = 'X';
        drawBoard(board);
        if(checkWin(board) == 1){
            printf("\nCongratulation Player %d. YOU WON!!!!\n\n", player);
            draw = 0;
            break;
        }
    }
    if(draw == 1)
        printf("OHH!! It's a DRAW\n\n");
}
int singlePlayer()
{
    char board[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int i, player, move, draw = 1;
    printf("----------------------------------------------------------------------------\nWelcome to Single Player Mode.\n\n");
    printf("What do you want?\n(1) Playing First\n(2) Playing Second\n\nChoose Your Option: ");
    scanf("%d", &player);
    while(player != 1 && player != 2){
        printf("\n!!!Invalid Input!!!\n\nFor Playing First Input: 1\nFor Playing Second Input: 2\n\nSelect Game Mode: ");
        scanf("%d", &player);
    }
    drawMainBoard();
    for(i = 0; i < 9; i++){
        move = (i + player) % 2;
        if(move == 1)
            playerMove(board);
        else
            computerMove(board);

        if(move == 0)
            move = 2;
        if(checkWin(board)){
            drawBoard(board);
            if(move == player)
                printf("\nCongratulation!!! YOU WON\n");
            else
                printf("\nYOU LOSE!!\n");
            draw = 0;
            break;
        }
    }
    if(draw){
        drawBoard(board);
        printf("\nOHH!! It's a draw.\n");
    }
}


int main()
{
    int mode;
    printf("Which mode u want to play?\n\n(1) Single Player\n(2) Multi-player\n\nSelect Game Mode: ");
    scanf("%d", &mode);
    while(mode != 1 && mode != 2){
        printf("\n!!!Invalid Input!!!\n\nFor Single Player Input: 1\nFor Multi-player Input: 2\n\nSelect Game Mode: ");
        scanf("%d", &mode);
    }
    if(mode == 1)
        singlePlayer();
    else
        multiPlayer();
    return 0;
}
