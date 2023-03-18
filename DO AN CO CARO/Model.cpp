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

int TestBoard(_POINT _A[][BOARD_SIZE], bool _TURN, int cRow, int cCol)
{
	if (CheckTie(_A)) return 0; //Hoa
	else
	{
		if (CheckWin(_A, cRow, cCol))
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

bool HorizontalCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol)
{
	int countWin = 1;
	bool blockRight = false;
	bool blockLeft = false;
	bool wall = false;
	int count = 1;
	bool keepCounting = true;

	if (currentCol == 0 || currentCol == BOARD_SIZE - 1) wall = true;

	while (currentCol + count < BOARD_SIZE)
	{
		if ((_A[currentRow][currentCol + count].c != 0) && (_A[currentRow][currentCol + count].c != _A[currentRow][currentCol].c))
		{
			blockRight = true;
			break;
		}
		else if ((_A[currentRow][currentCol + count].c == _A[currentRow][currentCol].c) && keepCounting)
		{
			if (currentCol + count == BOARD_SIZE - 1) wall = true;
			countWin++;
			count++;
		}
		else
		{
			count++;
			keepCounting = false;
		}
	}

	count = 1;
	keepCounting = true;

	while (currentCol - count > -1)
	{
		if ((_A[currentRow][currentCol - count].c != 0) && (_A[currentRow][currentCol - count].c != _A[currentRow][currentCol].c))
		{
			blockLeft = true;
			break;
		}
		else if ((_A[currentRow][currentCol - count].c == _A[currentRow][currentCol].c) && keepCounting)
		{
			if (currentCol - count == 0) wall = true;
			countWin++;
			count++;
		}
		else
		{
			count++;
			keepCounting = false;
		}
	}

	if (!blockLeft && !blockRight && !wall && (countWin == 4))
		return true;
	else if (countWin >= 5 && !(blockRight && blockLeft))
		return true;
	else
		return false;
}

bool VerticalCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol)
{
	int countWin = 1;
	bool blockUp = false;
	bool blockDown = false;
	bool wall = false;
	int count = 1;
	bool keepCounting = true;

	if (currentRow == 0 || currentRow == BOARD_SIZE - 1) wall = true;

	while (currentRow + count < BOARD_SIZE)
	{
		if ((_A[currentRow + count][currentCol].c != 0) && (_A[currentRow + count][currentCol].c != _A[currentRow][currentCol].c))
		{
			blockDown = true;
			break;
		}
		else if ((_A[currentRow + count][currentCol].c == _A[currentRow][currentCol].c) && keepCounting)
		{
			if (currentRow + count == BOARD_SIZE - 1) wall = true;
			countWin++;
			count++;
		}
		else
		{
			count++;
			keepCounting = false;
		}
	}

	count = 1;
	keepCounting = true;

	while (currentRow - count > -1)
	{
		if ((_A[currentRow - count][currentCol].c != 0) && (_A[currentRow - count][currentCol].c != _A[currentRow][currentCol].c))
		{
			blockUp = true;
			break;
		}
		else if ((_A[currentRow - count][currentCol].c == _A[currentRow][currentCol].c) && keepCounting)
		{
			if (currentRow - count == 0) wall = true;
			countWin++;
			count++;
		}
		else
		{
			count++;
			keepCounting = false;
		}
	}

	if (!blockUp && !blockDown && !wall && (countWin == 4))
		return true;
	else if (countWin >= 5 && !(blockUp && blockDown))
		return true;
	else
		return false;
}

