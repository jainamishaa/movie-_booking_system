#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<windows.h>
using namespace std;
void gotoxy (int x, int y);
COORD coord = {0, 0};
class movie{
private:

int m,*p,sn,arg,arg2;//sn is variable for show number in manager function N m is for number of shows in a day
string name[10];
int ar[100][12][18];
public:
    void main_menu();
    void customer();
    void admin();
    void showtiming();
    void movie_ticket();
    void buy_ticket();
    void royal();
    void executive();
    void club();
    void seatdisp(int z);
    void book(int z,int a);
    void seatin(int z);
    void admin1();
};

void gotoxy (int x, int y)	//defining/initializing to predefined objects
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void movie::main_menu(){
system("cls");
system("COLOR 4a");
char ch;
gotoxy(50,0);
cout<<"Generic Movie Hall"<<endl;
gotoxy(25,5);
cout<<"ENTER AS--"<<endl;
gotoxy(25,7);
cout<<"1.CUSTOMER | 2.ADMIN"<<endl;
gotoxy(25,8);
cout<<"Enter Your Choice:"<<endl;
gotoxy(43,8);
cin>>ch;
if(ch=='1'){
    customer();
}
else if(ch=='2'){
    admin();
}
else{
    gotoxy(43,10);
    main_menu();
}
}

void movie::customer(){
char ch;
system("cls");
system("COLOR 4a");
gotoxy(50,0);
cout<<"Generic Movie Hall"<<endl;
gotoxy(55,2);
cout<<"MENU"<<endl;
gotoxy(25,5);
cout<<" 1.ShowTiming |   2. Buy Ticket |   3.Exit"<<endl;
gotoxy(25,7);
cout<<"Enter Your Choice:"<<endl;
gotoxy(44,7);
cin>>ch;
if(ch=='1'){
    showtiming();
}
else if(ch=='2'){
    buy_ticket();
}
else if(ch=='3'){
    exit(0);
}
else{
    customer();
}
}

void movie::showtiming(){
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
gotoxy(0,9);
cout<<"ENTER B TO GO BACK"<<endl;
cin>>ch;
if((ch=='b')||(ch=='B')){
    main_menu();
}
else{
    showtiming();
}
}
}

void movie::buy_ticket(){
ifstream file;
char ch;
system("cls");
file.open("showtiming.txt");
while(!file.eof()){
    file.get(ch);
    cout<<ch;
}
gotoxy(0,9);
cout<<"ENTER THE MOVIE YOU WANT TO SEE ELSE PRESS E TO EXIT"<<endl;
cin>>ch;
if(ch=='e'||'E'){
    exit(0);
}
system("cls");
gotoxy(50,0);
cout<<"LUXURY:::::ENTER THE CLASS YOU WANT:"<<endl;
gotoxy(50,2);
cout<<"1.ROYAL"<<endl;
gotoxy(50,3);
cout<<"2.EXECUTIVE"<<endl;
gotoxy(50,4);
cout<<"3.CLUB"<<endl;
gotoxy(50,5);
cout<<"ENTER CHOICE:"<<endl;
gotoxy(63,5);
cin>>ch;
if(ch==1) cout<<"\nYou Have choose Royal Luxury";
        else if(ch==2) cout<<"\nYou Have choose Executive Luxury";
        else if(ch==3) cout<<"\nYou Have choose Club Luxury";

}




