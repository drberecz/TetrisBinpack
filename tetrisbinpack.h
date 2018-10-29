const short CHRF=219;

class moCSE{
      
      private:
              int fProp;
              bool alloW;

      public:
      		  int xPos;
			  int foX;
			  int foY;
              bool formLE();
              bool formTest(int fProp);
              void formbaL();
              void formbaLF();
              void formjoB();
              void formjoBF();
	      void formBe (int formB, int BfoY, int BfoX);
	      void formKi (int formK, int KfoY, int KfoX);
	      void fMasol();
		void palyastp();
};


struct shapE {
	int colouR;int indeX;
	int dimY; int dimX;
	short layOut[4][4];  
	
}formA[28];



class Binpack: public moCSE{
      
      private:
            short foo[1000][8];
            int fooV[45][45];
			int mcou ;
			bool kapcs;
			int fCopy; 
			int fCopyN; 
			int foXA;
			int foYA; 
			int foXN;
			int foYN;   

      public:
			int init(short mozg);
			void reset ();
			void displ ();
			void lejatsz(short i, bool displ, bool next );
			void evalos ();
			void lineC (short v,short w);
};



void Binpack:: lineC(short v,short w){  
	fooV[v][w] = 0; 	int fuLL=10, gaP = 0, gapcou = 1;
	for (short y=18; y>3; --y ){
		fuLL=10, gaP = 0;   
		for (short x=1; x<11; ++x){
		if (fooGy[y][x]!=219) {--fuLL;};
	}
		for (short x2=2; x2<11; ++x2){
if (gapcou>=0 && fuLL<9 && fooGy[y][x2]==219 && fooGy[y][x2-1]!=219 ){++gaP;--gapcou;
}
}
	if (fuLL>9 && gapcou>0){ fuLL+=20*y; --gapcou; }
	fooV[v][w]+= fuLL*(y+25); 
	}
//		score = fooV[v][w];
}


void Binpack:: lejatsz(short i, bool displ, bool next ){

	if (next) {fCurr = fCopyN; }else fCurr = fCopy; 
		foX=5;  foY=0;
	for (short j=0; j<8; ++j){	
		formKi(fCurr, foY, foX);

	if (foo[i][j]==1) {formjoBF();}
	if (foo[i][j]==2) {formbaL();}
	if (foo[i][j]==3) {formjoB();}

//	formBe(fCurr, foY, foX);	printP(true);Sleep(10); 
	}
	for (short k=0; k<20; ++k){
		formKi(fCurr, foY, foX);
	foY++;
	if (!formLE()) foY--;
		formBe(fCurr, foY, foX);if (displ){		printP(true);Sleep(20);	}
		
		}	
	if (next) { foXN = foX; foYN = foY; fCopyN = fCurr; }	else{
	foXA = foX; foYA = foY; fCopy = fCurr;  }
}


void Binpack::	evalos(){
	
	fCopy = fCurr; fCopyN = fNext;
	
	for (short i=0; i<44; ++i){
		for (short n=0; n<44; ++n){		
		lejatsz(i, false, false);
		lejatsz(n, false, true);
	lineC(i,n); formKi(fCopy, foYA, foXA);formKi(fCopyN, foYN, foXN);
		}

	}
	int iprop = 0 ; int itemp = fooV[0][0];
	for (short i2=0; i2<43; ++i2){	
	for (short i3=1; i3<43; ++i3){
	if (fooV[i2][i3]>itemp){ itemp = fooV[i2][i3];  iprop= i2;}
	}
}
	lejatsz(iprop, true, false );
	
}

void Binpack::displ(){ 	cout << endl;
	for (int y=0; y<41; ++y){
	for (int x=0; x<8; ++x){
	cout << foo[y][x];
	}
	cout << endl;
	}
}

void Binpack::reset(){
	mcou = 0; kapcs = true; foo[0][0] = 0; 
	}

