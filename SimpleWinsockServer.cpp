#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>

#pragma warning(disable:4996)

int main(int args,char* argv[])
{
    WSAData data;
    WORD DLLVersion = MAKEWORD(2, 1);
    if (WSAStartup(DLLVersion, &data) != 0)
    {
        std::cout << "Error" << std::endl;
        exit(1);
    }
    SOCKADDR_IN addr;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(8080);
    addr.sin_family = AF_INET;

    SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
    bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
    listen(sListen, SOMAXCONN);

    int sizeofaddr = sizeof(addr);
    SOCKET newCOnnection;
    auto newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

    if (newConnection == 0)
    {
        std::cout << "Connection Error" << std::endl;
    }
    else
    {
        std::cout << "Client connected" << std::endl;
    }

    system("pause");
    return 0;
}
