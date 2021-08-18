bool fileExists(std::string filename) {
  //check if file exists
  struct stat buffer;

  if (stat(filename.c_str(), &buffer) == 0) {
    return true;
  }
  return false;
}

void displayResult(std::vector<std::string> results, int x, bool foundOrNot) {
  //display the result, either found or not found
  if (!foundOrNot) {
    std::cout << "Searching " << x << " records..." << std::endl << std::endl << "Sorry, no contact details found." << std::endl;
  } else {
    std::cout << "Searching " << x << " records..." << std::endl << std::endl << "Contact Details Found:" << std::endl;
    for (int i=0; i<results.size(); i++ ) {
      std::cout << results[i] << std::endl;
    }
  }
}

void readFileFromSearch(std::string fileName, std::string searchString) {
  std::string fileLine;
  std::ifstream fileobject;
  bool doesFileExist = false;
  bool itemFound = false;
  int x = 0;
  std::vector<std::string> results;

  doesFileExist = fileExists(fileName); //check if file exists

  if (doesFileExist) {
    fileobject.open(fileName);

    while(!fileobject.eof()) { //loop through the file
      getline(fileobject, fileLine);
      if (fileLine.find(searchString) != std::string::npos) {
        //search line by line and bring back the entire line if something is found
        results.push_back(fileLine);
        itemFound = true;
        x++;
      } else {
        itemFound = false;
        x++;
      }
    }
    fileobject.close();
    
    if (!itemFound) { //show results
      displayResult(results, x, false);
    } else {
      displayResult(results, x, true);
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

  readFileFromSearch(fileName, userInput);
}

void splitByDelim(std::string lines, char delim) {
  std::string buffer;
  std::string temp;
  std::vector<std::string> itemsForDisplay;
  bool firstComma = true;
  bool secondComma = false;

  std::stringstream ss(lines); //this puts each line in a stream
  while(getline(ss, buffer, delim)) { //split the steam into a buffer at the delimiter
    if (firstComma) {
      temp = buffer[0]; //for some reason push_back doesn't like buffer[0] so do this
      itemsForDisplay.push_back(temp);
      firstComma = false;
      secondComma = true;
    } else if (secondComma)  {
      //trim the whitespace at the start of the item
      buffer.erase(0, buffer.find_first_not_of(" \n\r\t"));
      itemsForDisplay.push_back(buffer); //push the item into a vector
      secondComma = false;
      firstComma = false;
    } else {
      buffer.erase(0, buffer.find_first_not_of(" \n\r\t"));
      itemsForDisplay.push_back(buffer); //push the item into a vector
      firstComma = true;
      secondComma = true;
    }
  }

  for (int i=0; i<itemsForDisplay.size(); i++ ) {
      std::cout << itemsForDisplay[i] << std::endl;
    }
}

void splitFileByLine(std::string fileName) {
  bool doesFileExist = false;
  std::string fileLine;
  std::ifstream fileobject;
  std::vector<std::string> items;
  char delim = ',';
  std::vector<std::string> itemsForDisplay;
  bool firstComma = true;
  bool secondComma = false;
  std::string temp;
  std::string buffer;

  doesFileExist = fileExists(fileName); //check if file exists

  if (doesFileExist) {
    fileobject.open(fileName); //open file

    while(!fileobject.eof()) { //loop through the file
      getline(fileobject, fileLine); //grab each line
      splitByDelim(fileLine, delim); //pass each line to the split by , function
    }
    fileobject.close(); //close the file

    for (int i=0; i<itemsForDisplay.size(); i++ ) {
      std::cout << itemsForDisplay[i] << std::endl;
    }
  }
}

void dataFileParser(void) {
  std::string fileName = "primerChallenge6.csv";

  splitFileByLine(fileName);
  
}