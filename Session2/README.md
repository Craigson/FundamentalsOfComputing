#Session 2

##Expressions
Most of C++'s operators are either straightforward or something you have already encountered in p5. However the << and >> symbols aren't quite as obvious. Let's look a code snippet.

```
string name;
string age;
cout<<"Enter your name and age:";
cin>>name;
cin>>age;
```

First I declare the name and age variable along with their datatypes, then I'm sending the string, "Enter your name and age:" to the console. A user can input their name and age (separated by a newline) and the two inputs are assigned to name and age.

##Loops
C++ has three types of loops

1. Do...while loop - always executes at least once
2. while loop - repeats while the conditional statement is true
3. for loop - repeats a predetermined number of times

while loops and for loops should be familiar to you, so let's talk about do while loops.

```
// Local variable declaration:
   int a = 10;

   // do loop execution
   do {
      cout << "value of a: " << a << endl;
      a = a + 1;
   }while( a < 20 );
```

The block of code will keep executing as long as the conditional statment (a < 20) is true. Unlike a traditional while loop the block of code is guaranteed to run at least once, regardless of whether the conditional statement is true or false. 

##Using Predefined Functions
Just like with p5, C++ has several built in libraries, and if you're writing in C++, you have access to these functions. For example, the <cstdlib> library has the rand() function, which allows us to generate a random number. However, it is important to note that C++ uses a psudeorandom number generator, and that eventually, the series of numbers it outputs will repeat itself. To create a create a true random number we need a seed value and the srand(int num) function, which has the program generate a new sequence of numbers everytime you run the program.

To use any of these predefined functions, you have to include the library the function belongs to, just like with p5.

```
#include <cstdlib>
v1 = rand() % 100;         // v1 in the range 0 to 99
v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014
```

##Creating User-Defined Functions
This is almost exactly the same as creating a function in p5. A function is a group of statements that tells a computer how to execute a task. A C++ function has four parts:

1. Return type
2. Function name
3. Parameter list
4. Body of the function (the code)

Let's look at an user-defined function

```
double getDistance(int x1, int y1, int x2, int y2) {
	double distance;
	distance = sqrt((pow(x1-x2),2) + pow((y1-y2),2));
	return distance;
}
```

`double` is our return type, `getDistance` is our function name, `int x1, int y1, int x2, int y2` are our parameter list, and the three lines in the middle are the code.

It's also good to note that C++ functions must be defined in the code *before* you can call them. So this works:

```
double getDistance(int x1, int y1, int x2, int y2) {
	double distance;
	distance = sqrt((pow(x1-x2),2) + pow((y1-y2),2));
	return distance;
}

getDistance(3,4,5,6);
```

And this does not:

```
getDistance(3,4,5,6);

double getDistance(int x1, int y1, int x2, int y2) {
	double distance;
	distance = sqrt((pow(x1-x2),2) + pow((y1-y2),2));
	return distance;
}
```

If you really want to define your functions later in the program, you can write the function's signature at the top of the program. This would look like so:

```
double getDistance(int x1, int y1, int x2, int y2);

getDistance(3,4,5,6);

double getDistance(int x1, int y1, int x2, int y2) {
	double distance;
	distance = sqrt((pow(x1-x2),2) + pow((y1-y2),2));
	return distance;
}
```

##Call by Value vs Call by Reference
There are two types of parameters that can be used in functions

1. Call by Value
2. Call by Reference

What's the difference? As we mentioned in Session 1, a call by reference means the function is given the memory address that points to the value of the variable. So a call by reference changes the value of the variable in memory. When you call by value, a *copy* of the value of the variable is passed to the function, so the function does not affect the original value. 

Let's look at an example of call by value.

```
int num1 = 1;
int num2 = 2;
void addFive(int a, int b) {
	a += 5;
	b += 5;
	return a + b;
}

cout << addFive(num1, num2) << endl;
cout << num1 << endl;
cout << num2 << endl;
```
The three numbers printed to the console are 13, 1, and 2. Because *copies* of num1 and num2 were manipulated to return 13, but the original values of num1 and num2 remain untouched. This is how functions work in p5.

Let's look at an example of call by reference, it will look exactly the same except for a & symbol for the data type for each parameter.

```
int num1 = 1;
int num2 = 2;
void addFive(int& a, int b&) {
	a += 5;
	b += 5;
	return a + b;
}

cout << addFive(num1, num2) << endl;
cout << num1 << endl;
cout << num2 << endl;
```
In this case, the three numbers printed to the console are 13, 6, and 7.

