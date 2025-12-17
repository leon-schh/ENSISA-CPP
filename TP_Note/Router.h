#ifndef ROUTER_H
#define ROUTER_H

#include "NetworkDevice.h"

class Router : public NetworkDevice {
    private:
        int routingTableSize;
    public:
        Router();
        Router(std::string hostname, std::string ipAddress, std::string location, 
               std::string vendor, std::string osVersion, int year, 
               double powerConsumption, bool isCritical, int routingTableSize);
        Router(const Router &r);

        int getRoutingTableSize() const;
        void setRoutingTableSize(int routingTableSize);

        void printInfo() const override;
};

#endif