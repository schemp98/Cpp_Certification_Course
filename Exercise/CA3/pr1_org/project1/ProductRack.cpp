/*
* Vending Machine Project
* CSE-40477
*
* ProductRack.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include <cstring>
using std::strcmp;

#include "ProductRack.h"

Project1::ProductRack::ProductRack(
    StatusPanel &statusPanel,
    const char *allowedProductName,
    DeliveryChute &deliveryChute,
    unsigned productPriceCents)
    : statusPanel(statusPanel),
        deliveryChute(deliveryChute),
        productCount(0),
        productPriceCents(productPriceCents)
{
    // TODO: Implement
}

Project1::ProductRack::~ProductRack()
{
    // TODO: Implement
}

bool
Project1::ProductRack::isCompatibleProduct(const char *productName) const
{
    // TODO: Implement
    return false;
}

bool
Project1::ProductRack::isFull() const
{
    // TODO: Implement
    return false;
}

bool
Project1::ProductRack::isEmpty() const
{
    // TODO: Implement
    return false;
}

bool
Project1::ProductRack::addProduct(Product* pProduct)
{
    // TODO: Implement
    return false;
}

bool
Project1::ProductRack::deliverProduct()
{
   // TODO: Implement
    return false;
}

unsigned
Project1::ProductRack::getNumProductsInRack() const
{
    // TODO: Implement
    return 0;
}

unsigned
Project1::ProductRack::getProductPriceCents() const
{
    // TODO: Implement
    return 0;
}
