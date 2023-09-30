#include "types.h"
#include "stat.h"
#include "user.h"


int 
main(int argc, char **argv)
{
    if(argc < 3) {
        printf(1, "Usage: %s <pid> <value>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]); // Convert argument string to integer
    int value = atoi(argv[2]);
    printf(1,"%d: ",pid);
    if (setnice(pid, value)){
        printf(1,"wroung input\n");
    }

    exit();
}