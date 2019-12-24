#include "View.h"
#include <iostream>
#include "Point2D.h"
#include "GameObject.h"
using namespace std;

//const int view_maxsize=20; 

View :: View()
{
	size=11;
	scale=2;
	origin.x=0;
	origin.y=0; 
}

bool View :: GetSubscripts(int &out_x, int &out_y, Point2D location)
{
	Vector2D cv;
    cv = (location - origin) / scale;
    out_x = cv.x;
    out_y = cv.y;
    if (out_x >= 0 && out_x <= size - 1 && out_y >= 0 && out_y <= size - 1) {
        return true;
    }
    cout << "An object is outside the display" << endl;
    return false;
}


void View :: Clear()
{
	for (int i=0; i<view_maxsize; i++)
	{
		for (int j=0; j<view_maxsize; j++)
		{
			for (int k=0; k<2; k++)
			{
				if (k==0)
				{
					grid[i][j][k]='.'; 
				}
			else
				{
					grid[i][j][k]=' '; 
				}
			}
		}
	}
}

void View :: Plot(GameObject * ptr)
{
	int x;
	int y;

	if (GetSubscripts(x,y,(ptr->GetLocation())))
	{
		//char * ptrchar;
		if (grid[y][x][0]=='.')
		{
			ptr->DrawSelf(&grid[y][x][0]);
		}
		else
		{
			grid[y][x][0]='*';
			grid[y][x][1]=' ';
		}
	}
}
void View :: Draw()
{
	for (int i=size-1; i>=0; i--)
	{
		if (i%2==0)
		{
			cout<<(2*i);
			if (i<5)
			{
				cout <<" "; 
			}
		}
		else if (i==1 || i==3 || i==5 || i==7 || i==9)
		{
			cout<<"  "; 
		}
		for (int j=0; j<size; j++)
		{
			for (int k=0; k<2; k++)
			{
				cout<<grid[i][j][k];
			}
		}
		cout <<"\n"; 
	}
	cout <<"  0   4   8   12  16  20\n"; 
}