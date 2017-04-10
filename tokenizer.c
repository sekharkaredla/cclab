#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
int l,w,i,f;
bool testInt(char *,int *);
bool testFloat(char *,float *);
int main()
{
    FILE *fp;
    //int l,w,i,f;
    l=w=i=f=0;
    char c;
    int sumi=0;
    float sumf=0.0;
    fp=fopen("test.txt","r");char buf[100];int p=0;
    if(fp==NULL)
    exit(1);
    else
    {
        while((c=fgetc(fp))!=EOF)
        {
            if(c!=' '&&c!='\n'&&c!='\r')
            {
                buf[p++]=c;
            }
            else // if(c==' '||c=='\n'||c=='\r')
            {
                buf[p]='\0';
               // printf("hi :%s\n",buf);
                if(c=='\n')//||c=='\r')
                l++;
                int getint;float getfloat;
                if(testInt(buf,&getint))
                {
              //      i++;
                    sumi+=getint;
                }
                else if(testFloat(buf,&getfloat))
                {
            //        f++;
                    sumf+=getfloat;
                }
  		    else
                    w++;
                buf[p]='\0';
                p=0;
            }
           // printf("%d %d %d %d %s",i,l,f,w,buf);

        }
    }
printf("sum if ints %d\n",sumi);
printf("sum of floats %f\n",sumf);
printf("no of words %d\n",w);
printf("no of lines %d\n",l);
printf("no of integers %d\n",i);
printf("no of floats %d\n",f);
}
bool testInt(char *s,int *getint)
{
   //     printf("hi %d\n",*getint);
	*getint=0;
    int hit=1;
    int p;
    if(s[0]=='-')
        hit=-1;
    if(s[0]=='+'||s[0]=='-'||(s[0]>=48&&s[0]<=57))
    {
        if(s[0]>=48&&s[0]<=57)
        *getint=(int)(s[0]-48);
    }
    else
        return false;
    for(p=1;s[p]!='\0';p++)
    {
        if(s[p]>=48&&s[p]<=57)
        {
            *getint=(*getint)*10+(int)(s[p]-48);
        }
        else
            return false;

    }
    *getint=(*getint)*hit;
	i++;
    return true;
}
bool testFloat(char *s,float *getfloat)
{
	//printf("hi 3 : %s",s);
    float hit=1.0;
    *getfloat=0.0;
    int i;int count=0;
    if(s[0]=='-')
        hit=-1.0;
    if(s[0]=='+'||s[0]=='-'||(s[0]>=48&&s[0]<=57))
    {
        if(s[0]>=48&&s[0]<=57)
        *getfloat=(*getfloat)*10.0+(float)(s[0]-48);
    }
    else
        return false;
	int flag=0;int power1=-1;
	//printf("hi 4:%f",*getfloat);
    for(i=1;s[i]!='\0';i++)
    {
        if(s[i]=='.'&&count==0)
        {
            count++;flag=1;
		continue;
        }
        else if(s[i]=='.'&&count>0)
            return false;
        if((s[i]>=48&&s[i]<=57)&&flag==0)
        {
            *getfloat=(*getfloat)*10+(s[i]-48);
        }
        else if((s[i]>=48&&s[i]<=57)&&flag==1)
        {
                *getfloat=(*getfloat)+(s[i]-48)*(pow(10,power1));
                power1--;
        }
        else
            return false;

    }
    *getfloat=(*getfloat)*hit;
	f++;
    return true;
}


