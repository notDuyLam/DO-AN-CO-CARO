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
void DrawBoard(int pSize); //Vẽ bàn cờ
void DrawBoard_1(int m, int n); // Hàm hỗ trợ việc vẽ bàn cờ
void XWin(_POINT _A[][BOARD_SIZE]);
// In thông báo X chiến thắng
void OWin(_POINT _A[][BOARD_SIZE]);
// In thông báo O chiến thắng
void Draw(_POINT _A[][BOARD_SIZE]);
// In thông báo hòa
void NhapNhayQuanCo(_POINT _A[BOARD_SIZE][BOARD_SIZE], const short int toadothang[24], int pWhoWin);
// Làm cho quân cờ mà xếp đủ 5 quân thẳng hàng nhấp nháy khi chiến thắng
void ThongBaoWin(int pWhoWin, _POINT _A[][BOARD_SIZE]);
// Hàm này gọi ra các hàm XWin, OWin hay Draw để thông báo thắng/hòa
void ShowTurn(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN);
// Làm mờ hoặc làm nổi chữ X O khi đang chơi để biết là đang tới lượt của người chơi nào
void PrintText(string text, int color, int x, int y);
// In ra đoạn text với màu là color tại vị trí x y của màn hình
void DrawLoaded(_POINT _A[][BOARD_SIZE]);
// Hàm này để đánh dấu X và O trên bàn cờ với dữ liệu đã được lưu, dùng trong Load game
void HELP();
// Hiện hướng dẫn cho game
void About();
// Hiện thông tin các thành viên nhóm
void Sound(bool& SoundEffects, int& song, int& songtemp);
//Hàm này hiện menu điều chỉnh âm thanh ở ngoài
void SoundInGame(bool& SoundEffects, int& song, int& songtemp);
// Hàm này hiện menu điều chỉnh âm thanh khi đang chơi
void drawFrame(int x, int y, int width, int height);
// Hàm này nhận vào x, y là tọa độ tại vị trí bắt đầu vẽ khung, width và height là độ dài và chiều cao của khung
// có thể thay đổi các giá trị topleft... để vẽ loại khung khác nếu cần
void DrawBigText(string filename, int color, int x, int y);
// Hàm này dùng để in chữ từ file txt với tham số là màu chữ và tọa độ x, y cần in
void DrawBoardGiaoDien(_POINT _A[][BOARD_SIZE], int color);
// Vẽ khung nhỏ góc dưới bên phải màn hình để hiển thị các phím tắt hay menu phụ
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
// Thiết lập giao diện Ranking khi người chơi có nhu cầu xem danh sách thứ hạng của trò chơi
void ShowPlayerInfo(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2);
// Thiết lập giao diện thông tin người chơi khi vào game như số ván đã thắng, thứ hạng hiện tại

