#include <iostream>

using namespace std;
class GridCipher{
public:
    string grid[6][6];
    string word;
    string key;
    string hashResult;

    //construct
    void constructor(string aword){
        word = aword;
    }
    //set
    //get
    //methods
    //initialize Grid
    void initGrid(string grid[][]){
        int i,j,ctr=1;
        char letter;
        //loop through alphabet
        for(letter = 'A'; letter <= 'Z'; ++letter){
        //iterate through grid
            for(i=0;i<=6;++i){
                for(j=0;j<6;++j){
                        //check if it doesn't occupy spaces where numbers should be
                    if(i<=1 && j<=5){
                        grid[i][j] = 1;
                        ctr++;
                    }else{
                        //if it doesn't occupy. fill with letters
                        grid[i][j] = letter;
                    }
                }
            }
        }
        //print out everything
        for(i=0;i<=6;++i){
            for(j=0;j<=6;++j){
                cout << grid[i][j] << " ";
                cout << "\n";
            }
        }
    }




};

int main()
{
    GridCipher x;
    x.constructor("Cake");


}
