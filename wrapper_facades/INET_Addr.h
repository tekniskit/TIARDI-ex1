#include <Windows.h>

class INET_Addr {
public:
	INET_Addr(u_short port, u_long addr);
		
private:
	sockaddr_in addr_;
};