class car {
  private:
    //some defaults in case nothing is set
    const std::string DEFAULT_COLOUR = "Red";
    const std::string DEFAULT_MAKE = "Honda";
    const bool DEFAULT_ENGINE = 0;
    const bool DEFAULT_LOCKED = 0;
    
    std::string car_colour;
    std::string car_make;
    bool engine_turned_on;
    bool car_locked;

    void initialise_car(std::string colour, std::string make, bool running, bool is_locked) {
      set_colour(colour);
      set_make(make);
      engine_turned_on = running;
      car_locked = is_locked;
    }

  public:
    car() {
      initialise_car(DEFAULT_COLOUR, DEFAULT_MAKE, DEFAULT_ENGINE, DEFAULT_LOCKED);
    }
    //below allows a user to make a car of their own make and colour
    car(std::string make, std::string colour) {
      set_colour(colour);
      set_make(make);
    }
    
    void set_colour(std::string colour) { car_colour = colour; };
    
    std::string get_colour(void) { return car_colour; };
    
    void set_make(std::string make_of_car) { car_make = make_of_car; };
    
    std::string get_make(void) { return car_make; };
    
    void engine_on(void) { 
      if (engine_turned_on) {
        std::cout << std::endl << "Sorry, the engine is already on" << std::endl;
      } else {
        engine_turned_on = true;
      }
    };
    
    void engine_off(void) {
      if (engine_turned_on) {
        engine_turned_on = false;
      } else {
        std::cout << std::endl << "Sorry, the engine is already off" << std::endl;
      }
    };
    
    void locked(bool is_locked) {
      if (is_locked && car_locked) {
        std::cout << std::endl << "Sorry, the car is already locked." << std::endl;
      } else if (is_locked && !car_locked) {
        car_locked = true;
      } else if (!is_locked && !car_locked) {
        std::cout << std::endl << "Sorry, the car is already unlocked." << std::endl;
      } else {
        car_locked = false;
      }
    };

    void status() {
      std::string engine_label, locked_label;
      
      engine_turned_on ? engine_label = "Running" : engine_label = "Off";
      car_locked ? locked_label = "Locked" : locked_label = "Unlocked";
      
      std::cout << std::endl << "Car Status: colour: " << car_colour << ", make: " << car_make << ", engine: " << engine_label << ", " << locked_label;
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

    //ensure we have an actual number
    try {
      intUserInput = stoi(userInput);
    } catch (std::exception e) {
      std::cout << "Sorry, please only select from the menu above." << std::endl;
    }

    //switch for the menu choices
    switch (intUserInput) {
      case 1:
        my_car.engine_on();
        break;
      case 2:
        my_car.engine_off();
        break;
      case 3:
        my_car.locked(true);
        break;
      case 4:
        my_car.locked(false);
        break;
      default:
       userInput = "0";
    }
  } while (userInput != "0"); //check for quit key "0"
}

void carClass(void) {
  car my_car("Toyota", "Blue");
  carMenu(my_car);
}

class circle {
  private:
    float PI = 3.14159;
    int x;

  public:
    circle() {}

    float area(float r) { return PI*(r*r); }
};

class square {
  private:
    int a;

  public:
    square() {}

    float area(float s) { return s*s; }
};

class rectangle {
  private:
    int l, w;

  public:
    rectangle() {}
    
    float area(float l, float w) { return l*w; }
};

void areaOf(void) {
		circle myCircle;
    std::cout << "Area of Circle where radius is 4.5 " << myCircle.area(4.5) << std::endl;

    square mySquare;
    std::cout << std::endl << "Area of Square where side is 6.1: " << mySquare.area(6.1) << std::endl;

    rectangle myRectangle;
    std::cout << std::endl << "Area of a Rectangle where the length is 5.9 and width is 4: " << myRectangle.area(5.9, 4) << std::endl;
}