//global variables for threads
const int FREDTIMER1DURATION = 5;
const int FREDTIMER2DURATION = 10;

void sleepTimer(void) {
  std::string userInput;
  int userTime = 0;

  std::cout << std::endl << "Please enter the pause time in seconds: " << std::endl;
  std::getline(std::cin, userInput);
  std::cout << std:: endl;
  
  checkForInt(userInput, 0); //check we have a postive number
  userTime = stoi(userInput); //convert input to integer

  int milliseconds = userTime * 1000; //calculate the number of milliseconds from the seconds provided
	
  //not sure the below is strictly pausing everything for the seconds entered,
  //probably more pausing, releasing briefly, pausing and so on. Looks better though
  while (userTime >= 1)
  {
      std::cout << "\rTime remaining: " << userTime << std::flush << " ";
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      userTime--;
  }
  std::cout << std::endl << "Timer over" << std::endl;
}

void sleep(int seconds = 10) { //sleep for 10 seconds by default
  int milliseconds = seconds * 1000; //calculate the number of milliseconds from the seconds provided
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds)); //sleep for the milliseconds specified
}

void FredTheThreadTimer01() {
  std::cout << "Fred The Thread Timer 01 Thread ID: " << std::this_thread::get_id() << " started" << std::endl;
  sleep(FREDTIMER1DURATION); //sleep for the duration from the constant
  std::cout << "Fred The Thread Timer 01 Thread ID: " << std::this_thread::get_id() << " ended" << std::endl;
}

void FredTheThreadTimer02() {
  std::cout << "Fred The Thread Timer 02 Thread ID: " << std::this_thread::get_id() << " started" << std::endl;
  sleep(FREDTIMER2DURATION); //sleep for the duration from the constant
  std::cout << "Fred The Thread Timer 02 Thread ID: " << std::this_thread::get_id() << " ended" << std::endl;
}

void joinDetachThreads(void) {
	//start main thread
  std::cout << "Main thread: " << std::this_thread::get_id() << " started" << std::endl;

  //create two threads and start them
  std::thread FredTheThread01(FredTheThreadTimer01); //create a new thread FredTheThread01 and run timer1 without blocking execution
  FredTheThread01.detach(); // separate the thread allowing it to execute independently

  std::thread FredTheThread02(FredTheThreadTimer02); //create a new thread FredTheThread02 and run timer2 without blocking execution
  FredTheThread02.detach(); // separate the thread allowing it to execute independently

  sleep(15);

  std::cout << "Main thread: " << std::this_thread::get_id() << " ended" << std::endl;
}