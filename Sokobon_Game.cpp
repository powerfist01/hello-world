#include<iostream>

#include<conio.h>

#include<stdlib.h>

#include<windows.h>

#include<fstream>

using namespace std;



//Size of game area

const int MAX_COL = 8;

const int MAX_ROW = 7;

int count_move = 0;



struct coord

{

    int x;

    int y;

};



class block

{

public:

    int x;

    int y;



    void set_coord(int x, int y){

        this-> x = x;

        this-> y = y;

    }



    //Condition to move the box from different sides.

    void left_right_push(coord player, int lr){         //Left push x - 1 & right push x + 1

        if( x == player.x + lr && y == player.y)

            x += lr;

    }



    void up_down_push(coord player, int ud){                 //up push y - 1 & down push y + 1

        if( y == player.y + ud && x == player.x)

            y += ud;

    }



/////////////////////////////////////////////// METHODS FOR Resisting ///////////////////////////////////////



    //Condition to resist box move when near to (another box OR a wall)

    void nearby_lr(block box, coord& player, int lr){                        //It has inverse sign because every action has reaction but opposite in direction

        if((x+(lr)*2 == box.x+lr) && (y == box.y)){                          //we have to resist the player to move the box when they align side by side

            if((box.x+lr == player.x) && (box.y == player.y)){

                player.x += lr;                                             //to cancel the effect of coming decrement to remain in the same position

                box.x += lr;

                count_move--;

            }

        }

    }

    void nearby_ud(block box, coord& player, int ud){                        //It has inverse sign because every action has reaction but opposite in direction

        if((y+(ud)*2 == box.y+ud) && (x == box.x)){

            if((box.y+ud == player.y) && (box.x == player.x)){

                player.y += ud;

                box.y += ud;

                count_move--;

            }

        }

    }



    //Condition to resist player move when near to wall

    void nearwall_lr(coord& player, int lr){                        //It has inverse sign because every action has reaction but opposite in direction

        if((x+lr == player.x) && (y == player.y)){

            player.x += lr;                                             //to cancel the effect of coming decrement to remain in the same position

            count_move--;

        }

    }

    void nearwall_ud(coord& player, int ud){                        //It has inverse sign because every action has reaction but opposite in direction

        if((y+ud == player.y) && (x == player.x)){

            player.y += ud;

            count_move--;

        }

    }



    //Condition to resist box move at the boundary

    void at_boundary_lr(coord& player, int lr, int boundary){

        if(x + lr == boundary + (lr)*2 && ((player.x == x + lr)&&(player.y == y))){

            player.x += lr;

            x += lr;

            count_move--;

        }

    }

    void at_boundary_ud(coord& player, int ud, int boundary){

        if(y + ud == boundary + (ud)*2 && ((player.y == y + ud)&&(player.x == x))){

            player.y += ud;

            y += ud;

            count_move--;

        }

    }



};





int main()

