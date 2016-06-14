#include<stdio.h>


char board[9][9];

void swp(char *pta,char *ptb){
char temp=*ptb;
*ptb=*pta;*pta=temp;
return;
}

int abs(int i,int j){
	if(i-j>=0)return i-j;
	if(i-j<0)return j-i;
}

void chessboard()
{
	int i,j;
	for(i=0;i<9;++i){  board[0][i]=(char)(i+48);  board[i][0]=(char)(i+48);  }
	for(i=3;i<=6;++i){
		for(j=1;j<9;++j){
			board[i][j]='.';
		}
	}
	for(i=1;i<=8;++i){board[2][i]='N';}
	for(i=1;i<=8;++i){board[7][i]='n';}
	board[1][1]='R';   board[1][8]='R';
	board[1][2]='A';   board[1][7]='A';
	board[1][3]='B';   board[1][6]='B';
	board[1][4]='K';   board[1][5]='Q';
	board[8][1]='r';   board[8][8]='r';
	board[8][2]='a';   board[8][7]='a';
	board[8][3]='b';   board[8][6]='b';
	board[8][4]='k';   board[8][5]='q';

/*	printf("\n");
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			printf("\t%c",board[i][j]);
		}
		printf("\n\n\n");
	}*/
}

int movecheck(int i1,int j1,int i2,int j2){
	char l=board[i1][j1];
	if(l=='r' || l=='R'){
		if(i1==i2 || j1==j2){return 1;}
		else{return 0;}
	}
	if(l=='b' || l=='B'){
		if(abs(i1,i2) == abs(j1,j2)){return 1;}
		else{return 0;}
	}
	if(l=='k' || l=='K'){
		if((abs(i1,i2)==1) || (abs(j1,j2))==1){return 1;}
		else{return 0;}
	}
	if(l=='q' || l=='Q'){
		if(i1==i2 || j1==j2 || abs(i1,i2) == abs(j1,j2)){return 1;}
		else{return 0;}
	}
	if(l=='a' || l=='A'){
		int z=abs(i1,i2),x=abs(j1,j2);
		if(z==2 && x==1){return 1;}
		else if(z==1 && x==2){return 1;}
		else{return 0;}
	}
	if(l=='N'){
		int z=i2-i1,y=abs(j1,j2),flag=0;
		if(i1==2){
			if(z==1 && y==0){return 1;}
			else if(z==2 && y==0){return 1;}
			else if(z==1 && y==1 && board[i2][j2]!='.'){return 1;}
		}
		else if(i1>2){
			if(z==1 && y==0){return 1;}
			else if(z==1 && y==1 && board[i2][j2]!='.'){return 1;}
		}
		else {return 0;}
	}
	if(l=='n'){
		int z=i1-i2,y=abs(j1,j2),flag=0;
		if(i1==7){
			if(z==1 && y==0){return 1;}
			if(z==2 && y==0){return 1;}
			else if(z==1 && y==1 && board[i2][j2]!='.'){return 1;}
		}
		else if(i1<7){
			if(z==1 && y==0){return 1;}
			else if(z==1 && y==1 && board[i2][j2]!='.'){return 1;}
		}
		else {return 0;}
	}
}