void movie::seatdisp(int z)//argument to display the seats of that particular movie
{
    arg=z;
    int i,j;
    char ch='A',st;
   cout<<"\n\n\t\t\t\t\t\t\tBOOKED SEATS ARE MARKED WITH [x]\n\n";
    for(i=0;i<13;i++)
    {
        ch='A';
        ch=ch+i;
        cout<<"\t";

        for(j=0;j<18;j++)
        {
            if(ar[arg][i][j]==1)
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


void movie::book(int z,int a)//first argument is for the movie number and 2nd argument for manager mode
{int i,j,num,al,n,col,stor,arg;
arg=z;
    arg2=a;
    if(arg2==100)
    {
      cout<<"\nADMIN ENTER THE SEATS WHICH WONT BE AVAILABLE FOR BOOKING\n";
    }

else
{
 cout<<"\nCUSTOMER BOOKING\n";

}

        seatdisp(arg);
    char ch='A',chr;
    cout<<"\n\tENTER THE SEAT NUMBER\t";
        cin>>chr>>col;
        stor=chr-65;
        col=col-1;
        if(ar[arg][stor][col]==0)
        ar[arg][stor][col]=1;

        else
        {

            while(ar[arg][stor][col]!=0)
            {
                if(arg2==100)
               cout<<"\n\tADMIN YOU HAVE ALREADY MARKED THIS SEAT AS BOOKED ENTER A NEW SEAT WHICH IS BOOKED\n";
           else
           {
            cout<<"\n\tTHE SEAT YOU SELECTED IS ALREADY OCCUPIED ENTER A NEW SEAT\n";
           }
                cin>>chr>>col;
                stor=chr-65;
                col=col-1;
            }
            ar[arg][stor][col]=1;
        }

}

void movie::seatin(int z)//argument for the particular movie seat booking
{   int j,n;
    arg=z;
    //cout<<"THE ARGUMENT IS nest="<<arg<<endl;
     cout<<"\n\tENTER THE NUMBER OF SEATS TO BE BOOKED"<<"movie no="<<arg<<endl;
    cin>>n;
       for(j=0;j<n;j++)//loop for booking the desired no. of tickets as input by user
{
     book(arg,20);
     cout<<"LOOP IS RUNNING\n";
       system("cls");
  seatdisp(arg);

}



}


// void movie::royal(){

// gotoxy(50,2);
// cout<<"ROYAL SEATS"<<endl;
// gotoxy(50,8);
// cout<<"SEAT LAYOUT:"<<endl;
// gotoxy(30,10);
// fstream file;
// FILE *fk;
// file.open(royal.txt);
// char ch,seat;
// while(!file.eof()){
//     file.get(ch);
//     cout<<ch;
// }
// gotoxy(30,14);
// cout<<"ENTER THE SEATS YOU WANT:"<<endl;
// gotoxy(44,14);
// cin>>seat;
// fk = fopen("royal.txt",r);
// while(fscanf(fk,"%c",seat)!=EOF){
//     if(strcmp()){

//     }
// }
// }

// void movie::executive(){
// gotoxy(50,2);
// cout<<"EXECUTIVE SEATS"<<endl;
// gotoxy(50,8);
// cout<<"SEAT LAYOUT:"<<endl;
// gotoxy(30,10);
// fstream file;
// FILE *fk;
// file.open(executive.txt);
// char ch,seat;
// while(!file.eof()){
//     file.get(ch);
//     cout<<ch;
// }
// gotoxy(30,14);
// cout<<"ENTER THE SEATS YOU WANT:"<<endl;
// gotoxy(44,14);
// cin>>seat;
// fk = fopen("executive.txt",r);
// while(fscanf(fk,"%c",seat)!=EOF){
//     if(strcmp()){

//     }
// }
// }

// void movie::club(){
// gotoxy(50,2);
// cout<<"CLUB SEATS"<<endl;
// gotoxy(50,8);
// cout<<"SEAT LAYOUT:"<<endl;
// gotoxy(30,10);
// fstream file;
// FILE *fk;
// file.open(club.txt);
// char ch,seat;
// while(!file.eof()){
//     file.get(ch);
//     cout<<ch;
// }
// gotoxy(30,14);
// cout<<"ENTER THE SEATS YOU WANT:"<<endl;
// gotoxy(44,14);
// cin>>seat;
// fk = fopen("club.txt",r);
// while(fscanf(fk,"%c",seat)!=EOF){
//     if(strcmp()){

//     }
// }
// }

void movie::admin(){
system("cls");
system("color 4a");
gotoxy(50,0);
string username1 = "admin", password1 = "admin123", usern,passw;
cout<<"ADMIN"<<endl;
gotoxy(50,5);
cout<<"ENTER USERNAME:"<<endl;
gotoxy(64,5);
cin>>usern;
gotoxy(50,6);
cout<<"ENTER PASSWORD:"<<endl;
gotoxy(64,6);
cin>>passw;
if((usern)==username1&&(passw)==password1){
    admin1();
}
else{
    admin();
}
}


void movie::admin1(){

    ofstream fout;  // Create Object of Ofstream
    ifstream fin;
    fin.open("shows.txt");
    fout.open ("shows.txt",ios::app);
    int i,j;
    p=(int*)(malloc(sizeof(int)));
    cout<<"\n\tENTER THE NUMBER SHOWS IN A DAY\n";
    cin>>m;
    (*p)=m;
for(i=0;i<m;i++)
{   fflush(stdin);
    if(fin.is_open())
    {
            cout<<"\n\tENTER THE NAME OF MOVIE "<<i+1<<endl;
            getline(cin,name[i]);


    }


}
system("cls");
cout<<"\n\tTHE MOVIES RUNNING IN HALL ARE:\n";
for(i=0;i<m;i++)
{
    cout<<"MOVIE :\t"<<i+1<<"\t";
    cout<<name[i]<<endl;


}}

int main(){
ifstream file;
system("color 4a");
movie m;
m.main_menu();
return 0;
}