int Binpack::init(short mozg){
	xPos = 0;
	int j = 0;
	for (int i=0; i<4; ++i){

		for (j=0; j<i; ++j){
		foo[mcou][j] = 1;}
			
		for (j=0; j<mozg; ++j){
		if (kapcs){
			foo[mcou][j+4] = 2;
			}else {foo[mcou][j+4] = 3;}
		if (mcou>38) foo[mcou][j+4] =2;
		}
		
				
		++mcou;
	}
	++mozg;

	if (mozg>=5){ mozg = 0;
	if (kapcs){kapcs = false;}
	else if (!kapcs) {kapcs= true; }		
	}
	if (mcou<=40) {init(mozg);} else return mcou;
}




bool moCSE::formTest(int fProp){bool alloW=true;
	for (int y=0 ; y<4 ; ++y ) 
  {for (int x=0 ; x<4 ; ++x ){
	if (formA[fProp].layOut[y][x]==CHRF){if(fooGy[foY+y][foX+x]==CHRF) alloW=false;}
	}
	}
	return alloW;
}

 void moCSE::formbaLF(){
 	if(fCurr%4==0) fProp=fCurr+3;
 	else fProp=fCurr-1;
	if (formTest(fProp)) fCurr=fProp;
}

 void moCSE::formjoBF(){
 	if((fCurr+1)%4==0) fProp=fCurr-3;
 	else fProp=fCurr+1;
	if (formTest(fProp)) fCurr=fProp;
}
 	

 void moCSE::formbaL(){
 	fProp=fCurr;foX--;
	if (!formTest(fProp)) foX++;

}

 void moCSE::formjoB(){
 	fProp=fCurr;foX++;
	if (!formTest(fProp)) foX--;
}

 bool moCSE::formLE(){
 	fProp=fCurr;
    if(!formTest(fProp))return false;
 	return true;
 }





short forma[180][4]= {
			{  0,  3, 2,  15},
				  {219,  0,  0,  0},
				  {219,219,  0,  0},
				  {219,  0,  0,  0},
				  {  0,  0,  0,  0},
			
				  {  1,  2,  3,  15},
				  {219,219,219,  0},
				  {  0,219,  0,  0},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},
				  
				  {  2,  3,  2,  15},
				  {  0,219,  0,  0},
				  {219,219,  0,  0},
				  {  0,219,  0,  0},
				  {  0,  0,  0,  0},
				  
				  {  3,  2,  3,  15},
				  {  0,219,  0,  0},
				  {219,219,219,  0},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},
//l alak egyik
        {  4,  3, 2,  6},
				  {219,219,  0,  0},
				  {219,  0,  0,  0},
				  {219,  0,  0,  0},
				  {  0,  0,  0,  0},
			
				  {  5,  2,  3,  6},
				  {219,219,219,  0},
				  {  0,  0,219,  0},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},
				  
				  {  6,  3,  2,  6},
				  {  0,219,  0,  0},
				  {  0,219,  0,  0},
				  {219,219,  0,  0},
				  {  0,  0,  0,  0},
				  
				  {  7,  2,  3,  6},
				  {219,  0,  0,  0},
				  {219,219,219,  0},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},
//l alak masik
        {  8,  3, 2,  6},
				  {219,  0,  0,  0},
				  {219,  0,  0,  0},
				  {219,219,  0,  0},
				  {  0,  0,  0,  0},
			
				  {  9,  2,  3,  6},
				  {219,219,219,  0},
				  {219,  0,  0,  0},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},
				  
				  {  10,  3,  2,  6},
				  {219,219,  0,  0},
				  {  0,219,  0,  0},
				  {  0,219,  0,  0},
				  {  0,  0,  0,  0},
				  
				  {  11,  2,  3,  6},
				  {  0,  0,219,  0},
				  {219,219,219,  0},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},
