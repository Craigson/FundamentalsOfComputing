# Session 3

## Arrays
Array is something that you'll find in almost every programming language. It allows you to store x amount of same data type elements in a variable. However, you must declare at initialization how many elements can be stored in the array. You don't need to use all of the available places, but you can never change how many slots are in the array. So if you use all the available slots, you have to copy the array into a new, and larger, array.

Elements in an array are stored in consective memory addresses. You declare an array as `datatype varname[num]`. Here are some examples of that:

```
string names[4];	// this can store up to four string variables
int ages[10]; // this can store ten integers
```

The only time you don't have to declare a size is if you use an initializer list. Here is an example of that:

```
string seasons[] = {"Winter", "Spring", "Summer", "Fall"};
```

Note, we still use the square brackets which indicates to the program that `seasons` is an array. This also sets the size of the seasons array to 4.

Arrays are just pointers to where the data is stored. So when you pass an array as an argument it is automatically a call by reference (check the readme for Session 2 if you need a reminder what that is).

Also remember, to access an element in an array you *must* use an index value (ie seasons[1], names[3], ages[8]).

## Pointers
Every piece of data in a program can be found in memory via an address. A pointer is data type consisting of an address to a value in memory. Let's look at some code:

```
int katsAcct = 12345;
int* katsPtr = &katsAcct;
```
My first variable is an integer and my second value is a pointer that points to an integer. The * after the data type tells the computer it is a pointer and the & is what tells the computer to find the address of the variable.

So let's look at the following code:

```
cout << katsPtr << endl;
cout << *katsPtr << endl;
```
Our printout will be:

```
0x23a4f5
12345
```
The first line is a hexadecimal number (you can tell because it starts with 0x) which is the address to where my variable `katsAcct` is stored. The second line is the vairable value. By placing an * before the pointer name, we *dereferenced* the pointer so that it prints out its variable's value.
