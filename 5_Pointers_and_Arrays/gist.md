# Pointers and Arrays

![image](https://www.geeksforgeeks.org/wp-content/uploads/Double-Pointer-in-C.png)
## 5.1 Creation of pointers

* The code `ptr = &c` assigns the address of `c` to `ptr` (`&` is called the "address of" operator).
* `*ptr` gives the value stored in  `c` (`*` is called the dereferencing/indirection operator).
* Hence, `&c` is a pointer to `c` and `*ptr` is the value to which `ptr` points at.
* `int *ptr` should be read as : The expression `*ptr` is an `int`.
* A pointer is constrained to point to a particular type of object (except of `void*` which can point to any kind but cannot be derefenced).
* Unary operators `*` and `&` have higher precedence than mathematical operators. So, an expression like `*ptr = *ptr+5` increments the value of `c` by `5`.
* `++*ptr` and `(*ip)++` also increment the value of `c` by `1`. Parantheses are necessary in the 2nd case otherwise the value of ip would be increased by 1 (?? check)

## 5.2 Pointers and Function Arguments

* C passes all the function arguments by value. To pass by reference do something like below:
  ```C
  void swap( int *px, int *py){
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
  }
  swap (&a,&b);// This will swap the values of a and b.
  ```
## 5.3 Pointers and Arrays


* Arrays and Pointers are partners-in-crime. They can be used interchangably. The pointer version is __generally faster__.
* Let us consider the code fragment:
  ```C
  int a[10], *ptr;
  ptr = &a[0];
  ```
  * The above code fragment creates an `int` array of 10 elements and passes the address of the 1st element to `ptr`.
  * `ptr` and `a` _(name of the array)_ can be used as pointers to the 1st element. Hence, `ptr+i`,`ptr+i` and `&a[i]` point the the `ith` element i.e.`a[i]`.
  * `*ptr` and `*a` would give the value of `a[0]`. Similarly `*(ptr+i)`,`*(a+i)` and `ptr[i]`would give the values of the `ith` element i.e. `a[i]`.
  * Refer to this [image](http://codingfox.com/wp-content/uploads/2014/01/clip_image0032.gif) for more clarity.
  
* However, there are some differences. `ptr=a` and `ptr++` are legal. But, `a=ptr` and `a++` are illegal since array name `a` is not a variable.
* If you pass an array to a function, actually __address of the 1st element__ is passed in C. In fact, a __local copy__ of a variable pointing to the 1st element 
  is created by the function.
* It is possible to pass a subarray to a function as : `func(&a[2])` or `func(a+2)`. Such a function can be declared as `func(int arr[])` or `func(int *arr)`.
  It is of no consequence that the passed parameter refers to a larger array. The latter declaration is preferred because it is faster.

## 5.4 Address Arithmetic

* If `ptr` is a pointer to some element in an array, `ptr+i` points to the `ith` element after that element. This is consistent no matter the type of the array (`int`, `float` etc.)
* If `p` and `q` point to the members of the same array, then relations like `==,!=,<,>=` etc. work fine. `p<q` is true if `p` points to an element before that pointed by `q`. But there is undefined behavior for comparison/arithmetic for pointers pointing to separate arrays.
* If `p<q` and both `p` and `q` point to the same array, the expresssion `q-p+1` will return the length of the array.
* In a nutshell, the valid pointer arithmetic are:
  * assignment of pointers of the same type (`p=q`)
  * adding or subtracting a pointer and an integer
  * subtracting or comparing two pointers (of the same array)
  * assigning or comparing to `0`
* Some illegal pointer arithmetic are as follows:
  * Addition, multiplication or division of pointers
  * Shifting or masking of pointers
  * Addition `float` or `int` to pointers
  * Assigning a pointer of one type to another type without casting (except void*).  


## Important points

* A pointer to an int points only to the 1st byte.
* If you do `++` to an `int*`, it will increase its value by `sizeof(int)`. Similary for other datatypes.
* Memory addresses are referenced at the granularity of single __bytes__.
