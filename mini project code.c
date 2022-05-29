#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>


typedef struct voter_information {
    char id[10];
    char name[20];
    char birth_date[15];
    char f_name[20];
    char m_name[20];
    struct voter_information *next;
} node;

node *head;

int count1=0, count2=0,count3=0,count4=0,count5=0;
void main_loges();
void voter_insert();
void admin();
void exit();
void winner();
void not_again();
void voting();
void stop();
void show();
void registration();
void updateVoteDone(char[50]);
#define BUFFER_SIZE 1000

int main(){

    system("cls");
    printf("\n\n\n");
    printf(" \t\t\t    ----------- WELCOME TO ONLINE VOTING SYSTEM ---------- \n\n");
    printf("\t\t\t     --------**************************************-------- \n\n");
    printf("\t\t\t     ----- Please enter 1 for logging vote Main Loges ----- \n\n\n\n");

    int choice=0;
    scanf("%d",&choice);

     if(choice==1){
        main_loges();
    }
    return 0;
}

void main_loges(){

system("cls");
printf("\n\n\n\n");
printf("\t\t\t\t  *** MAIN MENU ***\n\n");

printf(" \t\t\t\t1.. FOR VOTER REGISTRATION ------- ||| \n");
Sleep(300);

printf(" \t\t\t\t2. FOR VOTER ENTRY ------- ||| \n");
Sleep(300);

printf(" \t\t\t\t3. FOR ADMIN PANEL ------- ||| \n");
Sleep(300);

printf(" \t\t\t\t4. FOR WINNER ------- ||| \n");
Sleep(300);

printf(" \t\t\t\t5. FOR EXIT ------- ||| \n\n\n");
Sleep(300);

printf("    \t  ------- After voter entry you can give your vote Otherwise you can not ----- \n\n\n\n ");
Sleep(500);

printf("    \t  ------- So please Enter 1 ----- \n\n\n\n ");

int T;
scanf("%d", &T);

if(T==1){
    registration();

}

if(T==2){
    voter_insert();

}

if(T==3){
     admin();

}

if(T==4){
    winner();

}

if(T==5){
    exit(0);
}

}

void registration(){
    printf("In registration \n");
    system("cls");
    printf("\n\n\n\n\n");

    FILE *fp;
    char ch;
    char dataToAppend[BUFFER_SIZE];

     fp=fopen("C:\\Users\\hamsa\\OneDrive\\Documents\\mini project file.txt","a");
    if(fp==NULL)
    {
        printf("file not present");
    }

    char id[10];
    printf("\t  \n\n");
    gets(id);


    char name[40];
    char birth_date[40];
    char f_name[40];
    char m_name[40];

    Sleep(300);
    printf("\t Enter your Name \n\n");
    gets(name);

    printf("\t Enter your Birth date \n\n");
    gets(birth_date);

    printf("\t Enter your Father name \n\n");
    gets(f_name);


    printf("\t Enter your Mother name \n\n");
    gets(m_name);

    fprintf(fp,name);
    fprintf(fp, "_");
    fprintf(fp,birth_date);
    fprintf(fp, "_");
    fprintf(fp,f_name);
    fprintf(fp, "_");
    fprintf(fp,m_name);
    fprintf(fp, "_\n");
    fclose(fp);

    //printf("End of registration \n");

    printf("  \t\t\t----- Please enter 1 for logging vote Main Loges ----- \n\n\n\n");

    int choice=0;
    scanf("%d",&choice);

     if(choice==1){
        main_loges();
    }

}

