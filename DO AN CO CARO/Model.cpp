#include "Model.h"

void ResetData(_POINT _A[][BOARD_SIZE], bool& _TURN, int& _COMMAND, int& _X, int& _Y)
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			_A[i][j].x = 4 * j + LEFT + 2; // Trùng với hoành độ màn hình bàn cờ
			_A[i][j].y = 2 * i + TOP + 1; // Trùng với tung độ màn hình bàn cờ
			_A[i][j].c = 0; // 0 nghĩa là chưa ai đánh dấu, nếu đánh dấu phải theo quy 
			//định như sau: -1 là lượt true đánh, 1 là lượt false đánh
		}
	}
	_TURN = true; _COMMAND = -1; // Gán lượt và phím mặc định
	_X = _A[0][0].x; _Y = _A[0][0].y; // Thiết lập lại tọa độ hiện hành ban đầu
}
//Hàm dọn dẹp tài nguyên
//void GabageCollect()
//{
//	// Dọn dẹp tài nguyên nếu có khai báo con trỏ
//}
bool CheckTie(_POINT _A[][BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_A[i][j].c == 0) return false;
		}
	}
	return true;
}

int TestBoard(_POINT _A[][BOARD_SIZE], bool _TURN, int cRow, int cCol,short int toadothang[24])
{
	if (CheckTie(_A)) return 0; //Hoa
	else
	{
		if (CheckWin(_A, cRow, cCol,toadothang))
			return (_TURN == FIRST ? P_X : P_O); //-1 nghia la luot 'true' thang
		else
			return 2;
	}
}

int CheckBoard(int pX, int pY, _POINT _A[][BOARD_SIZE], bool& _TURN) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {
				if (_TURN == true) _A[i][j].c = -1; // Nếu lượt hiện hành là true thì c = -1
				else _A[i][j].c = 1; // Nếu lượt hiện hành là false thì c = 1
				return _A[i][j].c;
			}
		}
	}
	return 0;
}

bool HorizontalCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24])
{
	int countWin = 1;
	int count = 1;
	unsigned short int id = 0;
	int dem = 1;
	toadothang[id] = currentRow;
	id++;
	toadothang[id] = currentCol;
	id++;
	while (currentCol + count < BOARD_SIZE)
	{
		if ((_A[currentRow][currentCol + count].c == _A[currentRow][currentCol].c))
		{
			countWin++;
			toadothang[id] = currentRow;
			id++;
			toadothang[id] = currentCol + dem;
			id++;
			dem++;
			count++;
		}
		else
			break;
	}

	count = 1;
	dem = 1;
	while (currentCol - count > -1)
	{
		if ((_A[currentRow][currentCol - count].c == _A[currentRow][currentCol].c))
		{
			countWin++;
			toadothang[id] = currentRow;
			id++;
			toadothang[id] = currentCol - dem;
			id++;
			dem++;
			count++;
		}
		else
			break;
	}


	if (countWin >= 5)
	{
		return true;
	}
	else
		return false;
}

bool VerticalCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24])
{
	int countWin = 1;
	int count = 1;
	unsigned short int id = 0;
	int dem = 1;
	toadothang[id] = currentRow;
	id++;
	toadothang[id] = currentCol;
	id++;
	while (currentRow + count < BOARD_SIZE)
	{
		if ((_A[currentRow + count][currentCol].c == _A[currentRow][currentCol].c))
		{

			countWin++;
			toadothang[id] = currentRow + dem;
			id++;
			toadothang[id] = currentCol;
			id++;
			dem++;
			count++;
		}
		else
			break;
	}

	count = 1;
	dem = 1;
	while (currentRow - count > -1)
	{
		if (_A[currentRow - count][currentCol].c == _A[currentRow][currentCol].c)
		{
			countWin++;
			toadothang[id] = currentRow - dem;
			id++;
			toadothang[id] = currentCol;
			id++;
			dem++;
			count++;
		}
		else
			break;
	}

	if (countWin >= 5)
		return true;
	else
		return false;
}

bool ForwardSlashCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24])
{
	int countWin = 1;
	int count = 1;

	unsigned short int id = 0;
	int dem = 1;
	toadothang[id] = currentRow;
	id++;
	toadothang[id] = currentCol;
	id++;
	while (currentRow + count < BOARD_SIZE && currentCol - count > -1)
	{
		if ((_A[currentRow + count][currentCol - count].c == _A[currentRow][currentCol].c))
		{

			countWin++;
			toadothang[id] = currentRow + dem;
			id++;
			toadothang[id] = currentCol - dem;
			id++;
			dem++;
			count++;
		}
		else
			break;
	}

	count = 1;
	dem = 1;
	while (currentRow - count > -1 && currentCol + count < BOARD_SIZE)
	{
		if (_A[currentRow - count][currentCol + count].c == _A[currentRow][currentCol].c)
		{
			countWin++;
			toadothang[id] = currentRow - dem;
			id++;
			toadothang[id] = currentCol + dem;
			id++;
			dem++;
			count++;
		}
		else
			break;
	}

	if (countWin >= 5)
		return true;
	else
		return false;
}

