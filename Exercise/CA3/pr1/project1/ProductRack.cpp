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
   // Need to populate the allowedProductName for this rack
   std::strcpy(this->allowedProductName, allowedProductName);
}

Project1::ProductRack::~ProductRack()
{
   // We need to remove any left over products in the rack
   for (; productCount > 0; )
      delete products[--productCount];
}

bool
Project1::ProductRack::isCompatibleProduct(const char *productName) const
{
   // strcmp returns 0 if strings are equivalent
   return (strcmp(productName, allowedProductName) == 0);
}

bool
Project1::ProductRack::isFull() const
{
   // Check if MAX_PRODUCTS are on rack
   return (productCount == MAX_PRODUCTS);
}

bool
Project1::ProductRack::isEmpty() const
{
   // Check if there are zero products
   return (productCount == 0);
}

bool
Project1::ProductRack::addProduct(Product* pProduct)
{
   // Check if product rack is full
   if (isFull())
   {
      //delete &pProduct;
      statusPanel.displayMessage(StatusPanel::MESSAGECODE_RACK_IS_FULL);
   }
   // Check if product is compatible
   else if (!isCompatibleProduct(pProduct->getName()))
      statusPanel.displayMessage(StatusPanel::MESSAGECODE_PRODUCT_DOES_NOT_MATCH_PRODUCT_RACK);
   else
   {
      // add pointer to array BEFORE incrementing productCount
      products[productCount] = pProduct;
      // We increment productCount AFTER adding to 0-based array
      productCount++;
      return true;
   }

   return false;
}

bool
Project1::ProductRack::deliverProduct()
{
   if (isEmpty())
      statusPanel.displayMessage(StatusPanel::MESSAGECODE_SOLD_OUT);
   else if (deliveryChute.insertProduct(products[productCount - 1]))
   {
      //  decrement productCount before nulling pointer in 0-based array
      productCount--;
      products[productCount] = 0;

      return true;
   }

   return false;
}

unsigned
Project1::ProductRack::getNumProductsInRack() const
{
   return productCount;
}

unsigned
Project1::ProductRack::getProductPriceCents() const
{
   return productPriceCents;
}
