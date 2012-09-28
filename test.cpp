#include <iostream>
#include <linxpp.h>

int main(void)
{
	static const LINX_SIGSELECT any[] = {0};
	union LINX_SIGNAL *buf;
	Linx endpoint("test");
	LINX_SPID server;

	std::cout << "Successfully opened a linx endpoint. \n";

	buf = endpoint.alloc(45, 0x80);
	if(buf != NULL)
		std::cout << "Successfully allocated a buffer \n";
	else
		std::cout << "Error\n";

	endpoint.hunt("test", &buf);
	buf = NULL;

	endpoint.receive(&buf, any);
	if(buf == NULL)
		std::cout << "error\n";

	server = endpoint.sender(&buf);
	
	endpoint.send(&buf, server);
	buf = NULL;

	endpoint.receive(&buf, any);
	if(buf == NULL)
		std::cout << "error\n";

	std::cout << "test successful\n";
	return 0;
}
