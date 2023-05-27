#pragma once
#include "Data.h"
#include "View.h"

void ResetData(_POINT _A[][BOARD_SIZE], bool& _TURN, int& _COMMAND, int& _X, int& _Y);
//void GabageCollect(); // Chi viet ham nay khi nao co dung con tro
int TestBoard(_POINT _A[][BOARD_SIZE], bool _TURN, int cRow, int cCol,short int toadothang[24]);
int CountX(_POINT _A[][BOARD_SIZE]);
int CountO(_POINT _A[][BOARD_SIZE]);
int CheckBoard(int pX, int pY, _POINT _A[][BOARD_SIZE], bool& _TURN);
bool CheckTie(_POINT _A[][BOARD_SIZE]);
bool HorizontalCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24]);
bool VerticalCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24]);
bool ForwardSlashCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24]);
bool BackwardSlashCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24]);
bool CheckWin(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24]);
int GetColIndex(int pX);
int GetRowIndex(int pY);
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
int getX(_POINT _A[][BOARD_SIZE], int i, int j);
// Luu gia tri cua X
int getY(_POINT _A[][BOARD_SIZE], int i, int j);
// Luu gia tri Y
int getCheck(_POINT _A[][BOARD_SIZE], int i, int j);
// Luu gia tri cua o trong
MOVE timkiemnuocdi(_POINT _A[][BOARD_SIZE], bool _TURN, int _COMMAND, int _X, int _Y, bool validEnter, bool& SoundEffects);
//Tim nuoc di cho may 
double tancongdoc(_POINT _A[][BOARD_SIZE], int x, int y);
// Tinh diem tan cong cho o trong theo hang doc
double tancongngang(_POINT _A[][BOARD_SIZE], int x, int y);
// Tinh diem tan cong cho o trong theo hang ngang
double tancongcheoxuoi(_POINT _A[][BOARD_SIZE], int x, int y);
// Tinh diem tan cong cho o trong theo duong cheo xuoi
double tancongcheonguoc(_POINT _A[][BOARD_SIZE], int x, int y);
// Tinh diem tan cong cho o trong theo duong cheo nguoc 
double phongngudoc(_POINT _A[][BOARD_SIZE], int x, int y);
// Tinh diem phong thu cho o trong theo hang doc
double phongngungang(_POINT _A[][BOARD_SIZE], int x, int y);
// Tinh diem phong thu cho o trong theo hang ngang
double phongngucheoxuoi(_POINT _A[][BOARD_SIZE], int x, int y);
// Tinh diem phong thu cho o trong theo duong cheo xuoi
double phongngucheonguoc(_POINT _A[][BOARD_SIZE], int x, int y);
// Tinh diem phong thu cho o trong theo duong cheo nguoc
void SetPlayer(_PLAYER& _PLAYER1, _PLAYER& _PLAYER2);
// Khi bắt đầu chơi gọi hàm này để người dùng nhập tên đồng thời lấy tên đó để xử lý ở các hàm khác
void SetPlayerVsComputer(_PLAYER& _PLAYER1, _PLAYER& _PLAYER2);
// Tương tự trên nhưng là cho khi chơi với máy, PLAYER2 là máy sẽ được tên mặc định là CARO_AI
