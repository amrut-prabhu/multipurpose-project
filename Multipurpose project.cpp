/***********************Header Files***********************/
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>
#include<ctype.h>
#include<stdio.h>
#include<iomanip>
#include <cstdlib>
#include <ctime>
#include <graphics.h>
#include <dos.h>
#include <math.h>
#include <windows.h>

using namespace std;

/*******************Time Table Structures*******************/

struct teacher   //Teacher Details
{
 char tno[5];
 int noperiods;   //Teacher code and number of periods
 char tname[30],subject[20];
 char classes[5];
 int ttt[5][9];
 int tcount[5];
 int subcount[5];
 int free;
};

teacher T1[6]={ {"101",0,"Mrs Rubeena  ","Mathematics      ","abcd"},
		  		{"103",0,"Mr Saji      ","Physics          ","abcd"},
		  		{"105",0,"Mrs Preethi  ","Chemistry  	     ","abcd"},
		  		{"107",0,"Mrs Nandini  ","Computer Science ","abcd"},
		  		{"109",0,"Mr Saijaan   ","English          ","abcd"},
		  		{"111",0,"Mr Maqsood   ","Arabic           ","abcd"},
			  };

teacher T2[6]={ {"102",0,"Mr Udupa     ","Mathematics      ","ABCD"},
			 	{"104",0,"Mrs Susan    ","Physics          ","ABCD"},
			 	{"106",0,"Mr Zaffer    ","Chemistry        ","ABCD"},
			 	{"108",0,"Mrs Lekshmi  ","Computer Science ","ABCD"},
			 	{"110",0,"Mrs Latha    ","English          ","ABCD"},
			 	{"112",0,"Mr Moidheen  ","Arabic           ","ABCD"},
			  };

struct clase     //Class Details
{
 char classname[4];
 char tsub[9][30];
 int  ctt[5][9];
}cl[8]; //0-3:11A-11D,4-7:12A-12D


/*****************Movie Booking Structures*****************/

struct date
{
	int dd,mm,yy;
};

struct times
{
	int hh,mm;
	char ap[5];	//am or pm
};

struct seat
{
	char srow;	//Seat row
	int scol;	//Seat column
};

struct ticket
{
	int tno;			//Ticket Number
	char movie[65];	    //Movie Name
	char cinema[50];    //Cinema Name
	date d;				//Date of movie
	times t;			//Time of movie
	int hall;			//Hall number
	seat sno;	    	//Seat Number
	char cardno[25];	//Credit Card Number
	char email[30];		//Email Address
}t[50];

struct hall
{
	int hall[8][16];	//Cinema Hall
};

struct cinehalls //Cinema halls in theatre
{
	hall h[13];
}challs;

/*****************Banking Structures*****************/

struct customer
{
	int custid;
    char custname[15];
	char username[10];
	char password[10];
	double balance;
}b[20];

struct staff
{  int staffid;
   char staffname[15];
   char username[10];
   char password[10];
}manager;


/*********************************************************************************/
/******************************Function Prototypes********************************/
/*********************************************************************************/

void mainmenu();

void intro();

/*********************Time Table Functions*********************/

void viewcl(int a[5][9],teacher te[6]);	//Display Class Time Table

void viewtt(int a[5][9],teacher te);   //Display Teacher Time Table

void ttchoice();		//Choosing which time table to display

void timetable();		//Main Time Table Program

/*******************Movie Booking Functions*******************/

void moviemenu();

void cineseats(int mno,int s);

void book();

void del();

void disp(int i);

void nowshow();

void coming();

/***********************Game Functions***********************/

void gamemenu();

void diffi1();  //easy

void diffi2();  //normal

void diffi3();  //hard

/***********************Bank Functions***********************/

void bankmenu();

void managerpass();

void search();

void display();

void openbal10000();

void newcust();

void existcust();

void withdraw();

void deposit();

void loan();

void newcustlogin();

/********************************************************************************************************************************************/
/****************************************************************Main Program****************************************************************/
/********************************************************************************************************************************************/
int tick,p=0,userpoint=0,compoint=0;
int q,r;

int main()
{

	for(int i=0;i<13;i++)
	{
        challs.h[i]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  //0-available,1-booked,9-no seat
					  0,0,9,0,0,0,0,0,0,0,0,0,0,9,0,0,
					  0,0,9,0,0,0,0,0,0,0,0,0,0,9,0,0,
					  0,0,9,0,0,0,0,0,0,0,0,0,0,9,0,0,
					  0,0,9,0,0,0,0,0,0,0,0,0,0,9,0,0,
					  0,0,9,0,0,0,0,0,0,0,0,0,0,9,0,0,
					  0,0,9,0,0,0,0,0,0,0,0,0,0,9,0,0,
					  0,0,9,0,0,0,0,0,0,0,0,0,0,9,0,0};
	}

	srand(time(0));

	tick=rand()%300+10; 	//Assigning random value to first ticket number

	//Assigning values to seats(Available/Booked)
	for(int i=0;i<13;i++)
	{
		for(int j=0;j<8;j++)	 //Seat letter
		{
			for(int k=0;k<16;k++)//Seat Number
			{
				if(challs.h[i].hall[j][k]!=9)
					challs.h[i].hall[j][k]=rand()%2;

			}
		}
	}

	intro();
	mainmenu();

	getch();
	return 0;
}


/**********************************************************************************/
/******************************Function Definitions********************************/
/**********************************************************************************/

void mainmenu()
{
	int ch; //Main Choice
	char tch;
	int ech;

	system("cls");
	cout<<"\nWhere do you want to go?"<<endl;
	cout<<"\n1.About Us";
	cout<<"\n2.Education Division";
	cout<<"\n3.Entertainment Division";
	cout<<"\n4.Banking Division";
	cout<<"\n5.Contact Us";
	cout<<"\n\nTo exit, press 0"<<endl;
	cout<<"\nEnter your choice\t\t";
	cin>>ch;


	switch(ch)
	{
	    case 1: system("cls");
				cout<<"\n Star Labs is an innovative company that has set a new standard in \n the development of programming. ";
				cout<<"\n\n Through its informative, understandable and readable programs it is\n shaping the future of programming. ";
				cout<<"\n \n This is a company that was started by 3 friends Amrut, Akhil \n and Naveen-the CEOs of STAR LABS. ";
				cout<<"\n \n The Company is ready to take in programmers who are ready to \n work towards the betterment of C++. ";

				char ch;
				cout<<"\n\n\n Do you want to go back to the menu?(y/n)\t";
				cin>>ch;
				system("cls");
				if(ch=='y')
					mainmenu();
				else
					exit(0);
				break;
		case 2: system("cls");
				cout<<"\nDo you want to generate a time table(y/n)?\t\t";
				cout<<"\n\nEnter your choice\t\t";
				cin>>tch;
				if(tch=='y')
					timetable();
				else
					mainmenu();
				break;

		case 3: system("cls");
				cout<<"\nChoose an option"<<endl;
				cout<<"\n1. Cine Royal Cinemas";
				cout<<"\n2. Play a game(rock,paper,scissors)";
				cout<<"\n\nTo go back, press 0"<<endl;
				cout<<"\nEnter your choice\t\t";
				cin>>ech;
				if(ech==1)
					{ system("cls");
					  moviemenu();}
				else if(ech==2)
					{ system("cls");
					  gamemenu();  }
				else
					mainmenu();
				break;

		case 4: system("cls");
			    bankmenu();

		case 5: system("cls");
				cout<<"\n For more information please do not hesitate to contact us at ";
			    cout<<"\n info@starlabs.com ";
				cout<<"\n Telephone : 02-6294564 ";
				cout<<"\n Mobile    : 050-4210348 ";
				cout<<"\n Fax       : 02-6232916 ";
				char op;
				cout<<"\n\n\n Do you want to go back to the menu?(y/n)\t";
				cin>>op;
				system("cls");
				if(op=='y')
					mainmenu();
				else
					exit(0);
				break;

		case 0: exit(0);
			    break;
		default: system("cls");
				 mainmenu();
				 break;
	}


};//mainmenu



void intro()
{
	srand(time(0));

   //request auto detection
   int gdriver = DETECT, gmode, errorcode;

   // initialize graphics and local variables
   initgraph(&gdriver, &gmode, "C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\x86_64-w64-mingw32\\include\\");

   // read result of initialization
   errorcode = graphresult();
   if (errorcode != grOk)  // an error occurred
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); //terminate with an error  code
    }

	int x=300,y=300;
	moveto(x,y);
	float r=170,i=1;
	int s=1,j=1;
	int x1=240,y1=230;
	for(;i<9;i+=0.05,j++)
	{
		setcolor(rand()%15);
		int maxx=getmaxx();  int maxy=getmaxy();
		for (int z=0 ;z<10;z++)
		{
			circle(rand()%maxx, rand()%maxy,1 );
			putpixel(rand()%maxx, rand()%maxy,rand()%15 );
		}

		int b=y+r*cos(i);
		int a1=x+r*sin(i*2);
		int b2=y+r*(cos(i)/8);

		setcolor(9);
		line(a1+10,b-65,a1+10,b2-65);

	    delay(1);

		switch(j)
		{
			case 25:s++;
					x1-=3;
					y1-=2;
				    break;
			case 50:s++;
					x1-=10;
					y1-=2;
				    break;
			case 75:s++;
					x1-=21;
					y1-=2;
				    break;
			case 100:s++;
					x1-=17;
					y1-=2;
				    break;
			case 125:s++;
					x1-=24;
					y1-=2;
				    break;
			case 160:s++;
					x1-=26;
					y1-=2;
				    break;
		}

		setcolor(14);
	    setbkcolor(12);
	    settextstyle(10,HORIZ_DIR,s);
	   	outtextxy(x1,y1,"Star Labs");

		//150,215
		//240,230

	}
   delay(1500);
   closegraph();
};//intro


