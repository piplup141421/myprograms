#include <iostream>
using namespace std;

int nth(int ,int);
void carry(int p[]);
void mutiply(int p[],int q);

int main(){

    int A[100]={0};
    bool start=false;
    A[0]=1;
    for(int i=1;i<=50;i++){
        mutiply(A,i);
    }

    for(int i=99;i>=0;i--){
        if(A[i]!=0){
            start=true;
        }
        if(start){
            cout<<A[i];
        }
    }
    return 0;
}

int nth(int temp,int n){
    int out=temp;
    for(int i=0;i<n;i++){
        out=out/10;
    }
    out=out%10;
    return out;
}

void carry(int p[]){
    for(int i=0;i<100;i++){
        if(p[i]>9){
            p[i]=p[i]-10;
            p[i+1]++;
        }
    }
}

void mutiply(int p[],int q){
    int res[100]={0};
    int add[11]={0};
    int temp;
    for(int i=0;i<100;i++){
        temp=q*p[i];
        for(int j=0;j<11;j++){
            add[j]=nth(temp,j);
        }
        for(int j=0;j<11;j++){
            res[i+j]=res[i+j]+add[j];
        }
        carry(res);
    }

    for(int i=0;i<100;i++){
        p[i]=res[i];
    }
}