bool BackwardSlashCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24])
{
	int countWin = 1;
	int count = 1;
	unsigned short int id = 0;
	int dem = 1;
	toadothang[id] = currentRow;
	id++;
	toadothang[id] = currentCol;
	id++;

	while (currentRow + count < BOARD_SIZE && currentCol + count < BOARD_SIZE)
	{
		if ((_A[currentRow + count][currentCol + count].c == _A[currentRow][currentCol].c))
		{
			countWin++;
			toadothang[id] = currentRow + dem;
			id++;
			toadothang[id] = currentCol + dem;
			id++;
			dem++;
			count++;
		}
		else
			break;
	}

	count = 1;
	dem = 1;

	while (currentRow - count > -1 && currentCol - count > -1)
	{
		if ((_A[currentRow - count][currentCol - count].c == _A[currentRow][currentCol].c))
		{
			countWin++;
			toadothang[id] = currentRow - dem;
			id++;
			toadothang[id] = currentCol - dem;
			id++;
			dem++;
			count++;
		}
		else
			break;
	}
	if (countWin >= 5)
		return true;
	else
		return false;
}

bool CheckWin(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol, short int toadothang[24])
{
	if (HorizontalCheck(_A, currentRow, currentCol,toadothang) || VerticalCheck(_A, currentRow, currentCol,toadothang) || BackwardSlashCheck(_A, currentRow, currentCol,toadothang) || ForwardSlashCheck(_A, currentRow, currentCol,toadothang))
		return true;
	else return false;
}

int GetRowIndex(int pY)
{
	int rowIndex;

	rowIndex = (pY - TOP - 1) / VERTICAL_DISTANCE;

	return rowIndex;
}

int GetColIndex(int pX)
{
	int colIndex;

	colIndex = (pX - LEFT - 2) / HORIZONTAL_DISTANCE;

	return colIndex;
}

void PlayBackGroundMusic(int song)
{
	if (song % 4 == 0)
		PlaySound(TEXT("nhacnen1.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);// Bat nhac nen 
	else if(song % 4 == 1)
		PlaySound(TEXT("nhacnen2.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);// Bat nhac nen
	else if (song % 4 == 2)
		PlaySound(TEXT("nhacnen3.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);// Bat nhac nen 
	else if (song % 4 == 3)
		PlaySound(TEXT("nhacnen4.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);// Bat nhac nen 
}

void StopMusic()
{
	PlaySound(0, 0, 0); // Tat nhac

}

void PlaySoundEffect(string s, bool MO_NHAC)
{
	if (!MO_NHAC)
		return;
	if (s == "move")
		PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC); // Dung de bat nhac khi di
	else if (s == "win")
		PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC); // Bat nhac khi thang
}

void NhapNhayQuanCo(_POINT _A[BOARD_SIZE][BOARD_SIZE], const short int toadothang[24], int pWhoWin)
{
	short int x, y;
	ShowCur(0);

	for (unsigned short int j = 1; j < 8; ++j)
	{
		for (int i = 0; i < 10; i += 2)
		{
			x = toadothang[i];
			y = toadothang[i + 1];

			int x2, y2;
			x2 = 4 * y + 2;
			y2 = 2 * x + 1;
			GotoXY(x2, y2);

			if (pWhoWin == -1)
			{
				cout << " ";
				Sleep(40);
				SetColor(2 + rand() % 14);
				GotoXY(x2, y2);
				cout << "X";
				cout << " ";
			}
			else if (pWhoWin == 1)
			{
				cout << " ";
				Sleep(40);
				SetColor(2 + rand() % 14);
				GotoXY(x2, y2);
				cout << "O";
				cout << " ";
			}
		}
	}
	Sleep(300);
	ShowCur(1);
	for (unsigned short int i = 0; i < 10; i += 2)
	{
		x = toadothang[i];
		y = toadothang[i + 1];

		int x2, y2;
		x2 = 4 * y + 2;
		y2 = 2 * x + 1;
		GotoXY(x2, y2);

		if (pWhoWin == -1)
		{
			SetColor(372);
			cout << " ";
			Sleep(40);

			GotoXY(x2, y2);
			cout << "X";
			cout << " ";
		}
		else if (pWhoWin == 1)
		{
			SetColor(372);
			cout << " ";
			Sleep(40);

			GotoXY(x2, y2);
			cout << "O";
			cout << " ";
		}
		ShowCur(1);
	}
	SetColor(7);
	Sleep(500);
}

