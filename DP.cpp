#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int food[n+1]={0};
    for(int i=1;i<=n;i++){
        cin>>food[i];
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        int sum=0;
        for(j=l;j<=r;j++){
            sum+=food[j];
        }
        cout<<sum<<endl;
    }
    return 0;
}