#pragma once
#include "Data.h"
#include "View.h"
#include "Model.h"

void StartGame(_POINT _A[][BOARD_SIZE], bool& _TURN, int& _COMMAND, int& _X, int& _Y, _PLAYER& _PLAYER1, _PLAYER& _PLAYER2);
void MoveLeft(_POINT _A[][BOARD_SIZE], int& _X, int& _Y);
void MoveRight(_POINT _A[][BOARD_SIZE], int& _X, int& _Y);
void MoveDown(_POINT _A[][BOARD_SIZE], int& _X, int& _Y);
void MoveUp(_POINT _A[][BOARD_SIZE], int& _X, int& _Y);

void ScreenStartGame(int n, _POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& SoundEffects, int& chedo, _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, int& song, int& songtemp);
int ProcessFinish(int pWhoWin, _POINT _A[][BOARD_SIZE], bool& _TURN, int& _X, int& _Y, short int toadothang[24], bool& SoundEffects, _PLAYER& _PLAYER1, _PLAYER& _PLAYER2);
int AskContinue(_POINT _A[][BOARD_SIZE]);
void SaveGame(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN, int chedo);
void LoadGame(string filename, _POINT _A[][BOARD_SIZE], _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& _TURN, int& _COMMAND, int& _X, int& _Y, int& chedo);
char RunYesNoMenu(int option);
int SelectMenu(_MENU menu);
string RunLoadingMenu(int option);
void RunEscMenu(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN, int option, bool& runGame, int chedo, int& song, int& songtemp);
void RunGame(_POINT _A[][BOARD_SIZE], _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& _TURN, int& _COMMAND, int& _X, int& _Y, bool& SoundEffects, int& chedo, int& song, int& songtemp);
void PlayWithComputer(_POINT _A[][BOARD_SIZE], bool& _TURN, int& _COMMAND, _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, int& _X, int& _Y, bool validEnter, bool& SoundEffects, int& chedo, int& song, int& songtemp);
int SelectMenu1(_MENU menu);
_MENU YesNoMenu(int x, int y);
_MENU LoadingMenu();
int EscMenu(_POINT _A[][BOARD_SIZE], bool& SoundEffects, int& song, int& songtemp);
