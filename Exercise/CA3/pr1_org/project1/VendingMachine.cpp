/*
* Vending Machine Project
* CSE-40477
*
* VendingMachine.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include "VendingMachine.h"

Project1::VendingMachine::VendingMachine(
    ostream &statusPanelStream,
    const char *productNames[NUM_PRODUCT_RACKS],
    unsigned productPrices[NUM_PRODUCT_RACKS])
    : statusPanel(statusPanelStream),
        deliveryChute(statusPanel),
        numCoins(0),
        unspentMoneyCents(0)
{
    // TODO: Implement
}

Project1::VendingMachine::~VendingMachine()
{
    // TODO: Implement
}

bool
Project1::VendingMachine::insertCoin(Coin *pCoin)
{
    // TODO: Implement
    return false;
}

bool
Project1::VendingMachine::pressButton(int button)
{
   // TODO: Implement
    return false;
}

Project1::Product *
Project1::VendingMachine::retrieveProduct()
{
    // TODO: Implement
    return 0;
}

bool
Project1::VendingMachine::addProduct(Product *pProduct)
{
    // TODO: Implement
    return false;
}

unsigned
Project1::VendingMachine::getProductCount(const char *productName) const
{
    // TODO: Implement
    return 0;
}

unsigned
Project1::VendingMachine::countTill() const
{
    // TODO: Implement
    return 0;
}

unsigned
Project1::VendingMachine::getNumCoinsInCoinBox() const
{
    // TODO: Implement
    return 0;
}
