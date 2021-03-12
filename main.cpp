#include <iostream>

using namespace std;
class GridCipher{
private:
    string grid[6][6];
    string key;
    string hashResult;
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

    //constructor

    void constructor(string newWord, string newKey, string newHashResult){
        word = newWord;
        key = newKey;
        hashResult = newHashResult;
    }
    //setter
    void setWord(string newWord){
        word = newWord;
    }
    void setKey(string newKey){
        key = newKey;
    }
    void setHashResult(string newHashResult){
        hashResult = newHashResult;
    }
    //methods
    //initialize Grid
    void initGrid(){
    string grid[6][6];
    int i,j,x=0,ctr=48, letterCtr=0;
    char letter;
    char letterList[26];
        for(letter = 'A'; letter <= 'Z'; ++letter){
            letterList[x] = letter;
            x++;

         }

            for(i=0;i<6;++i){
                for(j=0;j<6;++j){

                    if(i<=1 && j<=5){ //checks if it doesnt occupy space where numbers are supossed to be
                            if(ctr<58){
                                    grid[i][j] = ctr++;
                            }

                    }else{
                        grid[i][j] = letterList[letterCtr];
                        letterCtr++;
                    }
                }
            }

    }
    void display(){ //displays grid in 6x6 matrix form
    }
    void gridOperation(string password){
        int i;
        char letter[password.size()];
        for(i=0;i<password.size();++i){
            letter[i] = password[i];
        }
    }

};


int main()
{

    GridCipher word1;
    word1.gridOperation("Max");


}