// kocka#
		 {  12, 2,  2,  9},
				  {219,219,  0,  0},
				  {219,219,  0,  0},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},
				  
				  {  13, 2,  2,  9},
				  {219,219,  0,  0},
				  {219,219,  0,  0},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},

				  {  14, 2,  2,  9},
				  {219,219,  0,  0},
				  {219,219,  0,  0},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},

				  {  15, 2,  2,  9},
				  {219,219,  0,  0},
				  {219,219,  0,  0},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},


		 {  16, 2,  3,  13},
				  {219,219,  0,  0},
				  {  0,219,219,  0},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},
				  
				  {  17, 3,  2,  13},
				  {  0,219,  0,  0},
				  {219,219,  0,  0},
				  {219,  0,  0,  0},
				  {  0,  0,  0,  0},

				  {  18, 2,  3,  13},
				  {219,219,  0,  0},
				  {  0,219,219,  0},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},

				  {  19, 3,  2,  13},
				  {  0,219,  0,  0},
				  {219,219,  0,  0},
				  {219,  0,  0,  0},
				  {  0,  0,  0,  0},
				  
		 {  20, 2,  3,  13},
				  {  0,219,219,  0},
				  {219,219,  0,  0},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},
				  
				  {  21, 3,  2,  13},
				  {219,  0,  0,  0},
				  {219,219,  0,  0},
				  {  0,219,  0,  0},
				  {  0,  0,  0,  0},

				  {  22, 2,  3,  13},
				  {  0,219,219,  0},
				  {219,219,  0,  0},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},

				  {  23, 3,  2,  13},
				  {219,  0,  0,  0},
				  {219,219,  0,  0},
				  {  0,219,  0,  0},
				  {  0,  0,  0,  0},
// hosszu
		  {  24, 4,  1,  2},
				  {0,  219,  0,  0},
				  {0,  219,  0,  0},
				  {0,  219,  0,  0},
				  {0,  219,  0,  0},

		          {  25, 1,  4,  2},
				  {219,219,219,219},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},				  

		  		  {  26, 4,  1,  2},
				  {0,  0,  219,  0},
				  {0,  0,  219,  0},
				  {0,  0,  219,  0},
				  {0,  0,  219,  0},

		          {  27, 1,  4,  2},
				  {219,219,219,219},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0},
				  {  0,  0,  0,  0}				  


};




void moCSE::formBe (int formB, int BfoY, int BfoX){
	for (int y=0 ; y<4 ; ++y ) 
  {for (int x=0 ; x<4 ; ++x ){
	if (formA[formB].layOut[y][x]==CHRF){fooGy[BfoY+y][BfoX+x]=CHRF; fooGyC[BfoY+y][BfoX+x]=formA[formB].colouR;
	}
}
}
}

void moCSE::formKi (int formK, int KfoY, int KfoX){
	for (int y=0 ; y<4 ; ++y ) 
  {for (int x=0 ; x<4 ; ++x ){
	if (formA[formK].layOut[y][x]==CHRF){fooGy[KfoY+y][KfoX+x]=0; fooGyC[KfoY+y][KfoX+x]=8;
	}
}
}
}

void moCSE::fMasol(){int f=0;
	while (f<28){
		formA[f].indeX=forma[f*5][0];
		formA[f].colouR=forma[f*5][3];
		formA[f].dimY=forma[f*5][1];
		formA[f].dimX=forma[f*5][2];
	for ( int y=0; y<4; ++y){
		for (x=0; x<4; ++x){
		formA[f].layOut[y][x]=forma[f*5+1+y][x];
		}
	}
++f;
}
}

void moCSE::palyastp(){
	for (int y=0; y<21; ++y){
		fooGy[y][0]=CHRF;fooGy[y][11]=CHRF;fooGy[y][19]=178;	
		fooGy[y][20]=CHRF;fooGy[y][31]=CHRF;
	for (int x=0; x<32; ++x){
//		fooGy[19][x]=178;
//		if (x<=11)
 fooGy[19][x]=CHRF;
//		if (x>11)  fooGy[0][x]=178;
	    fooGyC[y][x]=8;
	}
}
}