int movecheck1(int i1,int j1,int i2,int j2)
{
	char l=board[i1][j1];

	if(l=='N'){
			if(board[i2][j2]=='.'){board[i2][j2]=l;board[i1][j1]='.';return 1;}
			else if(board[i2][j2]=='k' || board[i2][j2]=='r' || board[i2][j2]=='a' || board[i2][j2]=='b' || board[i2][j2]=='q' || board[i2][j2]=='n'){board[i2][j2]=board[i1][j1];board[i1][j1]='.'; return 1;}
			else{return 0;}
		}

	if(l=='n'){
			if(board[i2][j2]=='.'){board[i2][j2]=l;board[i1][j1]='.'; return 1;}
			else if(board[i2][j2]=='K' || board[i2][j2]=='R' || board[i2][j2]=='A' || board[i2][j2]=='B' || board[i2][j2]=='Q' || board[i2][j2]=='N'){board[i2][j2]=board[i1][j1];board[i1][j1]='.'; return 1;}
			else{return 0;}
		}

	if(l=='k'){
		if(board[i2][j2]=='.'){board[i2][j2]=l;board[i1][j1]='.'; return 1;}
		else if(board[i2][j2]=='K' || board[i2][j2]=='R' || board[i2][j2]=='A' || board[i2][j2]=='B' || board[i2][j2]=='Q' || board[i2][j2]=='N'){board[i2][j2]=board[i1][j1];board[i1][j1]='.'; return 1;}
		else{return 0;}
	}
	if(l=='K'){
		if(board[i2][j2]=='.'){board[i2][j2]=l;board[i1][j1]='.'; return 1;}
		else if(board[i2][j2]=='k' || board[i2][j2]=='r' || board[i2][j2]=='a' || board[i2][j2]=='b' || board[i2][j2]=='q' || board[i2][j2]=='n'){board[i2][j2]=board[i1][j1];board[i1][j1]='.'; return 1;}
		else{return 0;}
	}

	if(l=='r'){
		int i,flag=0;
		{if(i1==i2){
			if(j1<j2){for(i=j1+1;i<j2;++i){if(board[i1][i]!='.'){flag=1;break;}}}
			else if(j1>j2){for(i=j1-1;i>j2;--i){if(board[i1][i]!='.'){flag=1;break;}}}
		}
		else if(j1==j2){
			if(i1<i2){for(i=i1+1;i<i2;++i){if(board[i][j1]!='.'){flag=1;break;}}}
			else if(i1>i2){for(i=i1-1;i>i2;--i){if(board[i][j1]!='.'){flag=1;break;}}}
		}}
		if(flag==1){return 0;}
		else if(flag==0){
			if(board[i2][j2]=='.'){board[i2][j2]=l;board[i1][j1]='.'; return 1;}
			else if(board[i2][j2]=='K' || board[i2][j2]=='R' || board[i2][j2]=='A' || board[i2][j2]=='B' || board[i2][j2]=='Q' || board[i2][j2]=='N'){board[i2][j2]=board[i1][j1];board[i1][j1]='.'; return 1;}
			else{return 0;}
		}
	}
	if(l=='R'){
		int i,flag=0;
		{if(i1==i2){
			if(j1<j2){for(i=j1+1;i<j2;++i){if(board[i1][i]!='.'){flag=1;break;}}}
			else if(j1>j2){for(i=j1-1;i>j2;--i){if(board[i1][i]!='.'){flag=1;break;}}}
		}
		else if(j1==j2){
			if(i1<i2){for(i=i1+1;i<i2;++i){if(board[i][j1]!='.'){flag=1;break;}}}
			else if(i1>i2){for(i=i1-1;i>i2;--i){if(board[i][j1]!='.'){flag=1;break;}}}
		}}
		if(flag==1){return 0;}
		else if(flag==0){
			if(board[i2][j2]=='.'){board[i2][j2]=l;board[i1][j1]='.'; return 1;}
			else if(board[i2][j2]=='k' || board[i2][j2]=='r' || board[i2][j2]=='a' || board[i2][j2]=='b' || board[i2][j2]=='q' || board[i2][j2]=='n'){board[i2][j2]=board[i1][j1];board[i1][j1]='.'; return 1;}
			else{return 0;}
		}
	}

	if(l=='A'){
		if(board[i2][j2]=='.'){board[i2][j2]=l;board[i1][j1]='.'; return 1;}
		else if(board[i2][j2]=='k' || board[i2][j2]=='r' || board[i2][j2]=='a' || board[i2][j2]=='b' || board[i2][j2]=='q' || board[i2][j2]=='n'){board[i2][j2]=board[i1][j1];board[i1][j1]='.'; return 1;}
			else{return 0;}
	}
	if(l=='a'){
		if(board[i2][j2]=='.'){board[i2][j2]=l;board[i1][j1]='.'; return 1;}
			else if(board[i2][j2]=='K' || board[i2][j2]=='R' || board[i2][j2]=='A' || board[i2][j2]=='B' || board[i2][j2]=='Q' || board[i2][j2]=='N'){board[i2][j2]=board[i1][j1];board[i1][j1]='.'; return 1;}
			else{return 0;}
	}

	if(l=='b'){
		int i=i1,j=j1,flag=0;
		{if(i1>i2 && j1>j2){i=i1-1;j=j1-1;while(i>i2){if(board[i][j]!='.'){flag=1;break;} --i;--j;}}
		if(i1>i2 && j1<j2){i=i1-1;j=j1+1;while(i>i2){if(board[i][j]!='.'){flag=1;break;} --i;++j;}}
		if(i1<i2 && j1>j2){i=i1+1;j=j1-1;while(i<i2){if(board[i][j]!='.'){flag=1;break;} ++i;--j;}}
		if(i1<i2 && j1<j2){i=i1+1;j=j1+1;while(i<i2){if(board[i][j]!='.'){flag=1;break;} ++i;++j;}}}
		if(flag==1){return 0;}
		else{
			if(board[i2][j2]=='.'){board[i2][j2]=l;board[i1][j1]='.'; return 1;}
			else if(board[i2][j2]=='K' || board[i2][j2]=='R' || board[i2][j2]=='A' || board[i2][j2]=='B' || board[i2][j2]=='Q' || board[i2][j2]=='N'){board[i2][j2]=board[i1][j1];board[i1][j1]='.'; return 1;}
			else{return 0;}
		}
	}
		if(l=='B'){
		int i=i1,j=j1,flag=0;
		{if(i1>i2 && j1>j2){i=i1-1;j=j1-1;while(i>i2){if(board[i][j]!='.'){flag=1;break;} --i;--j;}}
		if(i1>i2 && j1<j2){i=i1-1;j=j1+1;while(i>i2){if(board[i][j]!='.'){flag=1;break;} --i;++j;}}
		if(i1<i2 && j1>j2){i=i1+1;j=j1-1;while(i<i2){if(board[i][j]!='.'){flag=1;break;} ++i;--j;}}
		if(i1<i2 && j1<j2){i=i1+1;j=j1+1;while(i<i2){if(board[i][j]!='.'){flag=1;break;} ++i;++j;}}}
		if(flag==1){return 0;}
		else{
			if(board[i2][j2]=='.'){board[i2][j2]=l;board[i1][j1]='.'; return 1;}
		else if(board[i2][j2]=='k' || board[i2][j2]=='r' || board[i2][j2]=='a' || board[i2][j2]=='b' || board[i2][j2]=='q' || board[i2][j2]=='n'){board[i2][j2]=board[i1][j1];board[i1][j1]='.'; return 1;}
			else{return 0;}
		}
		}
	if(l=='q'){
		int i=i1,j=j1,flag=0;
		{if(i1==i2){
			if(j1<j2){for(i=j1+1;i<j2;++i){if(board[i1][i]!='.'){flag=1;break;}}}
			if(j1>j2){for(i=j1-1;i>j2;--i){if(board[i1][i]!='.'){flag=1;break;}}}
		}
		if(j1==j2){
			if(i1<i2){for(i=i1+1;i<i2;++i){if(board[i][j1]!='.'){flag=1;break;}}}
			if(i1>i2){for(i=i1-1;i>i2;--i){if(board[i][j1]!='.'){flag=1;break;}}}
		}
		if(i1>i2 && j1>j2){i=i1-1;j=j1-1;while(i>i2){if(board[i][j]!='.'){flag=1;break;} --i;--j;}}
		if(i1>i2 && j1<j2){i=i1-1;j=j1+1;while(i>i2){if(board[i][j]!='.'){flag=1;break;} --i;++j;}}
		if(i1<i2 && j1>j2){i=i1+1;j=j1-1;while(i<i2){if(board[i][j]!='.'){flag=1;break;} ++i;--j;}}
		if(i1<i2 && j1<j2){i=i1+1;j=j1+1;while(i<i2){if(board[i][j]!='.'){flag=1;break;} ++i;++j;}}}
		if(flag==1){return 0;}
		else{
			if(board[i2][j2]=='.'){board[i2][j2]=l;board[i1][j1]='.'; return 1;}
			else if(board[i2][j2]=='K' || board[i2][j2]=='R' || board[i2][j2]=='A' || board[i2][j2]=='B' || board[i2][j2]=='Q' || board[i2][j2]=='N'){board[i2][j2]=board[i1][j1];board[i1][j1]='.'; return 1;}
			else{return 0;}
		}
	if(l=='Q'){
		int i=i1,j=j1,flag=0;
		{if(i1==i2){
			if(j1<j2){for(i=j1+1;i<j2;++i){if(board[i1][i]!='.'){flag=1;break;}}}
			if(j1>j2){for(i=j1-1;i>j2;--i){if(board[i1][i]!='.'){flag=1;break;}}}
		}
		if(j1==j2){
			if(i1<i2){for(i=i1+1;i<i2;++i){if(board[i][j1]!='.'){flag=1;break;}}}
			if(i1>i2){for(i=i1-1;i>i2;--i){if(board[i][j1]!='.'){flag=1;break;}}}
		}
		if(i1>i2 && j1>j2){i=i1-1;j=j1-1;while(i>i2){if(board[i][j]!='.'){flag=1;break;} --i;--j;}}
		if(i1>i2 && j1<j2){i=i1-1;j=j1+1;while(i>i2){if(board[i][j]!='.'){flag=1;break;} --i;++j;}}
		if(i1<i2 && j1>j2){i=i1+1;j=j1-1;while(i<i2){if(board[i][j]!='.'){flag=1;break;} ++i;--j;}}
		if(i1<i2 && j1<j2){i=i1+1;j=j1+1;while(i<i2){if(board[i][j]!='.'){flag=1;break;} ++i;++j;}}}
		if(flag==1){return 0;}
		else{
			if(board[i2][j2]=='.'){board[i2][j2]=l;board[i1][j1]='.'; return 1;}
		else if(board[i2][j2]=='k' || board[i2][j2]=='r' || board[i2][j2]=='a' || board[i2][j2]=='b' || board[i2][j2]=='q' || board[i2][j2]=='n'){board[i2][j2]=board[i1][j1];board[i1][j1]='.'; return 1;}
			else{return 0;}
		}
	}
}
}
void printboard(){
	int i,j;
	printf("\n");
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			printf("\t%c",board[i][j]);
		}
		printf("\n\n\n");
	}
}

