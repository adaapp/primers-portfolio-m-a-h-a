float fahrenheitToCentigrade(float f) {
  return ((f - 32) * 5 / 9); //Fahrenheit to Centigrade.
}

float centigradeToFahrenheit(float c) {
  return ((c * 9 / 5) + 32); //Centigrade to Fahrenheit.
}


void fahrenheitCentigradeConversion(void) {
  std::string userInput;
  float useableTemp = 0.0;
  float convertedTemp = 0.0;

  std::cout << std::endl << "Please enter the starting temperature: " << std::endl;
  std::getline(std::cin, userInput);
  useableTemp = stof(userInput);

  std::cout << "Press ‘C’ to convert from Fahrenheit to Centigrade" << std::endl;
  std::cout << "Press ‘F’ to convert from Centigrade to Fahrenheit." << std::endl << std::endl;

  std::cout << "\nYour choice: ";
  std::getline(std::cin, userInput);

  if(userInput == "C" || userInput == "c") {
    convertedTemp = fahrenheitToCentigrade(useableTemp);
  }

  if(userInput == "F" || userInput == "f") {
    convertedTemp = centigradeToFahrenheit(useableTemp);
  }

  std::cout << useableTemp << " degrees " << " is = " << convertedTemp << "\n";
}

void selfServiceCheckout(void) {
	std::cout << " - selfServiceCheckout: not yet implemented\n\n";
}

