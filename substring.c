#include <stdio.h>

#define MAX 100

char * find_sub_string(char *src, char *head, char *tail)
{
    int len_h = strlen(head);
    int len_t = strlen(tail);
    char *h_tmp;

    while(*src != '\0')
    {
        if(strncmp(src, head, len_h) == 0)
	{
            h_tmp = src;
	    src = src + len_h;
	    while(*src != '\0')
	    {
                 if(strncmp(src, tail, len_t) == 0)
		 {
                      *(src + len_t) = '\0';
		            return h_tmp;
		 }
		 src++;
	    }
	}
	src++;
    }

    return NULL;
   
}

int main()
{
    char src[MAX];
    char head[MAX];
    char tail[MAX];

    printf("Please input source string:\n");
    scanf("%s",src);

    printf("Please input head string:\n");
    scanf("%s",head);
    
    printf("Please input tail string:\n");
    scanf("%s",tail);
     
    char *sub_string = find_sub_string(src,head,tail);
    
    printf("the source string %s\n",src);
    printf("the sub string %s\n",sub_string);

    return 0;
}
