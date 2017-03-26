#Session 4

##Structured Data
In C++ you have access to something called *Abstract Data Types*, or ADT. ADT group together multiple primitive data types, and are created by the programmer. This may sound similar to a class, but they are different because ADT does not include any function definitions. 

A structured data type can contain other struct data types or arrays. To access the data properities of a struct data array you use dot notation. Also, you can initialize a structure when you create it.

**Clarification: ADT is the logical description of this concept and structured data type is the actual implemenation of it.

Let's look at an example:

```
struct Address { 
   char  city[30];
   char  state[3];
   int   zipcode;
};

struct DateOfBirth {
	int month;
	int date;
	int year;
}

struct Employee {
	char name[60];
	double hourlyWage;
	Address address;
	DateOfBirth dob;
}

int numEmployees;
cout<<"How many employees do you have?  \t";
cin>>numEmployees;
// create an array of type Employee
Employee employees[numEmployees];

for(int i=0; i<numEmployees; i++) {
	cout<<"Please enter their name  \t";
	cin>>employees[i].name;
	cout<<"Please enter their city  \t";
	cin>>employees[i].address.city;
	cout<<"Please enter their month of birth  \t";
	cin>>employees[i].dob.month;
}
```

##Vectors

A big downside to arrays is that they are a fixed size and once you initalize them, you can never change their size. So C++ offers the data type *vector*. It's similar to an array, but their size is dynamic, meaning we can change its size throughout the program. This is very similar to Java's ArrayList. But just like arrays, vector can only store data of the same data type.

Here are some ways you can declare a vector:

```
// initialized as an empty list of ints
vector<int> nums;

// nums2 contains 10 integer values
vector<int> nums2(10);

// prices contains 5 double values that are all set to 0.0
vector<double> prices(5, 0.0);
```

To add elements to a vector we use the function *push_back*

```
for(int i=0; i<10; i++){
	nums2.push_back(i);
}
```

Now nums is a vector containing 0,1,2,3,4,5,6,7,8,9.

If you already initialized a vector with a certain size (that can be changed later in the program) you can use [] to access certain indices.

```
for(int i=0; i<nums2.size(); i++){
	nums[i]=i;
}
```

Now nums2 also contains 0,1,2,3,4,5,6,7,8,9. There are also other vector functions we can use:

```
// at(idx) returns the element at index idx
int value = nums.at(2);		

// capacity() returns the max number of elements the vector can store before having to add additional 
// memeory. Vectors have a finite amount in memory, and if they need more memory they create a larger vector 
// and copy everything over from the original
int cap = nums.capacity();	

// removes the last element
nums.pop_back()

// clears the vector
nums.clear()
```


