//not ideal but create global variables (for data file parser)
std::vector<std::string> itemsForDisplay;
std::string maxSurname, maxSalaryLength = "";
int intMaxSurnameSize, intMaxSalaryLength = 0;
/*END*/

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
      }
      x++;
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

//from here down is "DATA FILE PARSER"
void getSize(std::string textToSize, int colNo) {
  if (colNo == 2) {
    //looking at surnames
    if (textToSize.size() > maxSurname.size()) {
      //word we've been passed is larger
      maxSurname = textToSize;
    }
    intMaxSurnameSize = maxSurname.size();
  } else {
    //looking at salaries
    if (textToSize.size() > maxSalaryLength.size()) {
      //salary we've been passed is longer
      maxSalaryLength = textToSize;
    }
    intMaxSalaryLength = maxSalaryLength.size();
  }
}

void splitByDelim(std::string lines, char delim) {
  //I know, somewhere in my tiny brain, that there's a better way of doing this but my brain is fried
  //I'm using flags to check if we want to add an item to col 1, 2 if not it's 3. it works, but I'm
  //sure there's a better, more efficient way, it's just not coming to me at the mo.
  std::string buffer;
  std::string temp;
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
      getSize(buffer, 2);
      itemsForDisplay.push_back(buffer); //push the item into a vector
      secondComma = false;
      firstComma = false;
    } else {
      buffer.erase(0, buffer.find_first_not_of(" \n\r\t"));
      getSize(buffer, 3);
      itemsForDisplay.push_back(buffer); //push the item into a vector
      firstComma = true;
      secondComma = true;
    }
  }
}

void showDataFileParserResult(std::vector<std::string> displayItems) {
  //we have the longest for each column, now we need to lay it out using setw.
  //have +1 for the headers to get the extra space at the end but not on the "-"
  //as this made it look odd.
  std::cout << std::endl << std::setw(8) << "Initial " << std::left << std::setfill(' ')
            << std::setw(intMaxSurnameSize+1) << "Last" << std::left << std::setfill(' ')
            << std::setw(intMaxSalaryLength+1) << "Salary" << std::left << std::setfill(' ') << std::endl;
  for (int i=0; i<7; i++) {
    std::cout << std::setw(0) << "-";
  }
  std::cout << " "; //add a space
  for (int i=0; i<(intMaxSurnameSize); i++) {
    std::cout << "-";
  }
  std::cout << " ";
  for (int i=0; i<(intMaxSalaryLength); i++) {
    std::cout << "-";
  }
  std::cout << std::endl;
  for (int i=0; i<itemsForDisplay.size(); i++ ) {
    std::cout << std::setw(8) << std::left << std::setfill(' ') << itemsForDisplay[i];
    i++;
    std::cout << std::setw(intMaxSurnameSize+1) << std::left << std::setfill(' ') << itemsForDisplay[i];
    i++;
    std::cout << std::setw(intMaxSalaryLength+1) << std::left << std::setfill(' ') << itemsForDisplay[i]<< std::endl;
  }
}

void splitFileByLine(std::string fileName) {
  bool doesFileExist = false;
  std::string fileLine;
  std::ifstream fileobject;
  char delim = ',';

  doesFileExist = fileExists(fileName); //check if file exists

  if (doesFileExist) {
    fileobject.open(fileName); //open file

    while(!fileobject.eof()) { //loop through the file
      getline(fileobject, fileLine); //grab each line
      splitByDelim(fileLine, delim); //pass each line to the split by , function
    }
    fileobject.close(); //close the file

    showDataFileParserResult(itemsForDisplay); //display results
  }
}

void dataFileParser(void) {
  std::string fileName = "primerChallenge6.csv";

  splitFileByLine(fileName);
}