float fahrenheitToCentigrade(float f) {
  return ((f - 32) * 5 / 9); //Fahrenheit to Centigrade.
}

float centigradeToFahrenheit(float c) {
  return ((c * 9 / 5) + 32); //Centigrade to Fahrenheit.
}

void output(float origTemp, float temperature, std::string convertTo, std::string convertFrom) {
  std::cout << origTemp << " degrees " << convertFrom << " is " << temperature << " in " << convertTo << std::endl;
}

bool checkForInt(std::string intToCheck, bool negativeAllowed) {
  try {
    int temp = stoi(intToCheck);
    //below we ensure the user has entered a positive value only, if not, throw an error. Ideally would check for decimals but stoi takes care of that anyway.
    if (negativeAllowed == 0 && stoi(intToCheck) < 0) {
      throw std::invalid_argument("Received a negative value.");
    }
    return true;
  } catch (std::exception e) {
    std::cout << "Unrecognised entry. Please try again and ensure you only enter a positive number, e.g. 22 or 2" << std::endl;
    return false;
  }
}

bool checkForFloat(std::string floatToCheck, bool negativeAllowed) {
  try {
    float temp = stof(floatToCheck);
    if (negativeAllowed == 0 && stof(floatToCheck) < 0) { //check for negative values
      throw std::invalid_argument("Received a negative value.");
    }
    return true;
  } catch (std::exception e) {
    std::cout << "Unrecognised entry. Please try again and ensure you only enter a positive number, e.g. 22 or 22.5" << std::endl;
    return false;
  }
}

void fahrenheitCentigradeConversion(void) {
  //declare variables
  std::string userInput, tempChoice;
  float useableTemp = 0.0;
  float convertedTemp = 0.0;

  //get the starting temperature from the user
  std::cout << std::endl << "Please enter the starting temperature: " << std::endl;
  std::getline(std::cin, userInput);

  //check if user has entered a useable number, 1 means negatives allowed
  bool proceed = checkForFloat(userInput, 1);
  if (proceed) {
    useableTemp = stof(userInput);
    std::cout << std::endl << "Press ‘C’ to convert from Fahrenheit to Centigrade" << std::endl << "Press ‘F’ to convert from Centigrade to Fahrenheit." << std::endl << std::endl;
    std::getline(std::cin, tempChoice);

    if (tempChoice == "C" || tempChoice == "c") {
      convertedTemp = fahrenheitToCentigrade(useableTemp); //convert temperature
      output(useableTemp, convertedTemp, "CENTIGRADE", "FAHRENHEIT"); //show output
    } else if (tempChoice == "F" || tempChoice == "f") {
      convertedTemp = centigradeToFahrenheit(useableTemp);
      output(useableTemp, convertedTemp, "FAHRENHEIT", "CENTIGRADE");
    } else {
      std::cout << std::endl << "Please enter only 'C' or 'F'." << std::endl;
    }
  }
}

/*SELF SERVICE CHECKOUT*/
int sumQuantities(std::vector<int> vectorQty) {
  int quantitySum = 0;
  //loop through vector and sum quantity. Ampersand means don't make a copy, use the actual item
  std::for_each(vectorQty.begin(), vectorQty.end(), [&] (int n) {
    quantitySum += n;
  });
  //return total quantity
  return quantitySum;
}

float sumTotal(std::vector<int> vectorQty, std::vector<float> vectorTtl) {
  float totalSum = 0.0;
  //loop through vector and sum total cost
  for (int i=0; i<vectorQty.size(); i++) {
    totalSum += vectorQty[i] * vectorTtl[i];
  }
  //return total cost
  return totalSum;
}

float roundSum(float number) {
  //rounds the number and the setprecision ensures it looks like currency
  return round(number * 100)/100;
}

void printReceipt(std::vector<std::string> allItemNames, std::vector<int> allItemQty, std::vector<float> allItemCosts) {
  #define SHOPPING_TAX 5.5 //shopping tax
  int totalItems = 0;
  float subtotal = 0.0;
  float totalTax = 0.0;

  totalItems = sumQuantities(allItemQty); //get the total quantity of items
  subtotal = sumTotal(allItemQty, allItemCosts); //get the subtotal cost
  totalTax = (subtotal/100) * SHOPPING_TAX; //work out the total tax

  std::cout << std::endl << "Your receipt:" << std::endl;

  //print out a receipt showing number of items, name, cost each
  for (int i=0; i<allItemNames.size(); i++) {
    std::cout << std::fixed << std::setprecision(2) << allItemQty[i] << " '" << allItemNames[i] << "' at £" << roundSum(allItemCosts[i]) << " each." << std::endl;
  }
  
  //display subtotal, tax amount and the total. Use round to keep things to two decimal places
  std::cout << std::fixed << std::setprecision(2) << std::endl << "Total Items = " << totalItems << std::endl << "Subtotal = £" << roundSum(subtotal) << std::endl << "Shopping Tax = £" << roundSum(totalTax) << std::endl << std::endl << "Total: £" << roundSum(subtotal + totalTax) << std::endl;
}

void selfServiceCheckout(void) {
  int x = 1;
  bool proceed = false;
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
    proceed = checkForInt(itemQty, 0); //check if user has entered a useable number
    if (proceed) {
      allItemQty.push_back(stoi(itemQty)); //store the item in the vector
    } else { //if input isn't valid, quit
      quitOrContinue = "q";
      break;
    }
    std::cout << std::endl << "Please enter the cost per item " << x << ":" << std::endl;
    std::getline(std::cin, itemCost);
    proceed = checkForFloat(itemCost, 0); //check if user has entered a useable number
    if (proceed) {
      allItemCosts.push_back(stof(itemCost)); //store the item in the vector
    } else { //if input isn't valid, quit
      quitOrContinue = "q";
      break;
    }
    std::cout << std::endl << "Press any key to add more items or 0 to finish" << std::endl;
    std::getline(std::cin, quitOrContinue);
    x++; //increment loop
  }
  while (quitOrContinue != "0"); //check for quit key "0"

  if (quitOrContinue == "0") { //ensure we've not thrown errors in the loop
    //receipt
    printReceipt(allItemNames, allItemQty, allItemCosts);
  }
}