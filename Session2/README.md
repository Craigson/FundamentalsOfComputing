#Session 2

##Expressions
Most of C++'s operators are either straightforward or something you have already encountered in p5. However the << and >> symbols aren't quite as obvious. Let's look a code snippet.

````
string name;
string age;
cout<<"Enter your name and age:";
cin>>name;
cin>>age;
````

First I declare the name and age variable along with their datatypes, then I'm sending the string, "Enter your name and age:" to the console. A user can input their name and age (separated by a newline) and the two inputs are assigned to name and age.

##Loops
C++ has three types of loops

1. Do...while loop - always executes at least once
2. while loop - repeats while the conditional statement is true
3. for loop - repeats a predetermined number of times

while loops and for loops should be familiar to you, so let's talk about do while loops.

````
// Local variable declaration:
   int a = 10;

   // do loop execution
   do {
      cout << "value of a: " << a << endl;
      a = a + 1;
   }while( a < 20 );
````

The block of code will keep executing as long as the conditional statment (a < 20) is true. Unlike a traditional while loop the block of code is guaranteed to run at least once, regardless of whether the conditional statement is true or false. 