##Default arguments
Just like with p5, we can use default arguments for our functions. Normally, parameters are undefined when we define a function, and when we call that function and pass in numbers or strings or objects or whatever the function requires, we give the parameters value. However, sometimes it's a good idea to have a parameter default to a certain value, which also makes passing in a value for that parameter optional.

Let's look at a function to find the total sales cost:

```
double getTotalCost(int value, int taxPercent=15) {
	double cost = value + (value * (taxPercent/100));
	return cost;
}

double costA = getTotalCost(100,20);
double costB = getTotalCost(100);
```

The first call to our function sets the tax to 20%, the second call does not provide a specific tax value, so the function uses the default value of 15%.

##Overloading Functions
Two or more functions may have the same name, as long as the list of parameters is different. This is called *overloading functions*. Let's say you want to create a print method that can print integers or doubles, you could simply overload your user-defined print function.

```
void printNum(int i) {
	cout << i << endl;
}

void printNum(double d) {
	cout << d << endl;
}

print(5);
print(5.5);
```

##Creating Classes
Last session, we went over Object Oriented Programming. Creating classes is an essetential part of OOP. It allows use to encapsulate our code, and creates more easily to read code. This is similar to when you created objects in p5. When we create classes in C++ we need two files:

1. Header file (.h extension)
2. C++ fill (.cpp extension)

Here is an example of a header file for a class called Puppy

```
class Puppy
{
     private :
          int numOfSpots;
          int age;
          string breed;
     public :
          //with default value
          Puppy(int s = 0, int a  = 0, string b = "mixed");
          // destructor
          ~Puppy();
          //	setter function
          void setBreed(string s);
          // Print a description of the puppy
          void print() const;
          //compare two puppy objects
          bool equals(Puppy&);
};
```

And here is the corresponding C++ file:

```
#include "Puppy.h"

// constructor
Puppy::Puppy(int s=0, int a=0, string b="mixed") {
	numOfSpots = s;
	age = a;
	breed = b;
}

// destructor
Puppy::~ Puppy() {
	// destructor code
}

void Puppy::setBreed(string s) {
	breed = s;
}

void Puppy::print() {
	cout << "This puppy has " << numOfSpots << " spots" << endl;
	cout << "They are " << age << endl;
	cout << "They are a " << breed << endl;
}

bool equals(Puppy& otherPuppy) {
	if(numOfSpots == otherPuppy.numOfSpots 
          && age == otherPuppy.age
          && breed == otherPuppy.breed)
          return true;
     else
          return false;
}

```
The :: is called a scope resolution operator. It tells the program what class the function belongs to. Destructor methods are the opposite of constructors. They are called when objects are destroyed (allocated). They are preceeded by a ~. You can think of it as a clean-up function, when we no longer are using an instance of a class, we want to free up space in memory and the destructor function allows us to do that. We have a seperate function to set the breed variable, because breed is a private property. This means if you call puppy.breed outside of the Puppy class this will not work. In the equal method, we can pass in a different Puppy instance and compare the two objects.

##Instantiating Classes
Here is an example of our main class which includes our newly defined Puppy class:

```
#include "Puppy.h"

Puppy puppy1;
Puppy puppy2(10,2,"basset hound");

puppy1.print();
puppy2.print();
```

We have created two puppies, one with the default arguments and one where we passed in our own parameters. We can now uses these objects to call the functions in our Puppy class.

##Encapsulation
Encapsulation is a key part of Object Oriented Programming. It allows the programmer to hide variables and the code for functions from the user. This might not seem useful now, but if you ever opensource your code it would be really annoying if people started breaking your algorithms!

##Inheirtance
Inheirtance is when one class *inheirts* all the instance data and functions from a different class. For example, our puppy class may inheirt from an Animal class that may have properties such as species, numOfLegs, lifeSpan, etc. And the Puppy class would have access to all of those properties. When you can think of Inheirtance, you can think of an is-a relationship. For example, a Puppy *is-a* Animal. A puppy has all the properties of a general animal, but is a more specific version. You still have to explicity say the Puppy Class inheirts from the Animal class, but the is-a test ensures that our logic is sound. For example, it would not make sense to have a Particle class inherit from an Animal class because a Particle is not an Animal.

##Polymorphism





