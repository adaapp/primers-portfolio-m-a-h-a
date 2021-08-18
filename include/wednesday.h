bool fileExists(std::string filename) {
  struct stat buffer;

  if (stat(filename.c_str(), &buffer) == 0) {
    return true;
  }
  return false;
}

void displayResult(std::vector<std::string> results, int x, bool foundOrNot) {
  if (!foundOrNot) {
    std::cout << "Searching " << x << " records..." << std::endl << std::endl << "Sorry, no contact details found." << std::endl;
  } else {
    std::cout << "Searching " << x << " records..." << std::endl << std::endl << "Contact Details Found:" << std::endl;
    for (int i=0; i<results.size(); i++ ) {
      std::cout << results[i] << std::endl;
    }
  }
}

void readFile(std::string fileName, std::string searchString) {
  std::string fileLine;
  std::ifstream fileobject;
  bool doesFileExist = false;
  bool itemFound = false;
  int x = 0;
  std::vector<std::string> results;

  doesFileExist = fileExists(fileName);

  if (doesFileExist) {
    fileobject.open(fileName);

    while(!fileobject.eof()) {
      getline(fileobject, fileLine);
      if (fileLine.find(searchString) != std::string::npos) {
        results.push_back(fileLine);
        itemFound = true;
        x++;
      } else {
        itemFound = false;
        x++;
      }
    }
    fileobject.close();
    
    if (!itemFound) {
      //std::cout << "Searching " << x << " records..." << std::endl << std::endl << "Sorry, no contact details found." << std::endl;
      displayResult(results, x, false);
    } else {
      displayResult(results, x, true);
      //std::cout << "Searching " << x << " records..." << std::endl << std::endl << "Contact Details Found:" << std::endl << fileLine << std::endl;
    }
  } else {
    std::cout << std::endl << "File does not exist" << std::endl;
  }
}

void phoneDirectory(void) {
  std::string userInput;
  std::string fileName = "phoneDirectory.txt";

	std::cout << "Please enter a name or telephone number to search:" << std::endl;
  std::getline(std::cin, userInput);

  readFile(fileName, userInput);
}


void dataFileParser(void) {
	std::cout << " - dataFileParser: not yet implemented\n\n";
}