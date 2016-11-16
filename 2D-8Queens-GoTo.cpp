#include <iostream>
using namespace std;
int main(){
        int b[8][8] = {0};
        int r;
        int c=0;
        b[0][0]=1;

        NC:     c++;
                if(c==8) goto Print;
                r = -1;

        NR:     r++;
                if (r == 8) goto Backtrack;

                // Row Test
                for(int i = 0; i < c; i++){
                        if (b[r][i] == 1) goto NR;
                }

                // Up Diagonal Test
                for(int i = 1; ((r-i) >= 0) && ((c-i) >= 0); c++){
                        if(b[r-i][c-i] == 1) goto NR;
                }

                // Down Diagonal Test
                for(int i = 1; ((r+i) < 8) && ((c-i) >= 0); c++){
                        if(b[r+i][c-i] == 1) goto NR;
                }
                                
                b[r][c] =1;
                goto NC;
                 
        Backtrack:
                c--;
                if(c == -1) return 0;
                r = 0;
                while(b[r][c] != 1){
                        r++;
                }
                b[r][c] = 0;
                goto NR;
                
        Print:  for(int i = 0; i < 8; i++){                             
                        for(int j = 0; j < 8; j++){
                                if(b[i][j] == 1) cout << "1";
                                else cout << "0";
                        }  
                        cout << endl;
                }
                cout << endl;
                goto Backtrack;
                
}
