#include "Router.h"
#include <iostream>

Router::Router() : NetworkDevice() {
    routingTableSize = 0;
}

Router::Router(std::string hostname, std::string ipAddress, std::string location, 
               std::string vendor, std::string osVersion, int year, 
               double powerConsumption, bool isCritical, int routingTableSize) 
               : NetworkDevice(hostname, ipAddress, location, vendor, osVersion, year, powerConsumption, isCritical) {
    this->routingTableSize = routingTableSize;
}

Router::Router(const Router &s) : NetworkDevice(s) {
    routingTableSize = s.routingTableSize;
}

int Router::getRoutingTableSize() const {
    return routingTableSize;
}

void Router::setRoutingTableSize(int routingTableSize) {
    this->routingTableSize = routingTableSize;
}

void Router::printInfo() const {
    std::cout << "Router Information:" << std::endl;
    std::cout << "Hostname: " << getHostname() << std::endl;
    std::cout << "IP address: " << getIpAddress() << std::endl;
    std::cout << "Location: " << getLocation() << std::endl;
    std::cout << "Vendor: " << getVendor() << std::endl;
    std::cout << "OS version: " << getOsVersion() << std::endl;
    std::cout << "Installed in: " << getYear() << std::endl;
    std::cout << "Power consumption: " << getPowerConsumption() << "W" << std::endl;
    std::cout << "Critical: " << (getIsCritical() ? "Yes" : "No") << std::endl;
    std::cout << "Size of the routing table: " << routingTableSize << std::endl;
}