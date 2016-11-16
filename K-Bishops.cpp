#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// checks diagonals, and checks to make sure current number in array is bigger than
// previous numbers in the array
bool ok(int q[], int col, int n){
        int i;
        for(i=0; i<col; i++)
                if(abs(q[col]/n-q[i]/n) == abs(q[col]%n-q[i]%n)) return false;
                if(q[i] < q[i-1]) return false;
        return true;
}

void backtrack(int &col){
        col--;
        if(col==-1){
                exit(1);
        }
}

void print(int q[], int k){
        static int count =0;
        cout<< ++ count<<endl<<endl;
        int i;
        for(i=0; i<k; i++){
                cout<<q[i]<<" ";
        }
        cout<<endl<<endl;
}

int main(){
        int c = 1;
        int n = 0, k = 0;
                
        // input size of board and number of bishops
        cout << "Give me a n for the nXn board: ";
        cin >> n;
        cout << "Enter k bishops: ";
        cin >> k;
        
        // create dynamic array that allows for any input of bishops
        int * q = new int [k];
                
        q[0] = 0;
        
        // goes through all possibilites to see where you can put the bishops on your
        // board

        bool from_backtrack=false;
        while(true){
                while(c<k){
                if(!from_backtrack)q[c]=-1;
                from_backtrack=true;
                        while(q[c]< n*n){
                                q[c]++;
                                if(q[c]==n*n){
                                        from_backtrack=true;
                                        backtrack(c);
                                        break;
                                }
                                if(ok(q,c,n)){
                                        from_backtrack=false;
                                        c++;
                                        break;
                                }
                        }
                }   
                print(q, k);
                from_backtrack=true;
                backtrack(c);
        }
        delete []q;
}
