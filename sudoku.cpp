#include <iostream>
using namespace std;

bool next(int *ty,int n);
bool solved(int board[9][9]);
void update(int board[9][9],int test[9][9],int *ty);

int main(){
    //input the problem
    int board[9][9];
    int test[9][9];
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>board[i][j];
            test[i][j]=board[i][j];
        }
    }

    int n=0;
    //count how many unknown
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                n++;
            }
        }
    }

    cout<<"ready to solve for "<<n<<" squares"<<endl;
    //cout<<solved(board)<<endl;

    //initialize the answer array
    int ty[81]={0};
    int *ptr=&ty[0];
    for(int i=0;i<n;i++){
        ty[i]=1;
    }

    cout<<"1st try"<<endl;
    update(board,test,ptr);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<test[i][j]<<" ";
        }
        cout<<endl;
    }
    int count=0;
    while(next(ptr,n)){
        update(board,test,ptr);
        if(solved(test)){
            cout<<"GOT IT!!!"<<endl;
            break;
        }
        cout<<count+2<<"th try"<<endl;
        count++;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<test[i][j]<<" ";
        }
        cout<<endl;
        }
    }

    cout<<"done!"<<endl;

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<test[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

bool next(int *ty,int n){
    bool doable=false;
    for(int i=0;i<n;i++){
        if(*(ty+i)!=9){
            doable=true;
        }
    }
    if(!doable){
        return false;
    }
    if(*ty!=9){
        *ty=*ty+1;
        return true;
    }else{
        *ty=1;
        next(ty+1,n-1);
    }
}

bool solved(int board[9][9]){
    bool lack=true;
    //check row
    for(int i=0;i<9;i++){
        for(int number=1;number<=9;number++){
            for(int j=0;j<9;j++){
                if(board[i][j]==number){
                    lack=false;
                }
            }
            if(lack){
                return false;
            }
            lack=true;
        }
    }
    lack=true;
    //check column
    for(int i=0;i<9;i++){
        for(int number=1;number<=9;number++){
            for(int j=0;j<9;j++){
                if(board[j][i]==number){
                    lack=false;
                }
            }
            if(lack){
                return false;
            }
            lack=true;
        }
    }
    lack=true;
    //check 3*3 boxes
    for(int I=0;I<7;I=I+3){
        for(int J=0;J<7;J=J+3){
            for(int number=1;number<=9;number++){
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(board[I+i][J+j]==number){
                            lack=false;
                        }
                    }
                }
                if(lack){
                    return false;
                }
                lack=true;
            }
        }
    }
    return true;
}

void update(int board[9][9],int test[9][9],int *ty){  
    int index=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                test[i][j]=*(ty+index);
                index++;
            }
        }
    }
}