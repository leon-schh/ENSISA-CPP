#include "Server.h"
#include <iostream>

Server::Server() : NetworkDevice() {
    cpuCores = 0;
}

Server::Server(std::string hostname, std::string ipAddress, std::string location, 
               std::string vendor, std::string osVersion, int year, 
               double powerConsumption, bool isCritical, int cpuCores) 
               : NetworkDevice(hostname, ipAddress, location, vendor, osVersion, year, powerConsumption, isCritical) {
    this->cpuCores = cpuCores;
}

Server::Server(const Server &s) : NetworkDevice(s) {
    cpuCores = s.cpuCores;
}

int Server::getCpuCores() const {
    return cpuCores;
}

void Server::setCpuCores(int cpuCores) {
    this->cpuCores = cpuCores;
}

void Server::printInfo() const {
    std::cout << "Server Information:" << std::endl;
    std::cout << "Hostname: " << getHostname() << std::endl;
    std::cout << "IP address: " << getIpAddress() << std::endl;
    std::cout << "Location: " << getLocation() << std::endl;
    std::cout << "Vendor: " << getVendor() << std::endl;
    std::cout << "OS version: " << getOsVersion() << std::endl;
    std::cout << "Installed in: " << getYear() << std::endl;
    std::cout << "Power consumption: " << getPowerConsumption() << "W" << std::endl;
    std::cout << "Critical: " << (getIsCritical() ? "Yes" : "No") << std::endl;
    std::cout << "CPU Cores: " << cpuCores << std::endl;
}