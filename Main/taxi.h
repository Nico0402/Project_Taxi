#define TEST_ERROR    	if (errno) {	dprintf(STDERR_FILENO,			\
					  "%s:%d: PID=%5d: Error %d (%s)\n", 	\
					  __FILE__,				\
					  __LINE__,				\
					  getpid(),				\
					  errno,				\
					  strerror(errno));			\
				}
