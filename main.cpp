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
    void display(string grid[6][6]){ //displays grid in 6x6 matrix form
        int i,j,ctr=0;
        for(i=0;i<=6;++i){
            for(j=0;j<=6;++j){
                if(ctr<6){
                    cout << grid[i][j] << " ";
                    ctr++;
                }else{
                    cout << endl;
                    ctr = 0;
                }

            }
        }

    }
    //initialize Grid
    void initGrid(){
    string grid[6][6];
    int i,j,x=0,ctr=48, letterCtr=0;
    /*string *cursor;*/
    char letter;
    char letterList[26];
        for(letter = 'A'; letter <= 'Z'; ++letter){
            letterList[x] = letter;
            x++;

         }

            for(i=0;i<6;++i){
                for(j=0;j<6;++j){

                    if(i<=1 && j<6){ //checks if it doesnt occupy space where numbers are supossed to be
                            if(ctr<58){
                                    grid[i][j] = ctr++;
                                    /*if(j+1<=6){//test condition: pointer *cursor points to the current element in the grid, may be used to point to next element
                                        cursor = (*(grid+1)+j);
                                        cout << *cursor << endl;
                                    }else if(j+1 >6 && i<=6){

                                    }*/

                            }else{
                            grid[i][j] = letterList[letterCtr];
                            letterCtr++;
                            }

                    }else{
                        grid[i][j] = letterList[letterCtr];
                        letterCtr++;
                    }
                }



    }
    //instert display() here if needed

}
    //algo 1: user input acts key to rotation
    void binaryConverter(string password){
        int i,remainder;
        char letter[password.size()];
        int ascii[password.size()], remainderSet[10];

        for(i=0;i<password.size();++i){
            letter[i] = password[i]; //isolate individual letters on password string
            ascii[i] = int(letter[i]); //convert letters to ascii number values
            cout << ascii[i] << " ";
        }
        for(i=0;i<password.size();++i){

            while(remainder!=0){
                remainder = ascii[i];
                remainderSet[i] = remainder%2;
                remainder = remainder/2;

            }
        }

    }
    //moves the grid to specified rotations
    void gridOperation(string grid[6][6], int code){



    }

};


int main()
{

    GridCipher word1;
    word1.binaryConverter("Max");


}
