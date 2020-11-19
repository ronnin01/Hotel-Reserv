#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h> // <- kani nga library is time ni pwede nato ma kuha ang time current time sa inyu pc or laptop

void add();  //kani sila kay functions rani kahebaw naman mo ani
void list();
void edit();
void delete1();
void search();

struct CustomerDetails{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];   //nag struct ko para dili katag ang atong data kung mo add ta mo delete or mo edit
	char nationality[15];
	char email[20];
	char period[10];
	char arrivaldate[10];
}s;

/*
if naa mo na libgan pangutana lang mo nako hahahah sorry na dugay gamay na busy sa personal life hahaha but anyways kita ta soon maybe monday adto mi ila lawlaw ayaw lang sa amo kay layu na kaayu
kalas plete sa amo hahahaha, then kalimot ko sa fflush guys ako pani e search para unsa ni siya nga function

 -then naa ta ko e add if ang room number kay na book nah dapat walay mag ka pareha pero sige lang on process paman ni ma human ra nya ni puhon-
*/
int main(){
	int i=0;

	time_t t; // kaning time_t kay para sa time ni siya
	time(&t);
	char customername;
	char choice;

    system("cls");// to clear the screen and cls
	system("Color a");
 	printf("\t\t***********************************************\n");
	printf("\t\t*                                             *\n");
	printf("\t\t*       -----------------------------         *\n");
	printf("\t\t*         Group 1 Hotel Reservation           *\n");
	printf("\t\t*       -----------------------------         *\n");
	printf("\t\t*                                             *\n");
	printf("\t\t***********************************************\n\n\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");
	printf(" \n Press any key to continue:");
	getch(); // kaning getch kay para dili nalang mag enter enter ang user lahus nalang siya pislit sa key para wala nay hasul kung mag enter pa ang user ug number
    system("cls");
	while (1){
		system("cls");
		printf("\n");
		printf("   ******************************  |HOTEL RESERVATION MANAGEMENT|  ***************************** \n");
		printf("\n");
		printf("\t\t *Please enter your choice for menu*:");
		printf("\n\n");
		printf(" \n\t Enter 1 -> Book a room");
		printf("\n\t------------------------");
		printf(" \n\t Enter 2 -> View Customer Record");
		printf("\n\t----------------------------------");
		printf(" \n\t Enter 3 -> Delete Customer Record");
		printf("\n\t-----------------------------------");
		printf(" \n\t Enter 4 -> Search Customer Record");
		printf("\n\t-----------------------------------");
		printf(" \n\t Enter 5 -> Edit Record");
		printf("\n\t-----------------------");
		printf(" \n\t Enter 6 -> Exit");
		printf("\n\t-----------------");
		printf("\n");
		for(i=0;i<80;i++){
           printf("-");
		}
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(i=0;i<80;i++){
            printf("-");
	    }

		choice=getche(); // same rani sila sa getch pero ang getch dili makita dili ma print sa console kung unsa imo ge pislit while sa kaning getche kay makita
		switch(choice){
			case '1':
				add();
				break;
			case '2':
				list();
				break;
			case '3':
				delete1();
				break;
			case '4':
				search();
				break;
			case '5':
				edit();
				break;
			case '6':
				system("cls");
				printf("\n\n\t *****THANK YOU*****");
				printf("\n\t FOR TRUSTING OUR SERVICE\n\n\n\n\n\n\n\n\n\n\n\n");
				exit(0);
				break;
		}
	}

	return 0;
}

