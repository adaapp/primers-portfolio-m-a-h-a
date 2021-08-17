std::vector<int> definePassword(std::string password) {
  int alphanumeric, numbers, specials, x, poundSignFound;
  std::vector<int> totals;

  alphanumeric = numbers = specials = poundSignFound = x = 0;

  while (x <= (password.length()-1)) {
    if ((password[x] >= 'a' && password[x] <= 'z') || (password[x] >= 'A' && password[x] <= 'Z')) {
      alphanumeric++;
    } else if (password[x] >= '0' && password[x] <= '9') {
      numbers++;
    } else {
      if (password[x] == char(163)) {
        //because of ASCII and locals, the £ symbol is counted twice, this removes one
        poundSignFound++;
      }
      specials++;
    }
    x++;
  }

  totals.push_back(alphanumeric); //0
  totals.push_back(numbers); //1
  totals.push_back(specials - poundSignFound); //2
  totals.push_back(password.length()); //3

  return totals;
}

int chckPassword(std::vector<int> passwordTotals) {
  if ((passwordTotals[2] <= 0 || passwordTotals[2] <=3) && (passwordTotals[0] <=0 || passwordTotals[1] <=0)) {
    return 1;
  } else if ((passwordTotals[3] >= 4 && passwordTotals[3] <= 7) || ((passwordTotals[0] <=0 || passwordTotals[1] <=0) && passwordTotals[2] >= 4)) {
    return 2;
  } else if (passwordTotals[3] >= 8 && passwordTotals[0] >= 4 && passwordTotals[1] >= 2 && passwordTotals[2] >= 1) {
    return 4;
  } else if (passwordTotals[3] >= 8 && passwordTotals[0] >= 4 && passwordTotals[1] >= 2 && passwordTotals[2] <= 0) {
    return 3;
  } else {
    return 0;
  } 
}

void passwordComplexityChecker(void) {
  std::string userInput;
  int passwordValue;
  std::vector<int> passwordComplexity;

	std::cout << "Please enter your password" << std::endl;
  std::getline(std::cin, userInput);

  passwordComplexity = definePassword(userInput);
  passwordValue = chckPassword(passwordComplexity);

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


void employeeListRemoval(void) {
	std::cout << " - employeeListRemoval: not yet implemented\n\n";
}
