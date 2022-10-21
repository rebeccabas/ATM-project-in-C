#include<stdio.h>           //Inclusion
#include<conio.h>           //Of
#include<string.h>          //Header
#include<stdlib.h>          //Files
#include<time.h>            //Is
#include<windows.h>         //Done
#include<ctype.h>           //In This Section

//global variables
int i,count;
char pin[4];
unsigned long amount=5000, deposit, withdraw;
int choice, k;
char transaction = 'y';


//structure
struct login
{
    char fname[30];
    char lname[30];
    char username[30];
    char password[30];
    char pin[4];
}l;


//function prototype
void registration();
void login();
void nwelc();
void welcome();

//main function
void main()
{
 int option;
 system("color 3F");
 welcome();
    start:
     printf("\n\n");

    printf("\t\t\t\t\t");
    printf("-->Enter '1' to register a new account.\n");
    Sleep(750);
    printf("\t\t\t\t\t");
    printf("-->Enter '2' to login \n"); 
    Sleep(750);
    printf("\t\t\t\t\t");
    printf("-->Enter '3' to exit \n"); 
    Sleep(750);
    printf("\t\t\t\t\t");
     printf("\n\n");
     printf("\t\t\t\t\t\t\t\t");
    printf("Enter '1', '2' or '3':   "); 
    scanf("%d",&option);        

    if(option == 1)
        {
            system("CLS");
            
            registration();
        }

          else if(option == 2)
        {
            system("CLS");
            login();
        }

        else if(option == 3)
        {
            end:
          system("CLS");
          int i;
 
            printf("\t\t\t\t\t");
            for (i = 1; i <= 100; i++)
            {
            printf("=");
            Sleep(25);
            }
            printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t");
            printf("THANKYOU FOR USING BCT BANK ATM\n");
            printf("\n\n\n\n");
            printf("\t\t\t\t\t");
            for (i = 1; i <= 100; i++)
            {
            printf("=");
            Sleep(25);
            }
                }
        else 
        {
          
            printf("\t\t\t\t\t");
            printf("Enter a valid option");
            Sleep(1500);
            system("CLS");
            nwelc();
            goto start;




        }
            
        
}

void registration() //this function stores the value of first name, last name, username, password and pincode input by the user
{
   
    nwelc();
    FILE *log;

    log=fopen("login.bin","w");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
    printf("\n\n");

    printf("\t\t\t\t\t");
    printf("Welcome to BCT ATM Services. Please provide the following information to proceed.\n\n");
    Sleep(500);
    printf("\t\t\t\t\t");
    printf("\n\n");
    printf("\t\t\t\t\t");
    printf("Enter First Name:  ");
    scanf("%s",l.fname);
    printf("\n\n");
    printf("\t\t\t\t\t");
    printf("Enter Surname:  ");
    scanf("%s",l.lname);

    Sleep(1000);
    printf("\n\n\t\t\t\t\t\t\t\t****Thank you.****");
    Sleep(1000);
    system("CLS");
    nwelc();
    printf("\n\n");
    printf("\t\t\t\t\t");
     
    printf("------Now please choose a username and password as credentials for system login.------");
     

    printf("\n\t\t\t\t\t");

    printf("-->Ensure the username is no more than 30 characters long.");
    Sleep(250);
    printf("\n\t\t\t\t\t");
    printf("-->Ensure your password is at least 8 characters long and contains lowercase, uppercase, numerical and special character values.\n");
    printf("\n\n");
    printf("\t\t\t\t\t"); 

    printf("Enter Username:  ");
    scanf("%s",l.username);
     printf("\n\n");
     printf("\t\t\t\t\t"); 
    printf("Enter Password:  ");
    scanf("%s",l.password);
     printf("\n\n");
     printf("\t\t\t\t\t"); 
     printf("Enter Pin:  ");
    scanf("%s",l.pin);
    fwrite(&l,sizeof(l),1,log);
    fclose(log); 

    Sleep(500);
    printf("\n\n");
    printf("\t\t\t\t\t");
    printf("Confirming details......\nWelcome, %s!",l.fname);
    
    printf("Registration Successful!");
    Sleep(500);
    printf("Press any key to continue...");
    
     getchar();
    system("CLS");
    nwelc();
    login();
}