bool ForwardSlashCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol)
{
	int countWin = 1;
	bool blockUp = false;
	bool blockDown = false;
	bool wall = false;
	int count = 1;
	bool keepCounting = true;

	if (currentCol == 0 || currentCol == BOARD_SIZE - 1 || currentRow == 0 || currentRow == BOARD_SIZE - 1) wall = true;

	while (currentRow + count < BOARD_SIZE && currentCol - count > -1)
	{
		if ((_A[currentRow + count][currentCol - count].c != 0) && (_A[currentRow + count][currentCol - count].c != _A[currentRow][currentCol].c))
		{
			blockDown = true;
			break;
		}
		else if ((_A[currentRow + count][currentCol - count].c == _A[currentRow][currentCol].c) && keepCounting)
		{
			if (currentRow + count == BOARD_SIZE - 1 || currentCol - count == 0) wall = true;
			countWin++;
			count++;
		}
		else
		{
			count++;
			keepCounting = false;
		}
	}

	count = 1;
	keepCounting = true;

	while (currentRow - count > -1 && currentCol + count < BOARD_SIZE)
	{
		if ((_A[currentRow - count][currentCol + count].c != 0) && (_A[currentRow - count][currentCol + count].c != _A[currentRow][currentCol].c))
		{
			blockUp = true;
			break;
		}
		else if ((_A[currentRow - count][currentCol + count].c == _A[currentRow][currentCol].c) && keepCounting)
		{
			if (currentCol + count == BOARD_SIZE - 1 || currentRow - count == 0) wall = true;
			countWin++;
			count++;
		}
		else
		{
			count++;
			keepCounting = false;
		}
	}

	if (!blockUp && !blockDown && !wall && (countWin == 4))
		return true;
	else if (countWin >= 5 && !(blockUp && blockDown))
		return true;
	else
		return false;
}

bool BackwardSlashCheck(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol)
{
	int countWin = 1;
	bool blockUp = false;
	bool blockDown = false;
	bool wall = false;
	int count = 1;
	bool keepCounting = true;

	if (currentCol == 0 || currentCol == BOARD_SIZE - 1 || currentRow == 0 || currentRow == BOARD_SIZE - 1) wall = true;

	while (currentRow + count < BOARD_SIZE && currentCol + count < BOARD_SIZE)
	{
		if ((_A[currentRow + count][currentCol + count].c != 0) && (_A[currentRow + count][currentCol + count].c != _A[currentRow][currentCol].c))
		{
			blockDown = true;
			break;
		}
		else if ((_A[currentRow + count][currentCol + count].c == _A[currentRow][currentCol].c) && keepCounting)
		{
			if (currentRow + count == BOARD_SIZE - 1 || currentCol + count == BOARD_SIZE - 1) wall = true;
			countWin++;
			count++;
		}
		else
		{
			count++;
			keepCounting = false;
		}
	}

	count = 1;
	keepCounting = true;

	while (currentRow - count > -1 && currentCol - count > -1)
	{
		if ((_A[currentRow - count][currentCol - count].c != 0) && (_A[currentRow - count][currentCol - count].c != _A[currentRow][currentCol].c))
		{
			blockUp = true;
			break;
		}
		else if ((_A[currentRow - count][currentCol - count].c == _A[currentRow][currentCol].c) && keepCounting)
		{
			if (currentRow - count == 0 || currentCol - count == 0) wall = true;
			countWin++;
			count++;
		}
		else
		{
			count++;
			keepCounting = false;
		}
	}

	if (!blockUp && !blockDown && !wall && (countWin == 4))
		return true;
	else if (countWin >= 5 && !(blockUp && blockDown))
		return true;
	else
		return false;
}

bool CheckWin(_POINT _A[][BOARD_SIZE], int currentRow, int currentCol)
{
	if (HorizontalCheck(_A, currentRow, currentCol) || VerticalCheck(_A, currentRow, currentCol) || BackwardSlashCheck(_A, currentRow, currentCol) || ForwardSlashCheck(_A, currentRow, currentCol))
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

void PlayBackGroundMusic()
{
	PlaySound(TEXT("nhacnen.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC); // Bat nhac nen 

}

void StopMusic()
{
	PlaySound(0, 0, 0); // Tat nhac

}

void PlaySoundEffect(string s)
{
	if (s == "move")
		PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC); // Dung de bat nhac khi di
	else if (s == "win")
		PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC); // Bat nhac khi thang
}

