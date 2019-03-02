#include<stdio.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
void graph();
void welcome();
void loading();
void menu();
//////////////////////dollar//////////////////////////////////
void doltaka();
void doleuro();
void dolrupe();
void dolbit();
void dolsaudi();
void dolpound();
/////////////////////euro////////////////////////////////////
void eurotaka();
void eurodol();
void eurorupe();
void eurobit();
void eurosaudi();
void europound();
////////////////////rupe////////////////////////////////////
void rupetaka();
void rupedol();
void rupeeuro();
void rupebit();
void rupesaudi();
void rupepound();
///////////////////taka///////////////////////////////////
void takadol();
void takaeuro();
void takarupe();
void takabit();
void takasaudi();
void takapound();
////////////////////bitcoin//////////////////////////////
void bitdol();
void biteuro();
void bitrupe();
void bittaka();
void bitsaudi();
void bitpound();
//////////////////////saudi riyal/////////////////////////////
void saudidol();
void saudieuro();
void saudirupe();
void sauditaka();
void saudibit();
void saudipound();
///////////////////////pound/////////////////////////////////
void pounddol();
void poundeuro();
void poundrupe();
void poundtaka();
void poundsaudi();
void poundbit();

//////////////////finish currency/////////////////////////
void way();
void finish();
void netxcome();
///////////////////*global variable declaration*//////////////////
float money,exchange,taka;



struct node
{
    float data;
    struct node* next;
};