int cunt=0,count=0,R=3;
void voter_insert(){

    char id[10],name[25],birth_date[15],f_name[25],m_name[25];
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t\t IF ALL THE DETAILS MATCH,YOU CAN CAST YOUR VOTE OTHERWISE YOU CANNOT.\n\n");

    Sleep(300);
    printf("\t\tPlease ....");
    Sleep(300);

    printf("\t  \n\n");
    gets(id);

    Sleep(300);
    printf("\t Enter your Name \n\n");
    gets(name);

    printf("\t Enter your Birth date \n\n");
    gets(birth_date);

    printf("\t Enter your Father name \n\n");
    gets(f_name);

    printf("\t Enter your Mother name \n\n");
    gets(m_name);

    //system("cls");
    printf("\n\n\n\n\n");

    FILE *fp;
    char ch;

    char line[256];
    Sleep(300);

    fp=fopen("C:\\Users\\hamsa\\OneDrive\\Documents\\mini project file.txt","r");

    bool found=false;
    bool name_found=false;
    bool dob_found=false;
    bool fname_found=false;
    bool mname_found=false;



    int first=0;
    int second=0;
    int i,j,ctr;
    char newString[30][30];
    char lineData[100];

    if(fp==NULL){
        printf("file not present");
    }else{
       // printf("In Else fp==NULL");
        while (fgets(line, sizeof(line), fp)) {//end of file
        //printf("%s", line);
        j=0; ctr=0;

		for(i=0;i<=(strlen(line));i++){
			// if _ or NULL found, assign NULL into newString[ctr]
			if(line[i]=='_'||line[i]=='\0')
			{
				newString[ctr][j]='\0';
				ctr++;  //for next word
				j=0;    //for next word, init index to 0
			}
			else
			{
				newString[ctr][j]=line[i];
				j++;
			}
		}

		for(i=0;i < ctr;i++){
			if(strcmp(newString[0],name)==0 && strcmp(newString[1],birth_date)==0 && strcmp(newString[2],f_name)==0 && strcmp(newString[3],m_name)==0){
			found=true;
			fclose(fp);
			//updateVoteDone(line);
			voting();
		}

		}
		    }
    if(!found){
            //system("cls");
        printf("USER NOT FOUND. Please reenter with correct details \n");
        Sleep(4000);
        main_loges();
    }

}
}


void updateVoteDone(char line[50]){
    FILE *fp;
fp=fopen("C:\\Users\\hamsa\\OneDrive\\Documents\\mini project file.txt","r");
printf("in updateVoteDone--- %s\n",line);
char line1[50];
FILE *in = fopen( "C:\\Users\\hamsa\\OneDrive\\Documents\\mini project file.txt", "r" );
FILE *out = fopen( "C:\\Users\\hamsa\\OneDrive\\Documents\\mini project file.txt.tmp", "w+" );



if(fp==NULL){
        printf("file not present");
    }else{
        while (fgets(line1, sizeof(line1), fp)) {//end of file
        //printf("iN WHILE  %s", line1);
        }
    }
 while (fgets(line1, sizeof(line1), fp)) {//end of file

    printf("line1 =  %s\n",line1);

    if(strcmp(line1,line)==0)
    {
        printf(" equal\n");
        printf("%s%s", line1,line);
        break;
    }

}

printf("End of updateVoteDone ");
}//end of updateVoteDone()

void voting(){

     system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t   --------- List of Candidates --------\n\n");
    Sleep(300);

    printf("\t\t\t\t\t NAME               SYMBOL \n\n");
    Sleep(300);
    printf("\t\t\t\t\t  1. Maya           1. Boat\n");
    printf("\t\t\t\t\t  2. Sowmmya        2. Cycle\n");
    printf("\t\t\t\t\t  3. Harsha         3. Palm\n");
    printf("\t\t\t\t\t  4. Sparsh         4. Farmer\n");
    printf("\t\t\t\t\t  5. Vachana        5. tree                                                                                       \n");

    int B,j;
    printf("\tPlease....\n");
    printf("\t\t\t\t\t Enter your choice....\n");
    for(j=1;j<=1;j++){
        scanf("%d", &B);
        if(B==1){
            count1++;
        }
        if(B==2){
            count2++;
        }
        if(B==3){
            count3++;
        }
        if(B==4){
            count4++;
        }
        if(B==5){
            count5++;
        }
        if(B !=1 && B !=2 && B!=3 && B!=4 && B!=5){
            printf("\t\t\t  Your vote is invalid \n\n");
            main_loges();
        }
    }

    int R;
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t If you want see present winner Enter 1 or zero (0) for main Loges\n\n\n");
    scanf("%d",&R);
    if (R==1)
    {
        winner();
    }
    if(R != 1)
    {
        main_loges();
    }

}

