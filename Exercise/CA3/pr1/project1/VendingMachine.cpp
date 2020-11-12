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
   // We need to set up the product buttons and racks
   for (int prodIdx = 0; prodIdx < NUM_PRODUCT_RACKS; prodIdx++)
   {
      productRacks[prodIdx] = new ProductRack(statusPanel, productNames[prodIdx], deliveryChute, productPrices[prodIdx]);
      productButtons[prodIdx] = new ProductButton(*productRacks[prodIdx]);
   }
}

Project1::VendingMachine::~VendingMachine()
{
   // We need to clean up memory dynamically allocated in constructor
   for (int prodIdx = 0; prodIdx < NUM_PRODUCT_RACKS; prodIdx++)
   {
      delete productRacks[prodIdx];
      delete productButtons[prodIdx];
   }

   // We need to get rid of any Coins added to the coinBox
   for (; numCoins > 0; )
      delete coinBox[--numCoins];
}

bool
Project1::VendingMachine::insertCoin(Coin *pCoin)
{
   if (pCoin->getDenomination() != Coin::COINTYPE_WOODEN_NICKEL)
   {
      // add Coin to coinBox
      coinBox[numCoins] = pCoin;
      // increase number of Coins (1 -based)
      numCoins++;
      // add Coin Value to unspentMoneyCents
      unspentMoneyCents += pCoin->getValueCents();
      return true;
   }
   else
      statusPanel.displayMessage(StatusPanel::MESSAGECODE_BAD_COIN);

   return false;
}

bool
Project1::VendingMachine::pressButton(int button)
{
   // First check if valid button pressed, if not display status message
   if (!((button >= 0) && (button < NUM_PRODUCT_RACKS)))
      statusPanel.displayMessage(StatusPanel::MESSAGECODE_WRONG_BUTTON);
   // if valid button pressed, ensure there is enough money before pressing
   else if (productButtons[button]->getProductPriceCents() <= unspentMoneyCents)
   {
      // We need to decrement the unspentMoney by the Product Price
      unspentMoneyCents -= productButtons[button]->getProductPriceCents();
      return productButtons[button]->press();
   }
   else
      statusPanel.displayMessage(StatusPanel::MESSAGECODE_INSUFFICIENT_MONEY);

   return false;
}

Project1::Product *
Project1::VendingMachine::retrieveProduct()
{
   return deliveryChute.retrieveProduct();
}

bool
Project1::VendingMachine::addProduct(Product *pProduct)
{
   for (int prodIdx = 0; prodIdx < NUM_PRODUCT_RACKS; prodIdx++)
   {
      // Check to see which rack (if any) contains product we want to add
      if (productRacks[prodIdx]->isCompatibleProduct(pProduct->getName()))
         // Attempt to add product to rack
         return productRacks[prodIdx]->addProduct(pProduct);
   }

   statusPanel.displayMessage(StatusPanel::MESSAGECODE_NO_RACK_FOR_PRODUCT);
   return false;
}

unsigned
Project1::VendingMachine::getProductCount(const char *productName) const
{
   for (unsigned prodIdx = 0; prodIdx < NUM_PRODUCT_RACKS; prodIdx++)
   {
      // Check to see which rack (if any) contains product we want to add
      if (productRacks[prodIdx]->isCompatibleProduct(productName))
         return productRacks[prodIdx]->getNumProductsInRack();
   }

   // No compatible racks for product
   return 0;
}

unsigned
Project1::VendingMachine::countTill() const
{
   unsigned till = 0;
   for (unsigned coinIdx = 0; coinIdx < numCoins; coinIdx++)
      till += coinBox[coinIdx]->getValueCents();

   return till;
}

unsigned
Project1::VendingMachine::getNumCoinsInCoinBox() const
{
   return numCoins;
}
