#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <fstream>
using namespace std;


int m,*p,sn,arg,arg2,tkt,tkt_pr,cost=0,ext,nt=0,sti;//sn is variable for show number in manager function N m is for number of shows in a day
//sti is for showtime input in manager func
//st is for showtime check the seat_disp func
//tkt is to count the no.of tickets to be booked by customer
//tkt_pr is to print the no.of tickets to be booked
//nt is the number of timings of a particular movie
string name,tkt_pnt,pass;//pass is to save the password
//tkt_pnt[100] to print the movie name in ticket
int ar[20][100][12][18],tkt_row[12],tkt_col[18],str_tim[100];//last two array r to be used to print ticket
//str_tim is saving the no.of show of a particular movie
/*in the array ar
1st arg is for movie no.
2nd arg is for particular showtime of particular movie
3rd arg is for rows
4th arg is for columns*/
string tim[100][100];
/*ITS THE string array to store the timings of a particular movie
1st argument is for movie number and and argument is for no.timings that
particular runs*/

void show()//this function is for entering the number of movie running in hall
{
    ofstream fout;  // Create Object of Ofstream
    ifstream fin;
    int i,j;
    p=(int*)(malloc(sizeof(int)));
    cout<<"\n\n\t\t\t\t\t\t\tENTER THE NUMBER MOVIES RUNNING IN THE HALL\n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>m;
    (*p)=m;
for(i=0;i<m;i++)//m is the total no of movies running in that hall
{   fflush(stdin);
    fin.open("shows.txt");
    fout.open ("shows.txt",ios::app);
    if(fout.is_open())
    {
     cout<<"\n\n\t\t\t\t\t\t\tENTER THE NAME OF MOVIE "<<i+1<<endl;
     cout<<"\t\t\t\t\t\t\t";
     cin>>name;
     fout<<i+1<<"."<<"\t"<<name<<"\t\t\t\t\t\t\t\t";
     cout<<"\n\n\t\t\t\t\t\t\tENTER THE NUMBER OF SHOWS OF MOVIE: "<<name<<" IN A DAY : ";
     cin>>nt;
     str_tim[i]=nt;
     //here a function is to be added to save the show timings
     cout<<"\n\n\t\t\t\t\t\t\tENTER THE SHOW TIMINGS OF THE MOVIE : "<<name<<endl;
     for(j=0;j<nt;j++)
     {   fflush(stdin);
         cout<<"\t\t\t\t\t\t\t";
         cin>>tim[i][j];
         fout<<tim[i][j]<<"  ";
         // this is the function for collecting the show timings

     }
     fout<<endl;

    }
     fin.close();
     fout.close();
}
ofstream file;
system("cls");//after the input is being over the screen is cleared and data is displayed
cout<<"\n\n\t\t\t\t\t\t\tTHE MOVIES RUNNING IN HALL ARE:\n";
for(i=0;i<m;i++)
{
    ifstream file;
    char ch;
    system("cls");
    while(1){
        file.open("shows.txt");
        while(!file.eof()){
            file.get(ch);
            cout<<ch;
           }
        file.close();
        break;
}
}
}



void seatdisp(int z,int wt)
//1st argument to display the seats of that particular movie
//2nd arg is for the particular movie time
{
    arg=z;
    sti=wt;
    int i,j;
    char ch='A',st;
    system("cls");
    cout<<"\n\nCOST OF RECTILINEAR:Rs 500/-\n";
      cout<<"COST OF SUPER DELUXE :Rs 200/-\n";
    cout<<"COST OF  DELUXE :Rs 100/-\n";

   cout<<"\n\n\t\t\t\t\t\t\tBOOKED SEATS ARE MARKED WITH [x]\n\n";
   cout<<"\n\n\t\t\t\t\t\t\tTHIS IS THE SEAT MATRIX FOR MOVIE: "<<name[arg-1]<<"\n\n";
    for(i=0;i<13;i++)
    {
        ch='A';
        ch=ch+i;
        cout<<"\t";
     for(j=0;j<18;j++)
        {
            if(ar[arg][sti][i][j]==1)
            cout<<"["<<" X"<<"]";
            else
            {
                cout<<"["<<ch<<j+1<<"]";
            }

            cout<<" ";//1 white spaces given
                      //the seat would be displayed in format[A1]

            if(j==4||j==12)
                cout<<"\t";

        }
        cout<<"\n\n";
 if(i==12)
    {
        cout<<"\n\n\t\t\t\t\t\t SCREEN THIS WAY\n";
        cout<<"\t______________________________________________________________________________________________________________";
    }

    }

}




