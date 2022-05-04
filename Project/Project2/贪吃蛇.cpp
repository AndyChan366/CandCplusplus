#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#define up 'w'
#define down 's'
#define left 'a'
#define right 'd'
#define stop 'p'
void welcome();               
void Finish();                
void creatgraph();            
void gotoxy(int x,int y);  
void gotoprint(int x,int y); 
void gotodelete(int x,int y);
void creatfood();             
int ClickControl();           
int Judge();                  
void MovingBody();            
void Eating();               
void ChangeBody(int a,int b); 
typedef struct Snakes{
	int x;
	int y;
	struct Snakes *next;
}snake;
snake *head,*tail;
struct Food{
	int x;
	int y;
}food;
char name[20];
int score=0;
char click=1;
int speed;
int main(){
	system("color 0C");
	welcome();
	creatgraph();
	creatfood();
	if (ClickControl()==0) return 0;
	return 0;
}
void welcome(){
	gotoxy(15,10);
	printf("/**********************************************/");
	gotoxy(15,20);
	printf("/**********************************************/");
	gotoxy(20,13);
	printf("请在英文输入法中操作，反向移动等同于吃到自己，wasd控制,p暂停");
	gotoxy(14,16);
	printf("游戏初始化为头部向上，所以请在开始时选择wad，否则会挂掉哦！");
	gotoxy(20,18);
	printf("PLEASE ENTER YOUR NAME:");
	scanf("%s",&name,10);
	system("cls");
}
void creatgraph(){
	int i;
	for(i=0;i<58;i=i+2){
		gotoprint(i,0);
		gotoprint(i,26);
	}
	for(i=1;i<26;i++){
		gotoprint(0,i);
		gotoprint(56,i);
	}
	gotoxy(63,10);
	printf("Hello %s,Welcome to play",name);
	gotoxy(63,15);
	printf("Your score is:%d",score);
	gotoxy(63,20);
	head=(snake*)malloc(sizeof(snake));
	head->x=16;
	head->y=15;
	tail=(snake*)malloc(sizeof(snake));
	snake *p=(snake*)malloc(sizeof(snake));
	snake *q=(snake*)malloc(sizeof(snake));
	p->x=16;
	p->y=16;
	q->x=16;
	q->y=17;
	head->next=p;
	p->next=q;
	q->next=tail;
	//gotoprint(p->x, p->y);
	//gotoprint(q->x, q->y);
	tail->next=NULL;
	tail->x=4;
	tail->y=2;
}
void gotoxy(int x,int y){
	COORD pos;
	HANDLE hOutput;
	pos.X=x;
	pos.Y=y;
	hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}
void gotoprint(int x,int y){
	gotoxy(x,y);
	printf("■");
}
/**********************************************************/
void gotodelete(int x,int y){
	gotoxy(x,y);
	printf("  ");
}
/**********************************************************/
void creatfood(){
	srand((int)time(NULL));
	lable:
	food.y=rand()%(25-1+1)+1;
	food.x=rand()%(54-2+1)+2;
	if(food.x%2!=0){
		food.x=food.x+1;
	}
	snake *judge=head;
	while(1){  //遍历排除蛇身重复
		if(judge->next==NULL) break;
		if(food.x==judge->x&&food.y==judge->y){
			goto lable;
		}
		judge=judge->next;
	}
	gotoxy(food.x,food.y);
	printf("⊙");
}
/**********************************************************/
int ClickControl(){
	char c;
	while(1){
		if(Judge()==0) return 0;
		if(_kbhit()){
			click=_getch();
		}
		MovingBody();
		Eating();
	}
	return 1;
}
/**********************************************************/
void MovingBody(){
	int count=0;
	int a=head->x,b=head->y;
	snake *p=head;
	while(1){
		if(p->next==NULL) break;
		gotodelete(p->x, p->y);
		count++;
		p=p->next;
	}
	switch(click){
		case up:
			head->y-=1;
			ChangeBody(a,b);
			break;
		case down:
			head->y+=1;
			ChangeBody(a,b);
			break;
		case left:
			head->x-=2;
			ChangeBody(a,b);
			break;
		case right:
			head->x+=2;
			ChangeBody(a,b);
			break;
		case stop:
			_getch();
			break;
	}
	p=head;
	while(1){
		if(p->next==NULL) break;
		gotoprint(p->x,p->y);
		p=p->next;
	}
	p=head;
	gotoxy(0,28);
	if(count<=5)speed=300;
	else if(count>5&&count<=10)speed=250;
	else if(count>10&&count<=20)speed=200;
	else speed=100;
	Sleep(speed);
}
/**********************************************************/
void Eating(){
	if(head->x==food.x&&head->y==food.y){
		creatfood();
		snake *_new=(snake*)malloc(sizeof(snake));
		snake *p;
		p=head;

		while(1){
			if(p->next->next==NULL) break;
			p=p->next;
	}
		p->next=_new;
		_new->next=tail;
		score+=10;
		gotoxy(77,15);
		printf("%d",score);
	}
}
/**********************************************************/
void ChangeBody(int a,int b){
	snake *p=head->next;
	int mid1,mid2,_mid1,_mid2;
	mid1=p->x;
	mid2=p->y;
	while(1){
		if(p->next->next==NULL) break;
		_mid1=p->next->x;
		_mid2=p->next->y;
		p->next->x=mid1;
		p->next->y=mid2;
		mid1=_mid1;
		mid2=_mid2; 
		p=p->next;
	}
	p=head->next;
	if (p->next!= NULL)
	{
		p->x=a;
		p->y=b;
	}
}
/**********************************************************/
int Judge(){
	if(head->x==0||head->x==56||head->y==0||head->y==26){
		Finish();
		return 0;
	}
	snake *p=head->next;
	while(1){
		if(p->next==NULL) break;
		if(head->x==p->x&&head->y==p->y){
			Finish();
			return 0;
		}
		p = p->next;
	}
	return 1;
}
/**********************************************************/
void Finish(){
	system("cls");
	gotoxy(15,10);
	printf("/**********************************************/");
	gotoxy(15,20);
	printf("/**********************************************/");
	gotoxy(18,14);
	printf("GAME OVER");
	gotoxy(20,16);
	printf("Your Score is %d",score);
	gotoxy(18,18);
	printf("继续努力!");
	gotoxy(0,27);
	system("pause");
}

