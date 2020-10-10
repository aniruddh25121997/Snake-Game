#include<iostream>
#include<conio.h>
#include<time.h>
#include<windows.h>
using namespace std;
int x,y,fx,fy,score;
const int width=50;
const int height=20;
bool gameover;
enum direction {STOP=0,UP ,DOWN,LEFT ,RIGHT};
direction dir;
int tx[100],ty[100];
int tl=0;

void setup()
{
    gameover=false;
    dir=STOP;
   x=width/2;
   y=height/2;
   srand(time(0));
   fx=rand()%(width-1);
   srand(time(0));
   fy=rand()%(height-1);
   score=0;
}
void draw()
{
   system("cls");
    for(int i=0;i<width;i++)
        cout<<"#";
    cout<<endl;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
         if(j==x&&i==y)
                cout<<"O";
                else if(j==fx&&i==fy)
                    cout<<"o";
         else if(j==0||j==width-1)
            cout<<"#";
            else
            {
                bool p=true;
                for(int k=0;k<tl;k++)
                {
                    if(tx[k]==j&&ty[k]==i)
                    {
                        cout<<"0";
                        p=false;
                    }
                }
                if(p)
                cout<<" ";
            }

        }
        cout<<endl;
    }
     for(int i=0;i<width;i++)
        cout<<"#";
        cout<<endl;
        cout<<"SCORE : "<<score<<endl;
}
void input()
{
    if(kbhit())
 {
     switch(getch())
     {
     case 'a':
        dir=LEFT;
        break;
        case 'd':
        dir=RIGHT;
        break;
        case 'w':
        dir=UP;
        break;
        case 's':
        dir=DOWN;
        break;
        case 'x':
        gameover=true;
        break;
     }
 }
}
void logic()
{
    int px=tx[0];
    int py=ty[0];
    int p2x,p2y;
    tx[0]=x;
    ty[0]=y;
   for(int i=1;i<tl;i++)
    {
        p2x=tx[i];
        p2y=ty[i];
        tx[i]=px;
        ty[i]=py;
        px=p2x;
        py=p2y;
    }
     switch(dir)
     {
         case LEFT:
       x--;
        break;
        case RIGHT:
        x++;
        break;
        case UP:
       y--;
        break;
        case DOWN:
        y++;
        break;
        default :
        break;
     }
     if(x>=width)
      x=0;
      else if(x<0)
       x=width-1;
       if(y>=height)
      y=0;
      else if(y<0)
       y=height-1;
     for(int i=0;i<tl;i++)
     {
         if(tx[i]==x&&ty[i]==y)
         {
             cout<<"GAMEOVER"<<endl;
           gameover=true;
           getch();
         }
     }
     if(x==fx&&y==fy)
     {
               score+=10;
           srand(time(0));
      fx=rand()%(width-1);
       srand(time(0));
       fy=rand()%(height);
        tl++;
     }
 }
int main()
{
    setup();
    while(!gameover)
    {
        draw();
        input();
        logic();
        Sleep(50);
    }
}
