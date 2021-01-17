/* vulp.c */
#include <stdio.h>
#include<unistd.h>

#include<sys/types.h>

int main()
{
char * fn = "/tmp/XYZ";
char buffer[60];
FILE *fp;
long int i;

/* get user input */
scanf("%50s", buffer );

uid_t uid=getuid();
uid_t euid=geteuid();
seteuid(uid);

fp = fopen(fn, "a+");
if(fp!=NULL){
fwrite("\n", sizeof(char), 1, fp);
fwrite(buffer, sizeof(char), strlen(buffer), fp);
fclose(fp);
}
else printf("cannot open file \n");
seteuid(euid);
}
