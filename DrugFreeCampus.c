#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct student{
    char nam[50];
    char mail[50];
    int phn;
    char blood[50];
    char date[12];
    char sts[20];
}s;

FILE *fp;
long sz=sizeof(s);

int main(){

    int ch;
    int pass;
         time_t t;
         time(&t);
         printf("Code Compiling Time %s\n",ctime(&t));
            printf("Hello There !!!!!  \tInput password to Enter Admin Pannel\n");
            printf("\nInput the password: ");
            scanf("%d",&pass);
    {
     	                     if (pass==2424)
	                  {
		              printf("Correct password,\n");
		              printf("\n\t \t  **Welcome to PROGECT ANTI-GRUG**\n");
		              printf("\n\t \t  Turn Your Back On Drugs And Face Your Dreams\n");

                      }
                       else
                        {
                       printf("Password incorrect Restart the Program\n");
                       _Exit(0);


    }
    }

    while(1){
        printf("\n\t\t\t\t<***ANTI DRUG***>\n");
        printf("1.Add New Data\n");
        printf("2.List of Data\n");
        printf("3.Search\n");
        printf("0.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
        case 0:
            exit(0);

        case 1:
            add();
            break;

        case 2:
            list();
            break;

        case 3:
            src();
            break;

        default:
            printf("Invalid Choice...\n\n");

        }
        printf("Press Any Key To Continue...");
        getch();
    }

    return 0;
}


void add(){
    char date[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(s.date,date);

    fp = fopen("New.txt", "ab");
    printf("Enter Name : ");
    fflush(stdin);
    gets(s.nam);
    printf("Enter Email : ");
    fflush(stdin);
    gets(s.mail);
    printf("Enter phone : ");
    scanf("%d",&s.phn);
    printf("Enter Blood : ");
    fflush(stdin);
    gets(s.blood);
    printf("Type data of that student  : ");
    fflush(stdin);
    gets(s.sts);
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
}


void list (){

    system("cls");
    printf("List of the student\n");
    printf("%-20s %-20s %-20s %-20s %s\n\n", "Name", "Email", "phone", "Blood","Status Of Test","date");

    fp = fopen("New.txt", "rb");
    while(fread(&s, sizeof(s), 1, fp) == 1){
        printf("%-20s %-20s %-20d %-20s %-20s %s\n", s.nam, s.mail, s.phn, s.blood, s.sts,s.date);
    }

    fclose(fp);
}
void src()
{


int ch;
while(1)
{
  system("cls");
  printf("Tested Data Search\n");
  printf("1.Search With Name\n");
  printf("2.Search with Email Adress\n");
  printf("0.Back To Main\n");
  printf("Enter your choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
  case 0 :
    main();
    break;
  case 1 :
    srcnm();
    break;
  case 2 :
    srcem();
    break;
  }
  getch();
}
}
  void srcnm()
  {
      char na[30];
      int f=0;
      printf("Enter student name to Search\n");
      fflush(stdin);
      gets(na);
      printf("%-20s %-20s %-20s %-20s %s\n\n", "Name", "Email", "phone", "Blood","Status Of Test","date");
      fp=fopen("New.txt","rb");
      while(fread(&s,sz,1,fp)==1)
      {
          if(strcmpi(na,s.nam)==0){
            f=1;
             printf("%-20s %-20s %-20d %-20s %-20s %s\n", s.nam, s.mail, s.phn, s.blood, s.sts,s.date);
             break;
          }
      }
      fclose(fp);
      if(f==0){
        printf("Data Found\n");
      }
      else{
        printf("data found\n");
      }
  }
  void srcem()
  {
      char uu[30];
      int f=0;
      printf("Enter student Email to Search\n");
      fflush(stdin);
      gets(uu);
      printf("%-20s %-20s %-20s %-20s %s\n\n", "Name", "Email", "phone", "Blood","Status Of Test","date");
      fp=fopen("New.txt","rb");
      while(fread(&s,sz,1,fp)==1)
      {
          if(strcmpi(uu,s.mail)==0){
            f=1;
             printf("%-20s %-20s %-20d %-20s %-20s %s\n", s.nam, s.mail, s.phn, s.blood, s.sts,s.date);
             break;
          }
      }
      fclose(fp);
      if(f==0){
        printf("Data Found\n");
      }
      else{
        printf("data found\n");
      }
  }
