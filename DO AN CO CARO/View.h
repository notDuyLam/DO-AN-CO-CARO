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
// Vẽ thông báo X chiến thắng
void OWin(_POINT _A[][BOARD_SIZE]);
// Vẽ thông báo O chiến thắng
void Draw(_POINT _A[][BOARD_SIZE]);
// Vẽ thông báo hòa
void NhapNhayQuanCo(_POINT _A[BOARD_SIZE][BOARD_SIZE], const short int toadothang[24], int pWhoWin);
// Làm cho quân cờ mà xếp đủ 5 quân thẳng hàng nhấp nháy khi chiến thắng
void ThongBaoWin(int pWhoWin, _POINT _A[][BOARD_SIZE]);
// Hàm này gọi 2 hàm XWin OWin tùy theo người chơi nào thắng để thông báo thắng
void DrawBoard_1(int m, int n);
void ShowTurn(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN);
// Làm mờ hoặc làm nổi chữ X O khi đang chơi để biết là đang tới lượt của người chơi nào
void PrintText(string text, int color, int x, int y);
// In ra đoạn text với màu là color tại vị trí x y của màn hình
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
// Vẽ 1 khung nhỏ cho text được truyền vào để cho thành 1 nút
void drawSelectedButton(int x, int y, string text);
// Tương tự trên nhưng khung sẽ to hơn và có màu đỏ để làm nổi bật để cho biết đây là nút đang được chọn
void printCaro(int x, int y);
// In ra chữ Caro logo của game
void printBigCaro(int x, int y);
// Tương tự trên nhưng to hơn
void Loading();
// Màn hình Loading của game 
void DrawPhimTat(_POINT _A[][BOARD_SIZE]);
// Hàm này vẽ các phím lên màn hình khi chơi để người dùng biết nhấn nút nào để chơi
void ShowRank();
// Hàm này sẽ hiện xếp hạng của người chơi
void ShowPlayerInfo(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2);
// Hàm này khi vào đầu mỗi trận đấu in ra số thắng và xếp hạng của người chơi

