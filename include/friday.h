class car {
  private:
    const std::string DEFAULT_COLOUR = "Red";
    const std::string DEFAULT_MAKE = "Honda";
    const bool DEFAULT_ENGINE = 0;
    const bool DEFAULT_LOCKED = 0;
    
    std::string car_colour;
    std::string car_make;
    bool engine_turned_on;
    bool car_locked;

    //if no params are passed, use these defaults
    void initialise_car(std::string colour, std::string make, bool running, bool is_locked) {
      set_colour(colour);
      set_make(make);
      engine_turned_on = running;
      car_locked = is_locked;
    }

  public:
    car() {
      //std::cout << std::endl << "instantiated" << std::endl;
      initialise_car(DEFAULT_COLOUR, DEFAULT_MAKE, DEFAULT_ENGINE, DEFAULT_LOCKED);
    }
    car(std::string make, std::string colour) {
     // std::cout << std::endl << "instantiated with params." << std::endl;
      set_colour(colour);
      set_make(make);
      engine_off();
      locked(false);
    }
    
    void set_colour(std::string colour) { car_colour = colour; };
    
    std::string get_colour(void) { return car_colour; };
    
    void set_make(std::string make_of_car) { car_make = make_of_car; };
    
    std::string get_make(void) { return car_make; };
    
    void engine_on(void) { 
      if (engine_turned_on) {
        std::cout << "sorry";
      } else {
        engine_turned_on = true;
        std::cout << "wang dang doodle";
      }
    };
    
    void engine_off(void) { engine_turned_on = false; };
    
    void locked(bool is_locked) {
      if (is_locked) {
        car_locked = true;
      } else {
        car_locked = false;
      }
    }

    void status() {
      std::string engine_label, locked_label;
      
      engine_turned_on ? engine_label = "Running" : engine_label = "Off";
      car_locked ? locked_label = "Locked" : locked_label = "Unlocked";
      
      std::cout << "Car Status: colour: " << car_colour << ", make: " << car_make << ", engine: " << engine_label << ", " << locked_label;
    }      

    ~car() {
      //std::cout << std::endl << "destroyed" << std::endl;
    }
};

void carMenu(car my_car) {
  std::string userInput;
  bool userInputOk = false;
  int intUserInput;

  do {
    my_car.status();
    std::cout << std::endl << "1. Turn Engine On" << std::endl
            << "2. Turn Engine Off" << std::endl
            << "3. Lock The Car" << std::endl
            << "4. Unlock The Car" << std::endl
            << "Please select an option, or 0 to finish: " << std::endl;
    std::getline(std::cin, userInput);

    try {
      intUserInput = stoi(userInput);
      std::cout << "int ui " << intUserInput << std::endl;
    } catch (std::exception e) {
      std::cout << "try catch error" << std::endl;
    }

    switch (intUserInput) {
      case 1:
        my_car.engine_on();
    //    engine_on();
        break;
      case 2:
        my_car.engine_off();
        break;
      case 3:
        my_car.locked(true);
        break;
      default:
        std::cout << "switch default" << std::endl;
    }
  } while (userInput != "0"); //check for quit key "0"
}

void carClass(void) {
  car my_car;
  carMenu(my_car);
}

void areaOf(void) {
		std::cout << " - areaOf: not yet implemented\n\n";
}