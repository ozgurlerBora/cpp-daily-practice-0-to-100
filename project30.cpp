//
// Created by böo on 13/08/2026.
//
#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
class Player {
private:
    std::string username;
    int ping;
public:
    Player(std::string n,int p) {
        username=n;
        ping=p;
    }
    int getPing() {
        return ping;
    }
    std::string getUsername() {
        return username;
    }
    void spawn() {
        std::cout<<username<<"  has entered the game"<<std::endl;
    }
};
int main() {
    std::unordered_map<std::string,std::unique_ptr<Player>> server;
    std::vector<std::unique_ptr<Player>> queue;
    queue.push_back(std::make_unique<Player>("Bora",40));
    queue.push_back((std::make_unique<Player>("Efe",120)));
    queue.push_back((std::make_unique<Player>("Igor",15)));
    for (int i=0;i<queue.size();i++) {
        if (queue[i]->getPing()<100) {
            server[queue[i]->getUsername()]=std::move(queue[i]);
        }
        else {
            std::cout<<queue[i]->getUsername()<<"connection dropped. Ping  too high "<<std::endl;
        }
    }
    server["Bora"]->spawn();
    return 0;





}