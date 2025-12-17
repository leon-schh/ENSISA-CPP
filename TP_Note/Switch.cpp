#include "Switch.h"
#include <iostream>

Switch::Switch() : NetworkDevice() {
    portCount = 0;
}

Switch::Switch(std::string hostname, std::string ipAddress, std::string location, 
               std::string vendor, std::string osVersion, int year, 
               double powerConsumption, bool isCritical, int portCount) 
               : NetworkDevice(hostname, ipAddress, location, vendor, osVersion, year, powerConsumption, isCritical) {
    this->portCount = portCount;
}

Switch::Switch(const Switch &s) : NetworkDevice(s) {
    portCount = s.portCount;
}

int Switch::getPortCount() const {
    return portCount;
}

void Switch::setPortCount(int portCount) {
    this->portCount = portCount;
}

void Switch::printInfo() const {
    std::cout << "Switch Information:" << std::endl;
    std::cout << "Hostname: " << getHostname() << std::endl;
    std::cout << "IP address: " << getIpAddress() << std::endl;
    std::cout << "Location: " << getLocation() << std::endl;
    std::cout << "Vendor: " << getVendor() << std::endl;
    std::cout << "OS version: " << getOsVersion() << std::endl;
    std::cout << "Installed in: " << getYear() << std::endl;
    std::cout << "Power consumption: " << getPowerConsumption() << "W" << std::endl;
    std::cout << "Critical: " << (getIsCritical() ? "Yes" : "No") << std::endl;
    std::cout << "Number of ports: " << portCount << std::endl;
}