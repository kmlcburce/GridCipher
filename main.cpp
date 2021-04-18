#include <iostream>
#include <cstring>
#include <cctype>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
class GridCipher{
private:
    char grid1[6][6];
    char grid2[6][6];
    int seQ[10];
    char hashResult[20];
public:
    string word;
    GridCipher(){ //default values if nothing is entered
    word = "None inputted";
    }

    //get
    string getWord(){
        return word;
    }
    char* getHashResult(){
        return hashResult;
    }

    //constructor
    void constructor(string newWord){
        word = newWord;
    }

    //setter
    void setWord(string newWord){
        word = newWord;
    }

    //methods
    /*Initializations*/
    //initialize Grid
    void initGrid(){
        int i,j,x=0,ctr=48, letterCtr=0;
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
                                        this->grid1[i][j] = ctr++;
                                }else{
                                this->grid1[i][j] = letterList[letterCtr];
                                letterCtr++;
                                }
                        }else{
                            this->grid1[i][j] = letterList[letterCtr];
                            letterCtr++;
                        }
                    }
                }
    initSecondGrid();
    }
    void initSecondGrid(){
        int i,j,x=0,ctr=48, letterCtr=0;
        //string *cursor; del if needed
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
                                        this->grid2[i][j] = ctr++;
                                }else{
                                this->grid2[i][j] = letterList[letterCtr];
                                letterCtr++;
                                }
                        }else{
                            this->grid2[i][j] = letterList[letterCtr];
                            letterCtr++;
                        }
                    }
        }
    }
    /*Mutations*/
    void mutateGrid(){
    int i,ctr, ctr2=0,seq[10], key[20]= {4,2,3,1,0,3,2,1,4,3,4,2,3,1,0,3,2,1,4,3};
    srand(time(NULL));
    cout << "Sequence: ";
        for(ctr=0;ctr<20;ctr++){
            seq[ctr2]=rand()%10;
            this->seQ[ctr2] = seq[ctr2];
            if(seq[ctr2]%2==0){
                vswap(key[ctr],key[ctr+1]);
            }else{
                hswap(key[ctr],key[ctr+1]);
            }
            cout << seq[ctr2++];
            ctr++;
        }
        cout << endl;
    }

    void recreateGrid(){
    int i,j,ctr,ctr2=0,temp,seq[10],key[20]= {4,2,3,1,0,3,2,1,4,3,4,2,3,1,0,3,2,1,4,3};
    cout << "Enter Sequence(1 digit at a time):";

        //this was for scanf dunno if it works for cin
        for(i=0;i<10;i++){
            cin >> seq[i];
        }
        cout << "Sequence: ";
        for(ctr=0;ctr<20;ctr++){
            this->seQ[ctr2] = seq[ctr2];
            if(seq[ctr2]%2==0){
                vswap(key[ctr],key[ctr+1]);
            }else{
                hswap(key[ctr],key[ctr+1]);
            }
            cout << seq[ctr2++];
            ctr++;
        }
    }
    //moves the grid to specified rotations through row-col swapping
    void hswap(int x, int y){//row
    int ctr;
    int wordMax = this->word.length();
    char temp;
        for(ctr=0;ctr<6;ctr++){

            temp = this->grid2[x][ctr];
            this->grid2[x][ctr] = this->grid2[y][ctr];
            this->grid2[y][ctr] = temp;
        }
    }
    void vswap(int x, int y){//col
    int ctr;
    int wordMax = this->word.length();
    char temp;
    for(ctr=0;ctr<6;ctr++){
        temp = this->grid2[ctr][x];
        this->grid2[ctr][x] = this->grid2[ctr][y];
        this->grid2[ctr][y] = temp;
    }

    }
    /*Comparisons*/
    /*--Encryption--*/
    //Find coordinates in grid1 from grid2
    void getCoordinates(){
    int i,j,x,ctr1;
    int wordLength = this->word.length();
    int arr[wordLength][2];
    for(x=0;x<wordLength;x++){
        for(i=0;i<6;i++){
            for(j=0;j<6;j++){
               if(toupper(this->word[x]) == this->grid1[i][j]){//find letter coordinates in grid1 //error in this part
                    arr[x][0] = i;//arr holds x and y coordinates
                    arr[x][1] = j;
                    cout << this->word[x] << " - (X,Y) val: " << arr[x][1] << "," << arr[x][0] << endl;
                }
            }
        }
    }
    gridCompare(arr);
    }
    //gets new character based on original grid's coordinates stored in arr
    void gridCompare(int arr[][2]){
    int i,j,x,y,ctr=0, wordLength = this->word.length();
            for(x=0;x<wordLength;x++){
                //use arr coordinates in grid2
                i = arr[x][1];
                j = arr[x][0];
                this->hashResult[ctr] = this->grid2[i][j];
                ctr++;
            }
    }
    /*--Decryption--*/
    void getCoordinatesD(){
    int i,j,x,ctr1;
    int wordLength = this->word.length();
    int arr[wordLength][2];
    for(x=0;x<wordLength;x++){
        for(i=0;i<6;i++){
            for(j=0;j<6;j++){
               if(toupper(this->word[x]) == this->grid2[i][j]){//find letter coordinates in grid1 //changed to grid2
                    arr[x][0] = i;//arr holds x and y coordinates
                    arr[x][1] = j;
                    cout << this->word[x] << " - (X,Y) val: " << arr[x][1] << "," << arr[x][0] << endl;
                }
            }
        }
    }
    gridCompareD(arr);
    }
    //gets new character based on original grid's coordinates stored in arr
    void gridCompareD(int arr[][2]){
    int i,j,x,y,ctr=0, wordLength = this->word.length();
            for(x=0;x<wordLength;x++){
                //use arr coordinates in grid2
                i = arr[x][1];
                j = arr[x][0];
                this->hashResult[ctr] = this->grid1[i][j];
                ctr++;
            }
    }
    /*Displays*/
    void displayGrid1(){ //displays grid in 6x6 matrix form
        int i,j,ctr=0;
            for(i=0;i<6;i++){
                for(j=0;j<6;j++){
                    cout << this->grid1[i][j] << " ";
                }
                cout << endl;
            }
    }
    void displayGrid2(){ //displays grid in 6x6 matrix form (Error here. Fix priority: Low)
        int i,j,ctr=0;
            for(i=0;i<6;i++){
                for(j=0;j<6;j++){
                    cout << this->grid2[i][j] << " ";
                }
                cout << endl;
            }
    }
    void displayResult(){
    int i, wordLength = this->word.length();
    cout << "HashResult: ";
    for(i=0;i<wordLength;i++){
        cout << this->hashResult[i];
    }
    cout << endl;
    cout << "Key: ";
    for(i=0;i<10;i++){
        cout << this->seQ[i];
    }
    }
    /*Main callers*/
    void encrypt(string word){
    setWord(word);
    initGrid();
    mutateGrid();
    displayGrid2();
    getCoordinates();
    displayResult();

    }
    void decrypt(string word){
    setWord(word);
    initGrid();
    recreateGrid();
    displayGrid2();
    getCoordinatesD();
    displayResult();
    }
};


int main()
{
    int opt;
    string temp;
    GridCipher word1;
    cout << "1. Encrypt" << endl << "2. Decrypt" << endl << "Enter: ";
    cin >> opt;
    cout << endl;
    if(opt == 1){
        cout << "Enter word to be encyrpted (max char 20): ";
        cin >> temp;
    if(temp.length()< 20){
        word1.encrypt(temp);
    }else{
        cout << "Word is too long";
    }
    }else if(opt == 2){
    cout << "Enter encrypted word: ";
    cin >> temp;
    word1.decrypt(temp);
    }




}
