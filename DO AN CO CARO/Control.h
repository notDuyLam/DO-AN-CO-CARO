#pragma once
#include "Data.h"
#include "View.h"
#include "Model.h"

void StartGame(_POINT _A[][BOARD_SIZE], bool& _TURN, int& _COMMAND, int& _X, int& _Y);
void MoveLeft(_POINT _A[][BOARD_SIZE], int& _X, int& _Y);
void MoveRight(_POINT _A[][BOARD_SIZE], int& _X, int& _Y);
void MoveDown(_POINT _A[][BOARD_SIZE], int& _X, int& _Y);
void MoveUp(_POINT _A[][BOARD_SIZE], int& _X, int& _Y);

void GamePlay(_POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter);