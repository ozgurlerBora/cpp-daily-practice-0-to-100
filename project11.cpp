//
// Created by böo on 29/07/2026.
//
#include <iostream>
#include <vector>
#include <string>
class Item {
private:
    std::string ItemName;
    double price;
    int quantity;
public:
    Item(std::string name,double Nprice,int Nquantity) {
        if (Nprice<0||Nquantity<0) {
            std::cout<<"Invalid Input price and quantity automatically set to 0"<<std::endl;
            Nprice=0;
            Nquantity=0;
        }
        ItemName=name;
        price=Nprice;
        quantity=Nquantity;
    }
    double calculateSubtotal() {
        double sum;
        sum=price*quantity;
        return sum;
    }
    void printItem() {
        std::cout<<"Item name: "<<ItemName<<" Price is "<<price<<"  Quantity is "<<quantity<<std::endl;
    }

};
class ShoppingCart {
private:
    std::string customerName;
    std::vector <Item> cart;
public:
    ShoppingCart(std::string newCustomerName) {
       customerName=newCustomerName;
    }
    void addItem(std::string name,double price,int quantity) {
        Item temp(name,price,quantity);
        cart.push_back(temp);
    }
    void checkOut(){
        double grandTotal=0.0;
        for (int i=0;i<cart.size();i++) {
            cart[i].printItem();
            grandTotal=cart[i].calculateSubtotal()+grandTotal;
        }
        std::cout<<customerName<<"'s grand total is "<<grandTotal<<std::endl;
    }
};
int main() {
    ShoppingCart cart1 ("Bora");
    cart1.addItem("Laptop",1200,1);
    cart1.addItem(("Cable"),10,2);
    cart1.addItem(("fakeitem"),-45,-12);
    cart1.checkOut();
    std::cin.ignore(100,'\n');
    std::cin.get();
}