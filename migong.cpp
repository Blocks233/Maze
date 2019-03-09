#include<cstdio>
#include<fstream>
#include<string>
#include<iostream>
#include<windows.h>
#include<conio.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define maxn 10000

struct Player{
	int mid_x,mid_y;
	int start_x,start_y;
	int end_x,end_y;
	int fx;
}Player;
int data[maxn][maxn],size,win,err; 
using namespace std;
string FileName;


int main(){
	printf("欢迎使用 走迷宫\n");
	printf("请输入文件名(样例文件为in.txt)\n");
	scanf("%s",FileName.c_str());
	ifstream Input;
	Input.open(FileName.c_str());
	Input>>size>>Player.start_x>>Player.start_y>>Player.end_x>>Player.end_y;
	for(int i=0;i<size;i++) 
		for(int j=0;j<size;j++)	Input>>data[i][j];
	Input.close();
	
	if(data[Player.start_x][Player.start_y]) err=101;
	if(data[Player.end_x][Player.end_y]) err=102;
	if(Player.start_x==Player.end_x&&Player.start_y==Player.end_y) err=103;
	
	if(err){
		printf("ECC数据文件校验\n",err);
		printf("数据文件出错，错误码%d\n",err);
		switch(err){
			case 101 : 
				printf("错误原因:开始位置非法\n");
				break;
			case 102 : 
				printf("错误原因:结束位置非法\n");
				break;
			case 103 : 
				printf("错误原因:开始位置与结束位置重复\n");
				break;
			default : 
				printf("错误原因:未知错误\n");
				break;
		}
		system("pause");
		exit(0);
	}
	
	Player.mid_x=Player.start_x;
	Player.mid_y=Player.start_y;
	
	while(!win) {
		system("color 7");
		system("cls"); 
		for(int i=0;i<size;i++) {
			for(int j=0;j<size;j++){
				if(i==Player.mid_x&&j==Player.mid_y){
					printf("O ");continue;
				}
				else if(i==Player.end_x&&j==Player.end_y){
					printf("* ");continue;
				}
				if(data[i][j]==1)printf("■");
				else printf("  ");
			}
			printf("\n");
		}
		printf("输入方向 上箭头=上;右箭头=右;下箭头=下;左箭头=左:\n");
		Player.fx=0;
		Sleep(100);
		while(!Player.fx){
			if(KEY_DOWN(VK_UP)) Player.fx=1;
			else if(KEY_DOWN(VK_RIGHT)) Player.fx=2;
			else if(KEY_DOWN(VK_DOWN)) Player.fx=3;
			else if(KEY_DOWN(VK_LEFT)) Player.fx=4;
			else Player.fx=0;
		}
		if(Player.fx==1) {
			if(data[Player.mid_x-1][Player.mid_y]==1) {printf("方向非法!\n");system("color 4");system("pause");}
			else if(Player.mid_x-1<0||Player.mid_y<0) {printf("方向越界!\n");system("color 4");system("pause");}
			else Player.mid_x--;
		}
		if(Player.fx==2) {
			if(data[Player.mid_x][Player.mid_y+1]==1) {printf("方向非法!\n");system("color 4");system("pause");}
			else if(Player.mid_x>=size||Player.mid_y+1>=size) {printf("方向越界!\n");system("color 4");system("pause");}
			else Player.mid_y++;
		}
		if(Player.fx==3) {
			if(data[Player.mid_x+1][Player.mid_y]==1) {printf("方向非法!\n");system("color 4");system("pause");}
			else if(Player.mid_x+1>=size||Player.mid_y>=size) {printf("方向越界!\n");system("color 4");system("pause");}
			else Player.mid_x++;
		}
		if(Player.fx==4) {
			if(data[Player.mid_x][Player.mid_y-1]==1) {printf("方向非法!\n");system("color 4");system("pause");}
			else if(Player.mid_x<0||Player.mid_y-1<0) {printf("方向越界!\n");system("color 4");system("pause");}
			else Player.mid_y--;
		}
		if(Player.mid_x==Player.end_x&&Player.mid_y==Player.end_y) win=true;
	}
	system("cls");
	HWND hwnd=GetForegroundWindow();
	ShowWindow(hwnd,SW_MAXIMIZE);
printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　　　■■■■　　　　■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　　　■■■■　　　　■■■■　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　■■■　　　　　　　　　■■　　　　　　　　　　　■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　　　■■■■　　　■■■■■　　　　　　　　　　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　\n");
printf("　　　　　　　■■■■　　　　■■■■　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　\n");
printf("　　　　　　　■■■■　　　　■■■■　　　　　　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　\n");
printf("　　　　　　■■■■　　　　■■■■■■■■■■■■■■■■■　　　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■　　　　　　　\n");
printf("　　　　　　■■■■　　　　■■■■■■■■■■■■■■■■■　　　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■　　　　　　　　　\n");
printf("　　　　　■■■■　　　　■■■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■　　　　　　　　　　　\n");
printf("　　　　■■■■■　　　　■■■■　　　　　　　　　■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■　　　　　　　　　　　　\n");
printf("　　　　■■■■■　　　■■■■　　　■■■■　　　■■■■　　　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■　　　　　　　　　　　　　\n");
printf("　　　■■■■■■　　■■■■■　　　■■■■　　■■■■　　　　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■■■■　　　　　　　　　　　　　　　\n");
printf("　　■■■■■■■　■■■■■　　　　■■■■　　■■■■　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　　　　　　　■■■■■　　　　　　　　　　　　　　　　\n");
printf("　　■■■■■■■　■■■■　　　　　■■■■　　　　　　　　　　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■■　　　　　　　　　　　　　　　　　\n");
printf("　　　■■　■■■　　　　■　　　　　■■■■　　　　　　　　　　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■■　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　■■■　　　　　　■■　　■■■■　　■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　■■■　　　　　　■■■■■■■■　■■■■　　　　　　　　　　　　■■■■■■■■■■■■■■■■■　■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　■■■　　　　　■■■■■■■■■　■■■■　　　　　　　　　　　　■■■■■■■■■■■■■■■■■　■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　■■■　　　　　■■■■　■■■■　　■■■■　　　　　　　　　　　■■■　　■■■■■■　　　　■■　■■　　　■■■　　　　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　■■■　　　　■■■■　　■■■■　　■■■■■　　　　　　　　　　■■■　　■■■　■■■■■　■■　■■　■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　■■■　　　■■■■■　　■■■■　　　■■■■　　　　　　　　　　■■■■■■■■　■■■■■■■■　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　■■■　　■■■■■　　　■■■■　　　　■■■■　　　　　　　　　■■■■■■■■　■■■■■　■■　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　■■■　■■■■■　　　　■■■■　　　　■■■■■　　　　　　　　■■■　　■■■■■■■■■　■■　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　■■■　■■■■　　　　　■■■■　　　　　■■■■　　　　　　　　■■■■■■■■■■■■■■　■■　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　■■■　　■■■　　　　　■■■■　　　　　■■　　　　　　　　　■■■■■■■■■■■■■■■　■■　■■　■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　■■■　　　　　　　　　　■■■■　　　　　　　　　　　　　　　　■■■　　　■■■　　　■■■■■　■■■　■　■■　■　　　　　　　　　　　　　　　　　　　　■■■■　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　■■■■　　　　　　　　　■■■■　　　　　　　　　　　　　　　　■■■　　■■■■　　■■■■■■■■■■　　　■■■■■　　　　　　　　　　　　　　　■■■■■■■■　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　■■■■　　　　　■■■■■■■■　　　　　　　　　　　　　　　　■■■　■■■■■　■■■■　■■■■■■　　　■■■■■　　　　　　　　　　　　　　　■■■■■■■■　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　■■■■　　　　　　■■■■■■　　　　　　　　　　　　　　　　■■■■　■■■■　■■■■　　■■■■■　　　　■■■■■　　　　　　　　　　　　　　　■■■■■■■■　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　■■■■　　　　　　■■■■■　　　　　　　　　　　　　　　　　■■■■　■■■■　　■■　　　　　■■■　　　　　■■■　　　　　　　　　　　　　　　　　■■■■■■　　　　　　　　　　　　　　　　　　\n");
printf("　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　　　　　　　　　　　\n");
printf("\n");
	while(1){
		system("color 4F");
		Sleep(1000);
		system("color 20");
		Sleep(1000);
	}
}
