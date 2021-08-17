float fahrenheitToCentigrade(float f) {
  return ((f - 32) * 5 / 9); //Fahrenheit to Centigrade.
}

float centigradeToFahrenheit(float c) {
  return ((c * 9 / 5) + 32); //Centigrade to Fahrenheit.
}

void output(float origTemp, float temperature, std::string convertTo, std::string convertFrom) {
  std::cout << origTemp << " degrees " << convertFrom << " is " << temperature << " in " << convertTo << std::endl;
}

void fahrenheitCentigradeConversion(void) {
  //declare variables
  std::string userInput, tempChoice;
  float useableTemp = 0.0;
  float convertedTemp = 0.0;
  bool loopComplete = false;

  //get the starting temperature from the user
  std::cout << std::endl << "Please enter the starting temperature: " << std::endl;
  std::getline(std::cin, userInput);

  //loop to keep the program running should a user enter anything other than 'c' or 'f'
  while (!loopComplete) {
    try {
      //try/catch to ensure we can convert the temp the user has provided into a float
      useableTemp = stof(userInput);
      std::cout << std::endl << "Press ‘C’ to convert from Fahrenheit to Centigrade" << std::endl << "Press ‘F’ to convert from Centigrade to Fahrenheit." << std::endl << std::endl;
      std::getline(std::cin, tempChoice);

      if (tempChoice == "C" || tempChoice == "c") {
        convertedTemp = fahrenheitToCentigrade(useableTemp); //convert temperature
        output(useableTemp, convertedTemp, "CENTIGRADE", "FAHRENHEIT"); //show output
        loopComplete = true; //close loop
      }
      if (tempChoice == "F" || tempChoice == "f") {
        convertedTemp = centigradeToFahrenheit(useableTemp);
        output(useableTemp, convertedTemp, "FAHRENHEIT", "CENTIGRADE");
        loopComplete = true;
      } else if (!loopComplete) {
        std::cout << std::endl << "Please enter only 'C' or 'F'." << std::endl;
      }
    } catch (std::exception e) {
      std::cout << "Unrecognised entry. Please try again and ensure you only enter a number, e.g. 22 or 22.5" << std::endl;
      loopComplete = true;
    }
  }
}

int sumQuantities(std::vector<int> vectorQty) {
  int quantitySum = 0;
   
  std::for_each(vectorQty.begin(), vectorQty.end(), [&] (int n) {
    quantitySum += n;
  });

  return quantitySum;
}

float sumTotal(std::vector<int> vectorQty, std::vector<float> vectorTtl) {
  float totalSum = 0.0;

  for (int i=0; i<vectorQty.size(); i++) {
    totalSum += vectorQty[i] * vectorTtl[i];
  }

  return totalSum;
}

void selfServiceCheckout(void) {
	#define SHOPPING_TAX 5.5 //shopping tax
  float subtotal = 0.0;
  float totalTax = 0.0;
  int totalItems = 0;
  int x = 1;
  std::string itemName, itemQty, itemCost, quitOrContinue;
  //use vectors instead of array as arrays need to be declared with an amount
  std::vector<float> allItemCosts;
  std::vector<int> allItemQty;
  std::vector<std::string> allItemNames;

  do {
    //loop and ask user for the name, quantity and cost of each item
    std::cout << std::endl << "Please enter the name of item " << x << ":" << std::endl;
    std::getline(std::cin, itemName);
    allItemNames.push_back(itemName); //store the item in the vector
    std::cout << std::endl << "Please enter the quantity of item " << x << ":" << std::endl;
    std::getline(std::cin, itemQty);
    allItemQty.push_back(stoi(itemQty)); //store the item in the vector
    std::cout << std::endl << "Please enter the cost of item " << x << ":" << std::endl;
    std::getline(std::cin, itemCost);
    allItemCosts.push_back(stof(itemCost)); //store the item in the vector
    std::cout << std::endl << "Press any key to add more items or 0 to finish" << std::endl;
    std::getline(std::cin, quitOrContinue);
    x++; //increment loop
  }
  while (quitOrContinue != "0"); //check for quit key "0"

  totalItems = sumQuantities(allItemQty); //get the total quantity of items
  subtotal = sumTotal(allItemQty, allItemCosts); //get the subtotal cost
  totalTax = (subtotal/100) * SHOPPING_TAX; //work out the total tax

  //receipt
  std::cout << std::endl << "Your receipt:" << std::endl;

  //print out a receipt showing number of items, name, cost each
  for (int i=0; i<allItemNames.size(); i++) {
    std::cout << std::fixed << std::setprecision(2) << allItemQty[i] << " '" << allItemNames[i] << "' at £" << round(allItemCosts[i] * 100)/100 << " each." << std::endl;
  }
  
  //display subtotal, tax amount and the total. Use round to keep things to two decimal places
  std::cout << std::fixed << std::setprecision(2) << std::endl << "Total Items = " << totalItems << std::endl << "Subtotal = £" << round(subtotal * 100)/100 << std::endl << "Shopping Tax = £" << round(totalTax * 100)/100 << std::endl << std::endl << "Total: £" << round((subtotal + totalTax) * 100)/100 << std::endl;
}

