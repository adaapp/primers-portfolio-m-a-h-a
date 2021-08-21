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
This primer was all around the concept of classes which brings with it things like abstraction, encapsulation and all those additional good things. This is an area of advanced programming we use a lot at work but one in which I am currently struggling the most to grasp. I understand the concepts and I can see their benefits (see below) but I struggle putting it into practice, particularly with C#.

### Reflection (as well as issues, challenges & resolutions)
It transpires that I wasn't a million miles away with my initial attempt at this, I'm not sure why it wasn't working exactly but I decided to move everything into the same class which caused different issues. Once I pulled everything out again it started to work.

Once I get my head around what a class is and why and when you would use them I seem to be ok, it's just that I'm not (yet) using them day-in-day-out and so I forget the structure and use of them and, in turn, get frustrated with myself. Perserverience got me through this and quite a bit of try and fail.

### Primer 10 - Area of
This primer tasked us with building three classes which would provide the area of three shapes based on given dimensions. Once the initial concept was provided it was a reasonably straight forward task as they were all pretty similar.

### Reflection (as well as issues, challenges & resolutions)

I could have enhanced these to accept inputs from the user for the dimensions and which shape they wanted an area for. I didn't owing to time and other things going on that are consuming brain power at the moment!

---
## Section 2 - Programming Paradigms
### Programming Paradigms
Simply put, a programming paradigm, for example, procedural, object-oriented, functional, structured, declarative, imperative and event driven can be described as a specific approach used when trying to solve a problem.  Although many programming languages can (and do) support multiple paradigms this discussion will focus more specifically on the possible benefits with examples of the potential differences and similarities of five from the above list.
* Procedural - Procedural Programming is seen by many as the 'first step' a developer will take on their learning path. In essence, the code is one that instructs, directly, the machine and informs it on how to tackle a task in logical steps. Procedural Programming uses a linear, 'top-down' approach in execution with code split out into procedures, aka functions or routines.
* Object-orientated - This paradigm can be thought of like Lego, in so much as each brick, or object (of code), will link to another, enabling programmers to create huge programs using tiny objects, small pieces of code, all working together. This has obvious advantages in terms of things like separation of concern and allowing objects to do one thing really well, enabling upgrading to be easier.
* Functional - This paradigm sees programmers make their programs by writing multiple functions, as opposed to objects and procedures. It takes its ideas from mathematics and, as such, does not allow for the changing of state or mutable data. The idea is to minimize 'moving parts' of your code which, in turn, should make it easier to comprehend.
* Structured - Sometimes known as modular programming, Structured encourages the programmer to re-use elements as much as possible, as well as using switch statements and while and for loops, whilst keeping the code readable. Elements should be able to be written in any programming language providing they use a common interface or API that, ideally, does not compromise security.
* Declarative - This method of programming involves a high level of abstraction between the machine and programmer. The programmer is more concerned with defining the outcome, the end goal, as opposed to detailing all the steps to get there. In other words, Declarative programming is concerned more with the 'what' needs to be done, than the 'how' it needs to be done, leaving the latter up to the machine to interpret.
* Imperative - This paradigm is what the vast majority of programmers use today. A program written imperatively is made-up of clearly defined sequences of instructions to a machine, commands if you will, that tell the machine what to do, when, to fulfil the desired outcomes. Code written Imperatively is, more often than not, compiled to make it readable by the machine.

As has already been stated, many programming languages use more than one paradigm, combining them out of necessity or in an attempt to make a programmers life easier.

It could be said that a programmer, in the process of designing a solution to a problem, would use most, if not all of the paradigms, prior to reaching the final solution.

They could Declaratively define the solution beforehand, from a high level approach, detailing what they wish to achieve. They may then move onto a combination of Procedural, Structural and Functional, planning the functions they will require and where they may go within a program and what can be re-used as much as possible. Finally, they would use a combination of Imperative and Object-orientated (in truth all of the above) to build the final solution in their chosen programming language.

In my opinion the correct paradigm should be chosen to deliver the best solution.


---
## Section 3 - Continued Professional Development
### Benefits of becoming a Polyglot Programmer
A Polyglot Programmer is defined as someone who can write code in multiple languages. Many programmers are polyglots whether they realise it or not, for example, in writing the frontend for a website a programmer will use multiple languages, HTML, CSS, JavaScript etc.

The benefits to being a Polyglot Programmer may seem obvious: surely if you can write in C#, Java, Go and/or more your employment options would be numerous? You wouldn’t have to spend time looking for a job with a specific program languages, you’d have a choice of many.

Sadly, this is not generally the case. Whilst some employers will recognise that you can write in multiple languages and see it as an advantage, many organisations still only use one, main, programming language and want you to be an expert in that language, rather than someone who knows many languages well.

Another benefit of being a Polyglot Programmer is it gives you a well rounded knowledge and, in some circumstances, an edge over someone who, although they may be an ‘expert’ in a particular language, doesn’t have the ability to see things from a different perspective. 

As an example, what if we said that C# programmers always took a particular approach to solution A. That is the way it is always done when using C#. But what if Java solves the same solution in a slightly different approach, an approach that is also possible in C#. And what if that approach turned out to be better, more efficient say, or easier to maintain. If you only knew C#, you would never know to try this other approach.

By constantly learning new languages you are also keeping yourself abreast of the latest developments in technology, which is no mean feat these days. Even if you tried a new language at home, just running something on your local machine, giving it a go, it opens your eyes to new things, new approaches, new possibilities.

Many people, particularly developers in my own experience, love using the ‘latest and greatest’ thing. The latest piece of kit, newest edition of software, BETA versions of languages. Being a Polyglot Programmer means you have the ability to try the latest languages, learn them, ‘have a play’. In this regard it can be said to be good for your mental health, even if sitting a computer day-in-day-out is perhaps not the best for your physical health.
