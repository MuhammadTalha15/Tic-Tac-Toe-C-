#include <iostream>
#include <String.h>
#include <cstring>

using namespace std;

char currentPlayer = 'X';
bool isGameActive = true;
char gameBoard[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int winConditions[][3] = 
{
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}
};

int displayPlayer(char Player){
    cout<<" "<<endl;
    cout<< "Player " << Player << "'s Turn" <<endl;
}

void makeGameBoard(){
    cout << "-------------" <<endl;
    cout << "| " << gameBoard[0] << " | " << gameBoard[1] << " | " << gameBoard[2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << gameBoard[3] << " | " << gameBoard[4] << " | " << gameBoard[5] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << gameBoard[6] << " | " << gameBoard[7] << " | " << gameBoard[8] << " |" << endl;
    cout << "-------------" <<endl;
}

int handlePlayer(){
    int userChoice;

    cout << "Enter your Choice (0 - 9): "<<endl;
    cin>> userChoice;

        if (userChoice >= 0 && userChoice < 9 && gameBoard[userChoice] == ' '){
            gameBoard[userChoice] = currentPlayer;
            currentPlayer == 'X' ? currentPlayer = 'O' : currentPlayer = 'X';
        }
        else{
            cout<< "Enter Valid Choice"<<endl;
        }
}

int handleResultValidation(){
    for (const auto& combination : winConditions) {
        int a = combination[0];
        int b = combination[1];
        int c = combination[2];

        if (gameBoard[a] && gameBoard[a] == gameBoard[b] && gameBoard[a] == gameBoard[c]) {
            return gameBoard[a];
        }
    }
    return '\0';
}

int finalWin(){
    char wonPawn = handleResultValidation();
    if (wonPawn == 'X' || wonPawn == 'O'){
        makeGameBoard();
        isGameActive = false;
        cout<< "Player "<< wonPawn << " has Won!";
    }
}

bool checkDraw(){
    for(int i = 0; i < 9; i++){
        if(gameBoard[i] == ' '){
            return false;
        }
    }
    return true;
}

int main(){
    
    while(isGameActive){
        displayPlayer(currentPlayer);
        makeGameBoard();
        handlePlayer();
        
        if(checkDraw()){
            makeGameBoard();
            cout<<"It's a Draw"<<endl;
            break;
        }
        else{
            finalWin();
        }
    }
}