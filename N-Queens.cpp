#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// This function tests the row and diagnols to see if a queen was placed
bool test(int q[], int c){
        for(int i = 0; i < c; i++){
                if(q[c] == q[i] || (c-i) == abs(q[c]-q[i])) return false;
        }
        return true;
}

// This function backtracks if the program has gone off the board
void backtrack(int &c){
        c--;
}

// This goes throught all the possible solutions for every n queens problem
int main(){
        int n;
        cout << "Please enter an integer for the N Queens problem: ";
        cin >> n;
        cout << endl;
                                         
        for (int i = 1; i <= n; ++i) {
                int *q = new int[i];
                q[0]=1;
                int count = -1;
                int c = 0;
                bool from_backtrack=false;
                while(true){
                        while(c<i){
                                if(!from_backtrack)q[c]=-1;
                                from_backtrack=true;
                                while(q[c]<i){
                                        q[c]++;
                                        if(q[c]==i){
                                                from_backtrack=true;
                                                backtrack(c);
                                                break;
                                        }
                                        if(test(q,c)){
                                                from_backtrack=false;
                                                c++;
                                                break;
                                        }
                                }
                                if(c==-1)break;
                        }
                        count++;
                        backtrack(c);
                        from_backtrack=true;  
                        if(c<=-1)break;
                }
                delete []q;
                cout<<"There is "<<count<<" solutions to the "<< i <<" Queens problem."<<endl;
        }
        return 0;
}
                
