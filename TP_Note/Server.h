#ifndef SERVER_H
#define SERVER_H

#include "NetworkDevice.h"

class Server : public NetworkDevice {
    private:
        int cpuCores;
    public:
        Server();
        Server(std::string hostname, std::string ipAddress, std::string location, 
               std::string vendor, std::string osVersion, int year, 
               double powerConsumption, bool isCritical, int cpuCores);
        Server(const Server &s);

        int getCpuCores() const;
        void setCpuCores(int cpuCores);

        void printInfo() const override;
};

#endif