void book(int z,int wt ,int a)//first argument is for the movie number and 3rd argument for manager mode
//2nd arg is for show time
{int i,j,num,al,n,col,stor,arg;
arg=z;
sti=wt;
    arg2=a;
    if(arg2==100)
    {
      cout<<"\n\n\t\t\t\t\t\t\tADMIN ENTER THE SEATS WHICH WONT BE AVAILABLE FOR BOOKING\n";
    }

else
{
 cout<<"\n\n\t\t\t\t\t\t\tCUSTOMER BOOKING\n";

}

        seatdisp(arg,sti);
    char ch='A',chr;
    cout<<"\n\n\t\t\t\t\t\t\tENTER THE SEAT NUMBER\t";

        cin>>chr>>col;
        stor=chr-65;
        col=col-1;

        if(ar[arg][sti][stor][col]==0)
        {
            ar[arg][sti][stor][col]=1;

            tkt_col[tkt]=col;
            tkt_row[tkt]=stor;


        }
        else
        {

            while(ar[arg][sti][stor][col]!=0)
            {
                if(arg2==100)
                {
                  cout<<"\n\n\t\t\t\t\t\t\tADMIN YOU HAVE ALREADY MARKED THIS SEAT AS BOOKED ENTER A NEW SEAT WHICH IS BOOKED\n";
               cout<<"\t\t\t\t\t\t\t ";
                }

           else
           {
            cout<<"\n\n\t\t\t\t\t\t\tTHE SEAT YOU SELECTED IS ALREADY OCCUPIED ENTER A NEW SEAT\n";
            cout<<"\t\t\t\t\t\t\t ";
           }
                cin>>chr>>col;
                stor=chr-65;
                col=col-1;
            }
            ar[arg][sti][stor][col]=1;
           tkt_col[tkt]=col;
            tkt_row[tkt]=stor;
        }

}

void seatin(int z,int wt)//1st argument for the particular movie seat booking
//2nd arg is for particular show time of particular movie
{

     int n;
    arg=z;
    sti=wt;
    //cout<<"THE ARGUMENT IS nest="<<arg<<endl;
     cout<<"\n\n\t\t\t\t\t\t\tENTER THE NUMBER OF SEATS TO BE BOOKED"<<endl;
            cout<<"\t\t\t\t\t\t\t MOVIE NAME="<<name[arg-1]<<endl;
            cout<<"\t\t\t\t\t\t\t ";
    cin>>n;
    tkt_pr=n;
       for(tkt=0;tkt<n;tkt++)//loop for booking the desired no. of tickets as input by user
{
     book(arg,sti,20);
     cout<<"LOOP IS RUNNING\n";
       system("cls");
  seatdisp(arg,sti);

}

getch();
}




void manager()
{   char mov='c',in='c';
    show();
    while((mov=='c')||(mov=='C'))//this loop is for entering the seats that are booked for different movies
    {
        cout<<"\n\n\t\t\t\t\t\t\t ENTER THE SHOW NUMBER WHOSE SEATS U WANT TO ASSIGN FOR BOOKING\n";
        cout<<"\t\t\t\t\t\t\t";
    cin>>sn;
      cout<<"\n\n\t\t\t\t\t\t\t ENTER THE NUMBER CORRESPONDING TO THE TIME TO BOOK TICKET\n";
        cout<<"\t\t\t\t\t\t\t";
    cin>>sti;
    tkt_pnt=name[sn];

    while((in=='c')||(in=='C'))
    {
      book(sn,sti,100);
      system("cls");
      seatdisp(sn,sti);
    cout<<"\n\n\t\t\t\t\t\t\tPRESS 'C' or 'c' IF U WANT TO CONTINUE ENTERING THE BOOKED SEATS\n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>in;
    }

    cout<<"\n\n\t\t\t\t\t\t\tPRESS 'C' or 'c' IF U WANT TO CONTINUE ENTERING FOR OTHER MOVIES\n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>mov;
    in='c';
    }

}

void ticket_print()
{    int i,a=0,b=0,d=0;
    char c;

    for(i=0;i<tkt_pr;i++)//this loop is for printing the total cost of ticket
        {


             if(tkt_row[i]==0||tkt_row[i]==1)
            {
                cost=cost+500;
                a++;
            }
            else if(tkt_row[i]>1&&tkt_row[i]<7)
            {
                cost=cost+200;
                b++;
            }
            else{cost=cost+100;d++;}


        }
           cout<<"\n\n\n\t\t\tCOST : "<<endl;
           if(a!=0)
           cout<<"\t\t\t       "<<a<<" * 500"<<endl;
           if(b!=0)
           cout<<"\t\t\t      +"<<b<<" * 200"<<endl;
           if(c!=0)
           cout<<"\t\t\t      +"<<d<<" * 100"<<endl;
        cout<<"\n\n\n\n\t\t\tTHE TOTAL TICKET COST = Rs "<<cost<<"/-"<<endl;
        getch();

         system("cls");
    cout<<"\n\n\n\n\t\t\t________________________________________________________________________\n";
cout<<"\t\t\t|                                                                       |\n";
cout<<"\t\t\t|   Dear Customer,                                                      |\n";
cout<<"\t\t\t|                      Congratulation!! Your tickets has been booked.   |\n";
cout<<"\t\t\t|                                                                       |\n";
cout<<"\t\t\t|                  THE DETAILS:                                         |\n";
cout<<"\t\t\t|                                                                       |\n";
cout<<"\t\t\t|                            MOVIE NAME: "<<name[arg-1]<<"                                 \n";
cout<<"\t\t\t|                            SHOW STARTS: 3:15pm                        |\n";
cout<<"\t\t\t|                            NUMBER OF TICKETS BOOKED: "<<tkt_pr<<"                |\n";
cout<<"\t\t\t|                 THE SEAT NUMBERS ARE: ";for(i=0;i<tkt_pr;i++)
                                            {   c=tkt_row[i]+65;
                                                cout<<c<<tkt_col[i]+1;//PLS CHECK WHY I HV WRITTEN HERE +
                                                if(i<tkt-1)
                                                {
                                                    cout<<",";
                                                }
                                            }
cout<<"                        \n";
cout<<"\t\t\t|                                                                       |\n";
cout<<"\t\t\t|                                                                       |\n";
cout<<"\t\t\t|_______________________________________________________________________|\n";

}

