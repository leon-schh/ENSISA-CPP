#include "NetworkDevice.h"
#include <iostream>

NetworkDevice::NetworkDevice() {
    hostname = "";
    ipAddress = "";
    location = "";
    vendor = "";
    osVersion = "";
    year = 0;
    powerConsumption = 0.0;
    isCritical = false;
}

NetworkDevice::NetworkDevice(std::string hostname, std::string ipAddress, std::string location, 
                           std::string vendor, std::string osVersion, int year, 
                           double powerConsumption, bool isCritical) {
    this->hostname = hostname;
    this->ipAddress = ipAddress;
    this->location = location;
    this->vendor = vendor;
    this->osVersion = osVersion;
    this->year = year;
    this->powerConsumption = powerConsumption;
    this->isCritical = isCritical;
}

NetworkDevice::NetworkDevice(const NetworkDevice &n) {
    hostname = n.hostname;
    ipAddress = n.ipAddress;
    location = n.location;
    vendor = n.vendor;
    osVersion = n.osVersion;
    year = n.year;
    powerConsumption = n.powerConsumption;
    isCritical = n.isCritical;
}

std::string NetworkDevice::getHostname() const {
    return hostname;
}

std::string NetworkDevice::getIpAddress() const {
    return ipAddress;
}

std::string NetworkDevice::getLocation() const {
    return location;
}

std::string NetworkDevice::getVendor() const {
    return vendor;
}

std::string NetworkDevice::getOsVersion() const {
    return osVersion;
}

int NetworkDevice::getYear() const {
    return year;
}

double NetworkDevice::getPowerConsumption() const {
    return powerConsumption;
}

bool NetworkDevice::getIsCritical() const {
    return isCritical;
}

void NetworkDevice::setHostname(std::string hostname) {
    this->hostname = hostname;
}

void NetworkDevice::setIpAddress(std::string ipAddress) {
    this->ipAddress = ipAddress;
}

void NetworkDevice::setLocation(std::string location) {
    this->location = location;
}

void NetworkDevice::setVendor(std::string vendor) {
    this->vendor = vendor;
}

void NetworkDevice::setOsVersion(std::string osVersion) {
    this->osVersion = osVersion;
}

void NetworkDevice::setYear(int year) {
    this->year = year;
}

void NetworkDevice::setPowerConsumption(double powerConsumption) {
    this->powerConsumption = powerConsumption;
}

void NetworkDevice::setIsCritical(bool isCritical) {
    this->isCritical = isCritical;
}

void NetworkDevice::ping(NetworkDevice &other) {
    std::cout << "Ping from " << hostname << " (" << ipAddress << ") to " 
              << other.hostname << " (" << other.ipAddress << ")" << std::endl;
}

void NetworkDevice::printInfo() const {
    std::cout << "Network device of unknow type:" << std::endl;
    std::cout << "Hostname: " << hostname << std::endl;
    std::cout << "IP address: " << ipAddress << std::endl;
    std::cout << "Location: " << location << std::endl;
    std::cout << "Vendor: " << vendor << std::endl;
    std::cout << "OS version: " << osVersion << std::endl;
    std::cout << "installed In: " << year << std::endl;
    std::cout << "Power consumption: " << powerConsumption << "W" << std::endl;
    std::cout << "Critique: " << (isCritical ? "Yes" : "No") << std::endl;
}