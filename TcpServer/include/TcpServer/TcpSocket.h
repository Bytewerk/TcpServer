#pragma once
#include <unistd.h>
#include <stdint.h>
#include <string>

class TcpSocket
{
    public:
        TcpSocket();
        TcpSocket(int fd);
        ~TcpSocket();

        int GetFileDescriptor() const;
        bool Create();
        bool EnableReuseAddressOption();
        bool Bind(uint16_t port);
        bool Listen(int backlog);
        int Accept();
        bool Close();
        ssize_t Read(void* buf, size_t count);
        ssize_t Write(const void* buf, size_t count);
        ssize_t Write(const std::string data);

        std::pair<std::string,int> GetPeerNameAndPort();
        std::string GetPeerName();
        int GetPeerPort();
        std::string GetPeer();
        void SetUserData(void* userData);
        void* GetUserData();

    private:
        int _fd = -1;
        void* _userData = nullptr;
};

