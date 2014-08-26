#include "SOCK_Acceptor.h"
#include "INET_Addr.h"
#include "SOCK_Stream.h"
#include <Windows.h>

// Initialize a passive-mode acceptor socket.
SOCK_Acceptor::SOCK_Acceptor(const INET_Addr &addr) {
	// Create a local endpoint of communication.
	handle_ = socket(PF_INET, SOCK_STREAM, 0);

	// Associate address with endpoint.
	bind(handle_, addr.addr(), addr.size());

	// Make endpoint listen for connections.
	listen(handle_, 5);
}

// A second method to initialize a passive-mode
// acceptor socket, analogously to the constructor.
void SOCK_Acceptor::open(const INET_Addr &sock_addr) { /* ... */ }

// Accept a connection and initialize the <stream>.
void SOCK_Acceptor::accept(SOCK_Stream &s) {
	s.set_handle(handle_);
}