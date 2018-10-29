#include <windows.h>
//#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int y=0, x=0, z=0, i;
int stepcou=0, flashcou = 0, scorE=0;
short fooGy[23][41]; short fooGyC[23][41];
int fCurr=8;int fNext=5;

bool baLF=false,joBF=false,baL=false, joB=false,droP=false, gameover=false;

int score = 0;




void gotoxy(int x, int y) { 
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

#include "codec.h"


void printP(bool robot)
{char nyomo;
gotoxy(0,0);
for ( y=0 ; y<20 ; ++y ) 
  {for ( x=0 ; x<40 ; ++x )
{nyomo=fooGy [y][x];SetConsoleTextAttribute(hConsole, fooGyC[y][x]);cout <<nyomo;
    if  (x==39) cout <<"\n";
}
}
--flashcou;
SetConsoleTextAttribute(hConsole, rand()%15);
if (robot && flashcou>0){
gotoxy(3,21);

 cout  <<" ROBOT ";
}
else if(flashcou>0){
gotoxy(23,21);

 cout  <<" EMBER ";
}


}



#include "tetrisbinpack.h"			 


void keycsekk ()
{x=0; droP= false;
	do{
	int idoz=GetTickCount();int result=0;
	while ((idoz+75)>GetTickCount())
  {
           if(_kbhit()) result=_getch();
	}++x;
	if (result==118) {baL=true;joB=false;}
	if (result==98) {joB=true;baL=false;}
	if (result==110) {baLF=true;joBF=false;}
	if (result==109) {joBF=true;baLF=false;}
	if (result==32) {droP=true;break;}	
		
	}while(x<2 && !droP);  

}




void letol(int linec, short ij){
		short noi = 0; bool robi = true;
		if (ij>0) { noi = -150;} else {noi = 0; robi = false;}
		for (int x=1; x<11; ++x){
			fooGy[linec][x+ij]=0;}
			printP(robi); for (int i=0; i<3; ++i) {Beep(250+noi,50);Beep(375+noi,50);Beep(500+noi,50);}
	//	printP(robi);
     
		for (y=linec; y>2; --y ){
		for (int x=0; x<11; ++x){
		fooGy[y][x+ij]=fooGy[y-1][x+ij];fooGyC[y][x+ij]=fooGyC[y-1][x+ij];
	}
	}
}

void lineCou(short ik){
	for (y=18; y>3; --y ){ int fuLL=10;
		for (x=0; x<11; ++x){
		if (fooGy[y][x+ik]!=219) {--fuLL;};
	}
	if (fuLL==10) {letol(y,ik);}
	}

	

}


int main() {

   moCSE logic;
   Binpack robot;
logic.fMasol();
logic.palyastp();
printP(false);
Sleep(1000);
fCurr=3;
robot.reset();
robot.init(0);

do{ 
    robot.foY=0; logic.foY = 0; logic.foX = 24; 	robot.foX=5;
    robot.formKi(fNext, 5, 14);
    fNext=rand()%28;
	fooGy[3][14]='N';fooGy[3][15]='E';fooGy[3][16]='X';fooGy[3][17]='T';
    logic.formBe(fNext, 5, 14);
    flashcou =10;
robot.evalos();
lineCou(0); lineCou(0);  

    flashcou =5;
while (logic.foY<18){

	logic.formKi(fCurr, logic.foY, logic.foX);
	keycsekk();
	if (baLF) {logic.formbaLF();baLF=false;}
	if (joBF) {logic.formjoBF();joBF=false;}
	if (baL) { logic.formbaL();baL=false;}
	if (joB) {logic.formjoB();joB=false;}


//	if (logic.formLE() && droP && logic.foY%2==0 ) {logic.foY++; }

	score  = logic.foY;
	    logic.formBe(fCurr, logic.foY, logic.foX);
		printP(false); 
	logic.formKi(fCurr, logic.foY, logic.foX);
		logic.foY++; 
	if (!logic.formLE()){
		logic.foY--;
	    logic.formBe(fCurr, logic.foY, logic.foX);		
	Beep(750,50); break;}


}
if (gameover) break;
stepcou++;fCurr=fNext;

lineCou(20); lineCou(20); lineCou(20);

}while(stepcou<10);

 Beep(250,50);Beep(375,50);Beep(500,50);


cout << "      NEXT ROUND ?";
Sleep(5000);

	}