/*********************Time Table Functions*********************/

void timetable()
{
	  int i,j,m;
	  int p[5][9];
	  system("cls");
	  srand(time(0));
	  char ch;
	  system("cls");

	 //Making all class time tables empty
	  for(int w=0;w<8;w++)
		for(i=0;i<5;i++)
			for(j=0;j<9;j++)
				cl[w].ctt[i][j]=100;

	 //Assigning class name to each class structure
	 for(i=0;i<5;i++)
		strcpy(cl[i].classname,"11");

	 for(i=5;i<10;i++)
		strcpy(cl[i].classname,"12");

	 i=0;

	 for(ch=65;ch<69;ch++)
  	 {
		cl[i].classname[2]=ch;
		i++;
	 }

	 for(ch=65;ch<69;ch++)
	 {
		cl[i].classname[2]=ch;
		i++;
	 }


	//Assigning the entire teachers' time table with breaks
	for(m=0;m<6;m++)
		for(i=0;i<5;i++)
			for(j=0;j<9;j++)
				T1[m].ttt[i][j]=100;

	for(m=0;m<6;m++)
		for(i=0;i<5;i++)
			for(j=0;j<9;j++)
				T2[m].ttt[i][j]=100;


	//Assigning Practical Periods to classes
	for(i=0;i<7;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(strcmp(T1[i].tno,"103")==0)	//Physics 11
				switch(T1[i].classes[j])
				{
					case 'a':cl[0].ctt[0][1]=9;
						     cl[0].ctt[0][2]=9;
							 T1[i].ttt[0][1]=0;
							 T1[i].ttt[0][2]=0;
							 break;
					case 'b':cl[1].ctt[1][1]=9;
							 cl[1].ctt[1][2]=9;
							 T1[i].ttt[1][1]=1;
							 T1[i].ttt[1][2]=1;
							 break;
					case 'c':cl[2].ctt[2][1]=9;
							 cl[2].ctt[2][2]=9;
							 T1[i].ttt[2][1]=2;
							 T1[i].ttt[2][2]=2;
							 break;
					case 'd':cl[3].ctt[3][1]=9;
							 cl[3].ctt[3][2]=9;
							 T1[i].ttt[3][1]=3;
							 T1[i].ttt[3][2]=3;
							 break;
				}

			if(strcmp(T2[i].tno,"104")==0)	  //Physics 12
				switch(T2[i].classes[j])
				{
					case 'A':cl[4].ctt[0][6]=9;
							 cl[4].ctt[0][7]=9;
							 T2[i].ttt[0][6]=4;
							 T2[i].ttt[0][7]=4;
							 break;
					case 'B':cl[5].ctt[1][6]=9;
							 cl[5].ctt[1][7]=9;
							 T2[i].ttt[1][6]=5;
							 T2[i].ttt[1][7]=5;
							 break;
					case 'C':cl[6].ctt[2][6]=9;
							 cl[6].ctt[2][7]=9;
							 T2[i].ttt[2][6]=6;
							 T2[i].ttt[2][7]=6;
							 break;
					case 'D':cl[7].ctt[3][6]=9;
							 cl[7].ctt[3][7]=9;
							 T2[i].ttt[3][6]=7;
							 T2[i].ttt[3][7]=7;
							 break;
				}

			if(strcmp(T1[i].tno,"105")==0)		//Chemistry 11
				switch(T1[i].classes[j])
				{
					case 'a':cl[0].ctt[1][1]=10;
							 cl[0].ctt[1][2]=10;
							 T1[i].ttt[1][1]=0;
							 T1[i].ttt[1][2]=0;
							 break;
					case 'b':cl[1].ctt[2][1]=10;
							 cl[1].ctt[2][2]=10;
							 T1[i].ttt[2][1]=1;
							 T1[i].ttt[2][2]=1;
							 break;
					case 'c':cl[2].ctt[3][1]=10;
							 cl[2].ctt[3][2]=10;
							 T1[i].ttt[3][1]=2;
							 T1[i].ttt[3][2]=2;
							 break;
					case 'd':cl[3].ctt[4][1]=10;
							 cl[3].ctt[4][2]=10;
							 T1[i].ttt[4][1]=3;
							 T1[i].ttt[4][2]=3;
						 	 break;
				}

			if(strcmp(T2[i].tno,"106")==0)	//Chemistry 12
				switch(T2[i].classes[j])
				{
					case 'A':cl[4].ctt[1][6]=10;
							 cl[4].ctt[1][7]=10;
							 T2[i].ttt[1][6]=4;
							 T2[i].ttt[1][7]=4;
							 break;
					case 'B':cl[5].ctt[2][6]=10;
							 cl[5].ctt[2][7]=10;
							 T2[i].ttt[2][6]=5;
							 T2[i].ttt[2][7]=5;
							 break;
					case 'C':cl[6].ctt[3][6]=10;
							 cl[6].ctt[3][7]=10;
							 T2[i].ttt[3][6]=6;
							 T2[i].ttt[3][7]=6;
							 break;
					case 'D':cl[7].ctt[4][6]=10;
							 cl[7].ctt[4][7]=10;
							 T2[i].ttt[4][6]=7;
							 T2[i].ttt[4][7]=7;
							 break;
				}
			if(strcmp(T1[i].tno,"107")==0)	  //Comp Sc 11
				switch(T1[i].classes[j])
				{
					case 'a':cl[0].ctt[2][1]=11;
							 cl[0].ctt[2][2]=11;
							 T1[i].ttt[2][1]=0;
							 T1[i].ttt[2][2]=0;
							 break;
					case 'b':cl[1].ctt[3][1]=11;
							 cl[1].ctt[3][2]=11;
							 T1[i].ttt[3][1]=1;
							 T1[i].ttt[3][2]=1;
							 break;
					case 'c':cl[2].ctt[4][1]=11;
							 cl[2].ctt[4][2]=11;
							 T1[i].ttt[4][1]=2;
							 T1[i].ttt[4][2]=2;
							 break;
					case 'd':cl[3].ctt[0][1]=11;
							 cl[3].ctt[0][2]=11;
							 T1[i].ttt[0][1]=3;
							 T1[i].ttt[0][2]=3;
							 break;
				}
			if(strcmp(T2[i].tno,"108")==0)	  //Comp Sc 12
				switch(T2[i].classes[j])
				{
					case 'A':cl[4].ctt[2][6]=11;
							 cl[4].ctt[2][7]=11;
							 T2[i].ttt[2][6]=4;
							 T2[i].ttt[2][7]=4;
							 break;
					case 'B':cl[5].ctt[3][6]=11;
							 cl[5].ctt[3][7]=11;
							 T2[i].ttt[3][6]=5;
							 T2[i].ttt[3][7]=5;
							 break;
					case 'C':cl[6].ctt[4][6]=11;
							 cl[6].ctt[4][7]=11;
							 T2[i].ttt[4][6]=6;
							 T2[i].ttt[4][7]=6;
							 break;
					case 'D':cl[7].ctt[0][6]=11;
							 cl[7].ctt[0][7]=11;
							 T2[i].ttt[0][6]=7;
							 T2[i].ttt[0][7]=7;
							 break;
				}
		}
	}


	for(int x=0;x<6;x++)
	   for(i=0;i<5;i++)
	       for(int breakcount=0;breakcount<2;breakcount++)
		   {
		      int j;
		      j=rand()%8;

		      for(int tfree=0;tfree<6;tfree++)  //checking if ony two teachers are free at a given period
		      {
				int free=3;

			  	for(int m=0;m<5;m++)
			       if(T1[tfree].ttt[m][j]==101)
				 	   free--;
			  }

			  if (free>0)
				{
		       		if(T1[x].ttt[i][j]==100)
			  		{
			   			if(j>3)
			     			T1[x].ttt[i][j]=101;
			   			else
			    		{
			       			if(x==1||x==2||x==3)
				   			breakcount--;
			       			else
				   			T1[x].ttt[i][j]=101;
			     		}
			    	}

		      		else
			  	 		breakcount--;
		        }

			  else
				 breakcount--;
		   }

	for(int x=0;x<6;x++)
	   for(i=0;i<5;i++)
	       for(int breakcount=0;breakcount<2;breakcount++)
		     {
		      	int j;
		      	j=rand()%8;

		     	for(int tfree=0;tfree<6;tfree++) //checking if ony two teachers are free at a given period
		        {
					int free=3;
			  		for(int m=0;m<5;m++)
			       		if(T2[tfree].ttt[m][j]==101)
				 			free--;
				}


	   			if (free>0)
				{
		       		if(T2[x].ttt[i][j]==100)
			  		{
			   			if(j<6)
			     			T2[x].ttt[i][j]=101;
			   			else
			    		{
			       			if(x==1||x==2||x==3)
				   				breakcount--;
			       			else
				   				T2[x].ttt[i][j]=101;
			     		}
			  		}

				   else
			  		 breakcount--;
		        }

			 	else
				  breakcount--;
		    }


	//Main Linking Part of teacher and class time tables for 11th

	for (int w=0;w<4;w++)
	{
		int g,c,x,count[5][8],subcount[8],b,s[5][9];

		if(i==4)
		 for(m=0;m<6;m++)
		   if(subcount[m]>=2)
			count[i][m]=subcount[m];

		for(j=0;j<8;j++)
		  {  if ((j==0)||(j==4)||(j==5))
		  		subcount[j]=7;
		     else if (j==6)
			 	subcount[j]=2;
		     else if (j==7)
			 	subcount[j]=1;
		     else
			 	subcount[j]=5;
		  }

		for(i=0;i<5;i++)
			for(j=0;j<8;j++)
		  	{
			  if((j==0)||(j==4)||(j==5))
			  	 count[i][j]=2;
		     else
				count[i][j]=1;
			}

	    for(i=0;i<5;i++)
	    {
		  j=0;
		  do
		  {
		      x=rand()%6;
		      c=0;

			  if((cl[w].ctt[i][j]!=9)&&(cl[w].ctt[i][j]!=10)&&(cl[w].ctt[i][j]!=11)&&(cl[w].ctt[i][j]!=6)&&(cl[w].ctt[i][j]!=7))
			  {
			    if ((count[i][x]>0)&&(subcount[x]>0))
			    {
					if(T1[x].ttt[i][j]==100)
					{
						cl[w].ctt[i][j]=x;
						subcount[x]--;
						T1[x].ttt[i][j]=w;
						T1[x].tcount[i]--;
						count[i][x]--;
						j++;
						g=0;
						c=1;
					}
			    }

				else
		      	  for(int z=0;z<6;z++)
					 if((subcount[z]>0)&&(count[i][z]>0)&&(T1[z].ttt[i][j]==100))
					 {
						cl[w].ctt[i][j]=z;
						subcount[z]--;
						T1[z].ttt[i][j]=w;
						T1[z].tcount[i]--;
						count[i][z]--;
						j++;
						c=1;
						break;
					 }
		     }

		     if ((cl[w].ctt[i][j]>=9)&&(cl[w].ctt[i][j]<=11))
		     {
		   		j++;
				c=1;
		     }

		     if(c==0)
			    j++;

		  }while(j<9);
	   }

	    for(x=0;x<6;x++)
	  	{
		  	for(i=0;i<5;i++)
			for(j=0;j<9;j++)
				if(subcount[x]>0)
				   if((T1[x].ttt[i][j]==100)&&(cl[w].ctt[i][j]==100))
				       {
					   		cl[w].ctt[i][j]=x;
					  		subcount[x]--;
					  		T1[x].ttt[i][j]=w;
					  		T1[x].tcount[i]--;
					  		count[i][x]--;
					   }
			if(x==0)
				x+=3;
	  	}

	    for(x=1;x<4;x++)
			for(i=0;i<5;i++)
				for(j=0;j<9;j++)
					if(subcount[x]>0)
				  		if((T1[x].ttt[i][j]==100)&&(cl[w].ctt[i][j]==100))
				       	{
					  	 	cl[w].ctt[i][j]=x;
					  		subcount[x]--;
					  		T1[x].ttt[i][j]=w;
					  		T1[x].tcount[i]--;
					  		count[i][x]--;
					  	}

	    for(x=0;x<6;x++)
	  	{
		  	for(i=0;i<5;i++)
				for(j=0;j<9;j++)
					if(subcount[x]>0)
				  		if((T1[x].ttt[i][j]>=100)&&(cl[w].ctt[i][j]==100))
				        {
					   		cl[w].ctt[i][j]=x;
					  		subcount[x]--;
					  		T1[x].ttt[i][j]=w;
					  		T1[x].tcount[i]--;
					  		count[i][x]--;
						}

			if(x==0)
				x+=3;
	  	}

	    for(x=1;x<4;x++)
			for(i=0;i<5;i++)
				for(j=0;j<9;j++)
					if(subcount[x]>0)
				  		if((T1[x].ttt[i][j]>=100)&&(cl[w].ctt[i][j]==100))
				        {
					   		cl[w].ctt[i][j]=x;
					  		subcount[x]--;
					  		T1[x].ttt[i][j]=w;
					  		T1[x].tcount[i]--;
					  		count[i][x]--;
						}

	}

	for(int x=0;x<6;x++)
	 	T1[x].free=0;

	for(int x=0;x<6;x++)
	 	for(i=0;i<5;i++)
	    	for(j=0;j<9;j++)
				if(T1[x].ttt[i][j]==101)
					T1[x].free++;

	for(int x=0;x<6;x++)
	    for(i=0;i<5;i++)
	     	for(j=0;j<9;j++)
	       		if(T1[x].free<17)
					if(T1[x].ttt[i][j]==100)
		 			{
					 	T1[x].ttt[i][j]=101;
						T1[x].free++;
					}


	//Main Linking Part of teacher and class time tables for 12th

	for (int w=4;w<8;w++)
	{
		int g,c,x,count[5][8],subcount[8],b,s[5][9],p,q,temp,dsum=0,day[5];

		if(i==4)
		   for(m=0;m<6;m++)
				if(subcount[m]>=2)
					count[i][m]=subcount[m];

		for(j=0;j<8;j++)
		{
			if ((j==0)||(j==4)||(j==5))
				subcount[j]=7;
		    else if (j==6)
				subcount[j]=2;
		    else if (j==7)
				subcount[j]=1;
		    else
				subcount[j]=5;
		}

		for(i=0;i<5;i++)
			for(j=0;j<8;j++)
		  	{
			  	if((j==0)||(j==4)||(j==5))
					count[i][j]=2;
		    	else
					count[i][j]=1;
			}

	    for(i=0;i<5;i++)
	  	{
	   		j=0;
	   		do
	   		{
	    		x=rand()%6;
	    		c=0;

	 			if(cl[w].ctt[i][j]==100)
	  			{
				  	if ((count[i][x]>0)&&(subcount[x]>0))
	    			{
						if(T2[x].ttt[i][j]==100)
						{
			  				cl[w].ctt[i][j]=x;
			  				subcount[x]--;
			  				T2[x].ttt[i][j]=w;
			  				T2[x].tcount[i]--;
			  				count[i][x]--;
			  				j++;
							g=0;
							c=1;
						}
	    			}

					else
	      			  for(int z=0;z<6;z++)
						 if((subcount[z]>0)&&(count[i][z]>0)&&(T2[z].ttt[i][j]==100))
				       	 {
							cl[w].ctt[i][j]=z;
					  		subcount[z]--;
					  		T2[z].ttt[i][j]=w;
					  		T2[z].tcount[i]--;
					  		count[i][z]--;
							j++;
							c=1;
					  		break;
				         }
	   			 }

				if ((cl[w].ctt[i][j]>=9)&&(cl[w].ctt[i][j]<=11))
	     		{
				 	j++;
					c=1;
				}

	   			if(c==0)
					j++;

			   }while(j<9);
	  	 }

	    for(x=0;x<6;x++)
	  	{
		  	for(i=0;i<5;i++)
				for(j=0;j<9;j++)
					if(subcount[x]>0)
				  		if((T2[x].ttt[i][j]==100)&&(cl[w].ctt[i][j]==100))
				       	{
							cl[w].ctt[i][j]=x;
					  		subcount[x]--;
					  		T2[x].ttt[i][j]=w;
					  		T2[x].tcount[i]--;
					  		count[i][x]--;
						}
					if(x==0)
						x+=3;
	  	}

	    for(x=1;x<4;x++)
			for(i=0;i<5;i++)
				for(j=0;j<9;j++)
					if(subcount[x]>0)
				  		if((T2[x].ttt[i][j]==100)&&(cl[w].ctt[i][j]==100))
				       	{
						   	cl[w].ctt[i][j]=x;
					  		subcount[x]--;
					  		T2[x].ttt[i][j]=w;
					  		T2[x].tcount[i]--;
					  		count[i][x]--;
						}

		for(x=0;x<6;x++)
	  	{
		  	for(i=0;i<5;i++)
				for(j=0;j<9;j++)
					if(subcount[x]>0)
				  		if((T2[x].ttt[i][j]>=100)&&(cl[w].ctt[i][j]==100))
				       	{
						   	cl[w].ctt[i][j]=x;
					  		subcount[x]--;
					  		T2[x].ttt[i][j]=w;
					  		T2[x].tcount[i]--;
					  		count[i][x]--;
						}
					if(x==0)
						x+=3;
	  	 }

	    for(x=1;x<4;x++)
			for(i=0;i<5;i++)
				for(j=0;j<9;j++)
					if(subcount[x]>0)
				  		if((T2[x].ttt[i][j]>=100)&&(cl[w].ctt[i][j]==100))
				       	{
						   	cl[w].ctt[i][j]=x;
					  		subcount[x]--;
					  		T2[x].ttt[i][j]=w;
					  		T2[x].tcount[i]--;
					  		count[i][x]--;
						}


	}

	for(int x=0;x<6;x++)
	   T2[x].free=0;

	for(int x=0;x<6;x++)
	   for(i=0;i<5;i++)
	      for(j=0;j<9;j++)
			 if(T2[x].ttt[i][j]==101)
				T2[x].free++;

	for(int x=0;x<6;x++)
	   for(i=0;i<5;i++)
	      for(j=0;j<9;j++)
	       	 if(T2[x].free<17)
				if(T2[x].ttt[i][j]==100)
		 		{
				 	T2[x].ttt[i][j]=101;
					T2[x].free++;
				}


	//Fixing extra periods

	for(int w=0;w<8;w++)
	{
		int cnt=0;
		for(i=0;i<5;i++)
		{
			for(j=0;j<9;j++)
			{
				switch(cl[w].ctt[i][j])
				{case 6:cnt++;}
				if(cnt==3)
				{cl[w].ctt[i][j]=7;
				 break;}
			}
			if(cnt==3)
				 break;
		}
		if(cnt==3)
			   break;
	}

	ttchoice();

}//time table


