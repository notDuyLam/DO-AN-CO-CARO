#pragma once

//Libraries
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <vector>
#include <string>
#include <stack>
#include <thread>
#include <iomanip>
using std::cout;
using std::cin;
using std::string;
using namespace std;

//Hằng số
#define BOARD_SIZE 16 // Kích thước ma trận bàn cờ
#define LEFT 0 // Tọa độ trái màn hình bàn cờ
#define TOP 0 // Tọa độ trên màn hình bàn cờ
#define MIDDLESCREEN 540 //Tọa độ giữa màn hình hiển thị game theo trục x
#define WIDTH 1080
#define HEIGHT 580
#define X_CENTER WIDTH / 16 + 2
#define Y_CENTER HEIGHT / 32
#define FIRST true
#define SECOND false
#define P_X -1
#define P_O 1
#define SPACE 32
#define ENTER 13
#define ESC 27
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define HORIZONTAL_LINE (char)196
#define VERTICAL_LINE (char)179
#define HORIZONTAL_DISTANCE 4
#define VERTICAL_DISTANCE 2
#define TOP_LEFT (char)218
#define TOP_RIGHT (char)191
#define BOTTOM_LEFT (char)192
#define BOTTOM_RIGHT (char)217
#define TOP_CROSS (char)194
#define BOTTOM_CROSS (char)193
#define	LEFT_CROSS (char)195
#define RIGHT_CROSS (char)180
#define CROSS (char)197
#define FULL (char)219
#define DOUBLE_TOP_RIGHT (char)187
#define DOUBLE_TOP_LEFT (char)201
#define DOUBLE_BOTTOM_LEFT (char)200
#define DOUBLE_BOTTOM_RIGHT (char)188
#define DOUBLE_HORIZONTAL (char)205
#define DOUBLE_VERTICAL (char)186
const int KEY_ARROW_UP = 72;
const int KEY_ARROW_DOWN = 80;
const int KEY_ARROW_LEFT = 75;
const int KEY_ARROW_RIGHT = 77;

struct _POINT {
	int x,
		y,
		c;
}; // x: tọa độ dòng, y: tọa độ cột, c: đánh dấu
struct MOVE {
	int x;
	int y;
};
struct _MENU
{
	int options;	 //Số chức năng của Menu
	int x;			 // Tọa độ của điểm bắt
	int y;			 //đầu của chức năng đầu tiên
	int cursorColor; //Màu của con trỏ chọn Menu
};
struct _PLAYER
{
	string name; //Tên người chơi
	int wins = 0;	 //Đếm số trận thắng
	int rank; //Xếp hạng của người chơi

	bool operator>(_PLAYER other);
	bool operator<(_PLAYER other);
	bool operator==(_PLAYER other);
};
//File stuffs
#define SAVED_LIST "savedlist.txt" //Tên các file game đã được lưu
#define PLAYER_LIST "PlayerList.txt" //Thông tin các người chơi đã chơi game	
#pragma comment (lib,"winmm.lib") //dùng cho PlaySoundA()