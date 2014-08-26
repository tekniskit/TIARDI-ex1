#include <Windows.h>

class SOCK_Stream {
public:
	//Default and copy construcotr
	SOCK_Stream() : handle_ (INVALID_HANDLE_VALUE){}
	SOCK_Stream(SOCKET h) : handle_(h){}

	//Automatically close the handle on destruction.
	~SOCK_Stream();

	//Set/get the underlying SOCKET handle.
	void set_handle(SOCKET h);
	SOCKET get_handle() const;

	//Regular I/O operations
	SSIZE_T	recv(void *buf, size_t len, int flags);
	SSIZE_T send(const char *buf, size_t len, int flags);

	//I/O operations for "short" receives and sends.
	SSIZE_T recv_n(char *buf, size_t len, int flags);
	SSIZE_T send_n(const char *buf, size_t len, int flags);	

private:
	//Socket handle for exchanging socket data.
	SOCKET handle_;
	void close(SOCKET h);
};