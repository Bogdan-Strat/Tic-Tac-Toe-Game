#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v{
        {-1,-1,-1,-1,-1},
        {-1,-1,-2,-3,-1},
        {-1,-4,-5,-6,-1},
        {-1,-7,-8,-9,-1},
        {-1,-1,-1,-1,-1}
        /*{-1,-2,-3},
        {-4,-5,-6},
        {-7,-8,-9}*/
};

int draw=0,start;

void printGame(){
    int i,j;
    for(i=1;i<4;++i){
        for(j=1;j<4;++j)
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

void putX(int position){
    if(position <= 3){
        if(v[1][position-1+1]>0){
            cout<<"This position is already occupied. Please re-entered a new position\n.";
            cin>>position;
            putX(position);
        }
        else
            v[1][position-1+1]=1;
    }

    else if(position > 3 && position <= 6){
        if(v[2][position-3-1+1]>0){
            cout<<"This position is already occupied. Please re-entered a new position\n.";
            cin>>position;
            putX(position);
        }
        else
            v[2][position - 3-1+1]=1;
    }

    else if(position > 6 && position <= 9){
        if(v[3][position-6-1+1]>0){
            cout<<"This position is already occupied. Please re-entered a new position\n.";
            cin>>position;
            putX(position);
        }
        else
            v[3][position - 6-1+1]=1;
    }

    else if(position>9){
        cout<<"This position doesn't exist. Please re-enter a valide postion.\n";
        cin>>position;
        putX(position);
    }

}

int verifyComputerLosing(){
    int i,j;


    //Verify loosing on second diagonal
    if(v[1][3]==1){
        if(v[2][2]==1)
            return 2*3+0+1;
        if(v[3][1]==1)
            return 1*3+1+1;
    }
    if(v[2][2]==1){
        if(v[3][1]==1)
            return 0*3+2+1;
    }
    for(i=1;i<3;++i)
        for(j=1;j<3;++j){

            //Verify loosing on rows and columns
            if(v[i][j]==1 && i==1){
                    if(v[i][j+1]==1)
                        return (i-1)*3+j+1+1;
                    else if(v[i][j+2]==1)
                        return (i-1)*3+j+1;



                    if(v[i+1][j]==1)
                        return (i+1)*3+j;
                    else if(v[i+2][j]==1)
                        return i*3+j;

            }
            else if(v[i][j]==1 && i==2){
                 if(v[i][j+1]==1)
                     return (i-1)*3+j-1;

                 else if(v[i+1][j]==1)
                     return (i-2)*3+j;
            }



            //Verify loosing on principal diagonal
            if(v[1][1]==1){
                    if(v[2][2]==1)
                        return 2*3+2+1;
                    else if(v[3][3]==1)
                        return 1*3+0+2;
            }
            else if(v[2][2]==1){
                if(v[3][3]==1)
                    return 0*3+0+1;
            }


        }
    return 100; //computer is not in danger to lose at the first move



}
void put0(int position){
    if(verifyComputerLosing()!=100)
        position=verifyComputerLosing();
    cout<<verifyComputerLosing()<<'\n';
    if(position <= 3){
        if(v[1][position-1+1]>=0){
            position=(rand()%9)+1;
            put0(position);
        }
        else
            v[1][position-1+1]=0;
    }

    else if(position > 3 && position <= 6){
        if(v[2][position-3-1+1]>=0){
            position=(rand()%9)+1;
            put0(position);
        }
        else
            v[2][position - 3-1+1]=0;
    }

    else if(position > 6 && position <= 9){
        if(v[3][position-6-1+1]>=0){
            position=(rand()%9)+1;
            put0(position);
        }
        else
            v[3][position - 6-1+1]=0;
    }

    else if(position>9){
        position=(rand()%9)+1;
        putX(position);
    }

}

int VerifyIfOnePlayerWon(){
    int i,j;

    ///Verify if someone won on diagonals
    if(v[1][1]!=-1 && v[1][1]==v[2][2] && v[2][2]==v[3][3]){
        if(v[1][1]==1){
            if(start==1)
                cout<<"Player wins.\n";
            else
                cout<<"Computer wins\n";
            return 1;
        }

        else{
            if(start==1)
                cout<<"Computer wins.\n";
            else
                cout<<"Player wins\n";
            return 1;
        }

    }
    else if(v[1][3]>0 && v[1][3]==v[2][2] && v[2][2]==v[3][1]){
        if(v[1][3]==1){
            if(start==1)
                cout<<"Player wins.\n";
            else
                cout<<"Computer wins.\n";
            return 1;
        }

        else{
            if(start==1)
                cout<<"Computer wins.\n";
            else
                cout<<"Player wins.\n";
            return 1;
        }

    }


    ///Verify if someone won on rows or columns
    for(i=1;i<4;++i)
        for(j=1;j<4;++j){
            if(v[i][1]>0 && v[i][1]==v[i][2] && v[i][2]==v[i][3]){
                if(v[i][1]==1){
                    if(start==1)
                        cout<<"Player wins.\n";
                    else
                        cout<<"Computer wins.\n";
                    return 1;
                }

                else{
                    if(start==1)
                        cout<<"Computer wins.\n";
                    else
                        cout<<"Player wins.\n";
                    return 1;
                }

            }
            else if(v[1][j]>0 && v[2][j]==v[1][j] && v[2][j]==v[3][j]){
                if(v[1][j]==1){
                    if(start==1)
                        cout<<"Computer wins.\n";
                    else
                        cout<<"Player wins.\n";
                    return 1;
                }

                else{
                    if(start==1)
                        cout<<"Computer wins.\n";
                    else
                        cout<<"Player wins.\n";
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
        for(i=1;i<4;++i)
            for(j=1;j<4;++j){
                if(v[i][j]>0){
                    ok=1;
                    break;
                }

            }

        if(ok==0){
            cout<<"The game has ended. There isn't any position empty. The result is draw.\n";
        }
        else{
            if(start==1){
                cout<<"Player specify the position where you want to put X \n";
                cin >> position;
                putX(position);
                printGame();

                ///Verify if PLayer wins after his move.
                if(VerifyIfOnePlayerWon()==0){


                    if(draw==9){
                        cout<<"The game has ended. There isn't any position empty. The result is draw.\n";
                    }
                    else{
                        position=(rand()%9)+1;
                        put0(position);
                        cout<<"\n\n\n";
                        printGame();

                        Play();
                    }


                }
            }
            else{
                position=(rand()%9)+1;
                put0(position);
                cout<<"\n\n\n";
                printGame();

                //Verify if Computer wins after its move.
                if(VerifyIfOnePlayerWon()==0){
                    if(draw==9){
                        cout<<"The game has ended. There isn't any position empty. The result is draw.\n";
                    }
                    else{
                        cout<<"Player specify the position where you want to put X \n";
                        cin >> position;
                        putX(position);
                        printGame();

                        Play();
                    }
                }
            }






        }
    }




}

int main() {
    int i,j,position;
    for(i=1;i<4;++i){
        for(j=1;j<4;++j)
            cout<<v[i][j]<<" | ";
        cout<<"\n--------------\n";
    }

    cout<<"This is a Tic Tac Toe game. You are playing against the computer. Choose if you want to start first,by entering 1, respectively 2 if you want"
          "to start the second one.  Good luck player!\n ";
    cin>>start;

    if(start==1){
        cout<<"Player specify the position where you want to put X \n";
        cin >> position;
        putX(position);
        printGame();
        position=(rand()%9)+1;
        put0(position);
        cout<<"\n\n\n";
        printGame();

    }
    else{
        position=(rand()%9)+1;

        put0(position);
        // cout<<"\n\n\n";
        printGame();
        cout<<"Player specify the position where you want to put X \n";
        cin >> position;
        putX(position);
        printGame();
    }
    Play();
    return 0;
}
