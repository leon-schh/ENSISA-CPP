#ifndef SWITCH_H
#define SWITCH_H

#include "NetworkDevice.h"

class Switch : public NetworkDevice {
    private:
        int portCount;
    public:
        Switch();
        Switch(std::string hostname, std::string ipAddress, std::string location, 
               std::string vendor, std::string osVersion, int year, 
               double powerConsumption, bool isCritical, int portCount);
        Switch(const Switch &r);

        int getPortCount() const;
        void setPortCount(int portCount);

        void printInfo() const override;
};

#endif