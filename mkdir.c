#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    char *cwd;
    int ret, ret1;

    if(argc < 3)
    {
        fprintf(stderr,"Usage %s <PATH> <directory name>\n",argv[0]);
        return 1;
    }

    cwd = getcwd(NULL,0);
    if(cwd == NULL)
        perror("getcwd");
    else
        fprintf(stdout,"My current dir is --> %s\n",cwd);
    
    ret = chdir(argv[1]);
    if(ret ==-1)
        perror("chdir");
    else
    {
        cwd = getcwd(NULL,0);
        if(cwd == NULL)
            perror("getcwd");
        fprintf(stdout,"My directory has been changed to ----> %s\n",cwd);
        umask(0);
        ret1 = mkdir(argv[2], 0755);
        if(ret1 == -1)
            perror("mkdir");
        else{
            fprintf(stdout,"Directory called '%s%s' was created.\n",argv[1], argv[2]);

        }
    }

    free(cwd);
    return 0;
    
}
