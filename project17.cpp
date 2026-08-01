//
// Created by böo on 01/08/2026.
//
#include <iostream>
#include <string>
#include <vector>
class Server {
private:
    std::string ipAddress;
    int activeUsers;
public:
    Server(std::string newIpAdress) {
        ipAddress=newIpAdress;
        activeUsers=0;
    }
    std::string getIP() {
        return ipAddress;
    }
    void routeTraffic(int Users) {
        if (Users<0) {
            std::cout<<"Wrong Input"<<std::endl;
        }
        else {
            activeUsers=activeUsers+Users;
        }
    }
    void printStatus() {
        std::cout<<"The IP is "<<ipAddress<<"and active user count is "<<activeUsers<<std::endl;
    }
};
class DataCenter {
private:
    std::string centerName;
    std::vector <Server*> network;
public:

    void InstallServer(std::string newIP) {
        Server* newServer=new Server(newIP);
        network.push_back((newServer));
    }
    Server* getServer(std::string searchIP) {
        for (int i=0;i<network.size();i++) {
            if (searchIP==network[i]->getIP()) {
                return network[i];
            }
        }
        return nullptr;
    }
    ~DataCenter() {
        for (int i=0;i<network.size();i++) {
            delete network[i];
            std::cout<<"You have successfully cleared the memory!"<<std::endl;
        }
    }




};
int main() {
    DataCenter center1;
    center1.InstallServer("192.168.1.1");
    center1.InstallServer("192.162.1.2");
    Server* server1 =center1.getServer("192.168.1.1");
    if (server1!=nullptr) {
        server1->routeTraffic(5000);
        server1->printStatus();

    }

    return 0;
}