//basaha lang nya ninyu ang codes sa add basin naay error hahaha na kalimot nako sa c gud pero sige lang basin naa mo ganahan e add or naay error sulti.e lang ko or kamo ra add or ilis okay ra
// AYAW MO KALIMOT KANANG DOT LIKE SA s.roomnumber KANANG DOT IS LIKE SILBE GE TAWAG RANA NEMU NGA REFERENCE FROM S NGA STRUCT
void add(){
	FILE *f;
	char test;
	f=fopen("add.txt","a+");
	if(f==0){
        f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while(1){
		system("cls");
		printf("\n Enter Customer Details:");
		printf("\n**************************");
		printf("\n Enter Room number:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Enter Name:\n");
		scanf("%s",s.name);
		printf("Enter Address:\n");
		scanf("%s",s.address);
		printf("Enter Phone Number:\n");
		scanf("%s",s.phonenumber);
		printf("Enter Nationality:\n");
		scanf("%s",s.nationality);
		printf("Enter Email:\n");
		scanf(" %s",s.email);
		printf("Enter Period(\'x\'days):\n");
		scanf("%s",&s.period);
		printf("Enter Arrival date(dd\\mm\\yyyy):\n");
		scanf("%s",&s.arrivaldate);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\n1 Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		if(test==27)
			break;

	}
	fclose(f);
}

//e display niya a list sa records na ni book og room
void list(){
	FILE *f;
	int i;
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("ROOM    ");
	printf("NAME\t ");
	printf("\tADDRESS ");
	printf("\tPHONENUMBER ");
	printf("\tNATIONALITY ");
	printf("\tEMAIL ");
	printf("\t\t  PERIOD ");
	printf("\t ARRIVALDATE \n");

	for(i=0;i<118;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1){
		printf("\n%s \t%s \t\t%s \t\t%s \t%s  \t%s  \t     %s  \t  %s",s.roomnumber, s.name , s.address , s.phonenumber ,s.nationality ,s.email,s.period,  s.arrivaldate);
	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();
}

//deletion sa nag book ug room or cancel booking
void delete1(){
	FILE *f,*t;
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)
        exit(0);
	if((f=fopen("add.txt","r"))==NULL)
        exit(0);
	system("cls");
	printf("Enter the Room Number of the hotel to be deleted: \n");
	fflush(stdin);
	scanf("%s",roomnumber);
	while(fread(&s,sizeof(s),1,f)==1){
		if(strcmp(s.roomnumber,roomnumber)==0){
            i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1){
		printf("\n\n Records of Customer in this  Room number is not found!!");
		//remove("E:/file.txt");
	   //rename("E:/temp.txt","E:/file.txt");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	printf("\n\nThe Customer is successfully removed....");
	fclose(f);
	fclose(t);
	getch();
}

//e search ang ge book nga room
void search(){
    system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Enter Room number of the customer to search its details: \n");
	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f)==1){
		if(strcmp(s.roomnumber,roomnumber)==0){
			flag=0;
			printf("\n\tRecord Found\n ");
			printf("\nRoom Number:\t%s",s.roomnumber);
			printf("\nName:\t%s",s.name);
			printf("\nAddress:\t%s",s.address);
			printf("\nPhone number:\t%s",s.phonenumber);
			printf("\nNationality:\t%s",s.nationality);
			printf("\nEmail:\t%s",s.email);
			printf("\nPeriod:\t%s",s.period);
			printf("\nArrival date:\t%s",s.arrivaldate);
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("\n\tRequested Customer could not be found!");
	}
	getch();
	fclose(f);
}

//e edit ang ge book nga room pero sige lang ma explain ra gyud ni nako soon
void edit(){
	FILE *f;
	int k=1;
	char roomnumber[20];
	long int size=sizeof(s);
	if((f=fopen("add.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Room number of the customer to edit:\n\n");
	scanf("%[^\n]",roomnumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1){
		if(strcmp(s.roomnumber,roomnumber)==0){
			k=0;
			printf("\nEnter Room Number     :");
			gets(s.roomnumber);
			printf("\nEnter Name    :");
			fflush(stdin);
			scanf("%s",&s.name);
			printf("\nEnter Address        :");
			scanf("%s",&s.address);
			printf("\nEnter Phone number :");
			scanf("%f",&s.phonenumber);
			printf("\nEnter Nationality :");
			scanf("%s",&s.nationality);
			printf("\nEnter Email :");
			scanf("%s",&s.email);
			printf("\nEnter Period :");
			scanf("%s",&s.period);
			printf("\nEnter Arrival date :");
			scanf("%s",&s.arrivaldate);
			fseek(f,size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	if(k==1){
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		fclose(f);
		getch();
	}else{
	fclose(f);
	printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
	getch();
    }
}
