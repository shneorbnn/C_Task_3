#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 256

int my_strcmp(char *s1, char *s2)
{
    while((*s1==*s2)&&(*s1!='\0'))
    {
        s1++;
        s2++;
    }

    return *s1-*s2;
}

// cat,cats,lcat
int pA(char *a,char *b)
{
    int aLen= strlen(a);
    int bLen= strlen(b);
    //printf("strlen(a)=%d,strlen(b)=%d\n",aLen,bLen);
        if(aLen>bLen){
        //printf("ERROR:The size of A bigger then B");
        return 1;
    }else if((bLen-aLen)>2){
        //printf("no chance\n");
        return 1;
    }
    
    int oneLetterUnCorrect=1;
    int equal=0;
    int started=0;
    int aIndex=0;
    int bIndex=0;
    
    for(int i=bIndex; i<bLen;i++){
     //printf("value of A:%c index:%d\nvalue of B:%c index:%d \n",a[aIndex],aIndex,b[bIndex],bIndex);
        if(b[bIndex]==a[aIndex]){
            //printf("found one\n");
            started=1;
            equal++;
            aIndex++;
            bIndex++;
            if(equal==aLen){
                //printf("succsess!\n");
                return 0;
            }
        }else if(started==0){
            bIndex++;
        }else if(started==1){
        //printf("dident succsess!!\n");
        return 1;
        }
    }
}
//crat
int pB(const char *a, const char *b)
{
    int aLen= strlen(a);
    int bLen= strlen(b);
    //printf("strlen(a)=%d,strlen(b)=%d\n",aLen,bLen);
        if(aLen>bLen){
        //printf("ERROR:The size of A bigger then B");
        return 1;
    }else if((bLen-aLen)>2){
        //printf("no chance\n");
        return 1;
        }
    
    int oneLetterUnCorrect=1;
    int equal=0;
    int aIndex=0;
    int bIndex=0;
    
    for(int i=bIndex; i<bLen;i++){
     //printf("value of A:%c index:%d\nvalue of B:%c index:%d \n",a[aIndex],aIndex,b[bIndex],bIndex);
        if(b[bIndex]==a[aIndex]){
            //printf("found one\n");
            equal++;
            aIndex++;
            bIndex++;
            if(equal==aLen){
                //printf("succsess!");
                return 0;
                }
        }else if(oneLetterUnCorrect==1){
            oneLetterUnCorrect==0;
            bIndex++;
        }else if(oneLetterUnCorrect==0){
        //printf("dident succsess!!");
        return 1;
        }
    }
}

int main()
{
    
    FILE *pToFile = fopen("text.txt","r");
    char input[LINE];
    char tmp[LINE];
    char* cat = "cat";
    int firstline = 1;;
    const char *delim = " ";
    int plan = 0;
    int i = 0;
    while( fgets( input, LINE, pToFile)) {
        strcpy(tmp, input);
        char *token = strtok(input, delim);
        if(firstline == 1)
        {
            while (token != NULL) 
            {
                //printf("currnt token:    %s \n",token);
                if (my_strcmp(token,"cat") == 0)
                {
                    token = strtok(NULL, delim);
                    //printf("currnt token:    %s \n",token);
                    if (my_strcmp(token,"a\n") == 0)
                    {
                        plan = 1;
                        //printf("right input\n");
                    }
                    else if (my_strcmp(token,"b\n") == 0)
                    {
                        plan = 2;
                        //printf("right input\n");
                    }
                    else
                    {
                        //printf("wrong input");
                    }
                }
                else
                {
                    //printf("wrong input");
                }
                break;
            }
            firstline = 0;
        }
        else 
        {
            //printf("counting plane %d \n", plan);
            while (token != NULL)  
            {
                //printf("currnt token:    %s \n",token);
                if (plan == 1)
                {
                    if ((pA(cat,token) == 0))
                    {
                        
                        printf("%s",tmp);
                        break;
                    }   
                }
                else if (plan == 2)
                {
                    if ((pB(cat,token) == 0))
                    {
                        
                        printf("%s\n",token);
                    }
                }
                else
                {
                    //printf("wrong input\n");
                }
                token = strtok(NULL, delim);
            }
            i++;
        }
    }
    fclose(pToFile);
    return 1;
}