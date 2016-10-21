# Fundamentals Of Computing

##What is a computer?
The very first electromechanical computers consisted of electric switches driving mechanical relays to perform calculations.

These days, anything that has at least one central processing unit (CPU) and some memory is considered to be a computer in the general sense.  

##Algorithms
An algorithm is a set of step-by-step instructions a computer program follows to do something

* Just like a recipe or a set of driving directions
* Most often, there are multiple ways to write a single algorithm
	* Usually there is no single 'best' option, best each algorithm will have pros and cons

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

##Arrays
An array is a large block of memory. If we have an array with 10 elements, it just means we have enough memory to store 10 elements.

If you have ten integers in your array and each integer is four bytes, your array is forty bytes of memory. The first four bytes represent array[0], the next four bytes represent array[1], etc.

There are two ways to declare an array:

1. int x[N];
  * This declares array x to be of size N
  * The memory for this array goes on the stack
  * automatically deallocated
  * not a variable (you cannot change the size of x), you can think of it as a constant
2. int *x = malloc(sizeof(int) * N);
  * This also declares array x to be of size N
  * The memory for this array goes onto the heap
  * Must explicity call free on this array or you will have a memory leak
  * Here x is a variable, and we have two separate blocks of memory. The variable x is stored in the stack and is just a pointer which stores the memory address to the large block of memory stored on the heap.


