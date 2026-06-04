#   The first steps with Python

-   Python 3 is really easy to learn.
-   It allows you to start to programm without any deep knowledge.
-   In the beginning you hardly need a bunch of instructions.

### How to run the python script

-   Usually, you run your python script by using the python interpreter, like: `python[3.|exe] <your_python_file.py>`
-   Sometimes it may be important to run your script as a standalone "application".
    -   In that case the shebang command (first line only) is required: `#!/usr/bin/python3`
    -   Usually, you don't need that command and this will be in this file only.

>   **NOTE**:   On a Windows system you don't need a shebang command, because this won't have an effect. This is more in use on UNIX systems, like Linux, macOS, ...

### some philosophy
-   Python is an interpreter language, which means, you don't have to do any datatype definitions.
-   Every variable, here an object, can easy be defined and also reinterpreted by any other value.
-   However, there are >some< points to know:
    -   by using blocks, like conditions, loops, functions, ... it's required to know, which command/s is/are part of the block
        -   take a look into the certain section folders, like [decision making](../2_decision_making/README.md) [loops](../5_loops/README.md), [functions](../8_functions_in_python/README.md)
-   in contrast to any other language, it's neccessary to know what kind of indention you're using; there're two of them:
    -   space bar(s)
    -   tab(s)

-   Because Python won't agree a mix of both on one block, you **must** use one of them and this **must** be kept inside this current block.
    -   Each nested block **must** also follow this rule, otherwise an `IndentationError` appears

####    examples:
-   `_` = single space here
-   `*` = single tab here (usually, a tab has a length of 4 spaces and usually one tab only shall be enough)

```
# using space(s)
def use_spaces():
____print("This works fine")
____print("And another one.")

____if True:
________pass

# using tab(s)
def use_tabs():
****print("This works fine, too.")
****a = 15
****b = 19
****print(a+b)

# illegal: mix tab and spaces
def illegal():
____a = 10
____b = 20

****if True:   # <-- this raises an IndentationError on runtime
********pass
```

>   **NOTE**: You also can display whitespace(s) and tab(s) (almost any editor):
>>  view -> display whitespaces (or similar expression)

>>  in Visual Studio (used here), go to the gear symbol (left corner) => settings => in the search bar, hit "whitespace", be default the second entry `render whitespace` shall appear and set the setting to **all**

>>  Bonus: hit "insert spaces" in the search bar to decide, if a tab will automatically be converted into space(s), if you like.