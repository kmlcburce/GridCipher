#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
class GridCipher{
private:
    string grid[6][6];
    string key;
    string hashResult;
public:
    string word;
    GridCipher(){ //default values if nothing is entered
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
    void display(string grid[6][6]){ //displays grid in 6x6 matrix form (Error here. Fix priority: Low)
        int i,j,ctr=0;
            for(i=0;i<=6;i++){
                for(j=0;j<=6;j++){
                    if(ctr<6){
                        cout << grid[i][j] << " ";
                        ctr++;
                    }else{
                        cout << endl;
                        ctr = 0;
                    }

                }
            }
            cout << "Error occurs here";
    }
    //initialize Grid
    void initGrid(){
        string grid[6][6];
        int i,j,x=0,ctr=48, letterCtr=0;
        /*string *cursor;*/
        char letter;
        char letterList[26];
            for(letter = 'A'; letter <= 'Z'; letter++){
                letterList[x] = letter;
                x++;

             }

                for(i=0;i<6;i++){
                    for(j=0;j<6;j++){

                        if(i<=1 && j<6){ //checks if it doesnt occupy space where numbers are supossed to be
                                if(ctr<58){ //ASCII numbers starts from 48
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

    getCoords(grid,"word");

    }
    //display(grid);
    //vswap(grid,0,1); test out hswap and vswap here
    }
    //gets letter coordinates from grid and stores them in arr
    void getCoords(string grid[6][6], string word){
    int i, j,letterCtr=0, arrCtrX,arrCtrY, wordSize = word.size();
    string letter[wordSize];
    int arr[wordSize][2];

        for(i=0;i<wordSize;i++){
            letter[i] = word[i]; //isolate individual letters on input string
        }
        for(arrCtrX=0;arrCtrX<wordSize;arrCtrX++){//Loops for x value of arr[x][2]

                    for(i=0;i<6;i++){//Loops through grid[][] to find matching letter
                        for(j=0;j<6;j++){
                            if(strcmp(grid[i][j], letter[letterCtr]) = 0){ //can string be == with char?
                                cout << "Error occurs here";
                                arr[arrCtrX][0] =  i;
                                arr[arrCtrX][1] = j;
                                letterCtr++;
                        }
                    }
                }

        }
        for(arrCtrX=0;arrCtrX<wordSize;arrCtrX++){ //print out arr to check
            for(arrCtrY=0;arrCtrY<2;arrCtrY++){
                cout << arr[arrCtrX][arrCtrY] << " ";
            }
        }


    }
    //creates new grid to be scrambled
    void gridScrambler(){
        string newGrid[6][6];
        int i,j,x=0,ctr=48, letterCtr=0;
        char letter;
        char letterList[26];
            for(letter = 'A'; letter <= 'Z'; ++letter){
                letterList[x] = letter;
                x++;

             }

                for(i=0;i<6;i++){
                    for(j=0;j<6;j++){

                        if(i<=1 && j<6){ //checks if it doesnt occupy space where numbers are supossed to be
                                if(ctr<58){ //ASCII numbers starts from 48
                                        grid[i][j] = ctr++;
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
    }


    //gets new character based on original grid's coordinates
    void gridCompare(string grid[6][6]){



    }
    //moves the grid to specified rotations through row-col swapping
    void hswap(string grid[6][6], int x, int y){
    int ctr;
    string temp;
        for(ctr=0;ctr<6;ctr++){
            temp=grid[x][ctr];
            grid[x][ctr]=grid[y][ctr];
            grid[y][ctr]=temp;

        }
    display(grid);
    }
    void vswap(string grid[6][6], int x, int y){ // not implemented yet
    int ctr;
    string temp;
    for(ctr=0;ctr<6;ctr++){
        temp=grid[x][ctr];
        grid[ctr][x]=grid[ctr][y];
        grid[ctr][y]=temp;
    }
    display(grid);
    }
    /*void binaryConverter(string password){
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

    }*/

};


int main()
{

    GridCipher word1;
    word1.initGrid();


}
