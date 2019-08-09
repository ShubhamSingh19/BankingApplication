#include<graphics.h>
#include<iostream>
#include<stdio.h>

using namespace std;

char a[100];
char b[1];
char b1[1];
char b2[1];
struct info
{
    char name[100];
    int account;
    int amount;
}data;

 int main()
 {
     int gd=DETECT,gm,i;
     initgraph(&gd,&gm,"C:\\TC\\BGI");
     setbkcolor(CYAN);
     setfillstyle(SOLID_FILL,CYAN);
     outtextxy(100,100,"Type anything");
     cout<<"Enter name"<<endl;
     gets(data.name);
     cout<<"Enter account"<<endl;
     cin>>data.account;
     cout<<"Enter amount"<<endl;
     cin>>data.amount;
     cleardevice();
     if(a=="exit")
        closegraph();
    else
    {
        sprintf(b,"Name: %s",data.name);
        outtextxy(100,100,b);
        sprintf(b1,"Account: %d",data.account);
        outtextxy(100,200,b1);
        sprintf(b2,"Amount: %d",data.amount);
        outtextxy(100,300,b2);
    }
    getch();
    closegraph();
 }
