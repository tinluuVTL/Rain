#include<stdio.h>
#include<Windows.h>
#include<windows.h>
#include"mmsystem.h"
#include<time.h>
#include<thread>
#include<chrono>
using std::this_thread::sleep_for;
using std::chrono::milliseconds;


void gotoxy(int x,int y){
	HANDLE  h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD g = {(short)x,(short)y};
	SetConsoleCursorPosition(h,g);
}
void resizeConsole(int width, int height){
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void textcolor(int x){
	HANDLE  h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,x);
}
class rain{
	int x;
	int y;
	public:
		rain();
		void fall();
		int getx();
		int gety();
};

rain::rain(){
	x = rand()%100 + 1;
	y = rand()%20 + 1;
}
int rain::getx(){
	return x;
}
int rain::gety(){
	return y;
}


void rain::fall(){
	if(y == 20){
		x = rand()%100 + 1;
		y = rand()%20 + 1;
	}
	else y++;
}

void intro(){

	gotoxy(11, 23);textcolor(13);printf("Send to my love <3");
	for(int i=3; i>0; i--){
		gotoxy(50, 12);
		printf("%d", i);
		Sleep(1000);
	}
	gotoxy(48, 12);
	printf("READY!");
	Sleep(1000);
	system("cls");
}
void print(int x, int y, int time, char *a){
	int n = strlen(a);
	int rem = time/n;
	gotoxy(x,y);textcolor(12);
	for(int i=0; i<strlen(a); i++){
		printf("%c", a[i]);
		sleep_for(milliseconds(rem));
	}
	Sleep(500);
}

int main(){
	int n = 100, time = 40, sl = 1;
	rain a[n];
	resizeConsole(1000,600);
	//doi bai hat ban muon vao day
	PlaySound(TEXT("nhinvaomua.wav"), NULL, SND_ASYNC);

	gotoxy(11, 23);textcolor(13);printf("Send to my love <3");
	while(sl < 989){
		sl++;
		for(int i=0; i<n; i++){
			gotoxy(a[i].getx(), a[i].gety());
			textcolor(3);printf("|");
		} 
		Sleep(time);
		for(int i=0; i<n; i++){
			gotoxy(a[i].getx(), a[i].gety());
			printf(" ");
			a[i].fall();
		}
	}
	//Thay loi ban muon viet vao day
	intro();

	gotoxy(11, 23);textcolor(13);printf("Send to my love <3");
	print(35, 6, 4000, "Minh chia tay nhau khi chua bat dau");
	print(35, 8, 4000, "Minh chia tay nhau cho voi don dau");
	print(31, 10, 6000, "Noi nho anh se giu lai vao noi con mua cat giau");
	print(35, 12, 4000, "Minh chia tay nhau khi chua bat dau");
	print(37, 14, 3000, "Tinh yeu co le la mot phep mau");
	print(32, 16, 6000, "Du co don dau long van muon yeu dam sau");
	Sleep(1000);
	sl = 1;
	//Thay loi ban muon viet vao day
	while(sl < 180){
		if(sl >= 50) goto tt;
		gotoxy(35, 6);textcolor(12);printf("Minh chia tay nhau khi chua bat dau");
		gotoxy(35, 8);textcolor(12);printf("Minh chia tay nhau cho voi don dau");
		gotoxy(31, 10);textcolor(12);printf("Noi nho anh se giu lai vao noi con mua cat giau");
		gotoxy(35, 12);textcolor(12);printf("Minh chia tay nhau khi chua bat dau");
		gotoxy(37, 14);textcolor(12);printf("Tinh yeu co le la mot phep mau");
		gotoxy(32, 16);textcolor(12);printf("Du co don dau long van muon yeu dam sau");
		tt:;
		sl++;
		for(int i=0; i<n; i++){
			gotoxy(a[i].getx(), a[i].gety());
			textcolor(3);printf("|");
		} 
		Sleep(time);
		for(int i=0; i<n; i++){
			gotoxy(a[i].getx(), a[i].gety());
			printf(" ");
			a[i].fall();
		}
	}//Thay loi ban muon viet vao day
	print(32, 9, 6000, "Du co don dau, long van muon yeu em dam sau...");
	Sleep(15000);
	return 0;
}

