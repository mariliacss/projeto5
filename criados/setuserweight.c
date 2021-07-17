#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/errno.h>
#include <errno.h>
#include <linux/syscalls.h> 
#include <linux/kernel.h>
#include <linux/cred.h>

#define	EACCES		13
#define	EINVAL 22	/* Invalid argument */

int weights[65355];

SYSCALL_DEFINE2(setuserweight, int, uid, int, weight){
    if (uid == -1) {
        uid = current_uid().val;
    }
    if (!capable(CAP_SYS_ADMIN)) {
        errno = EACCES;
        return -1;
    }
    if (weight < 0){
        errno = EINVAL;
        return -1;
    }
    weights[uid] = weight;

    return 0;
}