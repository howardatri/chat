#pragma once
#include"const.h"
class CServer:public std::enable_shared_from_this<CServer>//奇异递归模板
{
public:
	CServer(boost::asio::io_context& ioc, unsigned short& port);
	void Start();
private:
	tcp::acceptor _acceptor;
	net::io_context& _ioc;

};