void ttchoice()
{
	int choice,tt;
	system("cls");
	cout<<"\nWhich would you like to view?"<<endl;
	cout<<"\n1. Time Tables of classes";
	cout<<"\n2. Time Tables of teachers";
	cout<<"\n3. Exit";
	cout<<"\n\nEnter your choice\t\t";

	cin>>choice;

	system("cls");
	if(choice==1)
	{
		cout<<"\nWhich class time table would you like to view?"<<endl;
		cout<<"\n1.11 A";
		cout<<"\n2.11 B";
		cout<<"\n3.11 C";
		cout<<"\n4.11 D";
		cout<<"\n5.12 A";
		cout<<"\n6.12 B";
		cout<<"\n7.12 C";
		cout<<"\n8.12 D";
		cout<<"\n\nPress 0 to go back to menu";
		cout<<"\n\nEnter your choice\t\t";
		cin>>tt;

		switch(tt)
		{
			case 1: viewcl(cl[0].ctt,T1);
					break;
			case 2: viewcl(cl[1].ctt,T1);
					break;
			case 3: viewcl(cl[2].ctt,T1);
					break;
			case 4: viewcl(cl[3].ctt,T1);
					break;
			case 5: viewcl(cl[4].ctt,T2);
					break;
			case 6: viewcl(cl[5].ctt,T2);
					break;
			case 7: viewcl(cl[6].ctt,T2);
					break;
			case 8: viewcl(cl[7].ctt,T2);
					break;
			//case 0: mainmenu();

		}

		system("cls");
		char ch;
		cout<<"\nDo you want to go back(y/n)?\t\t";
		cin>>ch;
		if(ch=='y')
			ttchoice();
		else
			exit(0);
	}

	else if(choice==2)
	{
		cout<<"\nWhich teacher's time table would you like to view?"<<endl;
		cout<<"\n1.Mrs Rubeena";
		cout<<"\n2.Mr Saji";
		cout<<"\n3.Mrs Preethi";
		cout<<"\n4.Mrs Nandini";
		cout<<"\n5.Mr Saijan";
		cout<<"\n6.Mr Maqsood";
		cout<<"\n7.Mr Udupa";
		cout<<"\n8.Mrs Susan";
		cout<<"\n9.Mr Zaffer ";
		cout<<"\n10.Mrs Lekshmi ";
		cout<<"\n11.Mrs Latha";
		cout<<"\n12.Mr Moidheen  ";
		cout<<"\n\nPress 0 to go back to menu";
		cout<<"\n\nEnter your choice\t\t";
		cin>>tt;

		switch(tt)
		{
			case 1: viewtt(T1[0].ttt,T1[0]);
					break;
			case 2: viewtt(T1[1].ttt,T1[1]);
					break;
			case 3: viewtt(T1[2].ttt,T1[2]);
					break;
			case 4: viewtt(T1[3].ttt,T1[3]);
					break;
			case 5: viewtt(T1[4].ttt,T1[4]);
					break;
			case 6: viewtt(T1[5].ttt,T1[5]);
					break;
			case 7: viewtt(T2[0].ttt,T2[0]);
					break;
			case 8: viewtt(T2[1].ttt,T2[1]);
					break;
			case 9: viewtt(T2[2].ttt,T2[2]);
					break;
			case 10:viewtt(T2[3].ttt,T2[3]);
					break;
			case 11: viewtt(T2[4].ttt,T2[4]);
					break;
			case 12: viewtt(T2[5].ttt,T2[5]);
					break;
			//case 0: mainmenu();

		}
	}
	else if(choice==3)
	{
		char ch;
		cout<<"\n Do you want to go back to the menu?(y/n)\t";
		cin>>ch;
		system("cls");
		if(ch=='y')
			mainmenu();
		else
			exit(0);

	}

	system("cls");
	char ch;
	cout<<"\nDo you want to go back(y/n)?\t\t";
	cin>>ch;
	if(ch=='y')
		ttchoice();
	else
		exit(0);
};//ttchoice



