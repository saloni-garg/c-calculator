#include"graphics.h"
#include"dos.h"
#include"stdio.h"
#include"math.h"
union REGS i,o;
char text[35][25]={
"7","8","9","*","4","5","6","/","1","2","3","+","0","00",".","-","M","M+",
"M-","+/-","MR","MC","x^2","sr","OFF","AC","CE","="};

int s=0,k=0,pass,op,prop,newnum=1,bt,memo=1,d=0,sq;
long double num=0,accum,m;
void normalbutton(int,int,int,int,char *);
void main()
{
int gd=DETECT,gm,x1,x2,y1,y2,i,j,maxx,maxy,x,y,button;
initgraph(&gd,&gm,"");
if(initmouse()==0)
 {
  closegraph();
  restorecrtmode();
  printf(" Mouse driver not loded");
  exit(1);
}
setcolor(2);
gotoxy(20,10);
printf("WELCOME TO ISTE
");
gotoxy(20,14);
printf("press any key to continue.......
");
getch();
cleardevice();
showmouseptr();
movemouseptr(&x,&y);
setcolor(15);
rectangle(198,140,417,163);
rectangle(199,141,418,164);
rectangle(197,139,416,162);
rectangle(185,130,430,450);
rectangle(184,129,431,451);
rectangle(182,127,433,454);
rectangle(181,126,434,453);
setfillstyle(SOLID_FILL,3);
//bar(200,142,415,161);
outtextxy(50,25,"A Calculator project in C presented by B.NARAYANA 
MOORTHY
AND  R.KARTHIK KEYAN");
outtextxy(200,100,"Press OFF button to exit....");
y1=140;
y2=160;
for(j=0;j<7;j++)
 {
  x1=200;
  x2=235;
  y1+=40;
  y2+=40;
for(i=0;i<4;i++)
{
   normalbutton(x1,x2,y1,y2,text[s]);
   s++;
   x1+=60;
   x2+=60;
   }
}
while(1)
{
getmousepos(&button,&x,&y);
y1=140;
y2=160;
for(j=0;j<7;j++)
 {
  x1=200;
  x2=235;
  y1+=40;
  y2+=40;
  for(i=0;i<4;i++)
  {
	if((x<x2&&x>x1)&&(y<y2&&y>y1))
	{
	if((button&1)==1)
	 {
	 gotoxy(28,10);
	bt=j*4+i;
	setcolor(11);
	outtextxy(x1+12,y1+7,text[j*4+i]);
	if(num>pow(10.0,18))
	exit();
	delay(10);
	delay(250);
	delay(10);
	switch (bt)
	{
	case  8 :
		addnum(1);
		break;
	case  9 :
		addnum(2);
		break;
	case  10 :
		addnum(3);
		break;
	case  4 :
		addnum(4);
		break;
	case  5 :
		addnum(5);
		break;
	case  6 :
		addnum(6);
		break;
	case  0 :
		addnum(7);
		break;
	case  1 :
		addnum(8);
		break;
	case  2 :
		addnum(9);
		break;
	case  12 :
		addnum(0);
		break;
	case  11 :
		operation(1);   // plus
		break;
	case  15 :
		operation(2);    // minus
		break;
	case  3 :
		operation(3);    // multiplication
		break;
	case  7 :
		operation(4);     // division
		break;
	case 13:
		doublezero();
		break;
	case  14 :
		decimal();
		break;
	case 16:
		m=m;
		printf("%25.5Lf",m); //memory call
		break;
	case 20:
		printf("%25.5Lf",m);
		break;
	case 19:
		plusminus();
		break;
	case 17:
		m=m+num;       //memory plus
		break;
	case 18:
		m=m-num;       //memory minus
		break;
	case 21:
		clearm();
		break;
	case 22 :
		square();
		break;
	case 23:
		sqroot();
		break;
	case 24:
		hidemouseptr();
		setcolor(1);
		cleardevice();
		setcolor(14);
		outtextxy(225,200,"THANK YOU");
		delay(2000);
		exit();
		break;
	case 25:
		allclear();
		break;
	case 26:
		clear();
		break;
	case 27:
		num=operation(5);      	 //  equalto
		break;
	 }
	 setcolor(1);
	outtextxy(x1+12,y1+7,text[j*4+i]);
	 }
   }
 x1+=60;

	x2+=60;
}
 }
 }
}
void normalbutton(int x1,int x2,int y1,int y2,char *text)
{
setcolor(15);
rectangle(x1-2,y1-2,x2+1,y2+1);
rectangle(x1-1,y1-1,x2+2,y2+2);
setcolor(5);
rectangle(x1,y1,x2+2,y2+2);
rectangle(x1,y1,x2+1,y2+1);
setfillstyle(SOLID_FILL,14);
bar(x1,y1,x2,y2);
setcolor(1);
outtextxy(x1+12,y1+7,text);
k++;
}

initmouse()
{
 i.x.ax=0;
 int86 (0x33,&i,&o);
 return(o.x.ax);
}
hidemouseptr()
{
	 i.x.ax=2;
	 int86(0x33,&i,&o);
	 return 0;
}

showmouseptr()
{
 i.x.ax=1;
 int86(0x33,&i,&o);
 return 0;
}
getmousepos(int *button,int *x,int *y)
{
 i.x.ax=3;
 int86(0x33,&i,&o);
 *button=o.x.bx;
 *x=o.x.cx;
 *y=o.x.dx;
 return 0;
}
/* Move mouse ptr to x,y */
movemouseptr(int *x,int *y)
{
 i.x.ax=4;
 int86(0x33,&i,&o);
 o.x.cx=*x;
 o.x.dx=*y;
 return 0;
}
addnum(int pass)
{   if(sq)
	newnum=1;

	if(newnum)
	  {      if(d)
	{
	  num=pass/(pow(10.0,d));
	  d++;
	  newnum=0;
	}
	 else
	{  num=pass;
	   newnum=0;
	}
	  }
	else
	{
	if(d)
	{
	   if(num<0)
		num=num-pass/(pow(10.0,d));
	   else
		num=num+pass/(pow(10.0,d));
	  d++;
	}
	else
	{
	num=num*10+pass;
	}
	}
 printf("%25.5Lf",num);
 return ;
}
operation(int opr)
{  long double pnum;
   pnum=num;

   if(newnum && (prop != 5) && memo)
   {
   }
   else
  {  newnum=1;
	 d=0;
	 sq=0;
	 switch(prop)
	{
	 case 1:
		accum=accum+pnum;
		break;
	 case 2:
		accum=accum-pnum;
		break;
	 case 3:
		accum=accum*pnum;
		break;
	 case 4:
		accum=accum/pnum;
		break;
	 default:
	   accum=pnum;
	 }
  }
	prop=opr;
	num=accum;
 printf("%25.5Lf",num);
 return num;
}
allclear()
{
 sq=0;
 accum=0;
 num=0;
 d=0;
 newnum=1;
 printf("%25.5Lf",num);
 return;
}
plusminus()
{ if(num!=0)
  {	num*=-1;
	printf("%25.5Lf",num);
  }
  return;
}
clearm()
{
m=0;
//printf("%25.5Lf",m);
return;
}
decimal()
{
 if(!d)
 {
 d=1;
	if(newnum==1)
	{
	 num=0;
	}
  printf("%25.5Lf",num);
  }
  return;
}
square()
{
sq=1;
 num*=num;
 printf("%25.5Lf",num);
return;
}
sqroot()
{ sq=1;
 num=pow(num,0.5);
 printf("%25.5Lf",num);
return;
}
doublezero()
{
 if(d)
   {
	 d++;
	 d++;
   }
 else
  num*=100;
 printf("%25.5Lf",num);
 return;
}
clear()
{
num=0;
printf("%25.5Lf",num);
return;
}