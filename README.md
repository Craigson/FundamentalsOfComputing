# Fundamentals Of Computing

##A short history of computing
The very first electromechanical computers comprised electric switches driving mechanical relays.  Later, around the 1930s, mechanical relays were replaced by vacuum tubes.  This greatly increased the capabilities and operating speed of these early machines.

Perhaps the single greatest invention in the history of computing was that of the bipolar transistor.  Why? They're smaller, require less power, generate less heat, and are more reliable.

The next great advance came in the form of the integrated circuit (IC), also referred to as a microchip.  An IC is a set of electronic circuits on a single plate of semiconductor material ( usually silicon ).  Several billion transistors (and other components) can fit onto a chip the size of a human fingernail.  This, in turn, led to the invention of the microprocessor. A microprocessor takes input, performs some sort of operation ( processing ), and produces an output.

At this point, you've probably heard the term 'bit' before ('bit' stands for 'binary digit' ).  Why is this relevant? Remember we were talking about the invention of the transistor - well, a transistor is essentially a small electronic switch.  It has two states: high-low / on-off / 1-0.

##Binary
You are use to the decimal (decem is latin for ten) notation, which uses ten numbers 0-9. If you need to represent a number larger than nine, you use a combination of these numbers. 

Let's look at the number **437**

We can write this several ways: </br>
400 + 30 + 7 </br>
4 * 100 + 3 * 10 + 7 *1</br>
4 * **10**<sup>2</sup> + 3 * **10**<sup>1</sup> + 7 * **10**<sup>0</sup>

so

| 4   | 3  | 7    |
| --- |--- | -----|
| 4*10<sup>2</sup>| 3*10<sup>1</sup> | 7*10<sup>0</sup>|

Note that just like we have **10** possible numbers in decimal notation, this is also a base **10** system. 437 has a hundreds place, a tens place, and a one place, which are all base **10**.

*Binary* is similar to decimal notation but instead of 10 numbers (0-9) and base 10, we have 2 (0 & 1) numbers and it is base 2. 

Let's look at the numbers zero through eight, in binary and decimal.

| Binary  | Decimal|       
| ------- |:-------|
| 0       | 0      |
| 1       | 1      |
| 10      | 2      |
| 11      | 3      |
| 100     | 4      |
| 101     | 5      |
| 110     | 6      |
| 111     | 7      |
| 1000    | 8      |

Let's break this down a bit with the binary number **101110011** 


| 1   | 0  | 1    | 1   |1    | 0     | 0     | 1 | 1 |
| --- |--- | -----|---  |---- |-----  | ----- |---| ---|
| 1*2<sup>8</sup>| 0*2<sup>7</sup> | 0*2<sup>6</sup>|0*2<sup>5</sup>|1*2<sup>4</sup>| 0*2<sup>3</sup> | 0*2<sup>2</sup>|0*2<sup>1</sup>|0*2<sup>0</sup>

add this all together and you get **371**

##Bits and Bytes

As we mentioned, a 'bit' is a 'binary digit'.  Now that we understand a little more about binary, it's time to introduce the concept of a 'byte'.  A byte is a collection of 8 bits.  In other words



##Variables
A variable represents a value. To use a variable there are two steps:

1. Declare - here you declare to the compiler that you are going to use the variable you have declared. A declaration contains 2 parts, a data type and a name.
  * Example: `int x;`
2. Assignment - here you give your variable a value using the equal sign. *You must declare a variable before you can assign it a value.*
  * Example: `x=42;`

You can also declare and assign variables in one line: `int x = 42;`

It is good practice to have descriptive variable names like length_square or number_coins. For C languages, like C++, it is convention to have all variable names all lowercased with underscores between words.

Let's look at the following code

~~~~~
int x = 42;
int y = x + 1;
x = 5;
~~~~~

What is y now equal to? If you said 43, you're correct. Even though x now equals 5, when y was assigned, x equaled 42, so y will stay at 43, regardless of what x is assigned to afterwards.

Let's look at another block of code

~~~~
int x;
x = x + 1;
~~~~

See the problem? We assign x after we declare it, but x has no value, or is null, and something plus nothing, is not only nothing, it's an error.

##Algorithms
An algorithm is a set of step-by-step instructions a computer program follows to do something

* Just like a recipe or a set of driving directions
* Most often, there are multiple ways to write a single algorithm
	* Usually there is no single 'best' option, best each algorithm will have pros and cons


##Arrays
An array is a large block of memory. If we have an array with 10 elements, it just means we have enough memory to store 10 elements.

If you have ten integers in your array and each integer is four bytes, your array is forty bytes of memory. The first four bytes represent array[0], the next four bytes represent array[1], etc.

There are two ways to declare an array:

1. `int x[N];`
  * This declares array x to be of size N
  * The memory for this array goes on the stack
  * automatically deallocated
  * not a variable (you cannot change the size of x), you can think of it as a constant
2. `int *x = malloc(sizeof(int) * N);`
  * This also declares array x to be of size N
  * The memory for this array goes onto the heap
  * Must explicity call free on this array or you will have a memory leak
  * Here x is a variable, and we have two separate blocks of memory. The variable x is stored in the stack and is just a pointer which stores the memory address to the large block of memory stored on the heap.


