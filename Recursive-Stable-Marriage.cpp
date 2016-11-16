#include <iostream>
#include <cstdlib>
using namespace std;


bool check(int q[], int col) {
        int mp[3][3]={0,2,1,
                0,2,1,
                1,2,0};
        int wp[3][3]={2,1,0,
                0,1,2,
                2,0,1};

         int nm = col, nw = q[col];

        for (int i = 0; i < col; ++i) {
                int cm = i, cw = q[i];
                if(cw==nw) return false;
                if((mp[cm][nw]<mp[cm][cw])&&(wp[nw][cm]<wp[nw][nm])) return false;
                if((mp[nm][cw]<mp[nm][nw])&&(wp[cw][nm]<wp[cw][cm])) return false;
        }
        return true;
}

void print(int q[]){
        int i;
        for(i=0; i<3; i++){
                cout<<q[i]<<" ";
        }
        cout<<endl<<endl;
}

void move(int* q, int col){ // try place in col i
        if(col==3){
                print(q);
                return;
        }
        for(int j=0;j<3;j++){ // j is the row value
                q[col]=j;
                if(check(q,col)) // try and place a queen in row j of col i,if yes
                        move(q,col+1); // go to next column otherwise try next j
        }// no value of j worked so return
}
        
int main(){
        int q[8]; q[0]=0;
        move(q,0);
        system("pause");
}