bool check(int n)
{
    if(n==1)
    {

    }
}

void play(){
	chessboard();
	printboard();
	int i1,i2,j1,j2,i,j,flag,king=1,KING=1;
	while(king==1 && KING==1){
	flag=0;
	while(flag!=1){
		printf("Move:Player1:");//player1 owns pieces represented with small letters
		scanf("%d,%d,%d,%d",&i1,&j1,&i2,&j2);
		if(board[i1][j1]=='n' || board[i1][j1]=='r' || board[i1][j1]=='a' || board[i1][j1]=='b' || board[i1][j1]=='k' || board[i1][j1]=='q'){

			if(movecheck(i1,j1,i2,j2)==0){printf("move not valid\n");}
			else {printf("%d\n",flag);
				if(movecheck1(i1,j1,i2,j2)==0){printf("Move not valid\n");}
				else {printboard();flag=1;}
			}
		}
		else printf("move Not valid");
	}
	KING=0;
	for(i=1;i<9;++i){
		for(j=1;j<9;++j){
			if(board[i][j]=='K'){KING=1;}
		}
		if(KING==1){break;}
	}
	if(KING==0){printf("PLAYER1 WON\n");return;}
	flag=0;
	while(flag!=1){
		printf("Move:Player2:");
		scanf("%d,%d,%d,%d",&i1,&j1,&i2,&j2);
		if(board[i1][j1]=='N' || board[i1][j1]=='R' || board[i1][j1]=='A' || board[i1][j1]=='B' || board[i1][j1]=='K' || board[i1][j1]=='Q'){
			if(movecheck(i1,j1,i2,j2)==0){printf("move not valid\n");}
			else {
				if(movecheck1(i1,j1,i2,j2)==0){printf("Move not valid\n");}
				else {printboard();flag=1;}
			}
		}
		else printf("move Not valid\n");
	}
	king=0;
	for(i=1;i<9;++i){
		for(j=1;j<9;++j){
			if(board[i][j]=='k'){king=1;}
		}
		if(king==1){break;}
	}
	if(king==0){printf("PLAYER2 WON\n");return;}
}
}


main(){
	play();
}
