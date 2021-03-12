#include <iostream>

using namespace std;
class GridCipher{
public:

    string word;

    GridCipher(){
    word = "None inputted";
    key = "NULL";
    hashResult = "NULL";

    }
    //get
    string getWord(){
        return word;
    }
    string getKey(){
        return key;
    }
    string getHashResult(){
        return hashResult;
    }
private:
    string grid[6][6];
    string key;
    string hashResult;
    //construct

    void constructor(string newWord, string newKey, string newHashResult){
        word = newWord;
        key = newKey;
        hashResult = newHashResult;
    }
    //set
    void setWord(string newWord){
        word = newWord;
    }
    void setKey(string newKey){
        key = newKey;
    }
    void setHashResult(string newHashResult){
        hashResult = newHashResult;
    }

protected:
    //methods
    //initialize Grid
    void initGrid(string grid[6][6]){
        int i,j,ctr=0;
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
    GridCipher word1;
    cout << word1.getKey();


}
