#include <iostream>
#include<Windows.h>
#include <ctime>

using namespace std;

int main() {

	int input_x;
	int input_y;
	int sethr;
	int setmin ;

	for (int i = 0; i < 10; ++i)
	{
		POINT p;
		if (GetCursorPos(&p))
		{
			cout <<"Poistion of X: " << p.x << endl;
			cout <<"Poistion of Y: " << p.y << endl;
			cout << "Please drop down the number!" << endl;
		}
		Sleep(300);
		system("cls");
	}

	Sleep(2000);
	cout << "Input the poistion of exit (X) : ";
	cin >> input_x;
	cout << "";
	cout << "Input the poistion of exit (Y) : ";
	cin >> input_y;

	cout << "";
	cout << "Input the Hour you want to set : ";
	cin >> sethr;
	cout << "";
	cout << "Input the Min you want to set : ";
	cin >> setmin;

	while(sethr < 1  | sethr > 24 | setmin < 1 | setmin > 60)
	{
		system("cls");
		cerr << "Set time Value Error" << endl;
		cout << "You have Seted: " << sethr << ":" << setmin << endl;
		cout << "Please Re Enter the value!" << endl;
		Sleep(1500);
		system("cls");
		cout << "";
		cout << "Input the Hour you want to set : ";
		cin >> sethr;
		cout << "";
		cout << "Input the Min you want to set : ";
		cin >> setmin;
	}

	Sleep(2000);

	while (true)
	{
		time_t now = time(0);
		tm* ltm = localtime(&now);


		if (ltm->tm_hour >= sethr && ltm->tm_min >= setmin)
		{
			cout << "Times up! Quit now!" << endl;;
			Sleep(500);
			cout << "Auto exiting in 1 second" << endl;;
			SetCursorPos(input_x, input_y);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			Sleep(1000);
			exit(1);
		}
		else
		{
			cout << "Status: Waiting" << endl;;
			cout << "Time Seted: " << sethr << ":" << setmin << endl;
			cout << "Now Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
			Sleep(300);
			system("cls");
		}

		Sleep(550);
	}

}