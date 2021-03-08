# Linked List
* They do not allow random access of data, which must be accessed sequentially
* `NULL` pointer denotes the end of a linked list. `START` points to the beginning of the linked list. If `START == NULL`, then the linked list is empty.
* The following code is used to create a linked list structure.
   ```
    struct node{
    int data; // This could be of any data type, array or structure 
    struct node *next;
    ```
 * Linked List         | Arrays
   --------------------| -------
   Non-contiguous storage| Consecutive Storage
   Variable size | Fixed Size
   O(n) access | O(1) access
   
   
