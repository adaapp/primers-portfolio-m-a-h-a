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
  std::string userInput, tempChoice;
  float useableTemp = 0.0;
  float convertedTemp = 0.0;

  std::cout << std::endl << "Please enter the starting temperature: " << std::endl;
  std::getline(std::cin, userInput);

  try {
    useableTemp = stof(userInput);
    std::cout << std::endl << "Press ‘C’ to convert from Fahrenheit to Centigrade" << std::endl << "Press ‘F’ to convert from Centigrade to Fahrenheit." << std::endl << std::endl;
    std::getline(std::cin, tempChoice);

    if (tempChoice == "C" || tempChoice == "c") {
      convertedTemp = fahrenheitToCentigrade(useableTemp);
      output(useableTemp, convertedTemp, "CENTIGRADE", "FAHRENHEIT");
    }
    if (tempChoice == "F" || tempChoice == "f") {
      convertedTemp = centigradeToFahrenheit(useableTemp);
      output(useableTemp, convertedTemp, "FAHRENHEIT", "CENTIGRADE");
    }
  } catch (std::exception e) {
    std::cout << "Unrecognised entry. Please try again and ensure you only enter a number, e.g. 22 or 22.5" << std::endl;
  }
}

void selfServiceCheckout(void) {
	std::cout << " - selfServiceCheckout: not yet implemented\n\n";
}

