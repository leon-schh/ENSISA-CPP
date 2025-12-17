#include "NetworkInfrastructure.h"

int NetworkInfrastructure::MAX_DEVICES = 10;

NetworkInfrastructure::NetworkInfrastructure() : name("") {
}

NetworkInfrastructure::NetworkInfrastructure(const std::string& name) : name(name) {
}

NetworkInfrastructure::NetworkInfrastructure(const NetworkInfrastructure& ni) : name(ni.name) {
    for (const auto* device : ni.devices) {
        devices.push_back(const_cast<NetworkDevice*>(device));
    }
}

NetworkInfrastructure::~NetworkInfrastructure() {
}

std::string NetworkInfrastructure::getName() const {
    return name;
}

void NetworkInfrastructure::setName(const std::string& name) {
    this->name = name;
}

int NetworkInfrastructure::getMaxDevices() {
    return MAX_DEVICES;
}

bool NetworkInfrastructure::hostnameExists(const std::string& hostname) const {
    for (const auto* device : devices) {
        if (device->getHostname() == hostname) {
            return true;
        }
    }
    return false;
}

void NetworkInfrastructure::sortDevices() {
    std::sort(devices.begin(), devices.end(), 
              [](const NetworkDevice* a, const NetworkDevice* b) {
                  return a->getHostname() < b->getHostname();
              });
}

std::string NetworkInfrastructure::getDeviceType(const NetworkDevice* device) const {
    if (dynamic_cast<const Server*>(device)) {
        return "Server";
    } else if (dynamic_cast<const Router*>(device)) {
        return "Router";
    } else if (dynamic_cast<const Switch*>(device)) {
        return "Switch";
    }
    return "Unknown";
}

void NetworkInfrastructure::listDevices() const {
    std::cout << "Network Infrastructure: " << name << std::endl;
    std::cout << "Total devices: " << devices.size() << std::endl;
    std::cout << "Device list (alphabetically sorted):" << std::endl;
    
    if (devices.empty()) {
        std::cout << "No devices configured." << std::endl;
    } else {
        for (size_t i = 0; i < devices.size(); ++i) {
            std::cout << "\nDevice " << (i + 1) << std::endl;
            std::cout << "Type: " << getDeviceType(devices[i]) << std::endl;
            devices[i]->printInfo();
        }
    }
}


bool NetworkInfrastructure::addDevice(NetworkDevice* device) {
    if (devices.size() >= MAX_DEVICES) {
        std::cout << "Error: Maximum number of devices." << std::endl;
        return false;
    }
    
    // Check for duplicate hostname
    if (hostnameExists(device->getHostname())) {
        std::cout << "Error: Device with hostname '" << device->getHostname() << "' already exists." << std::endl;
        return false;
    }
    
    // Add device and sort
    devices.push_back(device);
    sortDevices();
    
    return true;
}

NetworkDevice* NetworkInfrastructure::searchDeviceByHostname(const std::string& hostname) const {
    for (const auto* device : devices) {
        if (device->getHostname() == hostname) {
            return const_cast<NetworkDevice*>(device);
        }
    }
    return nullptr;
}

bool NetworkInfrastructure::removeDeviceByHostname(const std::string& hostname) {
    for (auto it = devices.begin(); it != devices.end(); ++it) {
        if ((*it)->getHostname() == hostname) {
            devices.erase(it);
            return true;
        }
    }
    std::cout << "Error: Device with hostname '" << hostname << "' not found." << std::endl;
    return false;
}

double NetworkInfrastructure::averagePowerConsumptionByType(const std::string& deviceType) const {
    double totalPower = 0.0;
    int count = 0;
    
    for (const auto* device : devices) {
        if (getDeviceType(device) == deviceType) {
            totalPower += device->getPowerConsumption();
            count++;
        }
    }
    
    if (count == 0) {
        std::cout << "Warning: No devices of type '" << deviceType << "' found." << std::endl;
        return 0.0;
    }
    
    return totalPower / count;
}

int NetworkInfrastructure::getDeviceCount() const {
    return static_cast<int>(devices.size());
}

void NetworkInfrastructure::clearAllDevices() {
    devices.clear();
}