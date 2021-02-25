#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
int p1,p2,p3,p4,p5,p6,x;
double score;
enum Direction{Stop=0,Up,Down};
bool gameOver;
Direction dir;
void setup(){
	gameOver=false;
	p1=8;
	p2=16;
	p3=24;
	p4=32;
	p5=40;
	p6=48;
	x=2;
	dir=Stop;
	score=0;
}
void Draw(){
	int i,j;
	cout<<"\n\n\n\n";
	for(i=0;i<=3;i++){
		cout<<"\t";
		for(j=1;j<=50;j++){
			if(i==x && j==1)
				cout<<"B";
			else if(i==2 && j==p1)
				cout<<(char)178;
			else if(i==2 && j==p2)
				cout<<(char)178;
			else if(i==2 && j==p3)
				cout<<(char)178;
			else if(i==2 && j==p4)
				cout<<(char)178;
			else if(i==2 && j==p5)
				cout<<(char)178;
			else if(i==2 && j==p6)
				cout<<(char)178;
			else if(i==3)
				cout<<"~";
			else
				cout<<" ";
		}
		cout<<endl;
	}
	if(p1>=1)
		p1=(p1-1)%50;
	else
		p1=50;
	if(p2>=1)
		p2=(p2-1)%50;
	else
		p2=50;
	if(p3>=1)
		p3=(p3-1)%50;
	else
		p3=50;
	if(p4>=1)
		p4=(p4-1)%50;
	else
		p4=50;
	if(p5>=1)
		p5=(p5-1)%50;
	else
		p5=50;
	if(p6>=1)
		p6=(p6-1)%50;
	else
		p6=50;
}
void Direction(){
	if(_kbhit()){
		switch(_getch()){
			case 'w':
				dir=Up;
				break;
		}
	}
}
void Logic(){
	switch(dir){
		case Up:
			if(x>0)
				x--;
			break;
		case Down:
			if(x<2)
				x++;
			break;
		default:
			break;
	}
	if((p1==1 || p2==1 || p3==1 || p4==1 || p5==1 || p6==1) && x==2)
		gameOver=true;
}
main(){
	cout<<"\n\n\tPlease wait while the game is loading....\n\n\t";
	for(int i=1;i<=40;i++){
		cout<<(char)178;
		Sleep(100);
	}
	cout<<"\n\n\tPress any key to continue....";
	getch();
	system("cls");
	setup();
	while(!gameOver){
		system("cls");
		Draw();
		Direction();
		Logic();
		if(x==0)
		dir=Down;
		cout<<"\n\n\tScore = "<<(int)score;
		score+=0.5;
		Sleep(100);
	}
	cout<<"\n\n\tYour game is over";
	getch();
	getch();
	getch();
}
