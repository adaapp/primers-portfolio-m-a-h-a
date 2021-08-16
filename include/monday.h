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

void selfServiceCheckout(void) {
	std::cout << " - selfServiceCheckout: not yet implemented\n\n";
}