void viewcl(int a[5][9],teacher te[6])
{
   int k,y,m,l,z,x;
   setbkcolor(0);

   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\x86_64-w64-mingw32\\include\\");

   setcolor(14);  //Line color

   line(0,0,0,405);     //left border
   line(0,0,1100,0);	    //top border
   line(1100,0,1100,405); //right border
   line(0,405,1100,405); //bottom border

   for(int i=64;i<1200;i+=115)  //vertical lines
       line(i,0,i,405);

   for(int j=55;j<450;j+=70)  //horizontal lines
       line(0,j,1100,j);

   line(0,0,64,55);  //Diagonal in first cell

   settextstyle(2,HORIZ_DIR,5);
   setcolor(10);
   outtextxy(25,5,"Period");
   outtextxy(5,30,"Days");

   //Printing period numbers
   settextstyle(8,HORIZ_DIR,4);
   setcolor(9);
   outtextxy(113,10,"1");
   outtextxy(227,10,"2");
   outtextxy(342,10,"3");
   outtextxy(455,10,"4");
   outtextxy(573,10,"5");
   outtextxy(685,10,"6");
   outtextxy(800,10,"7");
   outtextxy(915,10,"8");
   outtextxy(1030,10,"9");

   //Printing days numbers
   settextstyle(8,HORIZ_DIR,3);
   setcolor(9);
   outtextxy(5,78,"Sun");
   outtextxy(5,148,"Mon");
   outtextxy(5,218,"Tue");
   outtextxy(5,288,"Wed");
   outtextxy(5,358,"Thu");


   settextstyle(8,HORIZ_DIR,2);
   setcolor(7);

   for( k=0,y=80;k<5;k++,y+=70)
   {

 	for( m=0,x=70;m<9;m++,x+=115)
		{

			switch(a[k][m])
			{
				case 0  : outtextxy(x,y,"Math"); break;
				case 1  : outtextxy(x,y,"Physics");  break;
				case 2  : outtextxy(x,y,"Chemistry");  break;
				case 3  : outtextxy(x,y,"Comp Sc"); break;
				case 4  : outtextxy(x,y,"English"); break;
				case 5  : outtextxy(x,y,"Arabic"); break;
				case 6  : outtextxy(x,y,"GK/PT"); break;
				case 7  : outtextxy(x,y,"GK/PT"); break;
				case 9  : outtextxy(x+11,y-13,"Physics");
						  outtextxy(x,y+13,"Practical");
						  break;
				case 10 : outtextxy(x,y-13,"Chemistry");
						  outtextxy(x,y+13,"Practical");
						  break;
				case 11 : outtextxy(x+8,y-13,"Comp Sc");
						  outtextxy(x,y+13,"Practical");
						  break;
				case 100: outtextxy(x,y,"GK/PT");
						  break;
			}

		}

   }

   //Printing Subject Teachers
   settextstyle(4,HORIZ_DIR,3);
   setcolor(5);
   outtextxy(5,440,"Subject Teachers");

   settextstyle(8,HORIZ_DIR,2);
   setcolor(3);
   y=500;
   for(int i=0;i<6;i++,y+=30)
   {
		outtextxy(5,y,te[i].subject);
   		outtextxy(230,y,te[i].tname);
   }

   getch();
   closegraph();
};//viewcl


void viewtt(int a[5][9],teacher te)
{
   int k,y,m,l,z,x;
   setbkcolor(0);

   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\x86_64-w64-mingw32\\include\\");

   setcolor(14);  //Line color
   line(0,80,0,410);     //left border
   line(0,80,640,80);	    //top border
   line(640,80,640,410); //right border
   line(0,410,640,410); //bottom border

   for(int i=64;i<640;i+=64)  //vertical lines
       line(i,80,i,410);

   for(int j=135;j<440;j+=55)  //horizontal lines
       line(0,j,640,j);

   line(0,80,64,135);  //Diagonal in first cell

   settextstyle(2,HORIZ_DIR,5);
   setcolor(10);
   outtextxy(25,85,"Period");
   outtextxy(5,110,"Days");

   //Printing period numbers
   settextstyle(8,HORIZ_DIR,2);
   setcolor(9);
   outtextxy(93,98,"1");
   outtextxy(157,98,"2");
   outtextxy(221,98,"3");
   outtextxy(285,98,"4");
   outtextxy(349,98,"5");
   outtextxy(413,98,"6");
   outtextxy(477,98,"7");
   outtextxy(541,98,"8");
   outtextxy(605,98,"9");

   //Printing days numbers
   settextstyle(8,HORIZ_DIR,2);
   setcolor(9);
   outtextxy(5,152,"Sun");
   outtextxy(5,208,"Mon");
   outtextxy(5,262,"Tue");
   outtextxy(5,317,"Wed");
   outtextxy(5,375,"Thu");


   settextstyle(3,HORIZ_DIR,1);
   setcolor(7);

   for( k=0,y=152;k<5;k++,y+=55)
   {

 	 for( m=0,x=75;m<9;m++,x+=64)
		{
			switch(a[k][m])
			{
				case 0  : outtextxy(x,y,"11 A"); break;
				case 1  : outtextxy(x,y,"11 B");  break;
				case 2  : outtextxy(x,y,"11 C");  break;
				case 3  : outtextxy(x,y,"11 D"); break;
				case 4  : outtextxy(x,y,"12 A"); break;
				case 5  : outtextxy(x,y,"12 B"); break;
				case 6  : outtextxy(x,y,"12 C"); break;
				case 7  : outtextxy(x,y,"12 D"); break;
				case 101: outtextxy(x,y," "); break;
				case 100: outtextxy(x,y,"******"); break;
				default:  outtextxy(x,y," "); break;
			}

		}

   }

   //Printing Teacher info
   settextstyle(8,HORIZ_DIR,2);
   setcolor(12);

   outtextxy(5,5,"Code:");
   outtextxy(70,5,te.tno);

   settextstyle(9,HORIZ_DIR,2);
   setcolor(7);
   outtextxy(220,5,te.tname);


   settextstyle(8,HORIZ_DIR,2);
   setcolor(12);
   outtextxy(5,35,"Classes: ");

   settextstyle(3,HORIZ_DIR,1);
   for(int i=0;i<4;i++)
   {
   		switch(te.classes[i])
   		{
   			case 'a':outtextxy(110,33,"11 A,");
			   		 break;
			case 'b':outtextxy(160,35,"11 B,");
			   		 break;
			case 'c':outtextxy(210,35,"11 C,");
			   		 break;
			case 'd':outtextxy(260,35,"11 D");
			   		 break;
			case 'A':outtextxy(110,35,"12 A,");
			   		 break;
			case 'B':outtextxy(160,35,"12 B,");
			   		 break;
			case 'C':outtextxy(210,35,"12 C,");
			   		 break;
			case 'D':outtextxy(260,35,"12 D");
			   		 break;
		}
   }


   getch();
   /* clean up */
   closegraph();
};//viewtt


