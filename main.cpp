#include<iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<time.h>
using namespace std;
void gotoRowCol(int rpos, int cpos)
{
    int xpos = cpos, ypos = rpos;
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOuput, scrn);
}
void sleep(int m)
{
    for(int j=0; j<m*21000; j++)
    {

    }
}
void number(int &num, int row, int col, int rdim, int cdim)
{
    int x,y;
    y=row+rdim/2;
    x=col+cdim/2;
    gotoRowCol(x,y);
    cout<<num;

}
void one_box(int row, int col, int rdim, int cdim, char ch)
{
    for (int i=row; i<row+rdim; i++)
    {
        gotoRowCol(col,i);
        cout<<ch;
    }
    for (int i=row; i<row+rdim; i++)
    {
        gotoRowCol(col+cdim,i);
        cout<<ch;
    }
    for(int i=col; i<col+cdim; i++)
    {
        gotoRowCol(i,row);
        cout<<ch;
    }
    for(int i=col; i<col+cdim; i++)
    {
        gotoRowCol(i,row+rdim);
        cout<<ch;
    }
}
void dice(int &score, int turn)
{
    while(!kbhit())
    {
        score = rand()%6+1;
        gotoRowCol(20,130);
        cout<<"dice of player "<<turn+1<<": "<<score<<endl<<endl;
    }
    getch();
    getch();
}
void Player_score(int &p1, int &p2, int &score, int &turn,	int &counter, int &sum_for_six, char &pp1, char &pp2)
{
    dice(score,turn);
    gotoRowCol(25,130);
    if(turn==0)
    {
        if (pp1!='T')
        {
            if (score==6)
            {
                pp1='T';
            }
            turn=1;
            if(pp1=='T')
            {
                turn=0;
            }
        }
        else if(score==6)
        {
            sum_for_six=sum_for_six+score;
            turn=0;
            counter++;

            if(counter==3)
            {
                sum_for_six=0;
                turn=1;
                counter=0;
            }
        }
        else
        {
            score=score+sum_for_six;
            p1=p1+score;
            if(p1<101)
            {
                cout<<"Player 1: "<<p1;
                sum_for_six=0;
                counter=0;
            }
            else if(p1>100)
            {
                p1=p1-score;

                sum_for_six=0;
            }
            turn=1;
        }
    }
    else if(turn==1)
    {
        gotoRowCol(26,130);
        if (pp2!='T')
        {
            if (score==6)
            {
                pp2='T';
            }
            turn=0;
            if(pp2=='T')
            {
                turn=1;
            }
        }
        else if(score==6)
        {
            sum_for_six=sum_for_six+score;
            turn=1;
            counter++;
            if(counter==3)
            {
                sum_for_six=0;
                turn=0;
                counter=0;
            }
        }
        else
        {
            score=score+sum_for_six;
            p2=p2+score;

            if(p2<101)
            {
                cout<<"Player 2: "<<p2;
                sum_for_six=0;
                counter=0;
            }
            else if(p2>100)
            {
                p2=p2-score;
                sum_for_six=0;
            }
            turn=0;
        }
    }
}
void Snake_Ladder_Token(int p1, int p2, int &x, int &y, int turn)
{
    y=105;
    x=48;
    if(turn==1)
    {
        y=y+100*((p1-1)/10);
        y=y-10*p1;
        x=x-5*((p1-1)/10);
    }
    else if(turn==0)
    {
        y=y+100*((p2-1)/10);
        y=y-10*p2;
        x=x-5*((p2-1)/10);
    }
}
void snake_and_ladder(int &p1, int &p2, int x, int y, int turn)
{
    //Snakes
    gotoRowCol(12,130);
    cout<<"Snakes";
    if(p1==99)
    {
        Snake_Ladder_Token(p1, p2, x, y,turn);
        gotoRowCol(x,y);
        cout<<" ";
        p1=20;
        gotoRowCol(25,130);
        cout<<"Player 1: "<<p1;
    }
    if(p2==99)
    {
        Snake_Ladder_Token(p1, p2, x, y,turn);
        gotoRowCol(x,y-1);
        cout<<" ";
        p2=20;
        gotoRowCol(26,130);
        cout<<"Player 2: "<<p2;
    }
    gotoRowCol(14,130);
    cout<<"99 to 20";
    if(p1==87)
    {
        Snake_Ladder_Token(p1, p2, x, y,turn);
        gotoRowCol(x,y);
        cout<<" ";
        p1=47;
        gotoRowCol(25,130);
        cout<<"Player 1: "<<p1;
    }
    if(p2==87)
    {
        Snake_Ladder_Token(p1, p2, x, y,turn);
        gotoRowCol(x,y-1);
        cout<<" ";
        p2=47;
        gotoRowCol(26,130);
        cout<<"Player 2: "<<p2;
    }
    gotoRowCol(15,130);
    cout<<"87 to 47";
    if(p1==51)
    {
        Snake_Ladder_Token(p1, p2, x, y,turn);
        gotoRowCol(x,y);
        cout<<" ";
        p1=35;
        gotoRowCol(25,130);
        cout<<"Player 1: "<<p1;
    }
    if(p2==51)
    {
        Snake_Ladder_Token(p1, p2, x, y,turn);
        gotoRowCol(x,y-1);
        cout<<" ";
        p2=35;
        gotoRowCol(26,130);
        cout<<"Player 2: "<<p2;
    }
    gotoRowCol(16,130);
    cout<<"51 to 35";
    if(p1==40)
    {
        Snake_Ladder_Token(p1, p2, x, y,turn);
        gotoRowCol(x,y);
        cout<<" ";
        p1=20;
        gotoRowCol(25,130);
        cout<<"Player 1: "<<p1;
    }
    if(p2==40)
    {
        Snake_Ladder_Token(p1, p2, x, y,turn);
        gotoRowCol(x,y-1);
        cout<<" ";
        p2=20;
        gotoRowCol(26,130);
        cout<<"Player 2: "<<p2;
    }
    gotoRowCol(17,130);
    cout<<"40 to 20";
    //ladders
    gotoRowCol(12,148);
    cout<<"Ladders";
    if(p1==7)
    {
        Snake_Ladder_Token(p1, p2, x, y,turn);
        gotoRowCol(x,y);
        cout<<" ";
        p1=77;
        gotoRowCol(25,130);
        cout<<"Player 1: "<<p1;
    }
    if(p2==7)
    {
        Snake_Ladder_Token(p1, p2, x, y,turn);
        gotoRowCol(x,y-1);
        cout<<" ";
        p2=77;
        gotoRowCol(26,130);
        cout<<"Player 2: "<<p2;
    }
    gotoRowCol(14,148);
    cout<<"7 to 77";
    if(p1==11)
    {
        Snake_Ladder_Token(p1, p2, x, y,turn);
        gotoRowCol(x,y);
        cout<<" ";
        p1=41;
        gotoRowCol(25,130);
        cout<<"Player 1: "<<p1;
    }
    if(p2==11)
    {
        Snake_Ladder_Token(p1, p2, x, y,turn);
        gotoRowCol(x,y-1);
        cout<<" ";
        p2=41;
        gotoRowCol(26,130);
        cout<<"Player 2: "<<p2;
    }
    gotoRowCol(15,148);
    cout<<"11 to 41";
    if(p1==45)
    {
        Snake_Ladder_Token(p1, p2, x, y,turn);
        gotoRowCol(x,y);
        cout<<" ";
        p1=60;
        gotoRowCol(25,130);
        cout<<"Player 1: "<<p1;
    }
    if(p2==45)
    {
        Snake_Ladder_Token(p1, p2, x, y,turn);
        gotoRowCol(x,y-1);
        cout<<" ";
        p2=60;
        gotoRowCol(26,130);
        cout<<"Player 2: "<<p2;
    }
    gotoRowCol(16,148);
    cout<<"45 to 60";
    if(p1==59)
    {
        Snake_Ladder_Token(p1, p2, x, y,turn);
        gotoRowCol(x,y);
        cout<<" ";
        p1=97;
        gotoRowCol(25,130);
        cout<<"Player 1: "<<p1;
    }
    if(p2==59)
    {
        Snake_Ladder_Token(p1, p2, x, y,turn);
        gotoRowCol(x,y-1);
        cout<<" ";
        p2=97;
        gotoRowCol(26,130);
        cout<<"Player 2: "<<p2;
    }
    gotoRowCol(17,148);
    cout<<"59 to 97";

    x=48,y=105;
}
void Print_Box(int &num, int row, int col, int rdim, int cdim, char ch)
{
    int counters=0;
    for(int i=0; i<10; i++)
    {
        while(counters!=10)
        {
            number(num,row, col, rdim, cdim);
            one_box(row,col, rdim, cdim,ch);
            row=row+rdim;
            counters++;
            num--;
        }
        col=col+cdim;
        row=0;
        counters=0;
    }
}
void symbol(int p1, int p2, int &x, int &y, char player1, char player2, int turn, int &count1, int &count2, int &a, int &b)
{
    if(turn==1&&p1!=0)
    {
        if(p1>=10*(p1/10))
        {
            y=y+100*((p1-1)/10);
            x=x-5*((p1-1)/10);
        }
        else if(p1>(10*(p1/20)) && player1==' ' && p1<101)
        {
            x=x-5*(p1/20);
            y=y+100*(p1/20);
        }
        y=y-10*p1;
        gotoRowCol(x,y);
        cout<<player1;
    }
    else if(turn==0&&p2!=0)
    {
        if(p2>=10*(p2/10))
        {
            y=y+100*((p2-1)/10);
            x=x-5*((p2-1)/10);
        }
        else if(p2>10*(p2/20) && player2 ==' '&& p2 < 101)
        {
            x=x-5*(p2/20);
            y=y+100*(p2/20);
        }
        y=y-10*p2;
        gotoRowCol(x,y-1);
        cout<<player2;
    }
    x=48, y=105;
}
void Read(int &p1, int &p2, char &pp1, char &pp2, char ch3)
{
    ifstream read("Save_and_Load.txt");
    read>>p1>>ch3>>p2>>ch3>>pp1>>pp2;
}
void Write(int &p1, int &p2, char &pp1, char &pp2, char ch3)
{
    ofstream write("Save_and_Load.txt");
    write<<p1;
    write<<ch3<<p2;
    write<<ch3<<pp1<<pp2;
}
int main()
{
    int row=0, col=0, rdim=10, cdim=5, num=100, p1_score=0, p2_score=0, score, turn=0, counter=0, sum_for_six=0, x=48, y=105, a=0, b=0, count1=0, count2=0;
    char ch=219, pp1, pp2, player1, player2, load, save, ch3=',';
    cout<<"If you want to Load the Previous Game then press l or L \nFor New Game press n or N: ";
    cin>>load;
    if(load=='L' || load=='l')
    {
        Read(p1_score,p2_score,pp1, pp2,ch3);
    }
    cout<<p1_score<<ch3<<p2_score;
    cout<<"\nPlease enter character for Player 1: ";
    cin>>player1;
    cout<<"Please enter character for Player 2: ";
    cin>>player2;
    system("CLS");
    if(load=='L' || load=='l')
    {
        turn=1;
        Print_Box(num,row, col, rdim, cdim,ch);
        Snake_Ladder_Token(p1_score, p2_score, x, y,turn);
        gotoRowCol(x,y);
        cout<<player1;
        turn=0;
        Snake_Ladder_Token(p1_score, p2_score, x, y,turn);
        gotoRowCol(x,y-1);
        cout<<player2;
        turn=0;
        snake_and_ladder(p1_score,p2_score,x,y,turn);
        gotoRowCol(25,130);
        cout<<"Player 1: "<<p1_score;
        gotoRowCol(26,130);
        cout<<"Player 2: "<<p2_score;
    }
    if(load=='n' || load=='N')
    {
        Print_Box(num,row, col, rdim, cdim,ch);
    }
    x=48,y=105;
    while(p1_score!=100 && p2_score!=100)
    {
        Player_score(p1_score, p2_score, score,turn, counter, sum_for_six, pp1, pp2);
        symbol(p1_score, p2_score,x, y, player1,  player2, turn, count1, count2,a,b);
        symbol(p1_score-score, p2_score, x, y, ' ', player2, turn, count1, count2,a,b);
        symbol(p1_score, p2_score-score, x, y, player1, ' ', turn, count1, count2,a,b);
        snake_and_ladder(p1_score,p2_score,x,y,turn);
        Write(p1_score,p2_score,pp1, pp2,ch3);
        gotoRowCol(30,130);
        cout<<"For Save the Game press s or S: ";
        save=cin.get();
        if(save=='s'|| save=='S')
        {
            exit(1);
        }
    }
    gotoRowCol(28,130);
    if(p1_score==100)
    {
        cout<<"Player 1 Win!";
    }
    else
    {
        cout<<"Player 2 Win!";
    }
    getch();
}
