#include "types.h"
#include "stat.h"
#include "user.h"


int 
main(int argc, char **argv)
{
    if(argc < 2) {
        printf(1, "Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]); // Convert argument string to integer
    int result=getnice(pid);
    printf(1,"%d : %d\n",pid,result);
    exit();
}