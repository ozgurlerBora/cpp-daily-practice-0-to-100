//
// Created by böo on 03/08/2026.
//
#include <iostream>
#include <string>
#include <vector>
class Stock {
private:
    std::string tickerSymbol;//ticker symbol is a short code to identify a publicly traded company like AAPL
    double currentPrice;
public:
    Stock(std::string name,double number) {
        tickerSymbol=name;
        currentPrice=number;
    }
    std::string getTicker() {
        return tickerSymbol;
    }
    void updatePrice(double newPrice) {
        if (newPrice>0) {
            currentPrice=newPrice;
        }
        else std::cout<<"Wrong Price INPUT!"<<std::endl;
    }
    void displayStock() {
        std::cout<<"Current Price for the "<<tickerSymbol<<"is "<<currentPrice<<std::endl;
    }
};
class Portfolio {
private:
    std::vector<Stock*> holdings;
public:
    void buyStock(std::string ticker,double startPrice) {
        Stock* temp=new Stock(ticker,startPrice);
        holdings.push_back(temp);
    }
    Stock* getstock(std::string searchTicker) {
        for (int i=0;i<holdings.size();i++) {
            if (searchTicker==holdings[i]->getTicker()) {
                return holdings[i];
            }
        }
        return nullptr;
    }
    ~Portfolio() {
        for (int i=0;i<holdings.size();i++) {
            delete holdings[i];
            std::cout<<"Destructor works!"<<std::endl;
        }
    }

};
int main() {
    Portfolio port1;
    port1.buyStock("NVDA",115.50);
    port1.buyStock("AAPL",150);

    Stock* ptr1=port1.getstock("NVDA");
    if (ptr1!=nullptr) {
        ptr1->updatePrice(250);
        ptr1->displayStock();
    }
return 0;



}
