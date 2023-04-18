#pragma once
#include "Data.h"
#include "Model.h"
#include "Control.h"

void resizeConsole(int width, int height);
void CreateConsoleWindow(int pWidth, int pHeight); //Tao console voi kich thuoc cho truoc
void FixConsoleWindow(); //Co dinh console khong cho ng dung thay doi
void GotoXY(int x, int y);
void DrawBoard(int pSize);
//Hàm xử lý khi người chơi thua
int ProcessFinish(int pWhoWin, _POINT _A[][BOARD_SIZE], bool& _TURN, int& _X, int& _Y,short int toadothang[24], bool& MO_NHAC);
int AskContinue(_POINT _A[][BOARD_SIZE]);
void SetColor(WORD color);
void DrawBoard_1(int m, int n);
void TextColor(int color);
void ScreenStartGame(int n, _POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& MO_NHAC, int& chedo);
void ShowCur(bool CursorVisibility);
void ShowTurn(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN);
void PrintText(string text, int color, int x, int y);
void DrawLoaded(_POINT _A[][BOARD_SIZE]);
_MENU YesNoMenu(int x, int y);
_MENU LoadingMenu();
_MENU EscMenu(_POINT _A[][BOARD_SIZE]);
void ShowPlayerInfo(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2);
void Help();
void About();
void Sound(bool& MO_NHAC);
void drawFrame(int x, int y, int width, int height);
// Hàm này nhận vào x, y là tọa độ tại vị trí bắt đầu vẽ khung, width và height là độ dài và chiều cao của khung
// (độ dài và chiều nó vẽ hên xui nên cứ nhập đại số nào vô rồi canh điều chỉnh cho nó hợp lý là được)
// có thể thay đổi các giá trị topleft... để vẽ loại khung khác nếu cần
void DrawBigText(string filename, int color, int x, int y);
void DrawBoardGiaoDien(_POINT _A[][BOARD_SIZE], int color);
void drawButton(int x, int y, string text);
void printCaro(int x, int y);
void Loading();
void DrawPhimTat(_POINT _A[][BOARD_SIZE]);
