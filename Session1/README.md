#Resources
[Hardvard's CS50 course (best intro to CS course I've seen)](https://cs50.harvard.edu/)
[Lynda.com's essential c++](https://www.lynda.com/C-tutorials/C-Essential-Training/182674-2.html)

#Session 1

C++ is one of the most popular programming languages out there, particulary because of its efficient performance driven design. It is a C based language and has inherited much of the same syntax as the C programming language. A big difference between C++ and other languages such as Java, Ruby, or PHP is the control it provides over memory mangement. Most languages take care of this under the hood for you, but by being able to control how memory is allocated is one of the reasons C++ is so powerful. We'll go over just how memory is allocated in later sessions.

C++ also provides a more powerful option for creative coding, espically when used with frameworks like Cinder or OpenFrameworks.

##How do you code C++
As you may have guessed, the p5.js editor won't work for C++. There are many options for which IDE, or integrated development environment you use to develop C++, but Craig and I will be deomstrating with XCode.

##Return Types
We talked about static typing and dynamic typing last session and you can find our notes on that *here*[insert link]. As a reminder, C++ is a statically typed language where a type is bound to a variable, so instead of 

`var x = 5;`

like we see in Javascript, we have

`int x = 5;`

This also applies to our functions. Another major difference between C++ and Javascript is that functions have **return types**. What does this mean? Let's take a look at a basic Javascript function:

```
function addTwo(num) {
	return num + 2;
}
```

Let's say I change the function to cast the return value as a string:

```
function addTwo(num) {
	return str(num + 2);
}
```

Javascript doesn't care that you are now returning a string instead of a number, however C++ really cares. Everytime you write a function in C++ you **must** specify what kind of data type you are returning. So our function returning an integer would look like:

```
integer addTwo(integer num) {
	return num + 2;
}
```

And the function returning a string would look like:

```
string addTwo(integer num) {
	return std::to_string(num + 2);
}
```

Notice I also wrote the datatype *int* before our parameter *num*. That's because in addition to saying what datatype your function is returning you must also declare what datatype your paramters are. If your function doesn't return anything you use the datatype void.

## Writing to the Console
One of the best ways to debug your code is to print something to the console. However, println() is not a valid function is C++, to print to the console we use:

```
cout<<"I'm printing something"<<endl;
```

*cout* means output to the console and *endl* means end of line.

## Data Types
integer, short, and long are examples of primitive data types (as opposed to structured data). One difference between primitive and structured data is that primitives are stored by value not by reference. So if you have a variable of data integer and a value of 5, 5 will be stored to memory. We go over more data types and how much memory each take up in our previous lesson which can be found here[insert link]

When choosing what data type to use, always choose the one that requires the smallest amount of memory, that will increase the processing speed of your program.

## Implicit and Explicit Conversion
Even though you have to declare a data type for every new variable, you can temporary or permantely change a variable data type using implicit or explicit conversion.