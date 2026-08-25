#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <fstream>
class Item {
private:
    std::string name;
    std::string category;
    int powerLevel;
    double weight;
public:
    Item(std::string n,std::string c,int p,double w) {
        name=n;
        category=c;
        powerLevel=p;
        weight=w;
    }
    std::string getName() {
        return name;
    }
    std::string getCategory() {
        return category;
    }
    int getLevel() {
        return powerLevel;
    }
    double getWeight() {
        return weight;
    }


};
class Inventory {
private:
    std::vector <std::unique_ptr<Item>> bag;
public:
    void addItem(std::string n,std::string c,int p,double w) {
        bag.push_back(std::make_unique<Item>(n,c,p,w));
    }
    void display() {
        for (int i=0;i<bag.size();i++) {
            std::cout<<bag[i]->getName()<<" has "<<bag[i]->getLevel()<<" damage/defense and weighs  "<<bag[i]->getWeight()
            <<" and in "<<bag[i]->getCategory()<<" category."<<std::endl;
        }
    }
    void sortbyCategory() {
        std::sort(bag.begin(),bag.end() , [](const std::unique_ptr<Item>& a,const std::unique_ptr<Item>&b) {
            return a->getCategory() < b->getCategory();
        });
    }
    void sortbyPower() {
        std::sort(bag.begin(),bag.end(),[](const std::unique_ptr<Item>&a,const std::unique_ptr<Item>&b) {
            return a->getLevel()>b->getLevel();
        });
    }
    void saveGame(std::string filename) {
        std::ofstream outFile(filename);
        if (!outFile.is_open()) {
            std::cout <<"ERROR cant open the file!"<<std::endl;
        }
        for (int i=0;i<bag.size();i++) {
            outFile<<bag[i]->getName()<<std::endl;
            outFile<< bag[i]->getCategory()<<std::endl;
            outFile<< bag[i]->getLevel()<<std::endl;
            outFile<< bag[i]->getWeight()<<std::endl;
        }
        outFile.close();
    std::cout<<"Game saved successfully!"<<std::endl;
    }
    void loadGame(std::string filename) {
        std::ifstream readFile(filename);
        if (!readFile.is_open()) {
            std::cout <<"Error no save file can be found!"<<std::endl;
            return;
        }
        bag.clear();
        std::string n,c;
        int p;
        double w;
        while (std::getline(readFile,n)) {
            std::getline(readFile,c);
            readFile>>p;
            readFile>>w;
            readFile>>std::ws;
            addItem(n,c,p,w);
        }
        readFile.close();
        std::cout<<"Game Loaded Successfully!"<<std::endl;
    }
};
int main () {
    Inventory a;
    a.loadGame("inventory_save_file.txt");
    int choice = 0;

    while (choice!=5) {
        std::cout<<"\n ==== INVENTORY MENU ===="<<std::endl;
        std::cout<<"1. View Inventory"<<std::endl;
        std::cout<<"2. Add new Item"<<std::endl;
        std::cout<<"3. Sort By Power"<<std::endl;
        std::cout<<"4. Sort by Category"<<std::endl;
        std::cout<<"5. Save and Quit"<<std::endl;
        std::cout<<"Please type what would you like to do"<<std::endl;
        std::cin>>choice;
        if (choice==1) {
            a.display();
        }
        else if (choice==2) {
            std::string n,c;
            int p;
            double w;
            std::cout<<"Enter Item name"<<std::endl;
            std::getline(std::cin>>std::ws,n);

            std::cout<<"Enter category (e.g., Sword,Katana,Pot):"<<std::endl;
            std::getline(std::cin>>std::ws,c);

            std::cout<<"Enter Power Level"<<std::endl;
            std::cin>>p;

            std::cout<<"Enter Weight"<<std::endl;
            std::cin >>w;
            a.addItem(n,c,p,w);
            std::cout<<n<<" added to your bag!"<<std::endl;

        }
        else  if (choice==3) {
            a.sortbyPower();
            std::cout<<"Inventory sorted by power"<<std::endl;
            a.display();
        }
        else if (choice==4) {
            a.sortbyCategory();
            std::cout<<"Inventory sorted by category"<<std::endl;
            a.display();
        }
        else if (choice==5) {
            a.saveGame("inventory_save_file.txt");
        }
        else {
            std::cout <<"Invalid command. Try Again. \n";
        }
    }



   /* a.addItem("Moonveil","Katana",140,15);
    a.addItem("Uchigatana","Katana",96,13);
    a.addItem("Blasphemous","Sword",169,30);
    a.addItem("Fire Grease","Pot",1,1);
    a.addItem("Cracked Pot","Pot",1,1);  // ADDED THE ITEMS BEFORE TRYING TO LOAD FUNCTION
    a.loadGame("inventory_save_file.txt");
    a.display();
    a.sortbyPower();
    std::cout<<"--------------Sorted By Power--------------"<<std::endl;
    a.display();
    a.sortbyCategory();
    std::cout <<"------------Sorted By Category------------"<<std::endl;
    a.display();
    a.saveGame("inventory_save_file.txt"); */ // Saving Mechanism for the game  */

    return 0;


}