/*******************Movie Booking Functions*******************/

void moviemenu()
{
	int no,n,f=0;	//Main Menu option number
	char ans;
	do{
		cout<<"\nMenu"<<endl;
		cout<<"\n1. Book Tickets";
		cout<<"\n2. Delete a booking";
		cout<<"\n3. Show ticket details";
		cout<<"\n4. Now Showing";
		cout<<"\n5. Coming Soon";
		cout<<"\n6. Exit";
		cout<<"\n\nType Option Number\t";
		cin>>no;
		switch(no)
		{system("cls");
			case 1: book();
			  	    break;
			case 2: del();
			   	    break;
			case 3: system("cls");
					cout<<"\nEnter your ticket number to view other details\t";
					cin>>n;
					for(int i=0;i<20;i++)
						if(t[i].tno==n)
						{
							disp(i);
							f=1;
						}
					if(f==0)
						cout<<"\nInvalid ticket number"<<endl;
					break;
			case 4: nowshow();
			   	    break;
			case 5: coming();
			  	    break;
			case 6: cout<<"\nAre you sure(y/n)?\t";
				    cin>>ans;
				    if(ans=='y')
				       mainmenu();
				    else
				    { system("cls");
					  moviemenu();}
			default:system("cls");
					cout<<"Please choose a valid option"<<endl<<endl;

		}
	}while(no!=6);
};//moviemenu

void cineseats(int mno,int s)
{
	srand(time(0));
	setbkcolor(0);
	int i,j,k,x1,x2,y1,y2,x,y,style;

   // request auto detection
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy;

   // initialize graphics and local variables
   initgraph(&gdriver, &gmode, "C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\x86_64-w64-mingw32\\include\\");


   //Printing Seat Numbers
   settextstyle(9,HORIZ_DIR,2);
   setcolor(15);

   outtextxy(40,12,"1");
   outtextxy(75,12,"2");
   outtextxy(110,12,"3");
   outtextxy(145,12,"4");
   outtextxy(180,12,"5");
   outtextxy(215,12,"6");
   outtextxy(250,12,"7");
   outtextxy(285,12,"8");
   outtextxy(320,12,"9");
   outtextxy(345,12,"10");
   outtextxy(382,12,"11");
   outtextxy(417,12,"12");
   outtextxy(451,12,"13");
   outtextxy(486,12,"14");
   outtextxy(521,12,"15");
   outtextxy(556,12,"16");

   settextstyle(8,HORIZ_DIR,4);
   setcolor(15);

   outtextxy(7,40,"A");
   outtextxy(7,90,"B");
   outtextxy(7,140,"C");
   outtextxy(7,190,"D");
   outtextxy(7,240,"E");
   outtextxy(7,290,"F");
   outtextxy(7,340,"G");
   outtextxy(7,390,"H");

   settextstyle(3,HORIZ_DIR,4);
   setcolor(15);
   outtextxy(30,405,"_______________________________");
   outtextxy(30,432,"I");
   outtextxy(583,432,"I");
   settextstyle(7,HORIZ_DIR,4);
   outtextxy(235,439,"SCREEN");

   //Printing Seats
   i=mno-1;
   for(y1=40,j=0;j<8;j++)
   {
	   x1=35;
	   for(k=0;k<16;k++)
	   {
		   if(challs.h[i].hall[j][k]==0)
		     {
			    setfillstyle(SOLID_FILL, GREEN);
		        bar(x1,y1,x1+25,y1+35);
		     }

	   else if(challs.h[i].hall[j][k]==9)
		     {
			    setfillstyle(SOLID_FILL, BLACK);
		        bar(x1,y1,x1+25,y1+35);
		     }

	   else if(challs.h[i].hall[j][k]==1)
		     {
			    setfillstyle(SOLID_FILL, RED);
		        bar(x1,y1,x1+25,y1+35);
		     }

	   	   x1+=35;
	   }
	   y1+=50;
   }


   //Selecting seats to book
   while (!ismouseclick(WM_RBUTTONDOWN))
   {
		delay(100);
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if(x!=-1)
		{
			for(j=0;j<8;j++)
			{
				y1=40+(j*50);
				y2=75+(j*50);
				for(k=0;k<16;k++)
				{
					x1=35+(k*35);
					x2=60+(k*35);

					if((x>x1)&&(x<x2)&&(y>y1)&&(y<y2))
					{
						challs.h[i].hall[j][k]=2;
						t[s].sno.srow=j+65;
						t[s].sno.scol=k+1;
					}
				}
			}
		}
   }


  //Printing Seats after booking
  i=mno-1;
    for(y1=40,j=0;j<8;j++)
	   	{
		   x1=35;
		   for(k=0;k<16;k++)
		   {
			   if(challs.h[i].hall[j][k]==0)
			     {
				    setfillstyle(SOLID_FILL, GREEN);
			        bar(x1,y1,x1+25,y1+35);
			     }

		  else if(challs.h[i].hall[j][k]==1)
			     {
				    setfillstyle(SOLID_FILL, RED);
			        bar(x1,y1,x1+25,y1+35);
			     }

		  else if(challs.h[i].hall[j][k]==2)
			     {
				    setfillstyle(SOLID_FILL, BLUE);
			        bar(x1,y1,x1+25,y1+35);
		 		 }

		  else if(challs.h[i].hall[j][k]==9)
			     {
				    setfillstyle(SOLID_FILL, BLACK);
			        bar(x1,y1,x1+25,y1+35);
			     }

		   	   x1+=35;
		   }
		   y1+=50;
		}

   //Changing selected seats to booked
   for(j=0;j<8;j++)
   	   for(k=0;k<16;k++)
   		   if(challs.h[i].hall[j][k]==2)
   		   		challs.h[i].hall[j][k]=1;

   //clean up
   closegraph();
};//cineseats



