#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>
#include<alloc.h>

void main()
{
	int d=DETECT,m,r=50;
	float gx,gy,x,y,x1,y1,xm,ym,xh,yh,k=0,i,j,ii,l,mi;
	struct time t;
	void *mem;
	int size,rem,min;
	int pks=0;
	ii=13.89;
	initgraph(&d,&m,"c:\\turboc3\\bgi");
	outtextxy(190,20,"Analog Clock");
	setcolor(14);
	line(159,100,159,387);
	line(450,100,450,382);
	line(185,87,185,321);
	line(180,89,180,320);
	line(425,87,425,317);
	line(429,89,429,315);
	//for the box surrounding the digital time
	line(260,300,350,300);
	line(260,320,350,320);
	line(260,300,260,320);
	line(350,300,350,320);

	setcolor(14);
	arc(300,100,236,307,250);
	arc(305,362,61,119,300);
	arc(300,100,244,298,320);


	while(1)
	{

		while(ii<14.36)

		{
			if(kbhit())
			exit(1);
			// second's pixel
			for(i=11;i<=17.3;i+=0.105)
			{
				gx=55*cos(i);
				gy=55*sin(i);
				putpixel(gx+300,gy+200,4);

			 }
			 // outer circle
			 setcolor(2);
			 circle(300,200,85);
			 circle(300,200,87);
			 circle(300,200,90);
			 setcolor(3);
			 outtextxy(500,400,"Made By :-");
			 outtextxy(510,410,"Somnath Pratik");
			 outtextxy(510,420,"Avnish Raut");
			 outtextxy(510,430,"Domingos J Pinto");


			 setcolor(14);
			 circle(300,200,80);

			 setcolor(4);
			 outtextxy(330,143,"1");
			 outtextxy(350,165,"2");
			 outtextxy(360,197,"3");
			 outtextxy(352,228,"4");
			 outtextxy(328,252,"5");
			 outtextxy(298,260,"6");
			 outtextxy(264,252,"7");
			 outtextxy(242,226,"8");
			 outtextxy(235,197,"9");
			 outtextxy(235,165,"10");
			 outtextxy(260,140,"11");
			 outtextxy(292,135,"12");
			 //time function
			 ///*
			 gettime(&t);
			 gotoxy(35,20);
			 printf("%d:%d:%d",(int)(t.ti_hour),(int)(t.ti_min),(int)(t.ti_sec));

			 i=((int)(t.ti_sec)*(0.105))+11;
			 j=((int)(t.ti_min)*(0.105))+11;
			 k=(((int)(t.ti_hour)*(0.105))*5+11);

			 min=(int)(t.ti_min);
			 rem=min/12;
			 k=k+(rem*0.105);
			 ///*/
			 //calculations for second hand
			 x=r*cos(i);
			 y=r*sin(i);
			 setcolor(14);
			 line(300,200,x+300,y+200);

			 //calculations for minute hand
			 xm=(r-5)*cos(j);
			 ym=(r-5)*sin(j);
			 setcolor(9);
			 line(300,200,xm+300,ym+200);

			 //calculations for hour hand
			 xh=(r-20)*cos(k);
			 yh=(r-20)*sin(k);
			 setcolor(6);
			 line(300,200,xh+300,yh+200);

			 delay(200.5);

			 if(kbhit())
				 exit(1);
			 for(pks=1;pks<=4;pks++)
			 {

				 l=200*cos(ii);
				 mi=200*sin(ii);

				 setcolor(4);
				 line(300,290,300+l,190+mi);


				 setcolor(14);
				 setfillstyle(SOLID_FILL,14);
				 circle(l+300,mi+190,15);
				 floodfill(l+300,mi+190,14);

				 ii+=.105;

				 delay(200.5);
				 setcolor(0);
				 setfillstyle(SOLID_FILL,0);
				 circle(l+300,mi+190,15);
				 floodfill(l+300,mi+190,0);

				 line(300,290,300+l,190+mi);
			 }

			 setcolor(0);
			 line(300,200,x+300,y+200);
			 line(300,200,xm+300,ym+200);
			 line(300,200,xh+300,yh+200);
		}

		while(ii>13.89)
		{
			if(kbhit())
			exit(1);

			for(i=11;i<=17.3;i+=0.105)
			{
				gx=55*cos(i);
				gy=55*sin(i);
				putpixel(gx+300,gy+200,4);
			 }
			setcolor(12);
			circle(300,200,85);
			circle(300,200,87);
			circle(300,200,90);

			setcolor(4);
			outtextxy(500,400,"Made By :-");
			outtextxy(510,410,"Somnath Pratik");
			outtextxy(510,420,"Avnish Raut");
			outtextxy(510,430,"Domingos J Pinto");

			setcolor(15);
			setfillstyle(SOLID_FILL,0);
			circle(300,200,80);
			floodfill(300,200,0);
			setcolor(4);
			outtextxy(330,143,"1");
			outtextxy(350,165,"2");
			outtextxy(360,197,"3");
			outtextxy(352,228,"4");
			outtextxy(328,252,"5");
			outtextxy(298,260,"6");
			outtextxy(264,252,"7");
			outtextxy(242,226,"8");
			outtextxy(235,197,"9");
			outtextxy(235,165,"10");
			outtextxy(260,140,"11");
			outtextxy(292,135,"12");
			gettime(&t);
			gotoxy(35,20);
			printf("%d:%d:%d",(int)(t.ti_hour),(int)(t.ti_min),(int)(t.ti_sec));

			i=((int)(t.ti_sec)*(0.105))+11;
			j=((int)(t.ti_min)*(0.105))+11;

			k=(((int)(t.ti_hour)*(0.105))*5+11);
			min=(int)(t.ti_min);
			rem=min/12;
			k=k+(rem*0.105);

			x=r*cos(i);
			y=r*sin(i);
			setcolor(14);
			line(300,200,x+300,y+200);

			xm=(r-5)*cos(j);
			ym=(r-5)*sin(j);
			setcolor(9);
			line(300,200,xm+300,ym+200);

			xh=(r-20)*cos(k);
			yh=(r-20)*sin(k);
			setcolor(6);
			line(300,200,xh+300,yh+200);
			delay(200.5);


			if(kbhit())
				exit(1);
			for(pks=1;pks<=4;pks++)
			{
				l=200*cos(ii);
				m=200*sin(ii);

				setcolor(4);
				line(300,290,300+l,190+m);
				setcolor(14);
				setfillstyle(SOLID_FILL,14);
				circle(l+300,m+190,15);
				floodfill(l+300,m+190,14);

				ii-=0.105;
				delay(200.5);

				setcolor(0);
				setfillstyle(SOLID_FILL,0);
				circle(l+300,m+190,15);
				floodfill(l+300,m+190,0);
				line(300,290,300+l,190+m);
			}
			setcolor(0);
			line(300,200,x+300,y+200);
			line(300,200,xm+300,ym+200);
			line(300,200,xh+300,yh+200);
		}
      }
}
