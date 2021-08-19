# Primer Portfolio

## Section 1 - Primer Challenges
### Primer 1 - Fahrenheit / Centigrade Conversion
This challenge requires us to allow a user to enter a value before selecting whether to convert it from Fahrenheit to Centigrade or Centigrade to Fahrenheit.  As part of the initial design the conversion algorithms were needed for both calculations. 

To help complete this challenge I needed to break the overall problem down into the following main tasks: 
* Get data from the user
* Verify the data is in a suitable format
* Create a method to convert F->C
* Create a method to convert C->F
 
### Reflection (as well as issues, challenges & resolutions)
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

### Primer 3 - Password Complexity Checker
This challenge required me to create a system that would inform a user on the complexity of the password they entered based on the oft recognised system of using over eight characters, a combination of letters and numbers with some special characters thrown into the mix.

I recognised that there would need to be a couple of functions:
* One to get the users password
* One to loop through and check the letters, numbers etc of the password
* Another to convert the numbers received from the above into an integer representing the oft used 'weak', 'strong' etc
* A final one to marry the integer representation into the actual word 'weak' etc and show that to the user.
### Reflection (as well as issues, challenges & resolutions)
The two biggest headaches on this were figuring out how to get C++ to detect alphanumeric characters, numbers and special characters from a string variable. In the end it turned out to be quite easy. Once I'd realised C++ treated strings as individual chars I could simply loop through the word, see if it was a letter or number and, if not, it must be a special character.

There was a further snag involving the "£" symbol which is not represented in ASCII and so takes up two bytes, rather than the usual one. I'm sure there maybe further symbols that do this too but I tried all of them on my keyboard and the "£" sign appeared the only one.

The second headache was working out the IF statement to determine if a password is weak, strong etc based on the supplied characteristics. I tackled this with an initial 'stab' at it, testing the supplied passwords till they all passed, and then inputting my own. This threw up some interesting issues, one of which being that a password full of special characters hadn't been catered for so I had to make a decision as to where they would fall.

### Primer 4 - Employee List Removal
This challenge required me to create a system that would present the user with a list of 'people' and ask them to enter a name to remove from the list. The now updated list would subsequently be presented.

I decide to enhance the system a little by allowing the user to not only remove a name by typing it in, but also, if they typed a name that was not on the list, this would be added to the list.

### Reflection (as well as issues, challenges & resolutions)
This was a relatively straight forward task as it was mainly calling on work we had done previously. The main snag was getting C++ to find items in a case insensitive manner. In the end I resorted to uppercasing everything which perhaps may not be ideal depending on the use of the system but works for this purpose.

### Primer 5 - Phone Directory
This was an app that would allow a user to search for a person/company on either their name or their phone number. Given the previous challenges there wasn't a lot to think about and I just dove in.

### Reflection (as well as issues, challenges & resolutions)
Pretty straight forward task without too many issues. The final solution works well, searching on partial items and bringing back multiple results accordingly. I think I separated things out well.

### Primer 6 - Data File Parser
The data file parser task was to read in a pre-defined set of data from an external file and then present that back to the user in a pre-defined formatted manner.

I tackled this task by:
* Ensuring I could read from the file
* Printing the contents of the file to the screen
* Working out how to just show the first letter of the forename
* Working out how to get the spacing to work as pre-defined

### Reflection (as well as issues, challenges & resolutions)
I hated this task with every ounce of my being. It was singularly the most frustrating thing I think I've ever created.

The final solution feels messy and a bit hacky. It works, but I've not doubt there's a cleaner way to achieve it.

I'm pleased with how I worked out the longest word, even if it did require some global variables.

The "splitByDelim" function is the one which infuriated me the most, and still does. I'm sure there's a better way to achieve what I've done without using 'flags', but I just can't think of it and nothing I tried gave me the same results.

### Primer 7 - Sleep Timer
The sleep timer is a simple, short program that pauses the thread for the number of seconds the user inputs.

### Reflection (as well as issues, challenges & resolutions)
As we'd pretty much been shown how to do this I decided to enhance it by making it into a timer. Technically, I'm not sure it's holding the thread for the whole time the program is running, I think it may be holding, releasing, holding etc, even if briefly, but it looks better.

### Primer 8 - Joining & Detaching Threads
Again, this was relatively straight forward as we had been shown how to do it. We use ASYNC and AWAIT (C#) in work a lot whilst waiting for payment provider results and things of that nature so I'm reasonably familiar with threading.

### Reflection (as well as issues, challenges & resolutions)
In this example, the main thread starts, followed by the next two threads, both separate from each other and the main thread, in the order in which they're called.

They await for the pre-defined time and then end one after another, followed by the main thread...once I'd remembered to sleep that too, otherwise it ends prior to the other threads and the screen is all over the place.

### Primer 9 - Car Class
### Reflection (as well as issues, challenges & resolutions)

### Primer 10 - Area of
### Reflection (as well as issues, challenges & resolutions)

---
## Section 2 - Programming Paradigms
### Programming Paradigms
Simply put, a programming paradigm, for example, procedural, object-oriented, functional, structured, declarative, imperative and event driven can be described as a specific approach used when trying to solve a problem.  Although many programming languages can (and do) support multiple paradigms this discussion will focus more specifically on the possible benefits with examples of the potential differences and similarities of five from the above list. These are ...

---
## Section 3 - Continued Professional Development
### Benefits of becoming a Polyglot Programmer
Vestibulum vitae semper sem. Duis leo leo, suscipit at felis non, pellentesque varius massa. Sed sit amet orci nibh. Morbi scelerisque faucibus elit, vitae mollis turpis finibus eget. In convallis euismod nunc non imperdiet. Duis ultricies pulvinar lorem, sed molestie nunc porta at. Aenean arcu ante, efficitur nec felis sed, feugiat iaculis turpis. Vestibulum eu elementum diam. Quisque nec tortor auctor, scelerisque ante vitae, fringilla tellus.

Quisque ligula lectus, efficitur quis malesuada sit amet, malesuada sed nibh. In lorem erat, elementum quis tempus nec, rhoncus ac ante. Mauris suscipit massa tempor, pulvinar neque vel, gravida nulla. Donec massa diam, molestie in diam nec, vulputate faucibus ligula. Aliquam erat volutpat. Aliquam sit amet dui ligula. Nullam euismod eros ultrices magna convallis lobortis. Proin convallis placerat tincidunt. Quisque interdum, nisi id egestas luctus, augue libero lacinia urna, sit amet tempus nisl sem nec quam. Vestibulum interdum urna mauris, vel dignissim nisi dignissim egestas. Donec volutpat dictum dui, at egestas sem tristique nec.
