#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/errno.h>
#include <asm/uaccess.h>
#include <errno.h>
#include <linux/syscalls.h> 
#include <linux/kernel.h>
#include <linux/cred.h>
#include <setuserweight.c>
#define	EINVAL		22	/* Invalid argument */

SYSCALL_DEFINE1(getuserweight, int, uid){
 
    if (uid == -1) {
        uid = current_uid().val;
    }
    if(uid < 0 || uid > 65355){
        errno = EINVAL;
        return -1;
    }
    return weights[uid];
}