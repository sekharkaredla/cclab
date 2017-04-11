
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sumint=0;
float sumfloat=0.0;
char a[20];
char intlist[20][20],floatlist[20][20];
int lines=0,words=0,integers=0,floats=0;

void verify(char (*c)[20],int size) //function to identify and find the sum of integers and floats
{
    int dots,i=0,x,j=0,flag=0,temp=0;
    float temp1=0.0;
    while(j<=size)
	{
	   flag=0;
	   x=strlen(c[j]);
       for(i=0;i<x;i++)    //loop to check if characters are digits
	   {
            if(isdigit(c[j][i]))
                flag++;
	   }
        i=0;
        if(c[j][i]=='+'||c[j][i]=='-')
        {
            flag=1;
			for(i=0;i<x;i++)
			{
                if(isdigit(c[j][i]))
				    flag++;
			}
        }
       	
        if(flag==x && x!=0) //Loop to calculate sum of integers
        {
            i=0;
            if(c[j][0]=='+'||c[j][0]=='-')  //Loop to calculate sum for signed integers
            {
                for(i=1;i<x;i++)
                        a[i-1]=c[j][i];
                temp=atoi(a);   //convert word into integer
                if(c[j][0]=='+')
                {
                    sumint=sumint+temp;
                    strcpy(intlist[integers],a);
                }
                else if(c[j][0]=='-')
                {
                    sumint=sumint-temp;
                    strcpy(intlist[integers],c[j]);
                }
            }
           	else      //Loop to calculate sum for unsigned integers
           	{
       	        temp=atoi(c[j]);    //convert word into integer
       	        sumint=sumint+temp;
                strcpy(intlist[integers],c[j]);
           	}
           	integers++;
            for(i=0;i<20;i++)
            {
                a[i]='\0';
            }
        }
    	
        else
    	{
            i=0;flag=0;dots=0;
            for(i=0;i<x;i++)
            {
                if(isdigit(c[j][i]))
                    flag++;
                if(c[j][i]=='.')
                {
                    dots++;flag++;
                }
    		}
            i=0;
        	
            if(c[j][0]=='+'||c[j][0]=='-')
            {
    			dots=0;
                flag=1;
                for(i=0;i<x;i++)
                {
                    if(isdigit(c[j][i]))
                        flag++;
                    if(c[j][i]=='.')
    				{
                    	dots++;flag++;
    				}
    			}
            }
            
            if(flag==x && dots==1 && x!=0)  //Loop to calculate sum of floats
            {
                i=0;
                if(c[j][0]=='+'||c[j][0]=='-')  //Loop to calculate sum for signed floats
                {
                    for(i=1;i<x;i++)
                    	a[i-1]=c[j][i];
                    temp1=atof(a);  //convert word into float
                    if(c[j][0]=='+')
                    {
                    	sumfloat=sumfloat+temp1;
                        strcpy(floatlist[floats],a);
                    }
                    else if(c[j][0]=='-')
                    {
                    	sumfloat=sumfloat-temp1;
                        strcpy(floatlist[floats],c[j]);
                    }
                }
                else      //Loop to calculate sum for unsigned floats
                {
                    temp1=atof(c[j]);   //convert word into float
                    sumfloat=sumfloat+temp1;
                    strcpy(floatlist[floats],c[j]);
     			}
                floats++;
    			for(i=0;i<20;i++)
            	{
            		  a[i]='\0';
                }
            }
        }
		j++;
	}
}
int main()
{
    int i=0,j=0,check,chars=0;
    char c,s[20],arr[20][20];
    FILE *fp=fopen("input.txt","r");
    while((c=fgetc(fp))!=EOF)
	{
        if(c=='\n')
            lines++;
        if(c!=' '&&c!='\n')
        {
            s[i]=c;
            arr[j][i]=c;
            i++;
        }
        if(c==' '||c=='\n')
        {
            words++;
            arr[j][i]='\0';
            j++;
            for(i=0;i<20;i++)
                s[i]='\0';
            i=0;
        }
        chars++;
    }
	verify(arr,j-1);
    printf("\nNumber of characters:%d",chars-1);
    printf("\nNumber of words:%d",words);
    printf("\nNumber of lines:%d\n",lines);
    printf("\nIntegers in the file are:\n");
    for(i=0;i<integers;i++)
        printf("%s\t",intlist[i]);
    printf("\n\nFloats in the file are:\n");
    for(i=0;i<floats;i++)
        printf("%s\t",floatlist[i]);
    printf("\n\nSum of integers:%d",sumint);
    printf("\nSum of floats:%f\n",sumfloat);
}
