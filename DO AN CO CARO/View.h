#pragma once
#include "Data.h"
#include "Model.h"
#include "Control.h"

void resizeConsole(int width, int height); //Tạo màn hình console với kích thước cho trước
void FixConsoleWindow(); //Cố định màn hình console, không cho người dùng thay đổi
void SetColor(WORD color); //Thay đổi màu chữ
void TextColor(int color); //Thay đổi màu nền và màu chữ
void ShowCur(bool CursorVisibility); //Hiển thị con trỏ chuột hay không
void GotoXY(int x, int y); //Di chuyển đến tọa độ (x,y) trên màn hình console
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
// hiện menu hướng dẫn
void About();
// menu các thành viên nhóm
void Sound(bool& SoundEffects, int& song, int& songtemp);
//Hàm này hiện menu điều chỉnh âm thanh ở ngoài
void SoundInGame(bool& SoundEffects, int& song, int& songtemp);
// Hàm này hiện menu điều chỉnh âm thanh khi đang chơi
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
// Hàm này sẽ hiện xếp hạng của người chơi
void ShowPlayerInfo(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2);
void drawBox(int x, int y, int width, int height);

