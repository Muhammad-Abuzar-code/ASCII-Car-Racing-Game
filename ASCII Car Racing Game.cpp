#include <iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<conio.h>
#include<windows.h>
#include<fstream>

using namespace std;

void load_highscore();

void fullClearScreen();

void save_highscore();

void game_board_setup();

void player_input();

void draw_car();

void game_logic();

void moveCursorToTop();

const char Obstacle = char(219);
const int Board_height = 20;
const int Board_width = 25;
const int player_car_Y = Board_height - 2;

char gameBoard[Board_height][Board_width];

int highscore;
int score1,score2;
int framecount;
int final_score;

bool gameOver;
bool car1Crashed;
bool car2Crashed;

int Car1_X;
int Car2_X;



int main()
{
    srand(time(0));
    load_highscore();

    cout<<"==========================================="<<endl;
    cout<<"             ASCII Car Racing Game         "<<endl;
    cout<<"==========================================="<<endl;
    cout<<"P1 Controls: 'a'/'d' | P2 Controls: 'j'/'l'"<<endl;
    cout<<"==========================================="<<endl;
    cout<<"      Press 'x' to quit when game starts   "<<endl;
    cout<<endl;

    char ready;
    do{
        cout<<"Player 1 press 'Y / y' if Ready: ";
        cin>>ready;
    }
    while(ready!='y' && ready!='Y');


   do{
        cout<<"Player 2 press 'Y / y' if Ready: ";
        cin>>ready;
    }
    while(ready!='y' && ready!='Y');

    fullClearScreen();

    game_board_setup();

    gameOver = false;

    while(!gameOver){
        player_input();
        game_logic();
        draw_car();

        Sleep(50);
    }
    draw_car();

    int final_score = max(score1,score2);

    fullClearScreen();

    cout << "\n===========================================" << endl;
    cout << "           F I N A L   R E S U L T S!        " << endl;
    cout << "===========================================" << endl;
    cout << "Player 1 Score: " << score1 << endl;
    cout << "Player 2 Score: " << score2 << endl;
    cout << "-------------------------------------------" << endl;

     if (score1 > score2) {
        cout << ">>> PLAYER 1 IS THE WINNER! <<<" << endl;
    } else if (score2 > score1) {
        cout << ">>> PLAYER 2 IS THE WINNER! <<<" << endl;
    } else {
        cout << ">>> IT'S A TIE! <<<" << endl;
    }
    cout << "-------------------------------------------" << endl;

    if(final_score > highscore){
        save_highscore();
        load_highscore();
        cout<<"NEW HIGH SCORE: "<<highscore<<endl;

    }
    else {
        cout << "HIGH SCORE: " << highscore << endl;
    }
    cout << "===========================================\n" << endl;

    return 0;
}

void load_highscore(){

    //Load already save highscore in file
    ifstream fileIn("highscore.txt");
    if(fileIn.is_open()){
        fileIn>>highscore;
        fileIn.close();
    }
    else{
        highscore = 0;
    }
}

void save_highscore(){

    //Creates a file and puts high score in it
    ofstream fileOut("highscore.txt");
    if(fileOut.is_open()){
        fileOut << max(score1,score2);
        fileOut.close();
    }
}

void fullClearScreen(){
    //Clears the whole screen
        system("cls");
}

void game_board_setup(){

    //Set ups the Lanes and Game borders
    framecount = 0;
    score1 = 0;
    score2 = 0;
    car1Crashed = false;
    car2Crashed = false;

    Car1_X = 4;
    Car2_X = 21;

    for(int i = 0 ; i<Board_height ; i++){
        for(int j = 0 ; j<Board_width ; j++){
            if(j == 0 || j == Board_width-1){
                gameBoard[i][j] = '#';
            }
            else if(j == 7 || j == 13 || j == 18){
                gameBoard[i][j] = '|';
            }
            else{
                gameBoard[i][j] = ' ';
            }
            }
        }
    }

void player_input(){

    //Takes left right car move input from user
    char Move = ' ';

    if(_kbhit()){
        Move = _getch();
    }

    if(Move != ' '){
        if(Move == 'x'){
            gameOver = true;
        }
        if(!car1Crashed){
            if(Move == 'a'){
                Car1_X = 4;
                }

            else if(Move == 'd' ){
                Car1_X = 9;
            }
        }

        if(!car2Crashed){
            if(Move == 'j' ){
                Car2_X = 16;
            }
            else if(Move == 'l' ){
                Car2_X = 21;
            }
        }
        }
}

