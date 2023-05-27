#pragma once
#include "Data.h"
#include "Model.h"
#include "Control.h"

void resizeConsole(int width, int height);
void CreateConsoleWindow(int pWidth, int pHeight); //Tao console voi kich thuoc cho truoc
void FixConsoleWindow(); //Co dinh console khong cho ng dung thay doi
void SetColor(WORD color);
void TextColor(int color);
void ShowCur(bool CursorVisibility);
void GotoXY(int x, int y);
void DrawBoard(int pSize);
void XWin(_POINT _A[][BOARD_SIZE]);
void OWin(_POINT _A[][BOARD_SIZE]);
void Draw(_POINT _A[][BOARD_SIZE]);
void NhapNhayQuanCo(_POINT _A[BOARD_SIZE][BOARD_SIZE], const short int toadothang[24], int pWhoWin);
void ThongBaoWin(int pWhoWin, _POINT _A[][BOARD_SIZE]);
void DrawBoard_1(int m, int n);
void ShowTurn(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN);
void PrintText(string text, int color, int x, int y);
void DrawLoaded(_POINT _A[][BOARD_SIZE]);
void HELP();
void About();
void Sound(bool& SoundEffects, int& song, int& songtemp);
void SoundInGame(bool& SoundEffects, int& song, int& songtemp);
void drawFrame(int x, int y, int width, int height);
// Hàm này nhận vào x, y là tọa độ tại vị trí bắt đầu vẽ khung, width và height là độ dài và chiều cao của khung
// (độ dài và chiều nó vẽ hên xui nên cứ nhập đại số nào vô rồi canh điều chỉnh cho nó hợp lý là được)
// có thể thay đổi các giá trị topleft... để vẽ loại khung khác nếu cần
void DrawBigText(string filename, int color, int x, int y);
void DrawBoardGiaoDien(_POINT _A[][BOARD_SIZE], int color);
void drawButton(int x, int y, string text);
void drawSelectedButton(int x, int y, string text);
void printCaro(int x, int y);
void Loading();
void DrawPhimTat(_POINT _A[][BOARD_SIZE]);
void printBigCaro(int x, int y);
void ShowRank();
void ShowPlayerInfo(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2);
void drawBox(int x, int y, int width, int height);