void login() // this function reads the data from the earlier file and checks if the entered data and stored data are correct
             //if correct it proceeds to ATM dashboard
{
char username[30],password[20];
    FILE *log;

    log = fopen("login.bin","r");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);

        exit(1);
    }

    struct login l;
    nwelc();
    printf("\t\t\t\t\t"); 

    printf("\n\t\t\t\t\tPlease Enter your login credentials below\n\n");
    printf("\t\t\t\t\t"); 
    printf("Username:  ");
    scanf("%s",username);
    printf("\n\n");
    printf("\t\t\t\t\t"); 
    printf("Password: ");
    scanf("%s",password);
    
     while(fread(&l,sizeof(l),1,log))
        {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)

            {   
                printf("\n\t\t\t\t\tSuccessful Login\n");
                Sleep(500);
                system("CLS");
                nwelc();
                

               pincode:
                printf("\n\n");
                printf("\t\t\t\t\t");
                printf("Enter The Pincode : ");
                 while(pin[i]!=4)
                     {
                        pin[i]=_getch();
                        if(pin[i]==4)
                        break;
                        printf("*");
                        i++;
                      }
                pin[i]='\0';
                if(strcmp(pin,l.pin)==1)
                {
                  Beep(610, 500);
                  printf("\n\n");
                  printf("\t\t\t\t\t"); 
                  printf("Invalid pin!!!");
                  Sleep(250);
                   count++;
                 
                  
                     if (count == 3 && (strcmp(pin,l.pin)==1))
                {
                Sleep(150);
                printf("\n\n");
                printf("\t\t\t\t\t");
                printf("!!You have entered incorrect pincode 3 times. Try again later!!");
                printf(" \n\t\t\t\t\tEXITING");
                Sleep(250);
                for (i = 1; i <= 5; i++)
                {
                    printf(".");
                    Sleep(500);
                }
                break;
                
                exit(0);
                
                }
                goto pincode; //returns to pincode
                            }
                else if(strcmp(pin,l.pin)==0)  //if the pincode matches

                services:
                system("CLS");
                nwelc();
                printf("\n\n\t\t\t\t\t\t\t\t");
                printf("======== Available Services ========\n\n");
                printf("\t\t\t\t\t\t\t\t");
                printf("1. Check Balance\n");
                printf("\t\t\t\t\t\t\t\t");
                printf("2. Withdraw Cash\n");
                printf("\t\t\t\t\t\t\t\t");
                printf("3. Deposit Cash\n");
                printf("\t\t\t\t\t\t\t\t");
                printf("4. Quit\n");
                printf("\n\n");
                printf("\t\t\t\t"); 
                printf("******************************************************************************************************\n\n");
                printf("\t\t\t\t");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                system("CLS");
    switch (choice)
    {
    case 1:
      printf("\n\t\t\t\t\t YOUR BALANCE IS Rs%lu ", amount);
      break;
    case 2:

      printf("\n\t\t\t\t\t ENTER THE AMOUNT TO WITHDRAW: ");
      scanf("%lu", &withdraw);
      if (withdraw % 100 != 0)
      {
        printf("\n\t\t\t\t\t PLEASE ENTER THE AMOUNT IN MULTIPLES OF 100");
      }
      else if (withdraw > (amount - 500))
      {
        printf("\n\t\t\t\t\t INSUFFICENT BALANCE");
      }
      else
      {
        amount = amount - withdraw;
        printf("\n\n\t\t\t\t\t PLEASE COLLECT CASH");
        printf("\n\t\t\t\t\t YOUR CURRENT BALANCE IS Rs%lu", amount);
      }
      break;
    case 3:
      printf("\n\t\t\t\t\t ENTER THE AMOUNT TO DEPOSIT ");
      scanf("%lu", &deposit);
      amount = amount + deposit;
      printf("\n\t\t\t\t\tYOUR BALANCE IS Rs%lu", amount);
      break;
    case 4:
      break;
    default:
      printf("\n INVALID CHOICE");
      break;
    }

    printf("\n\n\n\t\t\t\t DO U WISH TO HAVE ANOTHER TRANSCATION?(y/n): ");
    fflush((&_iob[STDIN_FILENO]));
    scanf(" %c", &transaction);

    if(transaction == 'n' || transaction == 'N')
    {

      k = 1;
 
  printf("\n\n\t\t\t\t THANK YOU FOR USING BCT Bank ATM SERVICE");
  printf("\n\t\t\t\tEXITING");
  Sleep(250);
  for (i = 1; i <= 5; i++)
  {
    printf(".");
    Sleep(500);
    break;
  }
    }
  else if(k!=1)
  {
  goto services;
       
                  }
            }
        else 
            {

                printf("\n\t\t\t\tIncorrect Login Details\n\t\t\t\tPlease enter the correct credentials. You will now be redirected to the main page.\n");
                 Sleep(1500);
                system("CLS");
                main();
            }
        }

    fclose(log);
}

    
void welcome()
{
    int i;
 
    printf("\t\t\t\t\t");
    for (i = 1; i <= 100; i++)
    {
       printf("=");
       Sleep(25);
    }
     printf("\n\t\t\t\t\t\t\t\t\t\t");
     printf("WELCOME TO BCT BANK ATM\n");
     printf("\t\t\t\t\t");
    for (i = 1; i <= 100; i++)
    {
       printf("=");
       Sleep(25);
    }
}
void nwelc()
{
    int i;
    system("CLS");
    printf("\t\t\t\t\t");
    for (i = 1; i <= 100; i++)
    {
       printf("=");
     
    }
     printf("\n\t\t\t\t\t\t\t\t\t\t");
     printf("WELCOME TO BCT BANK ATM\n");
     printf("\t\t\t\t\t");
    for (i = 1; i <= 100; i++)
    {
       printf("=");

    }
}






