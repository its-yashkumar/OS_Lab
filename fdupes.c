#include <sys/stat.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/file.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include  <unistd.h>
#include <errno.h>
#include <sys/types.h>

struct directory{
char name[100];
long int size;
int p;
int gid;
};
void samefile(struct stat stats){
	struct stat f;
	if(stats.st_mode & R_OK)
	printf("Read\n");
	if(stats.st_mode & W_OK)
	printf("Write\n");
	if(stats.st_mode & X_OK)
	printf("Execute\n");
}
int main(){
	struct directory f[50];
	struct stat file;
	int i=0,j=0,ctr=0;
	char *s;
	char buf[100];
	s=getcwd(buf,sizeof(buf));
	printf("CWD:%s",s);
	struct dirent *de;
	DIR *dr=opendir(".");
	if(dr==NULL){
		printf("Could not open directory");
		return 0;
	}
	while((de=readdir(dr)) !=NULL){
		stat(de->d_name,&file);
		printf("Name:%s\nFIle size:%ld\nGid:%d\n",de->d_name, 		        file.st_size,file.st_gid);
		f[i].p=file.st_mode;
		f[i].size=file.st_size;
		strcpy(f[i].name,de->d_name);
		f[i].gid=file.st_gid;
		printf("st_mode=%d\n",file.st_mode);
		samefile(file);
		printf("\n");
		i++;
		ctr++;
	}	
	closedir(dr);
	for(i=0;i<ctr;i++){
		for(j=i+1;j<ctr;j++){
			if((f[i].size==f[j].size) && (f[i].gid==f[j].gid &&(f[i].p==f[j].p))){
			if(unlink(f[j].name)==0)
			printf("the file deleted is %s\n",f[j].name);
			}
			}
			}
			return 0;
			}