/* Function to create a new node with given data */
struct node *newNode(float data)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to insert a node at the beginning of the Linked List */
void push(struct node** head_ref, float new_data)
{
    /* allocate node */
    struct node* new_node = newNode(new_data);

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Multiply contents of two linked lists */
float multiplyTwoLists (struct node* taka, struct node* money)
{
    float num1 = 0, num2 = 0;
    while (taka || money)
    {
	if(taka)
	{
	    num1 = num1*10 + taka->data;
	    taka = taka->next;
	}
	if(money)
	{
	    num2 = num2*10 + money->data;
	    money = money->next;
	}
    }
return num1*num2;
}



///mouse

///shown mouse///


void showmouse()
{
    union REGS in,out;
    in.x.ax=1;
    int86(0x33,&in,&out);
}



//////////////////////*HIDE MOUSE*////////////////////////////////////


void hidemouse()
{
    union REGS in,out;
    in.x.ax=2;
    int86(0x33,&in,&out);
}





/////////////////////////*MOUSE INFORMATION*////////////////////////////




void mouseInfo(int*button,int*Xpos,int*Ypos)
{
    union REGS in,out;
    in.x.ax=3;
    int86(0x33,&in,&out);
    *Xpos=out.x.cx;
    *Ypos=out.x.dx;
    *button=out.x.bx;
}
int Xpos,Ypos,button;




//////////////////////////main function///////////////////////////////////////

void main()
{
    graph();
    welcome();
    loading();
    menu();
    doltaka();
    doleuro();
    dolrupe();
    dolbit();
    dolsaudi();
    dolpound();

    eurodol();
    eurorupe();
    eurotaka();
    eurobit();
    eurosaudi();
    europound();

    rupedol();
    rupeeuro();
    rupetaka();
    rupebit();
    rupesaudi();
    rupepound();

    takadol();
    takaeuro();
    takarupe();
    takabit();
    takasaudi();
    takapound();

    bitdol();
    biteuro();
    bitrupe();
    bittaka();
    bitsaudi();
    bitpound();

    saudidol();
    saudieuro();
    saudirupe();
    sauditaka();
    saudibit();
    saudipound();

    pounddol();
    poundeuro();
    poundrupe();
    poundtaka();
    poundsaudi();
    poundbit();

    way();
    finish();
    getch();
    closegraph();
}

///////////////////////// graph //////////////////////////////////

void graph()
{
    int dr=DETECT,dm;
    initgraph(&dr,&dm,"c:\\tc\\bgi");

}
///////////////////////////welcome page///////////////////////
void welcome()
{
    setcolor(9);
    setbkcolor(12);
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    outtextxy(100,200,"Welcome to money Exchanger");
    settextstyle(3,HORIZ_DIR,2);
    outtextxy(260,250,"Version 1.0");
    settextstyle(3,HORIZ_DIR,2);
    outtextxy(210,380,"Developed by Md.Emran Sikder");
    delay(6000);
    clrscr();
    cleardevice();
}

/////////////////////////////////// loading page /////////////////////////////////
void loading()
{
    setcolor(7);
    setbkcolor(1);
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    outtextxy(250,200,"Loading");
    delay(1000);
    outtextxy(380,200,".");
    delay(1000);
    outtextxy(390,200,".");
    delay(1000);
    outtextxy(400,200,".");
    delay(1000);
}

//////////////////////////////////////// menu ///////////////////////////////////////
void menu()
{
    cleardevice();
    graph();
    setcolor(8);
    setlinestyle(BOLD_FONT,HORIZ_DIR,2);
    line(90,410,90,50);
    line(90,410,590,410);
    settextstyle(3,HORIZ_DIR,1);
    setbkcolor(6);
    bar3d(150,80,480,105,1,1);
    outtextxy(205,78,"Exchange Dollar To Taka");
    delay(200);
    bar3d(150,110,480,135,1,1);
    outtextxy(205,107,"Exchange taka to dollar");
    delay(200);
    bar3d(150,140,480,165,1,1);
    outtextxy(205,136,"Exchange euro to taka");
    delay(300);
    bar3d(150,170,480,195,1,1);
    outtextxy(205,167,"Exchange taka to euro");
    delay(300);
    bar3d(150,200,480,225,1,1);
    outtextxy(205,198,"Exchange rupee to taka");
    delay(400);
    bar3d(150,230,480,255,1,1);
    outtextxy(205,229,"Exchange taka to rupee");
    delay(400);
    bar3d(150,260,480,285,1,1);
    outtextxy(205,259,"Different way");
    delay(400);
    bar3d(150,290,480,315,1,1);
    outtextxy(205,289,"E X I T");
    delay(400);
    showmouse();
    while(1)
    {
	mouseInfo(&button,&Xpos,&Ypos);
	if((Xpos>150 && Xpos <480) && (Ypos<105 & Ypos>80))
	{
	    if(1==(button&1))
	    {
		cleardevice();
		doltaka();
		break;
	    }
	}
	if((Xpos>150 && Xpos <480) && (Ypos<135 & Ypos>110))
	{
	    if(1==(button&1))
	    {
		cleardevice();
		takadol();
		break;
	    }
	}
	if((Xpos>150 && Xpos <480) && (Ypos<165 & Ypos>140))
	{
	    if(1==(button&1))
	    {
		cleardevice();
		eurotaka();
		break;
	    }
	}

	if((Xpos>150 && Xpos <480) && (Ypos<195 & Ypos>170))
	{
	    if(1==(button&1))
	    {
		cleardevice();
		takaeuro();
		break;
	    }
	}
	if((Xpos>150 && Xpos <480) && (Ypos<225 & Ypos>200))
	{
	    if(1==(button&1))
	    {
		cleardevice();
		rupetaka();
		break;
	    }
	}
	if((Xpos>150 && Xpos <480) && (Ypos<255 & Ypos>230))
	{
	    if(1==(button&1))
	    {
		cleardevice();
		takarupe();
		break;
	    }
	}
	if((Xpos>150 && Xpos <480) && (Ypos<285 & Ypos>260))
	{
	    if(1==(button&1))
	    {
		cleardevice();
		way();
		break;
	    }
	}
	if((Xpos>150 && Xpos <480) && (Ypos<315 & Ypos>290))
	{
	    if(1==(button&1))
	    {
		cleardevice();
		finish();
		break;
	    }
	}
/////////////fe///////////////////
    }

    hidemouse();
}
//////////////////////////////return or exit////////////////////////
void nextcome()
{

    bar3d(400,130,500,156,1,1);
    outtextxy(432,130,"Menu");
    bar3d(300,130,400,156,1,1);
    outtextxy(340,130,"Exit");
    showmouse();
    while(1)
    {
	mouseInfo(&button,&Xpos,&Ypos);
	if((Xpos>400 && Xpos <500) && (Ypos<156 & Ypos>130))
	{
	    if(1==(button&1))
	    {
		cleardevice();
		menu();
		break;
	    }
	}
	if((Xpos>300 && Xpos<400) && (Ypos<156 & Ypos>130))
	{
	    if(1==(button&1))
	    {
		cleardevice();
		finish();
		break;
	    }
	}
    }
}
/////////////////////////* finish work *///////////////////
void finish()
{
    exit(1);
}
//////////////////////////////////////another///////////////
void way()
{

    char mode[10];
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t         ");
    if((scanf("%s",mode) != EOF))
    {
	if(strcmp(mode,"dollar") == 0)
	{
	    outtextxy(330,75,"TO");
	    rectangle(200,95,500,115);
	    printf("\n\t\t         ");
	    if((scanf("%s",mode) !=EOF))
	    {
		if(strcmp(mode,"taka") == 0)
		{
		    cleardevice();
		    clrscr();
		    doltaka();
		}

		else if(strcmp(mode,"euro") == 0)
		{
		    cleardevice();
		    clrscr();
		    doleuro();
		}

		else if(strcmp(mode,"rupee") == 0)
		{
		    cleardevice();
		    clrscr();
		    dolrupe();
		}
		else if(strcmp(mode,"bitcoin") == 0)
		{
		    cleardevice();
		    clrscr();
		    dolbit();
		}
		else if(strcmp(mode,"riyal") == 0)
		{
		    cleardevice();
		    clrscr();
		    dolsaudi();
		}
		else if(strcmp(mode,"pound") == 0)
		{
		    cleardevice();
		    clrscr();
		    dolpound();
		}
	    }
	}
	else if(strcmp(mode,"euro") == 0)
	{
	    outtextxy(330,75,"TO");
	    rectangle(200,95,500,115);
	    printf("\n\t\t         ");
	    if((scanf("%s",mode) !=EOF))
	    {
		if(strcmp(mode,"taka") == 0)
		{
		    cleardevice();
		    clrscr();
		    eurotaka();
		}

		else if(strcmp(mode,"dollar") == 0)
		{
		    cleardevice();
		    clrscr();
		    eurodol();
		}

		else if(strcmp(mode,"rupee") == 0)
		{
		    cleardevice();
		    clrscr();
		    eurorupe();
		}
		else if(strcmp(mode,"bitcoin") == 0)
		{
		    cleardevice();
		    clrscr();
		    eurobit();
		}
		else if(strcmp(mode,"riyal") == 0)
		{
		    cleardevice();
		    clrscr();
		    eurosaudi();
		}
		else if(strcmp(mode,"pound") == 0)
		{
		    cleardevice();
		    clrscr();
		    dolpound();
		}
	    }
	}
	else if(strcmp(mode,"rupee") == 0)
	{
	    outtextxy(330,75,"TO");
	    rectangle(200,95,500,115);
	    printf("\n\t\t         ");
	    if((scanf("%s",mode) !=EOF))
	    {
		if(strcmp(mode,"taka") == 0)
		{
		    cleardevice();
		    clrscr();
		    rupetaka();
		}

		else if(strcmp(mode,"euro") == 0)
		{
		    cleardevice();
		    clrscr();
		    rupeeuro();
		}

		else if(strcmp(mode,"dollar") == 0)
		{
		    cleardevice();
		    clrscr();
		    rupedol();
		}
		else if(strcmp(mode,"bitcoin") == 0)
		{
		    cleardevice();
		    clrscr();
		    rupebit();
		}
		else if(strcmp(mode,"riyal") == 0)
		{
		    cleardevice();
		    clrscr();
		    rupesaudi();
		}
	    }
	}
	else if(strcmp(mode,"taka") == 0)
	{
	    outtextxy(330,75,"TO");
	    rectangle(200,95,500,115);
	    printf("\n\t\t         ");
	    if((scanf("%s",mode) !=EOF))
	    {
		if(strcmp(mode,"dollar") == 0)
		{
		    cleardevice();
		    clrscr();
		    takadol();
		}

		else if(strcmp(mode,"euro") == 0)
		{
		    cleardevice();
		    clrscr();
		    takaeuro();
		}

		else if(strcmp(mode,"rupee") == 0)
		{
		    cleardevice();
		    clrscr();
		    takarupe();
		}
		else if(strcmp(mode,"bitcoin") == 0)
		{
		    cleardevice();
		    clrscr();
		    takabit();
		}
		else if(strcmp(mode,"riyal") == 0)
		{
		    cleardevice();
		    clrscr();
		    takasaudi();
		}
	    }
	}
	else if(strcmp(mode,"bitcoin") == 0)
	{
	    outtextxy(330,75,"TO");
	    rectangle(200,95,500,115);
	    printf("\n\t\t         ");
	    if((scanf("%s",mode) !=EOF))
	    {
		if(strcmp(mode,"dollar") == 0)
		{
		    cleardevice();
		    clrscr();
		    bitdol();
		}

		else if(strcmp(mode,"euro") == 0)
		{
		    cleardevice();
		    clrscr();
		    biteuro();
		}

		else if(strcmp(mode,"rupee") == 0)
		{
		    cleardevice();
		    clrscr();
		    bitrupe();
		}
		else if(strcmp(mode,"taka") == 0)
		{
		    cleardevice();
		    clrscr();
		    bittaka();
		}
		else if(strcmp(mode,"riyal") == 0)
		{
		    cleardevice();
		    clrscr();
		    bitsaudi();
		}
	    }
	}
	else if(strcmp(mode,"riyal") == 0)
	{
	    outtextxy(330,75,"TO");
	    rectangle(200,95,500,115);
	    printf("\n\t\t         ");
	    if((scanf("%s",mode) !=EOF))
	    {
		if(strcmp(mode,"dollar") == 0)
		{
		    cleardevice();
		    clrscr();
		    saudidol();
		}

		else if(strcmp(mode,"euro") == 0)
		{
		    cleardevice();
		    clrscr();
		    saudieuro();
		}

		else if(strcmp(mode,"rupee") == 0)
		{
		    cleardevice();
		    clrscr();
		    saudirupe();
		}
		else if(strcmp(mode,"bitcoin") == 0)
		{
		    cleardevice();
		    clrscr();
		    saudibit();
		}
		else if(strcmp(mode,"taka") == 0)
		{
		    cleardevice();
		    clrscr();
		    sauditaka();
		}
	    }
	}

    }
}


////////////////////////// dollar area//////////////////
void doltaka()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka, 83.6);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\tDollar =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  Taka =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void doleuro()
{

    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka, .89);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\tDollar =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  euro =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void dolrupe()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,64.34);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\tDollar =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  rupee =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void dolbit()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.00039);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\tDollar =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  bitcoin =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void dolsaudi()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,3.75);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\tDollar =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  riyal =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void dolpound()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.77);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t dollar =  ");
    push(&money, 6);
    scanf("%f",money);
    printf("\n\t\t  pound =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
/////////////////////taka area////////////////////
void takadol()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,80.67);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t  Taka =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
     printf("\n\t\t  dollar =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void takarupe()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.80);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t  Taka =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  rupee =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void takaeuro()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,90.62);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t  Taka =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
     printf("\n\t\t  euro =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void takabit()
{
    taka=.0000048;
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t  Taka =  ");
    scanf("%f",&money);
    exchange=money/taka;
    rectangle(200,113,500,94);
    printf("\n\t\t  bitcoin =  %.3f",exchange);
    nextcome();
    getch();
}
void takasaudi()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.047);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t  Taka =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
     printf("\n\t\t  riyal =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void takapound()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.0096);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t taka =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  pound =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
////////////////////////// euro area/////////////////////
void eurotaka()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,90.62);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t  Euro =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  Taka =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void eurodol()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,1.13);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t  Euro =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  dollar =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void eurorupe()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,72.47);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t  Euro =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  rupee =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void eurobit()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.00044);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t  Euro =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  bitcoin =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void eurosaudi()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,4.23);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t  Euro =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  riyal =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void europound()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.87);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t euro =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  pound =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}


