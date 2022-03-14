#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

const string WORD_LIST[]={
"angle", "ant", "apple", "arch", "arm", "army",
 "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
 "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
 "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
 "cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
 "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
 "cow", "cup", "curtain", "cushion",
 "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
 "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
 "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
 "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
 "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
 "leaf", "leg", "library", "line", "lip", "lock",
 "map", "match", "monkey", "moon", "mouth", "muscle",
 "nail", "neck", "needle", "nerve", "net", "nose", "nut",
 "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
 "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
 "rail", "rat", "receipt", "ring", "rod", "roof", "root",
 "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
 "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
 "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
 "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
 "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
 "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
};
const string FIGURE[]={
	"  -------------     \n"
	"  |                 \n"
	"  |                 \n"
	"  |                 \n"
	"  |                 \n"
	"  |    \n"
	"-----  \n",
	"  -------------     \n"
	"  |           |     \n"
	"  |                 \n"
	"  |                 \n"
	"  |                 \n"
	"  |    \n"
	"-----  \n",
	"  -------------     \n"
	"  |           |     \n"
	"  |           o     \n"
	"  |                 \n"
	"  |                 \n"
	"  |    \n"
	"-----  \n",
	"  -------------     \n"
	"  |           |     \n"
	"  |           o     \n"
	"  |           |     \n"
	"  |                 \n"
	"  |    \n"
	"-----  \n",
	"  -------------     \n"
	"  |           |     \n"
	"  |           o     \n"
	"  |          /|     \n"
	"  |                 \n"
	"  |    \n"
	"-----  \n",
	"  -------------     \n"
	"  |           |     \n"
	"  |           o     \n"
	"  |          /|\\   \n"
	"  |                 \n"
	"  |    \n"
	"-----  \n",
	"  -------------     \n"
	"  |           |     \n"
	"  |           o     \n"
	"  |          /|\\   \n"
	"  |          /      \n"
	"  |    \n"
	"-----  \n",
	"  -------------     \n"
	"  |           |     \n"
	"  |           o     \n"
	"  |          /|\\   \n"
	"  |          / \\   \n"
	"  |    \n"
	"-----  \n",
};

const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);

const int Max_bad_guess=7;

string chooseword();
char readAGuess();
string guessed_word();
string update(string guessedWord, string secretWord, char guess);
bool contains(string secretWord, char guess);
void renderGame(string guessWord, int badGuessCount);

int main(){
    string secretWord=chooseword();
    string guessWord=string(secretWord.length(), '-');
    int badGuessCount=0;
    do{
    	system("cls");
        renderGame(guessWord, badGuessCount);
        char guess=readAGuess();
        if (contains(secretWord, guess)) 
            guessWord = update(guessWord, secretWord, guess);
        else badGuessCount++;
    }while(badGuessCount<Max_bad_guess &&guessWord!=secretWord);
    renderGame(guessWord, badGuessCount);
    if(badGuessCount<Max_bad_guess) cout<<"Congratuation! You win!";
    else{
    	cout<<"You lost!"<<endl
    		<<"The correct word is: "<<secretWord;
	}
    return 0; 
}

string chooseword(){
	srand(time(0));
   	int randomNumber=rand()%WORD_COUNT;
   	return WORD_LIST[randomNumber];
}
char readAGuess(){
    char t;
    cin>>t;
    return t;
}
bool contains(string secretWord, char guess){
    for(int i=0;i<secretWord.length();i++){
        if(secretWord[i]==guess) return true;
    }
    return false;
}
string update(string guessWord, string secretWord, char guess){
    for(int i=0;i<secretWord.length();i++){
        if(secretWord[i]==guess){
            guessWord[i]=guess;
        }
    }
    return guessWord;
}
void renderGame(string guessWord, int badGuessCount){
	cout << FIGURE[badGuessCount] << endl;
    cout<<guessWord<<endl;
    cout<<"Number of wrong guesses: "<<badGuessCount<<endl;
}
