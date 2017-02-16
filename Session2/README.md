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




