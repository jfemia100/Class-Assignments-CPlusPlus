#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


bool check(int q[], int c){
    for(int i=0; i<c; i++)
        if(q[c]==q[i] || (c-i)==abs(q[c]-q[i]))
            return false;
    return true;
}

void backtrack(int &c){
    c--;
    if(c==-1){
        exit(1);
    }
}

void print(int q[]){
    static int count =0;
    cout<< ++ count<<endl<<endl;
    int i;
    for(i=0; i<8; i++)
        cout<<q[i]<<" ";
    cout<<endl<<endl;
}

int main(){
    int q[8]; 
    q[0]=0;
    int c=1;
    
    bool from_backtrack=false;
    while(true){
        while(c<8){
            if(!from_backtrack) q[c]=-1;
            from_backtrack=true;
            while(q[c]<8){
                q[c]++;
                if(q[c]==8){
                    from_backtrack=true;
                    backtrack(c);
                }
                if(check(q,c)){
                    from_backtrack=false;
                    c++;
                }
            }
        }
        print(q);
        from_backtrack=true;
        backtrack(c);
    }    
}
