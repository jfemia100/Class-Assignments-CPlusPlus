#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
                
bool check(int n, int q[]){
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
        
void backtrack(int &n){
        n--;                                            
        if(n == -1) exit(1); 
}
                                
void print(int q[]){
        int count = 0;   
        cout << "Solution " << count << ": " << endl;
        cout << endl;
        cout << "     " << q[1] << "     " << q[4] << endl;                               
        cout << "  " << q[0] << "  " << q[2] << "  " << q[5] << "  " << q[7] << endl;
        cout << "     " << q[3] << "     " << q[6] << endl;
}
                         
int main(){
        int q[8];
        int n = 0;
        bool from_backtrack = false;
        while (true){
                while(n < 8){
                        if( !from_backtrack){
                                q[n] = -1;
                                from_backtrack = false;                         
                        }
                        while( q[n] < 8){
                                q[n]++;
                                if( q[n] == 8){
                                        backtrack(n);
                                }
                                if(check(n, q));
                        }
                        n++;
                }
                print(q);
                backtrack(n);                                           
                from_backtrack = true;
        }
}
