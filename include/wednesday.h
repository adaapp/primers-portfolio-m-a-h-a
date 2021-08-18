bool fileExists(std::string filename) {
  struct stat buffer;

  if (stat(filename.c_str(), &buffer) == 0) {
    std::cout << std::endl << "size: " << buffer.st_size;
    std::cout << std::endl << "modified: " << ctime(&buffer.st_mtime);
    return true;
  }
  return false;
}

void readFile(std::string fileName) {
  std::string fileLine;
  std::ifstream fileobject;
  bool doesFileExist = false;

  doesFileExist = fileExists(fileName);

  if (doesFileExist) {
    fileobject.open(fileName);

    while(getline(fileobject, fileLine)) {
      std::cout <<std::endl << fileLine;
    }
    fileobject.close();
  } else {
    std::cout << std::endl << "File does not exist" << std::endl;
  }
}

void phoneDirectory(void) {
  std::string userInput;
  std::string fileName = "phoneDirectory.txt";

	std::cout << "Please enter a name or telephone number to search:" << std::endl;
  std::getline(std::cin, userInput);

  readFile(fileName);
}


void dataFileParser(void) {
	std::cout << " - dataFileParser: not yet implemented\n\n";
}