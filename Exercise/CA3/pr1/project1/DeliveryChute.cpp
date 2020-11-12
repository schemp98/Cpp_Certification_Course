/*
* Vending Machine Project
* CSE-40477
*
* DeliveryChute.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include "DeliveryChute.h"

Project1::DeliveryChute::DeliveryChute(StatusPanel &statusPanel)
   : statusPanel(statusPanel),
   pProduct(0)
{
   // Constructor already initializes object correctly
}

Project1::DeliveryChute::~DeliveryChute()
{
   // Need to destroy product that remains in DeliveryChute
   if (pProduct != 0)
      delete pProduct;
}

bool
Project1::DeliveryChute::insertProduct(Product *pProduct)
{
   // Check if Chute is full
   if (containsProduct())
   {
      statusPanel.displayMessage(StatusPanel::MESSAGECODE_CHUTE_FULL);
      return false;
   }
   else
   {
      // Add Product to DeliveryChute if empty
      this->pProduct = pProduct;
      return true;
   }
}

Project1::Product *
Project1::DeliveryChute::retrieveProduct()
{
   // If Chute is full return product, otherwise return 0
   if (containsProduct())
   {
      // need to place pointer in temporary variable in order to null both
      // NULL the member variable pProduct and return it
      Project1::Product* returnProduct = pProduct;

      //relinquish product ownership
      pProduct = 0;
      return returnProduct;
   }
   else
      return 0;
}

bool
Project1::DeliveryChute::containsProduct() const
{
   // Check if there is a product in the chute
   return (pProduct != 0);
}
