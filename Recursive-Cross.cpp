#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool check(int q[], int n){
        int a[][5] =
        {
                {-1},
                {0, -1},
                {0, 1, -1},
                {0, 2, -1},
                {1, 2, -1},
                {1, 2, 3, 4, -1},
                {2, 3, 5, -1},
                {4, 5, 6, -1}
        };
        for(int i = 0; i < n; i++){
                if(q[i] == q[n]) return false;
        }
        for (int j = 0; a[n][j] != -1; j++){
                if(abs(q[n] - q[a[n][j]]) == 1) return false;
        }
        return true;
}
                
void print(int q[]){
        cout << endl;
        cout << "     " << q[1] << "   " << q[4] << endl;
        cout << "  " << q[0] << "  " << q[2] << "   " << q[5] << "  " << q[7] << endl;
        cout << "     " << q[3] << "   " << q[6] << endl;
}
          
        
void move(int* q, int n){ // try place in col i
        if(n==8){
                print(q);
                return;
        }
        for(int j=0;j<8;j++){ // j is the row value
                q[n]=j;
                if(check(q,n)) // try and place a queen in row j of col i,if yes
                        move(q,n+1); // go to next column otherwise try next j
        }// no value of j worked so return
}
        
        
int main(){
        int q[8]; q[0]=0;
        move(q,0);
        system("pause");
}