pass_proctect()//to protect the password
{

        int ps=0,star=0;// to count the characters in password

        //star is to print the password in * format
                    //pas[-1]=0;//intialised just like that "I GUESS ITS NIT REQUIRED"
         cout<<"\n\n\t\t\t\t\t\t\tENTER THE MANAGER PASSWORD\n";
         cout<<"\t\t\t\t\t\t\t";

                cin>>pass;
               ps=pass.length();
                system("cls");
                while(star<ps)
                {   if(star==0)
                {
                    cout<<"\n\n\t\t\t\t\t\t\tENTER THE MANAGER PASSWORD\n\n";

                    cout<<"\t\t\t\t\t\t\t\t";

                }

                    cout<<" * ";
                    star++;
                }

}


int main()
{
    while(1)
    {
       int i;
    char in='c',ind,cus;//cus is customer and ind is manager input
    cout<<"\n\n\t\t\t\t\t\t\tTO ENTER MANAGER LOGIN PRESS 'o' or 'O' ELSE ANY OTHER KEY FOR CUSTOMER BOOKING\n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>ind;
    int pas_count=0;
    if((ind=='o')||(ind=='O'))
    {
    	while(pas_count<3)
    	{
    		pass_proctect();
    	if(pass=="KASAW")
    	{
    		manager();//the manager mode to set the number of seats available for booking
    		pas_count=3;
    	}

    	else{
    	cout<<"PASSWORD ENTERED IS WRONG!!"<<" ATTEMPTS REMAINING = "<<2-pas_count<<" \n";//pas_count is to count no. of attempts left
    		pas_count++;
    	}

    }
    }
    else
    {
    system("cls");
    cout<<"\n\n\t\t\t\t\t\t\tDEAR CUSTOMER TO BOOK SEATS PRESS 'y' or 'Y' \n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>cus;
    //HERE I HAVE TO ADD THE CUSTOMER LOGIN FUNCTION
     if((cus=='y')||(cus=='Y'))//the customer part starts here
     {
         cout<<"\n\n\t\t\t\t\t\tTHE SEATS AVAILABLE ARE:\n";
    while((in=='c')||(in=='C'))
    {
        cost=0;
        cout<<"\n\n\t\t\t\t\t\t\tTHE MOVIES RUNNING IN HALL AND TIMINGS ARE:\n";//to display the shows running in theater



    ifstream file;
    char ch;
    system("cls");
    while(1){
        file.open("shows.txt");
        while(!file.eof()){
            file.get(ch);
            cout<<ch;
           }
        file.close();
        break;

}

            cout<<"\n\n\t\t\t\t\t\t\tENTER THE MOVIE NUMBER TO BOOK TICKET\n";
            cout<<"\t\t\t\t\t\t\t";
            cin>>arg;
             cout<<"\n\n\t\t\t\t\t\t\tCHOOSE THE NUMBER CORRENSPONDING TO TIMING TO BOOK TICKET FOR MOVIE"<<name[arg]<<endl;
            cout<<"\t\t\t\t\t\t\t";
            cin>>sti;
            tkt_pnt=name[arg];
               // cout<<"THE ARGUMENT IS ="<<arg<<endl;
            seatdisp(arg,sti);
            seatin(arg,sti);
            system("cls");
            seatdisp(arg,sti);
            /*HERE ANOTHER FUNCTION IS TO BE WRITTEN TO PRINT THE TICKETS*/
            system("cls");

            ticket_print();
    cout<<"\n\n\t\t\t\t\t\t\tPRESS 'C' or 'c' IF U WANT TO BOOK SEAT AGAIN?\n";
    cin>>in;
    }


     }


    }

cout<<"\n\n\t\t\t\t\t\t\t TO EXIT PROGRAM PRESS 9 \n";
cin>>ext;
if(ext==9)
    goto bye;

}
bye:
 return 0;
}
