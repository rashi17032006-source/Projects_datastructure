#include <iostream>
#include<limits>
using namespace std;

#define RED   "\033[31m"
#define BLUE  "\033[34m"
#define RESET "\033[0m"

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char currentmarker;
int currentplayer;
char player1_marker;
char player2_marker;
void drawboard(){
    cout<<"\n";
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            char c = board[i][j];
            if(c=='X')cout<<RED<<"X"<<RESET;
            else if (c=='O')cout<<BLUE<<"O"<<RESET;
            else cout<< c;

            if(j<2)cout<<" | ";
        }
        cout<<"\n";
        if(i<2)cout<<"--------\n";
    }
    cout<<"\n";           
}
bool placemarker(int slot){
    int row = (slot -1)/3;
    int col = (slot-1)%3;
    if(board[row][col]!='X'&&board[row][col]!='O'){

        board[row][col]=currentmarker;
        return true;
    }
    else{
        return false;
    }
}

int winner(){
    for( int i=0;i<3;i++){

        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2])
        return currentplayer;
        if (board[0][i]==board[1][i]&&board[1][ i]==board[2][i])
        return currentplayer;
  }
  if(board[0][0] == board[1][1]&& board[1][1] == board[2][2])
  return currentplayer;
  if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
  return currentplayer;
  return 0;
}
void swapplayerandmarker (){
    if(currentplayer == 1){
        currentplayer = 2;
        currentmarker =player2_marker;
    }
     else{
    currentplayer= 1;
    currentmarker = player1_marker;
}
}
void game(){
    int player_won;
    cout<<"Player 1,Choose yuour marker (X or O):";
    cin>>player1_marker;
    if(player1_marker == 'X')
    player2_marker = 'O';
    else 
    player2_marker = 'X';

    currentmarker = player1_marker;
    currentplayer = 1;
     drawboard();
    for(int i=0;i<9;i++){
        int slot ;
        cout<<"player"<<currentplayer<<"'s turn.enter slot;";
        cin>>slot;
        if(cin.fail()||slot<1||slot>9 ||!placemarker(slot)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"INVALID MOVE! Try Again.\n";
            i--;
            continue;
        }
        drawboard();
        player_won =winner();
        if(player_won!=0){
            cout<<"player" <<player_won<<"wins!";
        return;
     }
     swapplayerandmarker();


    }
    cout<<"ITs a Draw !\n";
}
int main(){
    game();
    return 0;
}