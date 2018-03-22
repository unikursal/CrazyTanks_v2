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

		Sleep(50);
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

	while (true){
		gl.update();

		if (GetAsyncKeyState(VK_LEFT)){
			gl.moveTank(Direction::LEFT);
		}

		if (GetAsyncKeyState(VK_RIGHT)){
			gl.moveTank(Direction::RIGHT);
		}

		if (GetAsyncKeyState(VK_DOWN)){
			gl.moveTank(Direction::DOWN);
		}

		if (GetAsyncKeyState(VK_UP)){
			gl.moveTank(Direction::UP);
		}

		if (GetAsyncKeyState(VK_SPACE)){
			gl.shoot();
		}

		if (GetAsyncKeyState(VK_ESCAPE)){
			system("cls");
			break;
		}
	}

	std::cout << "Play again press TAB.\nExit press ESC.\n";

	while (true){
		if (GetAsyncKeyState(VK_ESCAPE)){
			return 0;
		}

		if (GetAsyncKeyState(VK_TAB)){
			goto m;
		}

		Sleep(50);
	}

	delete myStrategy;

	return 0;
}