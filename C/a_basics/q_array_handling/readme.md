#   array handling
-   arrays can store a fixed amount of elements for a certain data type
>   **NOTE:**   *An array looks similar to a pointer, however, an array is shall not be handled like a pointer.*

##  determine the elements of an array
-   to determine the elements of an array `sizeof` is in use, however...
    -   assuming: `int array[] = {1,2,3};`

| attempt | effect |
| - | - |
| `sizeof(array)` | doesn't return the correct size of elements; this returns the amount of bytes instead (12) |
| `sizeof(array) / sizeof(array[0])` | returns the correct size of elements for this array (3) |
| `sizeof(array) / sizeof(int)` | does the same, but make sure to use teh correct data type |

### passing an array into a function
-   this also leads to a nasty side effect

#### wrong way:
```
void f(int *array) {
    size_t nbr_elements = sizeof(array) / sizeof(array[0]);

    for(size_t i = 0; i < nbr_elements; i++) {
        printf("%d\n", array[i]);
    }
}
```

>   **NOTE:**   *This returns only 1 element, because the used array is still the pointer address, where this array has been stored. Furthermore with `sizeof` only the size of the pointer type (`int`) will be used, divided by the size itself and **1** always returns.* 

#### correct way:

```
void f(int *array, size_t nbr_elements) {
    for(size_t i = 0; i < nbr_elements; i++) {
        printf("%d\n", array[i]);
    }
}
```

>   **NOTE:**   *When an array shall be used for a function, then the amount of elements has to be determined before and must also be added to the function itself.*