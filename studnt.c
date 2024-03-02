//custom cursor position + colored text+ masked password protection system
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

//defining different color codes
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
//defining struct for student information
struct student
{
    char name[100];
    char id[100];
    char email[100];
};

struct student students[100];
//this student count keeps track of students index
int student_count=0;

// Function declarations
void Password(void);
void MainMenu(void);

// Global variable
char correctPassword[10] = "project";

// Function to move cursor to specific position
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// Function to set text color
void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//password
void Password(void) {
    system("cls");
    char d[28] ="Password Protected";
    char ch, pass[10];
    int i = 0, j;

    gotoxy(15, 4);
    for (j = 0; j < 20; j++)
        printf(CYAN "*" RESET);
    for (j = 0; j < 20; j++)
        printf(CYAN "%c" RESET, d[j]);
    for (j = 0; j < 20; j++)
        printf(CYAN "*" RESET);

    gotoxy(15, 7);
    printf(CYAN "Enter Password:"RESET);

    while ((ch = getch()) != 13) {
        if (ch != 8) {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';

    if (strcmp(pass, correctPassword) == 0) {
        gotoxy(15, 9);
        printf(GREEN "Password match" RESET);
        gotoxy(15, 10);
        printf(GREEN "Press any key to continue..." RESET);
        getch();
        MainMenu();
    } else {
        gotoxy(15, 16);
        printf(RED "\aWarning!! Incorrect Password" RESET);
        gotoxy(15,18);
        printf(YELLOW "\aPress any key to try again........." RESET);
        getch();
        Password();
    }
}
//function inside main menu
void add_student()
{
    system("cls");
    gotoxy(6,2);
    printf(CYAN"Enter student information below.............."RESET);
    gotoxy(6,4);
    printf(CYAN"Enter Name: "RESET);
    getchar();
    gets(students[student_count].name);
    gotoxy(6,6);
    printf(CYAN"Enter ID: "RESET);
    gets(students[student_count].id);
    gotoxy(6,8);
    printf(CYAN"Enter email: "RESET);
    gets(students[student_count].email);
    gotoxy(6,10);
    student_count++;
    gotoxy(6,10);
    printf(CYAN"Data stored successfully"RESET);
    gotoxy(6,14);
    printf(CYAN"------------------------------------------\n"RESET);
}

void view_student()
{

    int i;
    if (student_count == 0)
    {
        printf("No Student!");
    }
    else
    {
        printf(CYAN"\nName\t\tId\t\temail\n"RESET);
        for(i=0; i<student_count;i++)
        {
        printf(CYAN"%s\t\t%s\t\t%s\n"RESET,students[i].name,students[i].id, students[i].email);
        }
    }
        printf(RED"------------------------------------------\n"RESET);
}

void delete_student()
{

}


void MainMenu() {
    system("cls");

    int n;
    gotoxy(10,5);
    printf(GREEN"======================This is main menu=====================\n"RESET);

    while(1)
    {

        gotoxy(10,8);
       // printf("\xB2\xB2\xB2 1. Add Student \xB2\xB2\xB2 2. View Student \xB2\xB2\xB2 3. Delete Student \xB2\xB2\xB2 4. Exit\n
                 printf(GREEN"\xB2\xB2\xB2 1.Add Student"RESET);
                 gotoxy(10,10);
                 printf(GREEN"\xB2\xB2\xB2 2.View student"RESET);
                 gotoxy(10,12);
                 printf(GREEN"\xB2\xB2\xB2 3.Delete Student"RESET);
                 gotoxy(10,14);
                 printf(GREEN"\xB2\xB2\xB2 4.Exit "RESET);
gotoxy(10,18);
                 printf(CYAN"Enter the corresponding number for selecting menu: "RESET);
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            add_student();
            break;
        case 2:
            view_student();
            break;
        case 3:
            delete_student();
            break;
        case 4:
            exit(0);

        }
        system("cls");
    }
}

int main() {
    Password();
    getch();
    return 0;
}