{

    fstream hiscore;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    char key;

    int score = 0;

    string name = "";

    SetConsoleTextAttribute(h, 255);

//############################################ HOME SCREEN ####################################################//



HOME_SCREEN:



    coord choose={5, 1};

    hiscore.open("high score.dat", ios::in);

    hiscore >> score;   hiscore >> name;

    do{



        //Condition to jump into help screen or into game screen

        if(key == '\r'){

            hiscore.close();

            if(choose.y == 1)

                goto GAME_SCREEN;

            else if(choose.y == 3)

                goto HELP_SCREEN;

            else if(choose.y == 5)

                goto ABOUT;

        }



        //to select to the option from the list

        switch(key){

        case 72:    //UP KEY

            if(choose.y == 1)       //resist to move further up at row 1

                choose.y += 2;

            choose.y -= 2;

            break;



        case 80:    //DOWN KEY

            if(choose.y == 5)       // resist to move further down at row 5

                choose.y -= 2;

            choose.y += 2;

            break;

        }



        system("cls");



        //to display the home list

        SetConsoleTextAttribute(h, 251);

        cout << "\n\t\x0f";

        SetConsoleTextAttribute(h, 252);

        cout<<" SOKOBAN GAME ";

        SetConsoleTextAttribute(h, 251);

        cout << "\x0f\n\n";

        SetConsoleTextAttribute(h, 255);

        for(int y = 1; y <= 5; y++){

            for(int x = 1; x <= 6; x++){

                if(choose.x == x && choose.y == y){

                    SetConsoleTextAttribute(h, 240);

                    cout << ">";

                    SetConsoleTextAttribute(h, 255);

                }

                else if(x == 6 && y == 1){

                    SetConsoleTextAttribute(h, 244);

                    cout << " START GAME";

                    SetConsoleTextAttribute(h, 255);

                }

                else if(x == 6 && y == 3){

                    SetConsoleTextAttribute(h, 244);

                    cout << " HELP";

                    SetConsoleTextAttribute(h, 244);

                }

                else if(x == 6 && y == 5){

                    SetConsoleTextAttribute(h, 244);

                    cout << " ABOUT";

                    SetConsoleTextAttribute(h, 255);

                }

                else

                    cout << " ";

            }

            cout << endl;

        }

        SetConsoleTextAttribute(h, 240);

        cout << "\nHigh Score : ";

        SetConsoleTextAttribute(h, 254);

        cout << name;

        SetConsoleTextAttribute(h, 240);

        cout << " in ";

        SetConsoleTextAttribute(h, 254);

        cout << score;

        SetConsoleTextAttribute(h, 240);

        cout << " moves";

        SetConsoleTextAttribute(h, 255);

        key = getch();



    }while(true);



//############################################ INTRODUCTION ####################################################//



ABOUT :

    SetConsoleTextAttribute(h, 240);

    system("CLS");

    Sleep(500);     cout << "First Year ";   Sleep(500);    cout << " First Semester" << endl;

    Sleep(500);     cout << "\nPROJECT : ";   Sleep(500);    cout << "SOKOBAN GAME" << endl;

    Sleep(500);    cout << "MADE BY : ";   Sleep(1000);      cout << "JA Developers"; Sleep(3000);



    key = 0;        //reset key

    SetConsoleTextAttribute(h, 255);

    goto HOME_SCREEN;



//############################################ HELP SCREEN ####################################################//



HELP_SCREEN:



    do{

        if(key == 8)        //Backspace

            goto HOME_SCREEN;



        system("CLS");

    SetConsoleTextAttribute(h, 240);

        cout << "\t***HELP***\n";

        cout << "1. Use cursor keys for movement\nof player." << endl;

        cout << "2. Place all the boxes in the\nspaces shown by star * to win \nthe game." << endl;

        cout << "Press 'r' to reset the box position." << endl;

        cout << "Player : \x02" << endl;

        cout << "Box : \xB1" << endl;

        cout << "Spaces : * ";



        key = getch();

    SetConsoleTextAttribute(h, 255);

    }while(true);





//############################################ GAME SCREEN ####################################################//



GAME_SCREEN:



    const int MAX_BOX = 6;

    const int MAX_WALL = 3;



    block box[MAX_BOX];

    block store_box[MAX_BOX];

    block wall[MAX_WALL];



    //initialize store block coordinates

    int count_store = 0;

    for(int x = 4; x <= 5; x++)

        for(int y = 3; y <= 5; y++)

        {

            store_box[count_store].set_coord(x, y);

            count_store++;

        }



    //initialize box coordinates

    int count_box = 0;

    for(int x = 3; x <= 6; x += 3)

        for(int y = 3; y <= 5; y++){

            if(x == 6 && y == 4)

                box[count_box].set_coord(x-1, y);

            else

                box[count_box].set_coord(x, y);

            count_box++;

        }



    //initialize wall coordinates

    wall[0].set_coord(4,2);

    wall[1].set_coord(4,6);

    wall[2].set_coord(7,4);



    coord player = {2, 2};



    do{

        //Action on cursor keys

        switch(key){

/////////////////////////////////////////////// ACTION ON UP KEY /////////////////////////////////////////////

        case 72:    //UP KEY

            //Condition to resist the movement when two box are side by side

            //nested loop is used for checking which boxes are near to each other in the game area

            for(int index1 = 0; index1 < MAX_BOX; index1++){

                for(int index2 = 0; index2 < MAX_BOX; index2++){

                    if(index1 != index2){

                            box[index1].nearby_ud(box[index2], player, 1);        //to resist the player in moving the box means

                    }                                                             //force should be on the player means opposite in direction.

                }

            }



            for(int index1 = 0; index1 < MAX_WALL; index1++){                   //same as above condition just difference is there is wall

                for(int index2 = 0; index2 < MAX_BOX; index2++){                //in place of second box.

                    wall[index1].nearby_ud(box[index2], player, 1);

                }

            }

            //Condition to resist box at boundary

            for(int index = 0; index < MAX_BOX; index++){

                box[index].at_boundary_ud(player, 1, 1);

            }

            //condition to resist the move of player at the boundary

            if(player.y == 2){

                player.y++;

                count_move--;

            }

            //condition to resist the move of player near wall

            for(int index = 0; index < MAX_WALL; index++){

                wall[index].nearwall_ud(player,1);

            }



            //Condition for pushing the box

            for(int index = 0; index < MAX_BOX; index++)

                box[index].up_down_push(player,-1);



            player.y--;

            count_move++;

            break;

/////////////////////////////////////////////// ACTION ON DOWN KEY /////////////////////////////////////////////

        case 80:    //DOWN KEY

            for(int index1 = 0; index1 < MAX_BOX; index1++){

                for(int index2 = 0; index2 < MAX_BOX; index2++){

                    if(index1 != index2){

                        box[index1].nearby_ud(box[index2], player, -1);

                    }

                }

            }

            for(int index1 = 0; index1 < MAX_WALL; index1++){

                for(int index2 = 0; index2 < MAX_BOX; index2++){

                    wall[index1].nearby_ud(box[index2], player, -1);

                }

            }



            for(int index = 0; index < MAX_BOX; index++){

                box[index].at_boundary_ud(player, -1, MAX_ROW);

            }



            if(player.y == MAX_ROW - 1){

                player.y--;

                count_move--;

            }

            for(int index = 0; index < MAX_WALL; index++){

                wall[index].nearwall_ud(player,-1);

            }





            for(int index = 0; index < MAX_BOX; index++)

                box[index].up_down_push(player, 1);



            player.y++;

            count_move++;

            break;

/////////////////////////////////////////////// ACTION ON LEFT KEY /////////////////////////////////////////////

        case 75:    //LEFT KEY

            for(int index1 = 0; index1 < MAX_BOX; index1++){

                for(int index2 = 0; index2 < MAX_BOX; index2++){

                    if(index1 != index2){

                        box[index1].nearby_lr(box[index2], player, 1);

                    }

                }

            }

            for(int index1 = 0; index1 < MAX_WALL; index1++){

                for(int index2 = 0; index2 < MAX_BOX; index2++){

                    wall[index1].nearby_lr(box[index2], player, 1);

                }

            }



            for(int index = 0; index < MAX_BOX; index++){

                box[index].at_boundary_lr(player, 1, 1);

            }



            if(player.x == 2){

                player.x++;

                count_move--;

            }

            for(int index = 0; index < MAX_WALL; index++){

                wall[index].nearwall_lr(player,1);

            }



            for(int index = 0; index < MAX_BOX; index++)

                box[index].left_right_push(player, -1);



            player.x--;

            count_move++;

            break;

/////////////////////////////////////////////// ACTION ON RIGHT KEY /////////////////////////////////////////////

        case 77:    //RIGHT KEY

            for(int index1 = 0; index1 < MAX_BOX; index1++){

                for(int index2 = 0; index2 < MAX_BOX; index2++){

                    if(index1 != index2){

                         box[index1].nearby_lr(box[index2], player, -1);

                    }

                }

            }

            for(int index1 = 0; index1 < MAX_WALL; index1++){

                for(int index2 = 0; index2 < MAX_BOX; index2++){

                    wall[index1].nearby_lr(box[index2], player, -1);

                }

            }



            for(int index = 0; index < MAX_BOX; index++){

                box[index].at_boundary_lr(player, -1, MAX_COL);

            }



            if(player.x == MAX_COL - 1){

                player.x--;

                count_move--;

            }

            for(int index = 0; index < MAX_WALL; index++){

                wall[index].nearwall_lr(player,-1);

            }



            for(int index = 0; index < MAX_BOX; index++)

                box[index].left_right_push(player, 1);



            player.x++;

            count_move++;

            break;

////////////////////////// reset the game ///////////////////////////////

        case 'r':

            player = {2, 2};

            for(int count_box = 0, x = 3; x <= 6; x += 3)

                for(int y = 3; y <= 5; y++){

                    if(x == 6 && y == 4)

                        box[count_box].set_coord(x-1, y);

                    else

                        box[count_box].set_coord(x, y);

                    count_box++;

                }

        break;

        }



        system("CLS");



        bool spc_ocupy1 = false, spc_ocupy2 = false, spc_ocupy3 = false;

        bool box_change = false;



/////////////////////////////////////////// DISPLAY GAME AREA //////////////////////////////////////////



        for(int y = 1; y <= MAX_ROW; y++){

            for(int x = 1; x <= MAX_COL; x++){

                spc_ocupy1 = false;

                spc_ocupy2 = false;

                spc_ocupy3 = false;

                box_change = false;

                for(int index = 0; index < MAX_BOX; index++){

                    if(box[index].x == x && box[index].y == y){

                        for(int index1 = 0; index1 < MAX_BOX; index1++){

                            if(store_box[index1].x == box[index].x && store_box[index1].y == box[index].y){

                                SetConsoleTextAttribute(h, 382);

                                cout << "\xB2";

                                SetConsoleTextAttribute(h, 255);

                                box_change = true;

                                spc_ocupy1 = true;

                            }

                        }

                        if(box_change == false){

                            SetConsoleTextAttribute(h, 182);

                            cout << "\xB1";

                            SetConsoleTextAttribute(h, 255);

                        }



                        spc_ocupy1 = true;

                        break;

                    }

                }

                if(spc_ocupy1 == false){

                    for(int index = 0; index < MAX_BOX; index++){

                        if(store_box[index].x == x && store_box[index].y == y && player.x == x && player.y == y){

                            SetConsoleTextAttribute(h, 253);

                            cout << "\x01";

                            SetConsoleTextAttribute(h, 255);

                            spc_ocupy2 = true;

                            break;

                        }

                        else if(store_box[index].x == x && store_box[index].y == y){

                            SetConsoleTextAttribute(h, 248);

                            cout << "*";

                            SetConsoleTextAttribute(h, 255);

                            spc_ocupy2 = true;

                            break;

                        }

                    }

                    if(spc_ocupy2 == false){

                        for(int index = 0; index < MAX_WALL; index++){

                            if(wall[index].x == x && wall[index].y == y){

                                SetConsoleTextAttribute(h, 177);

                                cout << "\xDB";

                                SetConsoleTextAttribute(h, 255);

                                spc_ocupy3 = true;

                                break;

                            }

                        }



                        if(spc_ocupy3 == false){





                            if(player.x == x && player.y == y){

                                SetConsoleTextAttribute(h, 253);

                                cout << "\x02";

                                SetConsoleTextAttribute(h, 255);

                            }

                            else if(x == 1 || x == MAX_COL || y == 1 || y == MAX_ROW){

                                SetConsoleTextAttribute(h, 177);

                                cout << "\xDB";

                                SetConsoleTextAttribute(h, 255);

                            }

                            else

                                cout << " ";



                        }

                    }

                }

            }

            cout << endl;

        }

        SetConsoleTextAttribute(h, 240);

        cout << "\nMOVES : " << count_move;

        SetConsoleTextAttribute(h, 255);

        int countbox = 0;

        for(int index1 = 0; index1 < MAX_BOX; index1++){

            for(int index2 = 0; index2 < MAX_BOX; index2++){

                if(box[index1].x == store_box[index2].x && box[index1].y == store_box[index2].y)

                    countbox++;

            }

        }

        if(countbox == MAX_BOX){

            system("CLS");

            SetConsoleTextAttribute(h, 240);

            cout << "\nYOU WON THE GAME IN " << count_move << " moves";

            hiscore.open("high score.dat", ios::in);

            hiscore >> score;

            hiscore.close();

            if(count_move < score || score == 0){

                hiscore.open("high score.dat", ios::out);

                cout << "\nYou have made a high score";

                cout << "\nEnter your name : ";

                cin >> name;

                score = count_move;

                hiscore << score << " ";  hiscore << name;

            }

            cout << "\nPress q to exit.";

            SetConsoleTextAttribute(h, 255);

            do{

                 key = getch();

            }while(key != 'q');

            break;

        }

        key = getch();





    }while(key != 'q');

    system("CLS");

}
