#include<iostream>
#include<windows.h>
#include<cmath>
#define PI 3.141592
int SCREEN_WIDTH=920;
int SCREEN_HEIGHT=450;
int main()
{
   // wchar_t *screen=new wchar_t[SCREEN_WIDTH*SCREEN_HEIGHT];
    HANDLE hConsole =CreateConsoleScreenBuffer(GENERIC_WRITE,0,NULL,CONSOLE_TEXTMODE_BUFFER,NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    double y;
    int x;
    x=0;
    y=0;
    int i=0;
    HDC myDC=GetDC(GetConsoleWindow());
    double pixel=0;
    COLORREF red=RGB(180,20,10);
    COLORREF blue=RGB(20,20,180);
    COLORREF green=RGB(20,180,20);
    double angle=0;
    double value;
    if(SCREEN_WIDTH%45!=0)
    {
        SCREEN_WIDTH=SCREEN_WIDTH-SCREEN_WIDTH%45 +45;
    }
    while(1)
    {
        angle=0;i=0;
        while(angle<200)
        {
        value=sin(angle)*100;
        SetPixel(myDC,angle*45,SCREEN_HEIGHT/2+value,blue);
        SetPixel(myDC,i,SCREEN_HEIGHT/2,red);
        SetPixel(myDC,SCREEN_WIDTH/2,i,red);
        if(i>=1000)i=0;
        angle+=0.01;
        i++;
        }
    }
    return 0;
}