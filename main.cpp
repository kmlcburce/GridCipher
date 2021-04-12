#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
class GridCipher{
private:
    string grid1[6][6];
    string grid2[6][6];
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
    void display(){ //displays grid in 6x6 matrix form (Error here. Fix priority: Low)
        int i,j,ctr=0;
            for(i=0;i<6;i++){
                for(j=0;j<6;j++){
                    if(ctr<=6){
                        cout << this->grid1[i][j] << " ";
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
    initSecondGrid();
    }
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

    /*gets new character based on original grid's coordinates
    void gridCompare(int arr[][2]){
    int i,j,x,y,ctr=0;
            for(x=0;x<this->word.length();x++){
                //use arr coordinates in grid2
                cout << this->grid2[arr[x][0]][arr[x][1]];
                ctr++;

            }
}*/

    void mutateGrid(){
    int ctr,seq[10];
    char key[20];
    for(ctr=0;ctr<10;ctr++){
        seq[ctr]=rand();
        cout << "Sequence: ";
        if(seq[ctr]%2==0){
            vswap(key[ctr],key[ctr+1]);
            printf("%d ",seq[ctr++]);
        }else{
            hswap(key[ctr],key[ctr+1]);
            printf("%d ",seq[ctr++]);
        }
    }
    printf("\nKey: %s", key);

}
    //moves the grid to specified rotations through row-col swapping
    void hswap(int x, int y){//row
    int ctr;
    int wordMax = this->word.length();
    char temp[wordMax+1];
        for(ctr=0;ctr<6;ctr++){
            strcpy(temp,this->grid2[x][ctr].c_str());
            cout << temp;
            //strcpy(this->grid2[x][ctr],this->grid2[y][ctr]);
            //strcpy(this->grid2[y][ctr],temp);
        }
}
    void vswap(int x, int y){//col
    int ctr;
    int wordMax = this->word.length();
    char temp[wordMax+1];
    for(ctr=0;ctr<6;ctr++){
        strcpy(temp, this->grid2[ctr][x].c_str());
        cout << temp;
        //strcpy(this->grid2[ctr][x],this->grid2[ctr][y]);
        //strcpy(this->grid2[ctr][y],temp);
    }

}
    void encrypt(string word){
    setWord(word);
    initGrid();
    mutateGrid();
    //getCoordinates();


    }
};


int main()
{
    string temp;
    GridCipher word1;
    cout << "Enter word to be encyrpted: ";
    cin >> temp;
    word1.encrypt(temp);


}
