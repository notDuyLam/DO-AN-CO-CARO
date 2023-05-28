#pragma once
#include "Data.h"
#include "View.h"
#include "Model.h"

void StartGame(_POINT _A[][BOARD_SIZE], bool& _TURN, int& _COMMAND, int& _X, int& _Y, _PLAYER& _PLAYER1, _PLAYER& _PLAYER2);
// Hàm này được gọi khi một trận mới được bắt đầu, hàm sẽ lấy thông tin về xếp hạng, số thắng,... của 2 người chơi đồng thời
// vẽ các giao diện cần thiết để chơi như các khung hướng dẫn phím bấm, bàn cờ...
void MoveLeft(_POINT _A[][BOARD_SIZE], int& _X, int& _Y);
// Di chuyển con trỏ khi chơi qua trái
void MoveRight(_POINT _A[][BOARD_SIZE], int& _X, int& _Y);
// Di chuyển con trỏ khi chơi qua phải
void MoveDown(_POINT _A[][BOARD_SIZE], int& _X, int& _Y);
// Di chuyển con trỏ khi chơi đi xuống
void MoveUp(_POINT _A[][BOARD_SIZE], int& _X, int& _Y);
// Di chuyển con trỏ khi chơi đi lên
void ScreenStartGame(int n, _POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& SoundEffects, int& chedo, _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, int& song, int& songtemp);
// Hàm này là menu chính của game, khi người chơi tương tác với menu chính là ở trong hàm này, từ hàm này sẽ gọi đến các hàm chức năng khác của game
// Hàm sẽ lặp lại vô tận mỗi khi người dùng ấn các nút W S hoặc mũi tên lên xuống để di chuyển qua lại giữa các lựa chọn
// và cứ mỗi lần ấn như vậy màn hình sẽ in ra các lựa chọn 1 lần nữa và làm nổi bật lựa chọn đang được chọn
int ProcessFinish(int pWhoWin, _POINT _A[][BOARD_SIZE], bool& _TURN, int& _X, int& _Y, short int toadothang[24], bool& SoundEffects, _PLAYER& _PLAYER1, _PLAYER& _PLAYER2);
// Nếu như có người chiến thắng hoặc hòa, hàm sẽ xử lý để thông báo thắng/hòa, ngược lại đổi lượt để tiếp tục chơi
int AskContinue(_POINT _A[][BOARD_SIZE]);
// Hàm sẽ hiện thông báo khi kết thúc game để hỏi người chơi có muốn tiếp tục không
void SaveGame(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN, int chedo);
// Chức năng lưu game khi đang chơi, giới hạn lưu tối đa là 10 file nếu vượt quá thì sẽ hỏi người dùng ghi đè lên file cũ
void LoadGame(string filename, _POINT _A[][BOARD_SIZE], _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& _TURN, int& _COMMAND, int& _X, int& _Y, int& chedo);
int SelectMenu(_MENU menu);
string RunLoadingMenu(int option);
void RunEscMenu(_POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN, int option, bool& runGame, int chedo, int& song, int& songtemp);
void RunGame(_POINT _A[][BOARD_SIZE], _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& _TURN, int& _COMMAND, int& _X, int& _Y, bool& SoundEffects, int& chedo, int& song, int& songtemp);
void PlayWithComputer(_POINT _A[][BOARD_SIZE], bool& _TURN, int& _COMMAND, _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, int& _X, int& _Y, bool validEnter, bool& SoundEffects, int& chedo, int& song, int& songtemp);
// Choi voi may 
int SelectMenu1(_MENU menu);
_MENU LoadingMenu();
int EscMenu(_POINT _A[][BOARD_SIZE], bool& SoundEffects, int& song, int& songtemp);
// Đây là hàm sẽ hiện menu khi người chơi ấn ESC khi đang chơi
