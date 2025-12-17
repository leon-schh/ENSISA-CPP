#include "NetworkDevice.h"
#include "Server.h"
#include "Router.h"
#include "Switch.h"
#include "NetworkInfrastructure.h"
#include <iostream>

int main() {
    NetworkInfrastructure infra("Infrastructure");
    
    Server* server1 = new Server("web-server-01", "10.0.1.10", "Datacenter A", 
                                "Dell", "RHEL 9", 2022, 350, true, 8);
    Server* server2 = new Server("db-server-01", "10.0.1.11", "Datacenter A", 
                                "Dell", "RHEL 9", 2021, 450, true, 16);
    Server* server3 = new Server("mail-server-01", "10.0.1.12", "Datacenter B", 
                                "Dell", "RHEL 9", 2020, 380, false, 4);
    
    Router* router1 = new Router("core-router-01", "192.168.1.1", "DataCenter A", 
                                "Cisco", "IOS-XE", 2021, 280, true, 5000);
    Router* router2 = new Router("branch-router-01", "192.168.2.1", "Datacenter B", 
                                "Juniper", "IOS-XE", 2022, 220, false, 2000);
    
    Switch* switch1 = new Switch("access-switch-01", "10.0.2.1", "DataCenter A", 
                                "Cisco", "IOS-XE", 2020, 180, false, 48);
    Switch* switch2 = new Switch("core-switch-01", "10.0.1.1", "DataCenter A", 
                                "Cisco", "IOS-XE", 2021, 320, true, 96);
    Switch* switch3 = new Switch("distribution-switch-01", "10.0.3.1", "Datacenter B", 
                                "Cisco", "IOS-XE", 2019, 200, true, 24);

    infra.addDevice(server1);
    infra.addDevice(server2);
    infra.addDevice(server3);
    infra.addDevice(router1);
    infra.addDevice(router2);
    infra.addDevice(switch1);
    infra.addDevice(switch2);
    infra.addDevice(switch3);

    infra.listDevices();

    std::cout << std::endl;
    std::cout << "Searching for created device:" << std::endl;
    NetworkDevice* foundDevice = infra.searchDeviceByHostname("web-server-01");
    if (foundDevice) {
        std::cout << "Device found" << std::endl;
        foundDevice->printInfo();
    } else {
        std::cout << "Device not found" << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "Searching for nonexistent device:" << std::endl;
    foundDevice = infra.searchDeviceByHostname("nonexistent-device");
    if (foundDevice) {
        std::cout << "Device found" << std::endl;
        foundDevice->printInfo();
    } else {
        std::cout << "Device not found (expected)" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Testing duplicate hostname" << std::endl;
    Server* duplicateServer = new Server("web-server-01", "10.0.1.99", "Datacenter C", 
                                       "Dell", "Ubuntu Server 22.04", 2023, 400, false, 12);
    infra.addDevice(duplicateServer);

    std::cout << std::endl;
    std::cout << "Testing averagePowerConsumptionByType()" << std::endl;
    std::cout << "Average power consumption by type:" << std::endl;
    std::cout << "Servers: " << infra.averagePowerConsumptionByType("Server") << "W" << std::endl;
    std::cout << "Routers: " << infra.averagePowerConsumptionByType("Router") << "W" << std::endl;
    std::cout << "Switches: " << infra.averagePowerConsumptionByType("Switch") << "W" << std::endl;
    std::cout << std::endl;

    std::cout << "Testing removeDeviceByHostname()" << std::endl;
    infra.removeDeviceByHostname("mail-server-01");
    infra.removeDeviceByHostname("nonexistent-device");

    std::cout << "Updated device list:" << std::endl;
    infra.listDevices();

    std::cout << std::endl;
    std::cout << "Testing MAX_DEVICES limit" << std::endl;
    std::cout << "Current device count: " << infra.getDeviceCount() << std::endl;
    
    std::cout << std::endl;
    std::cout << "MAX_DEVICES limit: " << NetworkInfrastructure::getMaxDevices() << std::endl;
    std::cout << "Adding additional devices to approach the limit" << std::endl;
    for (int i = 1; i <= 6; i++) {
        std::string hostname = "test-device-" + std::to_string(i);
        Server* testServer = new Server(hostname, "10.0.1." + std::to_string(10 + i), 
                                      "Test Location", "TestVendor", "TestOS", 2023, 100, false, 4);
        infra.addDevice(testServer);
        if (infra.getDeviceCount() >= NetworkInfrastructure::getMaxDevices()) {
            std::cout << "MAX_DEVICES limit reached!" << std::endl;
            break;
        }
    }
    std::cout << std::endl;
    std::cout << "Final device count: " << infra.getDeviceCount() << std::endl;
    std::cout << std::endl;
    return 0;
}