////////////////////////// rupee to taka/////////////////////
void rupetaka()
{


    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.80);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t Rupee =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  Taka =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void rupedol()
{

    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.016);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  dollar =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void rupeeuro()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.014);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t Rupee =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  euro =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void rupebit()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.0000060);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t Rupee =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  bitcoin =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void rupepound()
{

    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.012);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t Rupee =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  pound =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void rupesaudi()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.058);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t rupee =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  riyal =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}


void bitdol()
{

    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,2575.38);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t bitcoin =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  dollar =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void biteuro()
{

    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,2286.08);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t bitcoin =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  euro =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void bitrupe()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,165487.64);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t bitcoin =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  rupee =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void bittaka()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,207498.37);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t bitcoin =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  Taka =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void bitsaudi()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,9658.83);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t bitcoin =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  riyal =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void bitpound()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,1997.19);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t bitcoin =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  pound =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void saudidol()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.27);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t riyal =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  dollar =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void saudieuro()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.24);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t riyal =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  euro =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void saudirupe()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,17.15);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t riyal =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  rupee =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void sauditaka()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,21.48);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t riyal =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  Taka =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void saudibit()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.00010);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t riyal =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  bitcoin =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void saudipound()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.21);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t riyal =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  pound =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void pounddol()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,1.29);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t pound =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  dollar =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void poundeuro()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,1.15);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t pound =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  euro =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void poundrupe()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,83.02);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t pound =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  rupee =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void poundtaka()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,103.99);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t pound =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  Taka =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void poundsaudi()
{
    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,4.84);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t pound =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  riyal =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}
void poundbit()
{

    struct node* taka = NULL;
    struct node* money = NULL;
    push(&taka,.00050);
    cleardevice();
    setbkcolor(3);
    setcolor(1);
    bar3d(10,10,627,30,1,1);
    outtextxy(200,5,"please input your information");
    rectangle(200,60,500,80);
    printf("\n\n\n\n\t\t pound =  ");
    push(&money, 6);
    scanf("%f",money);
    rectangle(200,113,500,94);
    printf("\n\t\t  bitcoin =  %.2f", multiplyTwoLists(taka,money));
    nextcome();
    getch();
}

