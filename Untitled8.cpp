#include <Conio.h>
#include <graphics.h>
#include <iostream>
#include <cmath>
#include <string>
//#include <fstream>


#define closegr closegraph

#define point   double               //還不知道浮點數的精準度是否影響向量繪圓的誤差... 

#define tide    100000               //圓角度精準  圓周角/tide 

#define R       200                       //角度-座標比 之轉換用資料生成 圓函式 的半徑   亦可看為精準度 

using namespace std;

const point Pi=3.14159265358979;

struct degree_struct
{
  point tan_data[2][tide];
};
 
degree_struct degree_structor(int x=0,int y=0,int r=R)
{
  degree_struct degree;
  const int cx=x,cy=y;
  const point part=Pi*r/(tide/2);
  int a=0;
  point copyx;
  y-=r;
  do
  {
    switch(static_cast<int>(a*360/tide))
    {                                     //抵銷誤差值 法2   
      case 45:
        x=cx-r/sqrt(2),y=cy-r/sqrt(2.0);
          break;
      case 135:
        x=cx-r/sqrt(2),y=cy+r/sqrt(2.0);
          break;
      case 225:
        x=cx+r/sqrt(2),y=cy+r/sqrt(2.0);
          break;
      case 315:
        x=cx+r/sqrt(2),y=cy-r/sqrt(2.0);
          break;
      case 0:
	    x=cx,y=cy-r;
          break;
      case 90:
        x=cx-r,y=cy;
          break;
      case 180:
     	x=cx,y=cy+r;
          break;
      case 270:
    	x=cx+r,y=cy;
          break;
      default:
          break;
	}
    copyx=x;
    degree.tan_data[1][a]=x;
    degree.tan_data[2][a]=y;
    x+=part/r*(y-cy);
    y-=part/r*(copyx-cx);
    a++;
  }
  while(a<=tide);
  return degree;
}

degree_struct degree=degree_structor(0,0,R);

class vector
{
  public:
    point vx,vy,vz;
    //friend vector& operator^()
    // {                                  x,y,z軸變換後之新座標點角度轉換公式 
    //  }                                  (sinC-sinO)*y / [(sinC-sinO)*x+x^2+y^2]  待分解 
};

class view
{
  public:
    point Vx,Vy,Vz;
  
  private:
};

void Vbox(point x,point y,const int r)       //誤差抵銷前         Vbox向量繪圓  double型態 誤差 x =-1.321  誤差 y =-4.1693  float型態 誤差 x =-1.321  誤差 y =-4.1687
{                                            //半徑150            long double型態 誤差 x =-1.321  誤差 y =-4.1693
  point dx=0,dy=0;
  const int cx=x,cy=y;
  const point part=Pi*r/(tide/2);
  y-=r;
  int a=0;
  point copyx;
  do
  {
    switch(static_cast<int>(a*360/tide))     //抵銷誤差值 法2 
    {
      case 45:
      	x=cx-r/sqrt(2),y=cy-r/sqrt(2.0);
          break;
	  case 135:
        x=cx-r/sqrt(2),y=cy+r/sqrt(2.0);
          break;
	  case 225:
      	x=cx+r/sqrt(2),y=cy+r/sqrt(2.0);
          break;
	  case 315:
      	x=cx+r/sqrt(2),y=cy-r/sqrt(2.0);
          break;
      case 0:
      	x=cx,y=cy-r;
          break;
      case 90:
      	x=cx-r,y=cy;
          break;
      case 180:
      	x=cx,y=cy+r;
          break;
      case 270:
      	x=cx+r,y=cy;
          break;
      default:
          break;
	}          
    setcolor(GREEN);
    //dx+=1.321/720;     // 抵銷誤差值  
    // dy+=4.1693/720;    //                         
    copyx=x;
    cout<<a*360.0/tide<<endl;
    cout<<x-cx<<endl
        <<y-cy<<endl;
    line(x+dx,y+dy,x+part/r*(y-cy)+dx,y-part/r*(copyx-cx)+dy);
    x+=part/r*(y-cy);
    y-=part/r*(copyx-cx);
    a++;
    //delay(10);
  }
  while(a<=tide);
}

void ball(int x,int y,int r,int thick)
{
  int cr=-r;
  do
  {
    do
    {
    putpixel(y-r,x+sqrt(pow(cr,2)-pow(r,2)),GREEN);
    putpixel(y-r,x-sqrt(pow(cr,2)-pow(r,2)),GREEN);
    putpixel(x+sqrt(pow(cr,2)-pow(r,2)),y-r,GREEN);
    putpixel(x-sqrt(pow(cr,2)-pow(r,2)),y-r,GREEN);
    --r;
    }
    while(r!=cr);
    --thick;
    --cr;
    r=-cr;
  }
  while(thick!=0);
}

int main()
{
/*int a=0;
point out[2][tide];
degree_structor(0,0,R,out);
ofstream file;
file.open("C:\\Users\\max\\Desktop\\degree&tan.txt",ios::out);
if(file.is_open())
{
  do
  {
  file<<a*360/tide<<"度"<<"\n";
  file<<"x:"<<out[1][a]<<"   y:"<<out[2][a]<<"\n";
  a++;
  }
  while(a<=tide);
file.close();
return 0;
}
else
{
system("PAUSE");
exit(EXIT_FAILURE);
}*/ 
  int i = 1,p=1;
  int gd = DETECT, gm = 0;
  initgraph(&gd,&gm, "grafic.h"); /* BGI初始化 */
  while(1)
  {
    do
    {
      putpixel(300,300,RED); 
      cin>>i;
      setcolor(RED);
      line(p+0,p+300,0+i,300+i);
      circle(300,250,200);
      Vbox(300.0,250.0,200);
      p=i;
      i++;
    }
    while(1);
	
    if(kbhit())
      break;
  }
  getch(); 
  closegr();
  return 0;
}





//int reader(string )
