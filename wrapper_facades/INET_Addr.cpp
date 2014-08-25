#include "INET_Addr.h"

INET_Addr::INET_Addr(u_short port, u_long addr) {
	memset(&addr_, 0, sizeof addr_);
	addr_.sin_family = AF_INET;
	addr_.sin_port = htons(port);
	addr_.sin_addr.s_addr = htonl(addr);
}