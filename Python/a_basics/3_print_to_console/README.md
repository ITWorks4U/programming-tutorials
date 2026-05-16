#   Print to the console
-   "just" use `print()` function

####    What can be printed?
-   everything you want (and don't want to see, if you don't mind)

####    formatting output
-   there are different ways to do this:

-   **C-style**:
```
str_val: str = "This is a simple text."
print("%s" % str_val)
```

-   **Java/C#-style**:
```
str_val: str = "This is a simple text."
print("{}".format(str_val))
```

-   **Pythonic-style**:
```
str_val: str = "This is a simple text."
print(f"{str_val}")
```

######	attention
-   __EVERYTING__ will be "a word" when it's printed to the console or written into a file