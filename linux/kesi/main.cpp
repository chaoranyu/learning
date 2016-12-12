#include <iostream>
using namespace std;
#include <fcntl.h>
#include<sys/ioctl.h>
#include<linux/fs.h>
//#include <hdreg.h>
//#include <hdreg.h>

#define diskname  "/dev/sda2"

int main ()
{
	int fd = open(diskname, O_RDONLY);
	int64_t size;
	if(fd == -1)
	{
	    cout<<"faild"<<endl;
	}
	else
	{
	    cout<<"succse"<<endl;
	}
	//ioctl(fd,HDIO_GET_IDENTITY, &size)
	//if (ioctl(fd, HDIO_GET_IDENTITY, &size) >= 0) {
	//if (ioctl(fd,BLKSSZGET64, &size) >= 0) {
	if (ioctl(fd,BLKGETSIZE64, &size) >= 0) {
	    cout<<size<<endl;
	}else{
	    cout<<"ioctl fail"<<endl;
	}
	return 0;
}

