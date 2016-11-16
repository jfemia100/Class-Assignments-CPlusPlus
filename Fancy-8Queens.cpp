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
        if(c == -1) exit(1);
}

// This function prints the board
void print(int q[]){
        cout << endl;
        int i,j,k,l;
        typedef char box[5][7];
        box bb, wb, *board[8][8];

        // This is the setup when the queen is on a white spot
        box wq = {  
                {' ',' ',' ',' ',' ',' ',' '},
                {' ',char(219),' ',char(219),' ',char(219),' '},
                {' ',char(219),char(219),char(219),char(219),char(219),' '},
                {' ',char(219),char(219),char(219),char(219),char(219),' '},
                {' ',' ',' ',' ',' ',' ',' '}
        };
 
        // This is the setup when the queen is on a black spot
        box bq = {
                {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                {char(219),' ',char(219),' ',char(219),' ',char(219)},
                {char(219),' ',' ',' ',' ',' ',char(219)},
                {char(219),' ',' ',' ',' ',' ',char(219)},
                {char(219),char(219),char(219),char(219),char(219),char(219),char(219)}
        };
        
        for(i = 0; i < 5; i++){
                for(j = 0; j < 7;j++){
                        wb[i][j] = ' ';
                        bb[i][j] = char(219);
                }
        }
                
        // This fills the board with pointers  
        for(i = 0; i < 8; i++){
                for(j = 0; j < 8; j++){
                        if((i+j)%2 == 0){
                                if(q[i] == j)board[i][j] = &wq;
                                else board[i][j] = &wb;
                        }
                        else{
                                if(q[i] == j)board[i][j] = &bq;
                                else board[i][j] = &bb;
                        }
                }
        }
                        
        // This prints the acutal board, with the queens
        for(i = 0; i < 8; i++){
                for(k = 0; k < 5; k++){
                        for(j = 0; j < 8; j++){
                                for(l = 0; l < 7; l++){
                                        cout << (*board[i][j])[k][l];
                                }
                        }
                cout << endl;
                }
        }
        cout << endl;
        for(int n = 0; n <= 56; n++){
                cout << "-";
        }
        cout << endl;
}                       
        
// This goes throught all the possible solutions for the 8 queens
int main(){
        int q[8]; q[0] = 0;
        int c = 0;
        bool from_backtrack = false;
        while(true){
                while(c<8){
                        if(!from_backtrack) q[c] = -1;
                        from_backtrack = false;
                        while(q[c] < 8){
                                q[c]++;
                                while(q[c] == 8){
                                        backtrack(c);
                                        q[c]++;
                                }
                                if(test(q, c)){
                                        from_backtrack = false;
                                        c++;
                                }
                        }  
                } 
                print(q);
                backtrack(c);
                from_backtrack = true;
        }
}
