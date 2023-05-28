#pragma once
#include "Data.h"
#include "View.h"

void ResetData(_POINT _A[][BOARD_SIZE], bool& _TURN, int& _COMMAND, int& _X, int& _Y);
// Thiết lập lại dữ liệu cho bàn cờ mới
int TestBoard(_POINT _A[][BOARD_SIZE], bool _TURN, int cRow, int cCol,short int toadothang[24]);
// Gọi hàm CheckTie và CheckWin để kiểm tra có thắng hay hòa chưa, nếu chưa thì tiếp tục chơi
int CountX(_POINT _A[][BOARD_SIZE]);
// Đếm số lượng quân X có trên bàn cờ
int CountO(_POINT _A[][BOARD_SIZE]);
// Đếm số lượng quân O có trên bàn cờ
int CheckBoard(int pX, int pY, _POINT _A[][BOARD_SIZE], bool& _TURN);
// Kiểm tra xem ô đã được đánh dấu hay chưa, nếu chưa thì trả về c=0, rồi thì trả về giá trị c phù hợp
bool CheckTie(_POINT _A[][BOARD_SIZE]);
// Kiểm tra hòa
bool HorizontalCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24]);
// Kiểm tra thắng theo đường ngang
bool VerticalCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24]);
// Kiểm tra thắng theo đường dọc
bool ForwardSlashCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24]);
// Kiểm tra thắng theo đường chéo tới
bool BackwardSlashCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24]);
// Kiểm tra thắng theo đường chéo ngược
bool CheckWin(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24]);
// Hàm kiểm tra thắng, hàm này gọi tất cả các hàm trên để kiểm tra có thắng chưa
int GetColIndex(int pX);
// Lấy giá trị cột ở hoành độ pX
int GetRowIndex(int pY);
// Lấy giá trị hàng ở tung độ pY
void PlayBackGroundMusic(int song);
// Bật nhạc nền tùy bài theo biến song
void StopMusic();
// Dừng tất cả nhạc đang mở
void LoadData(string filename, _POINT _A[][BOARD_SIZE], _PLAYER& _PLAYER1, _PLAYER& _PLAYER2, bool& _TURN, int& _COMMAND, int& _X, int& _Y, int& chedo);
std::vector<string> LoadFiles();
bool CheckFileExistence(string filename);
// Kiểm tra file có tồn tại trong danh sách các file đã lưu hay không
void SaveData(string filename, _POINT _A[][BOARD_SIZE], _PLAYER _PLAYER1, _PLAYER _PLAYER2, bool _TURN, int chedo);
void SavePlayer(_PLAYER player);
// Lưu một tên người chơi vào file playerList và sắp xếp danh sách người chơi theo số thắng (nếu người chơi đã xuất hiện thì không lưu mới)
_PLAYER LoadPlayer(_PLAYER player);
void SetPlayerRank(_PLAYER& player);
int CheckPlayerExistence(_PLAYER player);
// Kiểm tra xem người chơi có trong danh sách những người chơi trước đó không
std::vector<_PLAYER> GetPlayerList();
void SortPlayerList(std::vector<_PLAYER>& playerList);
// Sắp xếp danh sách những người chơi theo số thắng và ghi lại vào file
void PlaySoundEffect(string s, bool SoundEffects);
// Thao tác với hiệu ứng âm thanh
int getX(_POINT _A[][BOARD_SIZE], int i, int j);
// Lưu giá trị của hoành độ x
int getY(_POINT _A[][BOARD_SIZE], int i, int j);
// Lưu giá trị của tung độ y
int getCheck(_POINT _A[][BOARD_SIZE], int i, int j);
// Lưu giá trị ô trống (0 là chưa đánh dấu, -1 là X đánh, 1 là O đánh)
MOVE timkiemnuocdi(_POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& SoundEffects);
// Tìm kiếm nước đi cho máy
double tancongdoc(_POINT _A[][BOARD_SIZE], int x, int y);
// Tính điểm tấn công cho ô trống theo hàng dọc
double tancongngang(_POINT _A[][BOARD_SIZE], int x, int y);
// Tính điểm tấn công cho ô trống theo hàng ngang
double tancongcheoxuoi(_POINT _A[][BOARD_SIZE], int x, int y);
// Tính điểm tấn công cho ô trống theo đường chéo xuôi
double tancongcheonguoc(_POINT _A[][BOARD_SIZE], int x, int y);
// Tính điểm tấn công cho ô trống theo đường chéo ngược
double phongngudoc(_POINT _A[][BOARD_SIZE], int x, int y);
// Tính điểm phòng thủ cho ô trống theo hàng dọc
double phongngungang(_POINT _A[][BOARD_SIZE], int x, int y);
// Tính điểm phòng thủ cho ô trống theo hàng ngang
double phongngucheoxuoi(_POINT _A[][BOARD_SIZE], int x, int y);
// Tính điểm phòng thủ cho ô trống theo đường chéo xuôi
double phongngucheonguoc(_POINT _A[][BOARD_SIZE], int x, int y);
// Tính điểm phòng thủ cho ô trống theo đường chéo ngược
void SetPlayer(_PLAYER& _PLAYER1, _PLAYER& _PLAYER2);
// Khi bắt đầu chơi gọi hàm này để người dùng nhập tên đồng thời lấy tên đó để xử lý ở các hàm khác
void SetPlayerVsComputer(_PLAYER& _PLAYER1, _PLAYER& _PLAYER2);
// Tương tự trên nhưng là cho khi chơi với máy, PLAYER2 là máy sẽ được tên mặc định là CARO_AI
