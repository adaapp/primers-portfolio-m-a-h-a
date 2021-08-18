# Primer Portfolio

## Section 1 - Primer Challenges
### Primer 1 - Fahrenheit / Centigrade Conversion
This challenge requires us to allow a user to enter a value before selecting whether to convert it from Fahrenheit to Centigrade or Centigrade to Fahrenheit.  As part of the initial design the conversion algorithms were needed for both calculations. 

To help complete this challenge I needed to break the overall problem down into the following main tasks: 
* Get data from the user
* Verify the data is in a suitable format
* Create a method to convert F->C
* Create a method to convert C->F
 
#### Reflection (as well as issues, challenges & resolutions)
We have been doing quite a lot of SOLID principle work recently at work and so this was timely. Ideally, I would have liked to have renamed the main function, currently "fahrenheitCentigradeConversion", as this is not actually doing the conversion anymore, however this would break the calls in main.cpp and I thought best not to.

Didn't really have any issues to speak of, other than getting the output function to return a string rather than output it to screen. It seems there isn't an easy way to convert floats to strings in C++ so left if as a void function.

### Primer 2 - Self-service Checkout
This challenge requires us to allow the user to enter a number of characteristics of items that they are purchasing. As a minimum the user should be able to enter the number of items they are purchasing and the cost per item.

The breakdown of work was similar to Primer 1:
* Get relevant data from the user
* Verify the data is in a useable format
* Create a method to sum the total cost
* Create a method to work out the Shopping Tax, fixed at 5.5%
* Work out the total cost.

### Reflection (as well as issues, challenges & resolutions)
I decided to allow the user to enter the name of the items they were purchasing, followed by the amount and cost per item. The user can then decide if they have added all the items or if they want to add more.

It was a relatively straight forward task. The main challenge was to discover how arrays work in C++ which led me to find out about Vectors. The next challenge was to ensure that, regardless of what the user entered for a monetary value, it always showed with two decimal places, so if a user entered "2", it should show "2.00".

..  
..  

---
## Section 2 - Programming Paradigms
### Programming Paradigms
Simply put, a programming paradigm, for example, procedural, object-oriented, functional, structured, declarative, imperative and event driven can be described as a specific approach used when trying to solve a problem.  Although many programming languages can (and do) support multiple paradigms this discussion will focus more specifically on the possible benefits with examples of the potential differences and similarities of five from the above list. These are ...

---
## Section 3 - Continued Professional Development
### Benefits of becoming a Polyglot Programmer
Vestibulum vitae semper sem. Duis leo leo, suscipit at felis non, pellentesque varius massa. Sed sit amet orci nibh. Morbi scelerisque faucibus elit, vitae mollis turpis finibus eget. In convallis euismod nunc non imperdiet. Duis ultricies pulvinar lorem, sed molestie nunc porta at. Aenean arcu ante, efficitur nec felis sed, feugiat iaculis turpis. Vestibulum eu elementum diam. Quisque nec tortor auctor, scelerisque ante vitae, fringilla tellus.

Quisque ligula lectus, efficitur quis malesuada sit amet, malesuada sed nibh. In lorem erat, elementum quis tempus nec, rhoncus ac ante. Mauris suscipit massa tempor, pulvinar neque vel, gravida nulla. Donec massa diam, molestie in diam nec, vulputate faucibus ligula. Aliquam erat volutpat. Aliquam sit amet dui ligula. Nullam euismod eros ultrices magna convallis lobortis. Proin convallis placerat tincidunt. Quisque interdum, nisi id egestas luctus, augue libero lacinia urna, sit amet tempus nisl sem nec quam. Vestibulum interdum urna mauris, vel dignissim nisi dignissim egestas. Donec volutpat dictum dui, at egestas sem tristique nec.