void admin()
{
    int B;
    printf("\n\n\n\n");
    printf("\t\t\tEnter password to unlock admin pane\n\n\n");
    scanf("%d",&B);
    if(B==2021)
    {
        show();
    }
    else
    {
        printf("wrong password\n");
    }
}

void show()
{
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t---- Count of votes for each candidate ----- \n\n\n");
    Sleep(300);
    printf("\t\t\t\t  *** Maya    got  %d  votes ***\n",count1);
    Sleep(300);
    printf("\t\t\t\t  *** Sowmya  got  %d  votes *** \n", count2);
    Sleep(300);
    printf("\t\t\t\t  *** Harsha  got  %d  votes ***\n", count3);
    Sleep(300);
    printf("\t\t\t\t  *** Sparsh  got  %d  votes ***\n", count4);
    Sleep(300);
    printf("\t\t\t\t  *** Vachana got  %d  votes ***\n", count5);
    Sleep(300);

    int R;
    printf("\t\t\t \n Enter 1 for main loges or 0 for exit\n");
    scanf("%d",&R);
    if (R==1)
    {
        main_loges();
    }
    else
    {
        exit(0);
    }
}

 void winner()
 {
     system("cls");
     printf("\n\n\n");
     if(count2<count1 && count3<count1 && count4<count1 && count5<count1)
        printf("\t\t\t*** present winner is Maya and got %d votes ***\n\n\n",count1);

     if(count1<count2 && count3<count2 && count4<count2 && count5<count2)
        printf("\t\t\t*** present winner is Sowmya and got %d votes ***\n\n\n",count2);

     if(count1<count3 && count2<count3 && count4<count3 && count5<count3)
        printf("\t\t\t*** present winner is Harsha and got %d votes ***\n\n\n",count3);

     if(count1<count4 && count2<count4 && count3<count4 && count5<count4)
        printf("\t\t\t*** present winner is Sparsh and got %d votes ***\n\n\n",count4);

     if(count1<count5 && count2<count5 && count3<count5 && count4<count5)
        printf("\t\t\t*** present winner is Vachana and got %d votes *** \n\n\n",count5);


     int T;
     printf("\t\t\t Enter one(1) for main loges or zero(0) for exit \n");
     scanf("%d",&T);
     if(T==1)
     {
         main_loges();
     }
     if(T!=1)
     {
         exit(0);
     }
 }

void stop(){

system("cls");
printf("\t------1-sorry u can't vote ,for ur wrong entry 3 times-1--------\n\n\n\n");
Sleep(300);
printf("\t\t\t*******-----please try Again after some moment------******\n\n\n");
Sleep(300);
printf("\t\t\t\t\t---------thank you----------\n\n\n\n");
Sleep(300);
}

void not_again()
{
    system ("cls");
    printf("\n\n\n\n");
    printf("\t\t----- You have given your vote successfully-----\n\n");
    Sleep(300);
    printf("   \t\t-----You can't vote for 2nd time-----\n\n\n");
    Sleep(300);
    printf("\t\t\t If you want see present winner Enter 1 or two(2) for main Loges\n\n\n");
    Sleep(300);
    printf("\t\t\t\t zero for Exit \n\n");
    scanf("%d",&R);
    if(R==1)
    {
        main_loges();
    }
    if((R != 1) || (R != 2))
    {
        exit(0);
    }
}
/*void exit(0)
{
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t----- You have given your vote successfully --------\n\n\n");
    Sleep(300);
    printf("\t\t\t\t******-----THANK YOU------*****\n\n\n");
    Sleep(300);
}*/
