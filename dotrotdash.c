// Very Nice rotdash with dot-ticker

#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    //const char arr[]={'.','o','O','o'};
    const char arr[] = { '|', '/', '-', '\\' };
    if (argc != 2)
	return 1;
    chdir("/proc");
    argc = 0;
    while (!access(argv[1], F_OK)) {
	printf("%c\b", arr[argc++]);
	if (argc == sizeof(arr)) {
	    printf(".%c\b", arr[argc - 1]);
	    argc = 0;
	}
	fflush(stdout);
	usleep(100000);
    }
    puts(".");
    return 0;
}
