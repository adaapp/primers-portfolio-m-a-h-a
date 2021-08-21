std::vector<int> definePassword(std::string password) {
  //function to count the component parts of the password (letters, numbers etc)
  int alphanumeric, numbers, specials, x, poundSignFound;
  std::vector<int> totals;

  alphanumeric = numbers = specials = poundSignFound = x = 0; //set everything to 0

  //loop through password and count component parts
  while (x <= (password.length()-1)) {
    if ((password[x] >= 'a' && password[x] <= 'z') || (password[x] >= 'A' && password[x] <= 'Z')) {
      alphanumeric++;
    } else if (password[x] >= '0' && password[x] <= '9') {
      numbers++;
    } else {
      if (password[x] == char(163)) {
        //because of ASCII and locals, the £ symbol is counted twice, this removes one count
        //there are probably others that fall into here but testing hasn't found any
        poundSignFound++;
      }
      specials++;
    }
    x++;
  }

  totals.push_back(alphanumeric);
  totals.push_back(numbers);
  totals.push_back(specials - poundSignFound);
  totals.push_back(password.length());

  return totals;
}

int checkPassword(std::vector<int> passwordTotals) {
  //declare these as it makes the below if statement slightly easier to understand.
  const int specialCharacters = 2;
  const int alphanumeric = 0;
  const int numbers = 1;
  const int maxPasswordLength = 3;

  //this is the logic to check the password and return the weakness (1) or strength (4). 0 is error
  if (((passwordTotals[specialCharacters] <= 0 || passwordTotals[specialCharacters] <=3) && (passwordTotals[alphanumeric] <=0 || passwordTotals[numbers] <=0)) || passwordTotals[maxPasswordLength] <4) {
    return 1;
  } else if (passwordTotals[maxPasswordLength] >= 8 && passwordTotals[alphanumeric] >= 4 && passwordTotals[numbers] >= 2 && passwordTotals[specialCharacters] >= 1) {
    return 4;
  } else if (passwordTotals[maxPasswordLength] >= 8 && passwordTotals[alphanumeric] >= 4 && passwordTotals[numbers] >= 2 && passwordTotals[specialCharacters] <= 0) {
    return 3;
  } else {
    return 2;
  } 
}

void passwordComplexityChecker(void) {
  std::string userInput;
  int passwordValue;
  std::vector<int> passwordComplexity;

	std::cout << "Please enter your password" << std::endl;
  std::getline(std::cin, userInput);

  //send password & receive a vector back showing numbers, letters etc.
  passwordComplexity = definePassword(userInput);
  //send password and receive it's strength
  passwordValue = checkPassword(passwordComplexity);

  std::string output = "Your password ";
  output += userInput;
  output += " is";

  switch (passwordValue) {
    case 1:
      output += " Weak";
      break;
    case 2:
      output += " Moderate";
      break;
    case 3:
      output += " Strong";
      break;
    case 4:
      output += " Very Strong";
      break;
    default:
      output = "There has been an error, please try again";
  }
  std::cout << output;
}

/*EMPLOYEE LIST REMOVAL*/
void displayEmployeeList(std::vector<std::string> employees) {
  //simple function to loop through the list of employees and display them
  std::cout << std::endl << "There are currently " << employees.size() << " employees:" << std::endl;
  for (int i=0; i<employees.size(); i++ ) {
    std::cout << employees[i] << std::endl;
  }
}

void employeeListRemoval(void) {
	std::vector<std::string> employees;
  std::string userInput = "";

  //initial set of employees
  employees.push_back("JOHN SMITH");
  employees.push_back("JAELYNN STUART");
  employees.push_back("KALEY BARAJAS");
  employees.push_back("WALTER COLLIER");
  employees.push_back("CALE MYERS");

  displayEmployeeList(employees);

  while (userInput != "0") { //check for quit key "0"
    std::cout << "Enter an employee name to remove or enter a new name to add (or 0 to exit):" << std::endl << std::endl;
    std::getline(std::cin, userInput); //get input
    std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper); //transform input to uppercase, makes searching easier

    //search for existing employee which uses an iterator to go over the characters of the string.
    std::vector<std::string>::iterator it = std::find(employees.begin(), employees.end(), userInput);
    
    if (userInput != "0") { //if 0 we should quit
      if (it == employees.end()) {
        //nothing found, adding someone new
        employees.push_back(userInput); //add to vector
        displayEmployeeList(employees); //display updated list
      } else {
        employees.erase(it); //found someone, remove them
        displayEmployeeList(employees); //display updated list
      }
    }
  }
}
