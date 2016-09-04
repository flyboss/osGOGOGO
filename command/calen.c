#include<stdio.h>

int isLeapyear(int year)/*this function is used to calculate that if a year is a leap year*/
{
    if(year%4==0)
        {
            if(year%100!=0)
                return 1;
            else if(year%100==0&&year%400==0)
                return 1;
            else
                return 0;
        }
    else
        return 0;

}


void printCalendar(int year,int day,int constmonth)/*this function is used to print the calendar of a year*/
{
    int month;
    int days;
    int FristDayOfMonth;
    int LastDayOfMonth;
    int i;
    for(month=1;month<=12;month++)
    {
         
         switch(month)
         {
               case 1:if(constmonth==month)
                      printf("January %d\n",year);
                      days=31;/*how many days in this month*/
                      break;
               case 2:if(constmonth==month)
                      printf("February %d\n",year);
                      days=(isLeapyear(year))? 29:28;/*this is used to calculate if there are 29 or 28 days in february*/
                      break;
               case 3:if(constmonth==month)
                      printf("March %d\n",year);
                      days=31;
                      break;
               case 4:if(constmonth==month)
                      printf("April %d\n",year);
                      days=30;
                      break;
               case 5:if(constmonth==month)
                      printf("May %d\n",year);
                      days=31;
                      break;
               case 6:if(constmonth==month)
                      printf("June %d\n",year);
                      days=30;
                      break;
               case 7:if(constmonth==month)
                      printf("July %d\n",year);
                      days=31;
                      break;
               case 8:if(constmonth==month)
                      printf("August %d\n",year);
                      days=31;
                      break;
               case 9:if(constmonth==month)
                      printf("September %d\n",year);
                      days=30;
                      break;
               case 10:if(constmonth==month)
                        printf("October %d\n",year);
                       days=31;
                       break;
               case 11:if(constmonth==month)
                        printf("November %d\n",year);
                       days=30;
                       break;
               case 12:if(constmonth==month)
                        printf("December %d\n",year);
                       days=31;
                       break;
               default:printf("error");
         }
         if(constmonth==month)
         printf("  S  M  T  W  T  F  S\n");/*print the days of a week*/
         if(month==1)/*January*/
                {
                 FristDayOfMonth=day;/*this is used to calculate the day of week that it is the frist day of the month*/
                 LastDayOfMonth=(days-8+day)%7;/*this is used to calculate the day of week that it is the last day of the month*/

             }
         else/*other months*/
             {
                FristDayOfMonth=(LastDayOfMonth==7)?1:LastDayOfMonth+1;/*this is used to calculate the day of week that it is the frist day of the month*/
                LastDayOfMonth=(days-8+FristDayOfMonth)%7;/*this is used to calculate the day of week that it is the last day of the month*/

             }
         if(constmonth==month)
         {
            for(i=1;i<FristDayOfMonth*3-2;i++)/*calculate the location of the frist day of a month*/
             printf(" ");
            for(i=1;i<=days;i++)/*print the calendar of a month*/
             {
                 printf("%3d",i);
                 if((i-(7-FristDayOfMonth+1))%7==0)
                     printf("\n");/* because it is Saturday*/
             }
              printf("\n");
         }
         

    }
}


int main(int argc, char * argv[])
{
    int choose;/*what is day today*/
    if(argc!=3)
    {
    	printf("please enter year!\n");
    	return 0;
    }
    //year
    char *s=argv[1];
    char *p;
    int year=0;
    for(p=s;*p!='\0';p++)
      year=year*10+*p-'0';


    //month
    s=argv[2];
    int month=0;
    for(p=s;*p!='\0';p++)
      month=month*10+*p-'0';
    printf("please choose the day of the week that is January 1st\n");
    printf("1:Sunday  2:Monday  3:Tuseday 4:Wednesday  5:Thrusday 6;Friday  7:Saturday\n");
    const int wr_bytes=10;
	  char content[wr_bytes];
	  read(0,content,wr_bytes);
    choose=content[0]-'0';
    if(choose<1||choose>7)
        {
            printf("choose error");
            return 0;
        }
    
    printCalendar(year,choose,month);
    return 0;
}