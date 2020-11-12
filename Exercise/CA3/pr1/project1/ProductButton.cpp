/*
* Vending Machine Project
* CSE-40477
*
* ProductButton.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include <cstring>
using std::strcpy;

#include "ProductButton.h"

Project1::ProductButton::ProductButton(ProductRack &productRack)
   : productRack(productRack) {}

bool
Project1::ProductButton::press()
{
   return productRack.deliverProduct();
}

unsigned
Project1::ProductButton::getProductPriceCents() const
{
   return productRack.getProductPriceCents();
}
