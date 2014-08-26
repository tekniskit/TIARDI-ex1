class SOCK_Acceptor {
	public:
		SOCK_Acceptor (const INET_Addr &addr);
		void open (const INET_Addr &sock_addr);
		void accept (SOCK_Stream &s);

	private:
		SOCKET handle_;
};