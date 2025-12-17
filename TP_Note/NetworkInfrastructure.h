#ifndef NETWORKINFRASTRUCTURE_H
#define NETWORKINFRASTRUCTURE_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "NetworkDevice.h"
#include "Server.h"
#include "Router.h"
#include "Switch.h"

class NetworkInfrastructure {
    private:
        std::string name;
        static int MAX_DEVICES;
        std::vector<NetworkDevice*> devices;
        
        bool hostnameExists(const std::string& hostname) const;
        
        void sortDevices();
        
        std::string getDeviceType(const NetworkDevice* device) const;
        
    public:
        NetworkInfrastructure();
        NetworkInfrastructure(const std::string& name);
        NetworkInfrastructure(const NetworkInfrastructure& ni);
        ~NetworkInfrastructure();

        std::string getName() const;
        void setName(const std::string& name);
        static int getMaxDevices();
        
        void listDevices() const;
        bool addDevice(NetworkDevice* device);
        NetworkDevice* searchDeviceByHostname(const std::string& hostname) const;
        bool removeDeviceByHostname(const std::string& hostname);
        double averagePowerConsumptionByType(const std::string& deviceType) const;
        
        int getDeviceCount() const;
        void clearAllDevices();
};

#endif