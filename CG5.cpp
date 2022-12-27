#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;
class KochCurve	//class has been declared
{
	public:	//access specifier
	void koch(int iteration,int x1,int y1,int x2,int y2)	//member function
	{
	int x3,y3,x4,y4,x5,y5;		
	int dx,dy;					
	if(iteration==0)			//if iteration is 0 
	{
		line(x1,y1,x2,y2);   //Straight line
	}
	else
	{
		delay(10);
		dx=(x2-x1)/3;
		dy=(y2-y1)/3;
		x3=x1+dx;
		y3=y1+dy;
		x4=(int)(0.5*(x1+x2)+sqrt(3)*(y1-y2)/6);  //
		y4=(int)(0.5*(y1+y2)+sqrt(3)*(x2-x1)/6);
		x5=2*dx+x1;
		y5=2*dy+y1;
		koch(iteration-1,x1,y1,x3,y3);
		koch(iteration-1,x3,y3,x4,y4);
		koch(iteration-1,x4,y4,x5,y5);
		koch(iteration-1,x5,y5,x2,y2);
	}
	}
};
int main()
{
	KochCurve k;
	int it;
	cout<<"**SNOWFLAKE USING KOCH CURVE**\n";
	cout<<"Enter Number Of Iterations : "<<endl;
	cin>>it;
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
k.koch(it,150,20,20,280);
k.koch(it,280,280,150,20);
k.koch(it,20,280,280,280);
getch();
closegraph();
return 0;
}