void book()
{
	int mno,cno,tim,seats,card;     //Movie Number, Cinema Number, Time Number,Number of Seats, Credit Card Option
	char email[30],cardno[25];
	int numseats;

	system("cls");
	cout<<"\nChoose a movie"<<endl;
	cout<<"\n1. G 		Into the Woods";
	cout<<"\n2. G		Paddington";
	cout<<"\n3. PG-13 	Night at the Museum: Secret of the Tomb";
	cout<<"\n4. PG-13	The Woman in Black 2: Angel of Death";
	cout<<"\n5. PG-13	Taken 3";
	cout<<"\n6. PG-13	Unbroken";
	cout<<"\n7. PG-15	The Hobbit: The Battle of the Five Armies";
	cout<<"\n8. PG-15	Foxcatcher";
	cout<<"\n9. PG-15	A Most Violent Year";
	cout<<"\n10.R		The Interview";
	cout<<"\n11.R  		Inherent Vice";
	cout<<"\n12.R		The Gambler";
	cout<<"\n13.R		The Pyramid";
	cout<<"\n\nWhich movie would you like to watch?\t";
	cin>>mno;

	system("cls");
	cout<<"\nChoose the cinema"<<endl;
	cout<<"\n1.Cine Royal, Khalidiyah";
	cout<<"\n2.Cine Royal, Dalma     ";
	cout<<"\n3.Cine Royal, Ruwais    ";
	cout<<"\n\nWhich cinema would you like to go to?\t";
	cin>>cno;

	system("cls");
	cout<<"\nChoose the time"<<endl;
	cout<<"\n1. 10:00 am";
	cout<<"\n2. 01:30 pm";
	cout<<"\n3. 05:00 pm";
	cout<<"\n4. 08:30 pm";
	cout<<"\n\nWhich show timing would you like to go to?\t";
	cin>>tim;

	system("cls");
	cout<<"\nHow many seats would you like to book?\t";
	cin>>seats;


	system("cls");

	numseats=p+seats;

	for(;p<numseats;p++)
	{
		t[p].tno=tick++;	//Assigning ticket number to tickets

		switch(mno)		   //Assigning Movie name and Hall Number to tickets
			{
				case 1: strcpy(t[p].movie,"G 	Into the Woods                         	 ");
						  t[p].hall=1;
						  break;
				case 2: strcpy(t[p].movie,"G	Paddington				 ");
					  	  t[p].hall=2;
						  break;
				case 3: strcpy(t[p].movie,"PG-13 Night at the Museum: Secret of the Tomb   ");
						  t[p].hall=3;
						  break;
				case 4: strcpy(t[p].movie,"PG-13	The Woman in Black 2: Angel of Death     ");
						  t[p].hall=4;
						  break;
				case 5: strcpy(t[p].movie,"PG-13	Taken 3					 ");
						  t[p].hall=5;
						  break;
				case 6: strcpy(t[p].movie,"PG-13	Unbroken                                 ");
						  t[p].hall=6;
						  break;
				case 7: strcpy(t[p].movie,"PG-15	The Hobbit: The Battle of the Five Armies");
						  t[p].hall=7;
						  break;
				case 8: strcpy(t[p].movie,"PG-15	Foxcatcher				 ");
						  t[p].hall=8;
						  break;
				case 9: strcpy(t[p].movie,"PG-15	A Most Violent Year			 ");
						  t[p].hall=9;
						  break;
				case 10:strcpy(t[p].movie,"R	The Interview				 ");
						  t[p].hall=10;
						  break;
				case 11:strcpy(t[p].movie,"R  	Inherent Vice				 ");
						  t[p].hall=11;
						  break;
				case 12:strcpy(t[p].movie,"R	The Gambler				 ");
						  t[p].hall=12;
						  break;
				case 13:strcpy(t[p].movie,"R	The Pyramid				 ");
						  t[p].hall=13;
						  break;
			}

		switch(cno)		//Assigning cinema name to tickets
			{
				case 1: strcpy(t[p].cinema,"Cine Royal, Khalidiyah");
						  break;
				case 2: strcpy(t[p].cinema,"Cine Royal, Dalma     ");
						  break;
				case 3: strcpy(t[p].cinema,"Cine Royal, Ruwais    ");
						  break;
			}

		//Assigning date to tickets
		t[p].d.dd=10;
		t[p].d.mm=1;
		t[p].d.yy=2015;

		switch(tim)		//Assigning movie timing to tickets
			{
				case 1: t[p].t.hh=10;
						  t[p].t.mm=0;
						  strcpy(t[p].t.ap,"am");
						  break;
				case 2: t[p].t.hh=1;
						  t[p].t.mm=3;
						  strcpy(t[p].t.ap,"pm");
						  break;
				case 3: t[p].t.hh=5;
						  t[p].t.mm=0;
						  strcpy(t[p].t.ap,"pm");
						  break;
				case 4: t[p].t.hh=8;
						  t[p].t.mm=3;
						  strcpy(t[p].t.ap,"pm");
						  break;
			}


		cineseats(mno,p);	//Selecting Seats


		//Showing ticket
		cout<<"\n\nHere are your ticket details"<<endl;
		cout<<"\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
		cout<<"\n* Ticket Number: "<<t[p].tno<<"     				  *";
		cout<<"\n* Movie: "<<t[p].movie<<" *";
		cout<<"\n* Cinema name: "<<t[p].cinema<<"			  *";
		cout<<"\n* Date of screening: "<<t[p].d.dd<<"/0"<<t[p].d.mm<<"/"<<t[p].d.yy<<"				  *";
		if(strcmpi(t[p].t.ap,"am")==0)
			cout<<"\n* Time of screening: "<<t[p].t.hh<<":"<<t[p].t.mm<<"0"<<t[p].t.ap<<"				  *";
		else
			cout<<"\n* Time of screening: 0"<<t[p].t.hh<<":"<<t[p].t.mm<<"0"<<t[p].t.ap<<"               	  	  *";
		cout<<"\n* Hall number: "<<t[p].hall<<"					  *";
		cout<<"\n* Seat number: "<<t[p].sno.srow<<t[p].sno.scol<<"				          *";
		cout<<"\n* Cost: AED 35						  *";
		cout<<"\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

	}

	cout<<"\n\nTotal Cost = 35x"<<seats<<" = AED"<<35*seats;

	//Getting customer email address
	cout<<"\n\nPlease enter your email address\t\t";
	cin>>email;

	//Getting customer credit card info
	system("cls");
	cout<<"\nChoose your card"<<endl;
	cout<<"\n1. Visa";
	cout<<"\n2. Mastercard";
	cout<<"\n\nWhich credit card would you like to use?\t";
	cin>>card;
	cout<<"\nEnter your credit card number\t\t";
	cin>>cardno;


	p-=seats;
	for(;p<numseats;p++)
	{
		strcpy(t[p].email,email);
		strcpy(t[p].cardno,cardno);
	}


	system("cls");
	cout<<"\nCongratulations! Your purchase has been successful.";
	cout<<"\nPlease check your email for the tickets.";

	//Returning to menu
	char ch;
	cout<<"\n\nDo you want to go back to the menu?(y/n)\t";
	cin>>ch;
	system("cls");
	if(ch=='y')
		moviemenu();
	else
		exit(0);
};//book



void del()
{
	system("cls");
	int n;
	char email[30],cardno[25];
	int found=0;
	cout<<"\nEnter your ticket number\t\t";
	cin>>n;
	for(int i=0;i<30;i++)
		if(t[i].tno==n)
		{
			found=1;
			cout<<"\nEnter your email address\t\t";
			cin>>email;
			cout<<"\nEnter your credit card number\t\t";
			cin>>cardno;
			break;
		}
	if(found==0)
	{
		cout<<"\n\nInvalid ticket Number";
		char ch;
		cout<<"\n\nDo you want to go back to the menu?(y/n)\t";
		cin>>ch;
		system("cls");
		if(ch=='y')
			moviemenu();
		else
			exit(0);
	}

	int f=1;
	for(int i=0;i<5;i++)
		if((t[i].tno==n)&&(strcmp(t[i].email,email)==0)&&(strcmpi(t[i].cardno,cardno)==0))
			{
				f=0;
				t[i]={0};
				system("cls");
				cout<<"\nYour ticket has been successfully deleted and you have been refunded";
			}
	if(f)
		cout<<"\n\nWrong email ID or card number entered";


	//Returning to menu
	char ch;
	cout<<"\n\nDo you want to go back to the menu?(y/n)\t";
	cin>>ch;
	system("cls");
	if(ch=='y')
		moviemenu();
	else
		exit(0);
};//del


void disp(int i)
{

	cout<<"\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	cout<<"\n* Ticket Number: "<<t[i].tno<<"     				  *";
	cout<<"\n* Movie: "<<t[i].movie<<" *";
	cout<<"\n* Cinema name: "<<t[i].cinema<<"			  *";
	cout<<"\n* Date of screening: "<<t[i].d.dd<<"/0"<<t[i].d.mm<<"/"<<t[i].d.yy<<"				  *";

	if(strcmpi(t[i].t.ap,"am")==0)
		cout<<"\n* Time of screening: "<<t[i].t.hh<<":"<<t[i].t.mm<<"0"<<t[i].t.ap<<"				  *";
	else
		cout<<"\n* Time of screening: 0"<<t[i].t.hh<<":"<<t[i].t.mm<<"0"<<t[i].t.ap<<"               	  	  *";

	cout<<"\n* Hall number: "<<t[i].hall<<"					  *";
	cout<<"\n* Seat number: "<<t[i].sno.srow<<t[i].sno.scol<<"				          *";
	cout<<"\n* Cost: AED 35						  *";
	cout<<"\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";


	//Returning to menu
	char ch;
	cout<<"\n\nDo you want to go back to the menu?(y/n)\t";
	cin>>ch;
	system("cls");
	if(ch=='y')
		moviemenu();
	else
		exit(0);
};//disp


void nowshow()
{
	system("cls");
	cout<<"\n Now Showing Movies in all Cine Royal Theatres across Abu Dhabi emirate"<<endl;
	cout<<"\n G 	Into the Woods";
	cout<<"\n G	Paddington";
	cout<<"\n PG-13 	Night at the Museum: Secret of the Tomb";
	cout<<"\n PG-13	The Woman in Black 2: Angel of Death";
	cout<<"\n PG-13	Taken 3";
	cout<<"\n PG-13	Unbroken";
	cout<<"\n PG-15	The Hobbit: The Battle of the Five Armies";
	cout<<"\n PG-15	Foxcatcher";
	cout<<"\n PG-15	A Most Violent Year";
	cout<<"\n R	The Interview";
	cout<<"\n R  	Inherent Vice";
	cout<<"\n R	The Gambler";
	cout<<"\n R	The Pyramid";

	//Returning to menu
	char ch;
	cout<<"\n\n Do you want to go back to the menu?(y/n)\t";
	cin>>ch;
	system("cls");
	if(ch=='y')
		moviemenu();
	else
		exit(0);
};//nowshow



void coming()
{
	system("cls");
	cout<<"\n Movies Coming Soon to Cine Royal Theatres"<<endl;
	cout<<"\n G 	The SpongeBob Movie: Sponge Out of Water";
	cout<<"\n G	Ballet 442";
	cout<<"\n PG-13  Still Alice";
	cout<<"\n PG-13	Spare Parts";
	cout<<"\n PG-13	The Lazarus Effect";
	cout<<"\n PG-15	Seventh Son";
	cout<<"\n R	The Wedding Ringer";
	cout<<"\n R	Blackhat";


	//Returning to menu
	char ch;
	cout<<"\n\n Do you want to go back to the menu?(y/n)\t";
	cin>>ch;
	system("cls");
	if(ch=='y')
		moviemenu();
	else
		exit(0);
};//coming

/**********************Game Functions**********************/

void gamemenu()
{
	int n;

	cout<<"\n1. Easy";
	cout<<"\n2. Normal";
	cout<<"\n3. Hard";
	cout<<"\nChoose a difficulty\t\t";
	cout<<"\n\nPress 0 to exit\n\n";
	cin>>n;

	switch(n)
	{
		case 1: diffi1();
				break;
		case 2: diffi2();
				break;
		case 3: diffi3();
				break;
		case 0: char op;
				cout<<"\n\nDo you want to go back to the menu?(y/n)\t";
				cin>>op;
				system("cls");
				if(op=='y')
					mainmenu();
				else
					exit(0);
				break;
		default:cout<<"\nInvalid Choice";
	}

};//gamemenu


