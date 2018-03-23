#include<Windows.h>
#include<iostream>

#include "GameLogic.h"
#include "Screen.h"
#include "Util.h"
#include "MyStrategy.h"


int main(int argc, char* argv[])
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 650, TRUE);

	std::cout << "Game CrazyTanks\nPlay press TAB.\nExit press ESC";

	MyStrategy* myStrategy = new MyStrategy();
	GameLogic gl = GameLogic(myStrategy);

	while (true){
		if (GetAsyncKeyState(VK_ESCAPE)){
			return 0;
		}

		if (GetAsyncKeyState(VK_TAB)){
			break;
		}

		Sleep(100);
	}

m:;
	system("cls");
	gl.start();

	{
		GetAsyncKeyState(VK_LEFT);
		GetAsyncKeyState(VK_UP);
		GetAsyncKeyState(VK_RIGHT);
		GetAsyncKeyState(VK_DOWN);
	}

	int res;

	while (true){
		res = gl.update();
		if (res == LOSE){
			system("cls");
			std::cout << "You lose\n";
			std::cin.get();
			break;
		}
		if (res == WIN){
			system("cls");
			std::cout << "You win\n";
			std::cin.get();
			break;
		}

		if (GetAsyncKeyState(VK_LEFT)){
			gl.moveUserTank(Direction::LEFT);
		}

		if (GetAsyncKeyState(VK_RIGHT)){
			gl.moveUserTank(Direction::RIGHT);
		}

		if (GetAsyncKeyState(VK_DOWN)){
			gl.moveUserTank(Direction::DOWN);
		}

		if (GetAsyncKeyState(VK_UP)){
			gl.moveUserTank(Direction::UP);
		}

		if (GetAsyncKeyState(VK_SPACE)){
			gl.shoot();
		}

		if (GetAsyncKeyState(VK_ESCAPE)){
			system("cls");
			break;
		}

		Sleep(50);
	}

	gl.finish();

	std::cout << "Play again press TAB.\nExit press ESC.\n";

	{
		GetAsyncKeyState(VK_ESCAPE);
		GetAsyncKeyState(VK_TAB);
	}

	while (true){
		if (GetAsyncKeyState(VK_ESCAPE)){
			return 0;
		}

		if (GetAsyncKeyState(VK_TAB)){
			goto m;
		}

		Sleep(100);
	}

	delete myStrategy;

	return 0;
}