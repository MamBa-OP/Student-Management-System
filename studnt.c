nclude<stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h> // Added to fix implicit declaration warning for strcmp
#include<conio.h> // Added for getch function

char departments[][10] = {"CSE", "SWE", "EEE", "NFE"}; // Corrected typo "catagories" to "categories"

void Password();
void mainmenu(void);
void addStudent(void);
void view(void);
void edit(void);
void delete(void); // Corrected function name to avoid conflict with reserved keyword
int getdata();
int checkid(int);

COORD coord = {0, 0}; // sets coordinates to 0,0
COORD max_res, cursor_size;

void gotoxy(int x, int y) {
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

FILE *fp;
int s;
char findStudent;
char password[10] = {"project"};

struct student {
    char name[50];
    int id;
    char email[50];
    char *dep;
    int studentNumber;
};

struct student a;

int main()

{
      Password();
      getch();
      return 0;

}

void mainmenu()
{

    system("cls");

    int i;
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Add Student");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. View Student");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. edit Student");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. delete info");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Close Application");
    gotoxy(20,15);

    printf("------------------------------------------");
    gotoxy(20,20);
    // t();
    gotoxy(20,21);
    printf("Enter your choice:");
    switch(getch())
    {
        case '1':
        addStudent();
        break;
    case '2':
        view();
        break;
        case '3':
        edit();
        break;
    case '4':
        delete();
        break;
    case '5':
    close();
    break;

    //     case '5':
    //     {
    //     system("cls");
    //     gotoxy(16,3);
    //     printf("Thanks for using the Program..");
    //     gotoxy(10,7);
    //     printf("Exiting in 5 second...........>");


    //     }
        default:
        {
        gotoxy(10,23);
        printf("\aWrong Entry!!Please re-entered correct option");
        if(getch())
        mainmenu();
        }

    }
}

void Password(void)
{

   system("cls");
   char d[25]="Password Protected";
   char ch,pass[10];
   int i=0,j;

    gotoxy(10,4);
    for(j=0;j<20;j++)
    {
    // delay(50);
    printf("*");
    }
    for(j=0;j<20;j++)
   {
   // delay(50);
   printf("%c",d[j]);
   }
   for(j=0;j<20;j++)
   {
   // delay(50);
   printf("*");
   }
   gotoxy(10,10);
   gotoxy(15,7);
   printf("Enter Password:");

   while(ch!=13)
   {
	ch=getch();

	if(ch!=13 && ch!=8){
	putch('*');
	pass[i] = ch;
	i++;
	}
   }
   pass[i] = '\0';
   if(strcmp(pass,password)==0)
   {

	gotoxy(15,9);
	printf("Password match");
	gotoxy(17,10);
	printf("Press any key to countinue.....");
	getch();
	mainmenu();
   }
   else
   {
	 gotoxy(15,16);
	 printf("\aWarning!! Incorrect Password");
	 getch();
	 Password();
   }
}



void addStudent(void)
{
    
    system("cls");
    int i;
    
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT DEPARTMENT");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 1. CSE");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 2. SWE");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 3. EEE");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 4. NFE");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Back to main menu");
    gotoxy(20,21);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,22);
    printf("Enter your choice:");
    scanf("%d",&s);
    if(s==5)
    mainmenu();
    
    system("cls");
    fp=fopen("another.dat","ab+");
    if(getdata()==1)
    {
    a.dep=departments[s-1];
    a.studentNumber=1;
    fseek(fp,0,SEEK_END);
    fwrite(&a,sizeof(a),1,fp);
    fclose(fp);
    gotoxy(21,14);
    printf("The record is sucessfully saved");
    a.studentNumber++;
    gotoxy(21,15);
    printf("Save any more?(Y / N):");
    if(getch()=='n')
        mainmenu();
    else
        system("cls");
        addStudent();
    }
}

int getdata()
{
    int t;
    gotoxy(20,3);
    printf("Enter the Information Below");

    gotoxy(21,5);
    printf("Department:");
    gotoxy(31,5);
    printf("%s",departments[s-1]);
    gotoxy(21,6);
    printf("Student ID:\t");
    gotoxy(33,6);
    scanf("%d",&t);
    if(checkid(t) == 0)
    {
        gotoxy(21,13);
        printf("\aThe student already exist\a");
        getch();
        mainmenu();
        return 0;
    }
    a.id=t;
    gotoxy(21,7);
    printf("Student Name:");gotoxy(36,7);
    scanf("%s",a.name);
    gotoxy(21,8);
    printf("Email:");gotoxy(28,8);
    scanf("%s",a.email);
    return 1;
}
int checkid(int t)  //check whether the student is exist in database or not
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
    if(a.id==t)
    return 0;  //returns 0 if student exists

    return 1; //return 1 if it doesn't exist
}


void edit (void){

};

void view(void)    //function to view students
{
    int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("*********************************Student List*****************************");
    gotoxy(2,2);
    printf(" DEPARTMENT     ID    STUDENT NAME     EMAIL");
    j=4;
    fp=fopen("another.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
    gotoxy(3,j);
    printf("%s",a.dep);
    gotoxy(20,j);
    printf("%d",a.id);
    gotoxy(24,j);
    printf("%s",a.name);
    gotoxy(36,j);
    printf("%s",a.email);
    printf("\n\n");
    j++;
      }

      gotoxy(3,25);
      printf("Total Students =%d",);
      fclose(fp);
      returnfunc();




}

void returnfunc(void)
{
    {
    printf(" Press ENTER to return to main menu");
    }
    a:
    if(getch()==13) //allow only use of enter
    mainmenu();
    else
    goto a;
}

void delete(void){

}

void close(void)
{
    system("cls");
    gotoxy(20,4);
    printf("\n");
    printf("\n");
    printf("Program closed successfully.............");
    printf("\n");
    printf("\n");
    printf("\n");
    //create a delay of this line and exit too
    exit(0);
}