void diffi1()	//easy
{
	system("cls");
	int ch=0;
	cout<<"Do you think you can beat the computer ? "<<endl;

	cout<<" 1. Rock "<<endl;
	cout<<" 2. Paper "<<endl;
	cout<<" 3. Scissors "<<endl;
	cout<<" Enter you choice : ";
	cin>>ch;

	int o,j=0,diff=0,winner=0;     //2-com wins,1-player wins,0-draw
    srand(time(0));

     o=rand()%4;

     if(o==0)
	 	j=rand()%3+1;
	 else
	 	switch(ch)
     	{
	       case 1:j=rand()%2;
		          if(j==0)    j=1;
		          else if(j==1)   j=3;
				  break;

	       case 2:j=rand()%2+1;
				  break;

	       case 3:j=rand()%2+2;
		   		  break;
		}

     switch(j)
     {
       case 1:cout<<"\n Computer chose:    Rock"<<endl;
	   		  if(ch==1)
				 winner=0;
	      	  if(ch==2)
			 	 winner=1;
	      	  if(ch==3)
				 winner=2;
	          break;

       case 2:cout<<"\n Computer chose:    Paper"<<endl;
	   		  if(ch==1)
				  winner=2;
	      	  if(ch==2)
				  winner=0;
	      	  if(ch==3)
				  winner=1;
	     	  break;

       case 3:cout<<"\nComputer chose:    Scissors"<<endl;
	   		  if(ch==1)
			  	 winner=1;
	      	  if(ch==2)
				 winner=2;
	     	  if(ch==3)
				 winner=0;
	      	  break;

      default:cout<<"\n Invalid choice";
     }

   switch(winner)
     {
      case 0:cout<<"\n It is a draw";
	     	 break;
      case 1:cout<<"\n You have won. Congratulations!!";
	    	 userpoint++;
	    	 break;
      case 2:cout<<"\n You lost to the computer. Better luck next time.";
	    	 compoint++;
	     	 break;
     }

    cout<<"\n\n The points are : ";
    cout<<"\n You      : "<<userpoint;
    cout<<"\n Computer : "<<compoint;
    if(compoint>userpoint)
     {
      	diff=compoint-userpoint;
      	cout<<"\n The computer leads by "<<diff<<" point(s)";
     }
    else if(userpoint>compoint)
     {
      	diff=userpoint-compoint;
      	cout<<"\n You lead by "<<diff<<" point(s)";
     }
    else
      cout<<"\n The scores are equal"<<endl;

    char opt;
    cout<<"\n\n Do you want to play again? (y/n) :  ";
	cin>>opt;
	if(opt=='y'||opt=='Y')
		diffi1();
	else
		mainmenu();
};//diffi1



void diffi2()	//normal
{
	system("cls");
	int ch=0;
	cout<<"Do you think you can beat the computer ? "<<endl;

	cout<<" 1. Rock "<<endl;
    cout<<" 2. Paper "<<endl;
	cout<<" 3. Scissors "<<endl;
	cout<<" Enter you choice : ";
	cin>>ch;

	int j,diff=0,winner=0;     //2-com wins,1-player wins,0-draw
    srand(time(0));

     j=rand()%3+1;

     switch(j)
     {
       case 1:cout<<"\n Computer chose:   Rock"<<endl;
	   		  if(ch==1)
				 winner=0;
	      	  if(ch==2)
			 	 winner=1;
	      	  if(ch==3)
				 winner=2;
	          break;

       case 2:cout<<"\n Computer chose:   Paper"<<endl;
	   		  if(ch==1)
				  winner=2;
	      	  if(ch==2)
				  winner=0;
	      	  if(ch==3)
				  winner=1;
	     	  break;

       case 3:cout<<"\nComputer chose:   Scissors"<<endl;
	   		  if(ch==1)
			  	 winner=1;
	      	  if(ch==2)
				 winner=2;
	     	  if(ch==3)
				 winner=0;
	      	  break;

      default:cout<<"\n Invalid choice";
     }

   switch(winner)
     {
      case 0:cout<<"\n It is a draw";
	     	 break;
      case 1:cout<<"\n You have won. Congratulations!!";
	    	 userpoint++;
	    	 break;
      case 2:cout<<"\n You lost to the computer. Better luck next time.";
	    	 compoint++;
	     	 break;
     }

    cout<<"\n\n The points are : ";
    cout<<"\n You      : "<<userpoint;
    cout<<"\n Computer : "<<compoint;
    if(compoint>userpoint)
     {
      	diff=compoint-userpoint;
      	cout<<"\n The computer leads by "<<diff<<" point(s)";
     }
    else if(userpoint>compoint)
     {
      	diff=userpoint-compoint;
      	cout<<"\n You lead by "<<diff<<" point(s)";
     }
    else
      cout<<"\n The scores are equal"<<endl;


	char opt;
    cout<<"\n\n Do you want to play again? (y/n) :  ";
	cin>>opt;
	if(opt=='y'||opt=='Y')
		diffi1();
	else
		mainmenu();
};//diffi2



void diffi3()	//hard
{
	system("cls");
	int ch=0;
	cout<<"Do you think you can beat the computer ?"<<endl;

	cout<<" 1. Rock "<<endl;
	cout<<" 2. Paper "<<endl;
	cout<<" 3. Scissors "<<endl;
	cout<<" Enter you choice : ";
	cin>>ch;

	int o,j,diff=0,winner=0;     //2-com wins,1-player wins,0-draw
    srand(time(0));

     o=rand()%25;

     if(o==0)
	 	j=rand()%3+1;
	 else
	 	switch(ch)
     	{
	       case 1:j=rand()%2+1;
		          break;

	       case 2:j=rand()%2+2;
				  break;

	       case 3:j=rand()%2;
		          if(j==0)   j=1;
		          else    j=3;
		   		  break;
		}

     switch(j)
     {
       case 1:cout<<"\n Computer chose:    Rock"<<endl;
	   		  if(ch==1)
				 winner=0;
	      	  if(ch==2)
			 	 winner=1;
	      	  if(ch==3)
				 winner=2;
	          break;

       case 2:cout<<"\n Computer chose:    Paper"<<endl;
	   		  if(ch==1)
				  winner=2;
	      	  if(ch==2)
				  winner=0;
	      	  if(ch==3)
				  winner=1;
	     	  break;

       case 3:cout<<"\nComputer chose:    Scissors"<<endl;
	   		  if(ch==1)
			  	 winner=1;
	      	  if(ch==2)
				 winner=2;
	     	  if(ch==3)
				 winner=0;
	      	  break;

      default:cout<<"\n Invalid choice";
     }

   switch(winner)
     {
      case 0:cout<<"\n It is a draw";
	     	 break;
      case 1:cout<<"\n You have won. Congratulations!!";
	    	 userpoint++;
	    	 break;
      case 2:cout<<"\n You lost to the computer. Better luck next time.";
	    	 compoint++;
	     	 break;
     }

    cout<<"\n\n The points are : ";
    cout<<"\n You      : "<<userpoint;
    cout<<"\n Computer : "<<compoint;
    if(compoint>userpoint)
     {
      	diff=compoint-userpoint;
      	cout<<"\n The computer leads by "<<diff<<" point(s)";
     }
    else if(userpoint>compoint)
     {
      	diff=userpoint-compoint;
      	cout<<"\n You lead by "<<diff<<" point(s)";
     }
    else
      cout<<"\n The scores are equal"<<endl;

    char opt;
    cout<<"\n\n Do you want to play again? (y/n) :  ";
	cin>>opt;
	if(opt=='y'||opt=='Y')
		diffi1();
	else
		mainmenu();
};//diffi3

/****************************************************************************Bank Functions****************************************************************************/

void bankmenu()
{
	 system("cls");
	 int ch;
	 b[0].custid=101;
	 strcpy(b[0].custname,"naveen");
	 strcpy(b[0].username,"nav98");
	 strcpy(b[0].password,"1234");
	 b[0].balance=75000;

	 b[1].custid=102;
	 strcpy(b[1].custname,"amrut");
	 strcpy(b[1].username,"amr98");
	 strcpy(b[1].password,"1234");
	 b[1].balance=75001;

	 b[2].custid=103;
	 strcpy(b[2].custname,"akhil");
	 strcpy(b[2].username,"akh98");
	 strcpy(b[2].password,"1234");
	 b[2].balance=75002;

	  r=3;

	  cout<<"\n Welcome to Bank of Star Labs ";
	  do
	  {
		  cout<<"\n \n 1. Customer Login ";
		  cout<<"\n 2. Sign Up (Existing customer) ";
		  cout<<"\n 3. Staff login ";
		  cout<<"\n 4. Exit ";
		  cout<<"\n \n Please enter your choice ";
		  cin>>ch;

		  switch(ch)
		  {
		   case 1 : system("cls" ); existcust(); break;
		   case 2 : system("cls");  newcustlogin(); break;
		   case 3 : system("cls");  managerpass(); break;
		   case 4 :	mainmenu();
		  }
	  }while(ch!=4);
}

