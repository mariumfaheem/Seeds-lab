/* vulp.c */
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main()
{
char * fn = "/tmp/XYZ";
char buffer[60];
FILE *f1, *f2;

struct stat f1stat, f2stat;
long int i;
/* get user input */
scanf("%50s", buffer );
/* 1st check*/
if(!access(fn, W_OK)){
f1 = fopen(fn, "a+");
fstat(fileno(f1), &f1stat);}
else
printf("No permission \n");

/* 2nd check*/
if(!access(fn, W_OK)){
f2 = fopen(fn, "a+");
fstat(fileno(f2), &f2stat);


/*check whether descriptors share the same inode*/
if(f1stat.st_ino==f2stat.st_ino){
fwrite("\n", sizeof(char), 1, f2);
fwrite(buffer, sizeof(char), strlen(buffer), f2);

fclose(f2);
fclose(f1);
}
else printf("race condition attack detected\n");
}
else printf("No permission \n");
}
