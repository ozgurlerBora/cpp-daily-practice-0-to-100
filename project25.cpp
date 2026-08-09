//
// Created by böo on 10/08/2026.
//
#include <iostream>
#include <vector>
#include <string>
class Notification {
protected:
    std::string recipient;
public:
    Notification(std::string name) {
        recipient=name;
    }
    virtual void send() {
        std::cout<<"Sending generic alert to ["<<recipient<<"]"<<std::endl;
    }

};
class EmailNotif : public Notification {
public:
    EmailNotif(std::string name): Notification(name) {

    }
    void send()override {
        std::cout<<"Sending EMAIL to ["<<recipient<<"] with HTML template."<<std::endl;
    }
};
class SmsNotif : public Notification {
public:
    SmsNotif(std::string name): Notification(name){}
    void send() override {
        std::cout<<"Sending SMS to ["<<recipient<<"] over cellular network"<<std::endl;

    }
};
int main() {
    std::vector<Notification*> pipeline;
    Notification* temp1 = new EmailNotif("Bora");
    pipeline.push_back(temp1);
    Notification* temp2 = new SmsNotif( "Bora");
    pipeline.push_back(temp2);
    for (int i=0;i<pipeline.size();i++) {
        pipeline[i]->send();
    }
    for (int i=0; i<pipeline.size();i++) {
        delete pipeline[i];
    }
    return 0;
}
