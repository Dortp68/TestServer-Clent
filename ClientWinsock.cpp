#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#pragma warning(disable:4996)
int main(int args, char* argv[])
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

    SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
    if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0)
    {
        std::cout << "Failed connected to server" << std::endl;
        return 1;
    }
    std::cout << "Success!" << std::endl;

    system("pause");
    return 0;
}