void managerpass()
{
	int ch;
	char usrname[10],pass[10],c[6];
	manager.staffid=100;
	strcpy(manager.staffname,"Ram");
	strcpy(manager.username,"bkram");
	strcpy(manager.password,"compbk");

	cout<<"\n Welcome manager ";
	cout<<"\n Please login to continue ";
	cout<<"\n \n \t Username : ";
	cin>>usrname;

	cout<<"\n \t Password : ";
	cin>>pass;



    //	if(strcmpi(pass,manager.password)==0)
    //	{
		system("cls");
		do
		{
		cout<<"\n Welcome Mr. Ram  ";
		cout<<"\n\n\n ";
		cout<<"\n 1. Searching for customer ";
		cout<<"\n 2. Display all customer information ";
		cout<<"\n 3. Display customers whose bank balance is above 100000";
		cout<<"\n 4. New customer ";
		cout<<"\n 5. Exit ";
		cout<<"\n\n\n Please enter your choice ";

		cin>>ch;
		system("cls");
		switch(ch)
		{  case 1 : search(); break;
		   case 2 : display(); break;
		   case 3 : openbal10000(); break;
		   case 4 : newcust(); break;
		   case 5 : char op;
		   		    cout<<"\n\n\n Do you want to go back to the menu?(y/n)\t";
					cin>>op;
					system("cls");
					if(op=='y')
						mainmenu();
					else
						exit(0);
					break;
		}
		}while(ch!=5);
    //	}
}

void search()
{
	char name[20]; int count=0;
	cout<<"\n Enter the customer's name to be searched for ";
	cin>>name;
	for(int q=0;q<r;q++)
		if(strcmpi(b[q].custname,name)==0)
		{
			cout<<"\n"<<name<<" \'s details are as follows ";
			cout<<"\n Customer name  : "<<b[q].custname;
			cout<<"\n Cust id        : "<<b[q].custid;
			cout<<"\n Opening balance: "<<b[q].balance;
			count++;
		}
		if(count==0)
			cout<<"\n There is no customer by the name you have entered ";
	char simp;
	cout<<"\n\n\n Press m to go to menu ";
	cin>>simp;
	if(simp=='m')
	system("cls");
}

void display()
{
	for(int q=0;q<r;q++)
	{
		cout<<"\n The details of customer "<<q+1<<" are as follows ";
		cout<<"\n Customer name  : "<<b[q].custname;
		cout<<"\n Cust id        : "<<b[q].custid;
		cout<<"\n Opening balance: "<<b[q].balance;
	}
	char simp;
	cout<<"\n\n\n Press m to go to menu ";
	cin>>simp;
	if(simp=='m')
	system("cls");
}

//display openbal>10000
void openbal10000()
{
	int count=0;
	for(int q=0;q<r;q++)
		if(b[q].balance>10000)
		{
			cout<<"\n Customer name  : "<<b[q].custname;
			cout<<"\n Cust id        : "<<b[q].custid;
			cout<<"\n Opening balance: "<<b[q].balance;
			count++;
		}
	if (count==0)
		cout<<"\n There are no customers whose opening balance is > 10000 ";
	char simp;
	cout<<"\n\n\n Press m to go to menu ";
	cin>>simp;
	if(simp=='m')
	system("cls");
}

void newcust()
{
	cout<<"\n Please enter the details of the new customer ";
	r=r+1;
	cout<<"\n Customer  ID    :  "; cin>>b[r].custid;
	cout<<"\n Name            :  "; cin>>b[r].custname;
	cout<<"\n Opening Balance :  "; cin>>b[r].balance;

	cout<<"\n Details have been succesfully recorder ";
	char simp;
	cout<<"\n\n\n Press m to go to menu ";
	cin>>simp;
	if(simp=='m')
	system("cls");
}


void existcust()
{
	int ch;
	char  usrname[10],pass[10];
	cout<<"\n Welcome customer ";
	cout<<"\n Please login to continue ";
	cout<<"\n \n \t Username : ";
	cin>>usrname;
	cout<<"\n \t Pin : ";
	for(q=0;q<4;q++)
		cin>>pass[q];

	for(q=0;q<r;q++)
		if (strcmpi(usrname,b[q].username)==0)
						break;
	    //	if(strcmpi(pass,b[q].password)==0)
	      //		 {
				do
				{
			     system("cls");
				 cout<<"\n Welcome "<<b[q].custname;
				 cout<<"\n\n\n";
				 cout<<"\n 1. Withdraw ";
				 cout<<"\n 2. Deposit ";
				 cout<<"\n 3. Apply for loan ";
				 cout<<"\n 4. Return to main menu ";

				 cout<<"\n Please enter your choice ";
				 cin>>ch;
				 system("cls");
				switch(ch)
				{
					case 1 : withdraw(); break;
					case 2 : deposit(); break;
					case 3 : loan(); break;

				}
				}while(ch!=4);
		//	 }
		}


void withdraw()
{
	int id,found=1,cash,retry=0;
	do
	{
		cout<<"\n Enter your customer id ";
		cin>>id;
		for(int q=0;q<r;q++)
			if(b[q].custid==id)
			{
				found=0;
				break;
			}
		if(found==0)
		{
			cout<<"\n Welcome "<<b[q].custname;
			cout<<"\n You have a balance of "<<b[q].balance;
			cout<<"\n Please enter the amount you want to withdraw ";
			cin>>cash;
			if(b[q].balance-cash>1000)
			{
				b[q].balance-=cash;
				cout<<"\n Transaction complete ";
				cout<<"\n Your new balance is "<<b[q].balance;
			}
			else
				cout<<"\n You cannot complete this transaction ";
		}
		else
		{
			retry++;
			if(retry==4)
			{
				system("cls");
				found=0;
				break;
			}
			cout<<"\n Invalid cust id ";
			cout<<"\n Please retry ";
			system("cls");
		}
	}while(found==1);
	char simp;
	cout<<"\n\n\n Press m to go to menu ";
	cin>>simp;
	if(simp=='m')
	system("cls");
}

//Deposit
void deposit()
{
	int id,found=1,cash,retry=0;
	do
	{

		cout<<"\n Enter your customer id ";
		cin>>id;
		for(int q=0;q<r;q++)
			if(b[q].custid==id)
			{
				found=0;
				break;
			}
		if(found==0)
		{
			cout<<"\n Welcome "<<b[q].custname;
			cout<<"\n You have a balance of "<<b[q].balance;
			cout<<"\n Please enter the amount you want to deposit ";
			cin>>cash;
			b[q].balance+=cash;
			cout<<"\n Transaction complete ";
			cout<<"\n Your new balance is "<<b[q].balance;
		}
		else
		{
			retry++;
			if(retry==4)
			{
				system("cls");
				found=0;
				break;
			}
			cout<<"\n Invalid cust id ";
			cout<<"\n Please retry ";
			system("cls");
		}
	}while(found==1);
	char simp;
	cout<<"\n\n\n Press m to go to menu ";
	cin>>simp;
	if(simp=='m')
	system("cls");
}

//Loan Application
void loan()
{
	float a,p,r,t1;
	cout<<"\n Worried about how to meet all the expenses coming up at once?  ";
	cout<<"\n Major surgical operation, repairing of old house, ";
	cout<<"\n passage money fr son’s education. ";
	cout<<"\n You can now heave a sigh of relief. ";
	cout<<"\n Our Personal loan Scheme has been designed just to meet such eventualities. ";
	cout<<"\n Our interest rates go at just between 10-15% ";
	cout<<"\n Please visit our nearest branch or fill the following details for more information ";

	cout<<"\n Enter the principal amount (in Rs.)  ";
	cin>>p;
	if(p<=500000)
		r=12;
	else
		r=10.5;
	cout<<" Enter the time for repayment (in years)";
	cin>>t1;

	a=p*pow((1+(r/100)),t1);

	cout<<"\n The amount you will have to repay per year is : "<<a/t1;
	cout<<"\n The amount you will have to repay per month is : "<<a/t1/12;

	char op;
	if(b[q].balance>50000)
	{ cout<<"\n Do you want to apply for a loan (Y/N) ";
	  cin>>op;
	  if((op=='y')||(op=='Y'))
	  {
		cout<<"\n Your request has been submited ";
		cout<<"\n Please take the following documentation and visit your home branch for further formalities ";
		cout<<"\n Proof of identity: Copy of passport/voter ID card/driving license ";
		cout<<"\n Proof of address: Copy of ration card/telephone or electricity bill/rental agreement/passport ";
		cout<<"\n Last 3 months bank statement/6 months bank passbook ";
		cout<<"\n Latest salary slip/ current dated salary certificate with the latest Form 16 ";
	  }
	}
	char simp;
	cout<<"\n\n\n Press m to go to menu ";
	cin>>simp;
	if(simp=='m')
	system("cls");
}

void newcustlogin()
{
	int cusid; char name[20],pass[15];;
	cout<<"\n Welcome to our net banking facility ";
	cout<<"\n Dear existing customer please provide the following details to initialize the setup for your net banking account ";
	cout<<"\n Customer  ID    :  "; cin>>cusid;
	cout<<"\n Name            :  "; cin>>name;
	for(q=0;q<r;q++)
		if(b[q].custid==cusid)
			break;
	if(strcmpi(b[q].custname,name)==0)
	{
		cout<<"\n Please fill out the following ";
		cout<<"\n Username        : "; cin>>b[q].username;
		cout<<"\n Password        : "; cin>>b[q].password;
		cout<<"\n Retype Password : "; cin>>pass;
		if(strcmp(b[q].password,pass)==0)
		{
			cout<<"\n Your request has been submitted ";
			cout<<"\n To continue please click the link that has been sent to your email id ";
		}
	}
	char simp;
	cout<<"\n\n\n Press m to go to menu ";
	cin>>simp;
	if(simp=='m')
	system("cls");
}

//End of Banking Functions



