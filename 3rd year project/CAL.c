#include<stdio.h>
#include<time.h>
#define ah_red "\e[31m"
#define ah_green "\e[32m"
#define ah_blue "\e[34m"
#define ah_pink "\e[36m"
#define ah_reset "\e[0m"
void print_time();
int daycode(int);                                  
void leapyear(int);
void printcal(int,int,int,int);             
void input_varification(int,int);
void print_Day();
int mm,yy,dd,a,i,b,daycode1,days_in_month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
char *day_in_month[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
char *month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};


int main()
{	int var;   	
	system("clear");   
	printf("\n Enter the date like dd-mm-yy  ");
	scanf("%d-%d-%d",&dd,&mm,&yy);
	printf("\n Enter your choice ");
	printf("\n 1.Show day ");
	printf("\n 2.Show Calendar ");
	printf("\n 3.Exit\n");
	scanf("%d",&var);
	
	switch(var)
	{
		case 1:
		print_Day();		
		case 2: 
		input_varification(dd,mm);
		break;
		case 3:
		break;
		default:
		printf("Enter the correct choice ");
	}
    	return 0;
}


//For calculating the day from where the 1st JAN of any year will start
int daycode(int x)
{
	int d1,d2,d3;
	d1=(x-1.)/4.;
	d2=(x-1.)/100.;
	d3=(x-1.)/400.;
	daycode1=(x+d1-d2+d3)%7;
	return daycode1;

}
//For calculating the day at the provided date
void print_Day()
{ 	int psudo_Code=0;
	for(i=0;i<mm;i++)
	{
		psudo_Code=(psudo_Code+days_in_month[i]);	
	}
	if(a==0)
	{
		psudo_Code=(7+dd+psudo_Code)%7;
		printf("\n Day at the entered date: %s",day_in_month[psudo_Code-1]);
	}
	
	else
	{
		psudo_Code=(a+dd+psudo_Code)%7;
		printf("\n Day at the entered date: %s",day_in_month[psudo_Code]);
	}	
}

//For calculating the leap year
void leapyear(int y)
{
	if((y%4==0&&y%100!=0)||y%400==0)
	{
		days_in_month[1]=29;
	}
	else
	{
		days_in_month[1]=28;
	}


}


//To print the calander

void printcal(x,z,ab,c)
{	
	int count=0;
	int part_daycode;
	int sum=0;
	part_daycode=z;
	//calculating the day

	printf(ah_pink "\n\t\t%s\n",month[ab-1]);
	for(i=0;i<7;i++)
	{	
		printf(ah_blue " %s ",day_in_month[i]);
	}
	printf("\n");

	for(i=1;i<ab;i++)
	{
		sum=sum+days_in_month[i-1];
	}
	sum=sum%7;
	part_daycode=(part_daycode+sum)%7;

		if(part_daycode==0)
		{
			for(i=1;i<7;i++)
			{
			printf(" -   ");
			count++;
			}
    	}
		else 
		{
			for(i=1;i<part_daycode;i++)
			{
			printf(" -   ");
			count++;
			}
		}
	
		for(i=1;i<=days_in_month[ab-1];i++) 
		{	
			count++;
			if(i<=9)
			{	
				if(count==7)
				{
					if(i==c)
					{
						printf(ah_pink "  %d  ",i);
						printf(ah_reset);
					}
					else
					{
					printf(ah_red "  %d  ",i);
					}
				}
				else
				{ 
					if(i==c)
					{
						printf(ah_pink "  %d  ",i);
					}
					else{
					printf(ah_green "  %d  ",i);}
				}
			}				
			else
			{	
				if(count==7)
				{
					if(i==c)
					{
						printf(ah_pink "  %d ",i);
					}
					else{
					printf(ah_red "  %d ",i);}
				}
				else
				{ 
					if(i==c)
					{
						printf(ah_pink "  %d ",i);
					}
					else{
					printf(ah_green "  %d ",i);}
				}
			}
			if(count==7) 
			{
				printf("\n");
				count=0;
			}
		}
		printf(ah_reset "\n");
}

// To print the system date and the time
void print_time()
{
	time_t tim;
	time(&tim);
	printf("current date and time:\n");
	printf(ctime(&tim));
	printf("\n");
}
void input_varification(int dd,int mm)
{
	if(dd>31 || mm>12)
		{
			printf("\n Please Provide The Valid Date \n");
		}
		else
		{
			a=daycode(yy);
			printf("\n The daycode :%d",a);
			leapyear(yy);
			printcal(yy,a,mm,dd);
   			printf("\n");
   			print_time();
   		}
}
