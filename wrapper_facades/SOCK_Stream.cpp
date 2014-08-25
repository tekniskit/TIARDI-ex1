#include "SOCK_Stream.h"

SOCK_Stream::~SOCK_Stream(){
	close(handle_);
}

void SOCK_Stream::set_handle(SOCKET h)
{
	handle_ = h;
}

SOCKET SOCK_Stream::get_handle() const
{
	return handle_;
}

//Regular I/O operations
SSIZE_T	recv(void *buf, size_t leg, int flags){

}

SSIZE_T send(const char *buf, size_t len, int flags){

}

void SOCK_Stream::close(SOCKET h){

}