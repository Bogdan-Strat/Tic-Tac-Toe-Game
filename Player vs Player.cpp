#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v{
    {-1,-2,-3},
    {-4,-5,-6},
    {-7,-8,-9}
};
 int draw=0;

void printGame();

void putX(int position){
    if(position <= 3){
        if(v[0][position-1]>0){
            cout<<"This position is already occupied. Please re-entered a new position\n.";
            cin>>position;
            putX(position);
        }
        else
            v[0][position-1]=1;
    }

    else if(position > 3 && position <= 6){
        if(v[1][position-3-1]>0){
            cout<<"This position is already occupied. Please re-entered a new position\n.";
            cin>>position;
            putX(position);
        }
        else
            v[1][position - 3-1]=1;
    }

    else if(position > 6 && position <= 9){
        if(v[2][position-6-1]>0){
            cout<<"This position is already occupied. Please re-entered a new position\n.";
            cin>>position;
            putX(position);
        }
        else
            v[2][position - 6-1]=1;
    }

    else if(position>9){
        cout<<"This position doesn't exist. Please re-enter a valide postion.\n";
        cin>>position;
        putX(position);
    }

}

void put0(int position){
    if(position <= 3){
        if(v[0][position-1]>0){
            cout<<"This position is already occupied. Please re-entered a new position\n.";
            cin>>position;
            putX(position);
        }
        else
            v[0][position-1]=0;
    }

    else if(position > 3 && position <= 6){
        if(v[1][position-3-1]>0){
            cout<<"This position is already occupied. Please re-entered a new position\n.";
            cin>>position;
            putX(position);
        }
        else
            v[1][position - 3-1]=0;
    }

    else if(position > 6 && position <= 9){
        if(v[2][position-6-1]>0){
            cout<<"This position is already occupied. Please re-entered a new position\n.";
            cin>>position;
            putX(position);
        }
        else
            v[2][position - 6-1]=0;
    }

    else if(position>9){
        cout<<"This position doesn't exist. Please re-enter a valide postion.\n";
        cin>>position;
        putX(position);
    }

}

int VerifyIfOnePlayerWon(){
    int i,j;

    ///Verify if someone won on diagonals
    if(v[0][0]!=-1 && v[0][0]==v[1][1] && v[1][1]==v[2][2]){
        if(v[0][0]==1){
            cout<<"Player 1 wins.\n";
            return 1;
        }

        else{
            cout<<"Player 2 wins.\n";
            return 1;
        }

    }
    else if(v[0][2]>0 && v[0][2]==v[1][1] && v[1][1]==v[2][0]){
        if(v[0][2]==1){
            cout<<"Player 1 wins.\n";
            return 1;
        }

        else{
            cout<<"Player 2 wins.\n";
            return 1;
        }

    }


    ///Verify if someone won on rows or columns
    for(i=0;i<3;++i)
        for(j=0;j<3;++j){
            if(v[i][0]>0 && v[i][0]==v[i][1] && v[i][1]==v[i][2]){
                if(v[i][0]==1){
                    cout<<"Player 1 wins.\n";
                    return 1;
                }

                else{
                    cout<<"Player 2 wins.\n";
                    return 1;
                }

            }
            else if(v[0][j]>0 && v[1][j]==v[0][j] && v[1][j]==v[2][j]){
                if(v[0][j]==1){
                    cout<<"Player 1 wins.\n";
                    return 1;
                }

                else{
                    cout<<"Player 2 wins.\n";
                    return 1;
                }

            }
        }
    return 0;
}

void Play(){
    int i,j,ok=0;

    int position;
    if(VerifyIfOnePlayerWon()==0){
        for(i=0;i<3;++i)
            for(j=0;j<3;++j){
                if(v[i][j]>0){
                    ok=1;
                    break;
                }

            }

        if(ok==0){
            cout<<"The game has ended. There isn't any position empty. The result is draw.\n";
        }
        else{
            //cout<<"This is position Tic Tac Toe game. Every position has position unique number from 1 to 9. Good luck players!\n ";
            cout<<"Player 1 specify the position where you want to put X \n";
            cin >> position;
            putX(position);

            printGame();


            ///Verify if PLayer1 wins after his move.
            if(VerifyIfOnePlayerWon()==0){


                if(draw==9){
                    cout<<"The game has ended. There isn't any position empty. The result is draw.\n";
                }
                else{
                    cout<<"Player 2 specify the position where you want to put 0 \n";
                    cin>>position;
                    put0(position);
                    printGame();

                    Play();
                }


            }

        }
    }




}

void printGame(){
    int i,j;
    for(i=0;i<3;++i){
        for(j=0;j<3;++j)
            if(v[i][j]==1)
                cout<<"X "<<"| ";
            else if(v[i][j]==0)
                cout<<"O "<<"| ";
            else
                cout<<v[i][j]<<" | ";
        cout<<"\n--------------\n";
    }
    draw++;
}
int main() {

    int i,j,position;
    for(i=0;i<3;++i){
        for(j=0;j<3;++j)
            cout<<v[i][j]<<" | ";
            cout<<"\n--------------\n";
        }
    cout<<"This is position Tic Tac Toe game. Every position has position unique number from 1 to 9. Good luck players!\n ";
    cout<<"Player 1 specify the position where you want to put X \n";
    cin >> position;
    putX(position);
    printGame();
    cout<<"Player 2 specify the position where you want to put 0 \n";
    cin>>position;
    put0(position);
    printGame();
    Play();

    return 0;
}
