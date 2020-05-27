#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>
#include<windows.h>
void add();
void list();
void edit();
void delete1();
void search();
struct node
{
    char data[25];
    struct node *next;
};struct node *head,*p,*nw,*newhead,*filedata;
int k;
struct node* readfromlist(struct node *start);
struct node* readnext(struct node *start,FILE *f);
struct CustomerDetails
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char period[10];
	char arrivaldate[10];
}s;
void main()
{
    time_t t;
    char use[20],c=' ';
    char pass[20];
    time(&t);
    int i=0;
    char choice;
    system("cls");
    printf("*********************************************************************************\n");
    printf("*                                                                               *\n");
    printf("*                                                                               *\n");
    printf("*                                                                               *\n");
    printf("*                                                                               *\n");
    printf("*                                                                               *\n");
    printf("*                                      WELCOME                                  *\n");
    printf("*                                                                               *\n");
    printf("*                                                                               *\n");
    printf("*                                HOTEL FORTUNE TOWER                            *\n");
    printf("*                                                                               *\n");
    printf("*                                                                               *\n");
    printf("*                                                                               *\n");
    printf("*                                                                               *\n");
    printf("*                                 HARSHIT SRIVASTAVA                            *\n");
    printf("*                                      19BCE0382                                *\n");
    printf("*********************************************************************************\n");
    for(i=0;i<80;i++)
		printf("-");
	    printf("\nLogin at : %s",ctime(&t));
    for(i=0;i<80;i++)
		printf("-");
    printf("\n");
    printf("Press ENTER to continue");
    getch();
    system("cls");
    printf("----------------------------------------\n");
    printf("                 LOGIN                  \n");
    printf("----------------------------------------\n");
    printf("               USERNAME:");
    scanf("%s",&use);
    printf("\n");
    printf("               PASSWORD:");
    i=0;
    while(i<20)
    {
        pass[i]=getch();
	    c=pass[i];
	    if(c==13)
        {
            break;
        }
        else
            printf("*");
	    i++;
    }
    pass[i]='\0';
    printf("\n");
    if(strcmp(use,"harshit")==0 && strcmp(pass,"19BCE0382")==0)
    {
        while (1)
        {
		system("cls");
		 for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("\t\t *Please enter your choice for menu*:");
		printf("\n\n");
		printf(" \n Enter 1 -> Book a room");
		printf("\n------------------------");
		printf(" \n Enter 2 -> View Customer Record");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Delete Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 4 -> Search Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 5 -> Edit Record");
		printf("\n-----------------------");
		printf(" \n Enter 6 -> Exit");
		printf("\n-----------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nLogin at : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");
		choice=getche();
		choice=toupper(choice);
		switch(choice)
		{
			case '1':
				add();break;
			case '2':
				list();break;
			case '3':
				delete1();break;
			case '4':
				search();break;
			case '5':
				edit();break;
			case '6':
				system("cls");
				printf("\n\n\t *****THANK YOU*****");
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
        }
    }
    else{
        printf("WRONG USER OR PASSWORD");
        exit(1);
    }
}
void add()
{
    nw=(struct node*)malloc(sizeof (struct node));
    strcpy(nw->data,"\0");
    nw->next=NULL;
    head=nw;
    p=nw;
	while(1)
    {
        system("cls");
		printf("\n Enter Customer Details:");
		printf("\n**************************\n");
        printf("Enter Room Number:\n");
        scanf("%s",&s.roomnumber);
        strcpy(head->data,s.roomnumber);
        head->next=NULL;

        printf("Enter Name:\n");
        scanf("%s",&s.name);
        nw=(struct node*)malloc(sizeof(struct node));
        p=head;
        while(p->next!=NULL)
            p=p->next;
        strcpy(nw->data,s.name);
        p->next=nw;
        nw->next=NULL;

        printf("Enter Address:\n");
        scanf("%s",&s.address);
        nw=(struct node*)malloc(sizeof(struct node));
        p=head;
        while(p->next!=NULL)
            p=p->next;
        strcpy(nw->data,s.address);
        p->next=nw;
        nw->next=NULL;

        printf("Enter Phone Number:\n");
        scanf("%s",&s.phonenumber);
        nw=(struct node*)malloc(sizeof(struct node));
        p=head;
        while(p->next!=NULL)
            p=p->next;
        strcpy(nw->data,s.phonenumber);
        p->next=nw;
        nw->next=NULL;

        printf("Enter Period:(days)\n");
        scanf("%s",&s.period);
        nw=(struct node*)malloc(sizeof(struct node));
        p=head;
        while(p->next!=NULL)
            p=p->next;
        strcpy(nw->data,s.period);
        p->next=nw;
        nw->next=NULL;

        printf("Enter Arrival Date:(DD/MM/YYYY)\n");
        scanf("%s",&s.arrivaldate);
        nw=(struct node*)malloc(sizeof(struct node));
        p=head;
        while(p->next!=NULL)
            p=p->next;
        strcpy(nw->data,s.arrivaldate);
        p->next=nw;
        nw->next=NULL;

        WriteInfile(head);
        printf("\n\n1 Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		char test=getche();
		if(test==27)
			break;
    }
}
void WriteInfile(struct node* start)
{
    FILE *f;
	f=fopen("hotelFT.txt","a+");
	if(f==0)
	{   f=fopen("hotelFT.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	struct node *j;
	j=start;
	while(j!=NULL)
    {
        fseek(f,0,SEEK_END);
        fwrite(j,sizeof(struct node),1,f);
        j=j->next;
    }
	fclose(f);
}
void list()
{
    int i;
	system("cls");
	printf("ROOM\t\t");
	printf("NAME\t");
	printf("\tADDRESS\t");
	printf("\tPHONENUMBER");
	printf("\t\tPERIOD\t");
	printf("\tARRIVALDATE \n");
	for(i=0;i<118;i++)
		printf("-");
    struct node *FN;
    FN=readfromlist(newhead);
    struct node *k;
    k=FN;
   // while(k->next!=NULL)
      //  printf("%s\t",k->data);
    printf("\n");
    for(i=0;i<118;i++)
		printf("-");
    getch();
}
struct node* readfromlist(struct node *start)
{
    FILE *f ;
	if((f=fopen("hotelFT.txt","r"))==NULL)
		exit(0);
    fseek(f,0,SEEK_END);
    free(start);
    long files=ftell(f);
    rewind(f);
    int n=(int)(files/sizeof(struct node));
    int q;
    for(q=0;q<n;q++)
    {
        fseek(f,(sizeof(struct node)*q),SEEK_SET);
        start=readnext(start,f);
        if((q+1)%6==0)
            start=NULL;
    }
    return start;
    fclose(f);
}
struct node* readnext(struct node *start,FILE *f)
{
    if(start==NULL)
    {
        start=(struct node*)malloc(sizeof(struct node));
        fread(start,sizeof(struct node),1,f);
        start->next=NULL;
        printf("\n%s\t",start->data);
    }
    else
    {
        struct node *temp=start;
        nw=(struct node*)malloc(sizeof(struct node));
        while(temp->next!=NULL)
            temp=temp->next;
        fread(nw,sizeof(struct node),1,f);
        temp->next=nw;
        nw->next=NULL;
        printf("\t%s\t",nw->data);
    }
    return start;
}
void search()
{
    system("cls");
    char sn[20];
    printf("Enter Name of Customer:");
    scanf("%s",&sn);
    printf("\n");
    FILE *f;
	if((f=fopen("hotelFT.txt","r"))==NULL)
		exit(0);
    fseek(f,0,SEEK_END);
    long files=ftell(f);
    rewind(f);
    int n=(int)(files/sizeof(struct node));
    int q,k;
    for(q=0;q<n;q++)
    {
        struct node *nm;
        nm=(struct node*)malloc(sizeof(struct node));
        strcpy(nm->data,"\0");nw=(struct node*)malloc(sizeof(struct node));
        strcpy(nw->data,"\0");
        nw->next=NULL;
        fread(nm,sizeof(struct node),1,f);
        nm->next=NULL;
        if(strcmp(nm->data,sn)==0)
        {
            for(int i=q-1;i<q+5;i++)
            {
                if(i==q-1)
                    printf("Room: ");
                else if(i==q)
                    printf("Name: ");
                else if(i==q+1)
                    printf("Address: ");
                else if(i==q+2)
                    printf("Phone Number: ");
                else if(i==q+3)
                    printf("Period(in days): ");
                else
                    printf("Arrival Date: ");
                struct node *temp;
                temp=(struct node*)malloc(sizeof(struct node));
                strcpy(temp->data,"\0");
                temp->next=NULL;
                fseek(f,(sizeof(struct node)*i),SEEK_SET);
                fread(temp,sizeof(struct node),1,f);
                printf("%s\n",temp->data);
            }
            k=1;
            break;
        }
    }
    if(k!=1)
        printf("Customer Record doesn't exist");
    fclose(f);
    getch();
}
void delete1()
{
    system("cls");
    char sn[20];
    printf("Enter the Room Number of the Customer you want to delete: ");
    scanf("%s",&sn);
    printf("\n");
    FILE *f;
	if((f=fopen("hotelFT.txt","a+"))==NULL)
		exit(0);
    fseek(f,0,SEEK_END);
    long files=ftell(f);
    rewind(f);
    int n=(int)(files/sizeof(struct node));
    int q=0;
    nw=(struct node*)malloc(sizeof(struct node));
    strcpy(nw->data,"\0");
    nw->next=NULL;
    filedata=nw;
    while(q!=n)
    {
        struct node *nm;
        nm=(struct node*)malloc(sizeof(struct node));
        strcpy(nm->data,"\0");
        nm->next=NULL;
        fseek(f,(sizeof(struct node)*q),SEEK_SET);
        fread(nm,sizeof(struct node),1,f);
        if(strcmp(nm->data,sn)==0)
        {
            q=q+6;
        }
        else
        {
            if(strcmp(filedata->data,"\0")==0)
            {
                strcpy(filedata->data,nm->data);
                filedata->next=NULL;
            }
            else
            {
                p=filedata;
                nw=(struct node*)malloc(sizeof(struct node));
                strcpy(nw->data,"\0");
                nw->next=NULL;
                while(p->next!=NULL)
                {
                    p=p->next;

                }
                strcpy(nw->data,nm->data);
                p->next=nw;
                nw->next=NULL;
            }
            q++;
        }
    }
    fclose(f);
    fclose(fopen("hotelFT.txt","w"));
    if(strcmp(filedata->data,"\0")!=0)
        WriteInfile(filedata);
    printf("DONE!!!");
    getch();
}
void edit()
{
    system("cls");
    printf("Enter The Customer whose details you want to Edit: ");
    char en[25];
    scanf("%s",&en);
    printf("\n");
    FILE *f;
	if((f=fopen("hotelFT.txt","r+"))==NULL)
		exit(0);
    fseek(f,0,SEEK_END);
    long files=ftell(f);
    rewind(f);
    int n=(int)(files/sizeof(struct node));
    int q;
    for(q=0;q<n;q++)
    {
        struct node *nm;
        nm=(struct node*)malloc(sizeof(struct node));
        strcpy(nm->data,"\0");
        fread(nm,sizeof(struct node),1,f);
        nm->next=NULL;
        if(strcmp(nm->data,en)==0)
        {
            int index,ch;
            char det[25];
            printf("Enter choice to Edit:\n1-->ROOM\n2-->NAME\n3-->ADDRESS\n4-->PHONE\n5-->NO. OF DAYS\n6-->ARRIVAL DATE\n");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                index=q-1;
                break;
            case 2:
                index=q;
                break;
            case 3:
                index=q+1;
                break;
            case 4:
                index=q+2;
                break;
            case 5:
                index=q+3;
                break;
            case 6:
                index=q+4;
                break;
            default:
                printf("Wrong Choice");
            }
            fseek(f,(sizeof(struct node)*index),SEEK_SET);
            printf("Enter New Value: ");
            scanf("%s",&det);
            fwrite(det,1,sizeof(struct node),f);
            break;
        }
    }
    fclose(f);
    getch();
}

