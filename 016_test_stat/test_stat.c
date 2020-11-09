#include <stdio.h>
//通过man文档可以查看到stat函数组头文件
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//open函数的参数头文件
#include <fcntl.h>

#if 0
	
struct stat {
               dev_t     st_dev;         /* ID of device containing file */
               ino_t     st_ino;         /* Inode number */
               mode_t    st_mode;        /* File type and mode */
               nlink_t   st_nlink;       /* Number of hard links */
               uid_t     st_uid;         /* User ID of owner */
               gid_t     st_gid;         /* Group ID of owner */
               dev_t     st_rdev;        /* Device ID (if special file) */
               off_t     st_size;        /* Total size, in bytes */
               blksize_t st_blksize;     /* Block size for filesystem I/O */
               blkcnt_t  st_blocks;      /* Number of 512B blocks allocated */

               /* Since Linux 2.6, the kernel supports nanosecond
                  precision for the following timestamp fields.
                  For the details before Linux 2.6, see NOTES. */

               struct timespec st_atim;  /* Time of last access */
               struct timespec st_mtim;  /* Time of last modification */
               struct timespec st_ctim;  /* Time of last status change */

           #define st_atime st_atim.tv_sec      /* Backward compatibility */
           #define st_mtime st_mtim.tv_sec
           #define st_ctime st_ctim.tv_sec
           };
#endif

int main(int argc,char *argv[])
{
	struct stat groupstat;
	int fd,ret;
	
	if(argc <2)
	{
		printf("Please input file path\n");
		return 1;
	}

//stat函数测试	
	ret = stat(argv[1],&groupstat);
	if(ret)
	{
		printf("Please make sure file path\n");
		return 1;
	}
	printf("stat function test, %s of st_ino inode is %ld\n",argv[1],groupstat.st_ino);
	printf("stat function test, %s of st_size size is %ld\n",argv[1],groupstat.st_size);
	
//fstat函数测试
	fd = open(argv[1],O_RDWR|O_NOCTTY|O_NDELAY);
	if(fd<0)
	{
		printf("Please make sure file path\n");
		return 1;
	}
	ret = fstat(fd,&groupstat);
	if(ret)
	{
		printf("Please make sure file path\n");
		return 1;
	}
	printf("fstat function test, %s of st_ino  inode is %ld\n",argv[1],groupstat.st_ino);
	printf("fstat function test, %s of st_size size is %ld\n",argv[1],groupstat.st_size);

//lstat函数测试	
	ret = lstat(argv[1],&groupstat);
	if(ret)
	{
		printf("Please make sure file path\n");
		return 1;
	}
	printf("lstat function test, %s of st_ino inode is %ld\n",argv[1],groupstat.st_ino);
	printf("lstat function test, %s of st_size size is %ld\n",argv[1],groupstat.st_size);
	
return 0;
}
