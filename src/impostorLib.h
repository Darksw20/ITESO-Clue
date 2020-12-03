#ifndef _IMPOSTOR_GUARD_H
#define _IMPOSTOR_GUARD_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "raylib.h"

typedef enum {
    LOGO, 
    POWERED, 
    DISCLAIMER, 
    MENU,
    GAME,
    PAUSE,
    NEWGAME,
    LOADGAME,
    SAVEGAME,
    SETTINGS,
    CREDITS,
    GREETIGS,
    THANKS,
    EXIT

} GameScreen;


struct Box{
    int                 isRoom;
    char                status;         //f = free; - = blocked; p = player; d = doors; r = rooms, c = cafeteria
    Vector2             tilePosition;
};


struct BoardGame{
    Texture2D           mapBackground;
    Texture2D           map;
    Camera2D            camera;
    struct Box          boxes[24][24];
}; typedef struct BoardGame* Board;


struct Card_struct{
    char                uniqueInitial;
    char*               name;
    Texture2D           visual;
}; typedef struct Card_struct* Card;


struct Player_ref{
    int                 isLive; 
    int                 movingAnimate;
    int                 cards[3];       // Deck of cards
    int                 frame;          // Visible frame
    int                 maxFrames;      // Frames in the Texture
    int                 x;
    int                 y;
    int                 movesLeft;
    float               frameWidth;     // Width of the Colider
    float               frameHeight;    // Height of the Colider
    float               timer;          // Helper Timer for animation
    char*               c_player;       // Color of the character
    char*               name;           // Name of the player
    Card                cardsInHand;    // Cards of each player
    int                 numCards;       // Number of cards for each player
    struct Rectangle    frameRec;       // Rectangle Frame Colider
    struct Vector2      position;       // Position in the window
    Texture2D           skin[4];        // 0 = Stand Right || 1 = Stand Left || 2 = Walking Right || 3 = Walking Left  
    struct Player_ref*  next;           // Pointer To Create a CLL
}; typedef struct Player_ref* Player;


struct ImpostorGame{
    int                 screenWidth;
    int                 screenHeight;
    int                 screenCenterWidth;
    int                 screenCenterHeight;
    int                 relScreenX;
    int                 relScreenY;
    int                 fps;
    int                 playersAlive;
    float               speed;
    Card                envelope;               // Cards inside the envelope
    Board               board;
    Player              playerInTurn;
};




struct GameHistory{
    
};

struct Notebook{
    
};

struct Accusations{

};

typedef struct ImpostorGame* GameState, GameInitialState;

GameState newImpostorGame();
Player newPlayer(GameState, char[10]);
Board NewBoard(GameState);

void newPlayerList(GameState);
void addPlayerToList(GameState, Player);

void playImpostor(GameState);
void endImpostor(GameState);
void initImpostor(GameState);

#endif