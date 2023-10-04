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
    int pid = atoi(argv[1]);
    ps(pid);

    // for(int i = 1; i < argc; i++) {
    //     int pid = atoi(argv[i]); // Convert argument string to integer
    //     ps(pid); // Call ps function with pid value
    // }

    exit();
}