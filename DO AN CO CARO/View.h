#pragma once
#include "Data.h"
#include "Model.h"
#include "Control.h"

void CreateConsoleWindow(int pWidth, int pHeight); //Tao console voi kich thuoc cho truoc
void FixConsoleWindow(); //Co dinh console khong cho ng dung thay doi
void GotoXY(int x, int y);
void DrawBoard(int pSize);
//Hàm xử lý khi người chơi thua
int ProcessFinish(int pWhoWin, _POINT _A[][BOARD_SIZE], bool& _TURN, int& _X, int& _Y);
int AskContinue(_POINT _A[][BOARD_SIZE]);
void SetColor(int color);
void PrintText(string text, int color);
void DrawTableLine(int numOfCol, char mainSym, char subSym, int width);
void DrawBoard_1(int m, int n);
void Textcolor(int color);
void ScreenStartGame(int n, _POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter);