void moveCursorToTop() {

    //Moves cursor to top and overwrites everything from there
        COORD pos = {0, 0};
        HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(output, pos);
}

void draw_car(){

    //Draws the car and then at the end removes car for car to be drawn at new position
    moveCursorToTop();

    cout << "         ASCII Car Racing Game         " << endl;
    cout << "=======================================" << endl;
    cout << "P1 Score: " << score1 << " | P2 Score: " << score2 << " | High Score: " << highscore << endl;
    cout << "---------------------------------------" << endl;

     if(!car1Crashed){
        gameBoard[player_car_Y-1][Car1_X-1] = '/';
        gameBoard[player_car_Y-1][Car1_X] = '^';
        gameBoard[player_car_Y-1][Car1_X+1] = '\\';
        gameBoard[player_car_Y][Car1_X-1] = '|';
        gameBoard[player_car_Y][Car1_X] = '1';
        gameBoard[player_car_Y][Car1_X+1] = '|';
     }
     else{
        gameBoard[player_car_Y-1][Car1_X] = 'X';
     }

     if(!car2Crashed){
        gameBoard[player_car_Y-1][Car2_X-1] = '/';
        gameBoard[player_car_Y-1][Car2_X] = '^';
        gameBoard[player_car_Y-1][Car2_X+1] = '\\';
        gameBoard[player_car_Y][Car2_X-1] = '|';
        gameBoard[player_car_Y][Car2_X] = '2';
        gameBoard[player_car_Y][Car2_X+1] = '|';
     }
     else{
        gameBoard[player_car_Y-1][Car2_X] = 'X';
     }

     for(int i = 0 ; i < Board_height ; i++){
        for(int j = 0 ; j < Board_width ; j++){
            cout << gameBoard[i][j];
        }
        cout<<endl;
     }

// Deletes the car from Board so that new position of car be displayed
     for(int i = player_car_Y - 1; i <= player_car_Y ; i++){
        for(int j = Car1_X-1 ; j <= Car1_X+1 ; j++){
            gameBoard[i][j] = ' ';
        }
        for(int h = Car2_X-1 ; h <= Car2_X+1 ; h++){
            gameBoard[i][h] = ' ';
        }
     }
}

void game_logic(){

    //Car1 collision with obstacle check

    if(!car1Crashed){
        if(gameBoard[player_car_Y-2][Car1_X-1] == Obstacle ||
           gameBoard[player_car_Y-2][Car1_X] == Obstacle ||
           gameBoard[player_car_Y-2][Car1_X + 1] == Obstacle)
           {
            car1Crashed = true;
           }
         }

    //Car2 collision with obstacle check
     if(!car2Crashed){
        if(gameBoard[player_car_Y-2][Car2_X-1] == Obstacle ||
           gameBoard[player_car_Y-2][Car2_X] == Obstacle ||
           gameBoard[player_car_Y-2][Car2_X + 1] == Obstacle)
           {
            car2Crashed = true;
           }
     }

    //Moving Obstacle down
     for(int i = Board_height-1 ; i>1 ; i--){
        for(int j = 1 ; j<Board_width ; j++){
            bool Car1_Track = (j > 0 && j < 13);
            bool Car2_Track = (j > 13 && j < Board_width - 1);

            if((Car1_Track && !car1Crashed) || (Car2_Track && !car2Crashed)){
                if(gameBoard[i-2][j] == Obstacle){
                    gameBoard[i][j] = Obstacle;
                    gameBoard[i-2][j] = ' ';
                }
            }

        //Clearing Obstacles at end of gameBoard

            if(i >= player_car_Y-1 && gameBoard[i][j] == Obstacle){
                gameBoard[i][j] = ' ';
            }

        }
     }


    //Obstacles Spawning and Score increasing

    framecount++;
    if(framecount >= 6){
        framecount = 0;

        //P1 Obstacle Spawn and Score

        if(!car1Crashed){
            score1 += 10;
            if(rand() % 10 < 6){
                int Lane = (rand() % 2 == 0)? 4 : 9;
                gameBoard[0][Lane] = Obstacle;
                gameBoard[1][Lane] = Obstacle;
            }
        }
        //P2 Obstacle Spawn and Score
        if(!car2Crashed){
            score2 += 10;
            if(rand() % 10 < 6){
                int Lane = (rand() % 2 == 0)? 16 : 21;
                gameBoard[0][Lane] = Obstacle;
                gameBoard[1][Lane] = Obstacle;
            }
        }
    }

    //Game Over Check

    if(car1Crashed && car2Crashed){
        gameOver = true;
    }

}
