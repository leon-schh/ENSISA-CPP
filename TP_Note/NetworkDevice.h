#ifndef NETWORK_DEVICE_H
#define NETWORK_DEVICE_H

#include <iostream>
#include <string>
#include <math.h>

class NetworkDevice {
    private:
        std::string hostname;
        std::string ipAddress;
        std::string location;
        std::string vendor;
        std::string osVersion;
        int year;
        double powerConsumption;
        bool isCritical;
    public:
        NetworkDevice();
        NetworkDevice(std::string hostname, std::string ipAddress, std::string location, std::string vendor, std::string osVersion, int year, double powerConsumption, bool isCritical);
        NetworkDevice(const NetworkDevice &n);

        std::string getHostname() const;
        std::string getIpAddress() const;
        std::string getLocation() const;
        std::string getVendor() const;
        std::string getOsVersion() const;
        int getYear() const;
        double getPowerConsumption() const;
        bool getIsCritical() const;

        void setHostname(std::string hostname);
        void setIpAddress(std::string ipAddress);
        void setLocation(std::string location);
        void setVendor(std::string vendor);
        void setOsVersion(std::string osVersion);
        void setYear(int year);
        void setPowerConsumption(double powerConsumption);
        void setIsCritical(bool isCritical);

        void ping(NetworkDevice &other);
        virtual void printInfo() const;

        
};

#endif