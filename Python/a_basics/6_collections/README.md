#   Collections in Python

-   allows you to handle a bunch of objects at the same time
-   unlike to compiler languages, like C, C++, Java, C#, ... you can store **anything** in your collection

### different types of collections

| collection | effect | can be modified | defined with | example |
| - | - | - | - | - |
| list | linear, unordered collection of multiple elements | yes |  `list(), []` | `[1,2,3,4,5]`| 
| tuple	| unordered collection of fixed elements | no | `tuple(), ()` | `(1,2,3,4,5)`
| set | linear, ordered collection of unique elements | yes | `set()` | `{1,2,3,4,5}` |
| dictionary | ordered collection of key-value-pairs, where the keys are ordered by default; the key is unique | yes |`dict(), {}` | `{a: 1, b: 2, c: 3}`

> Are you confused about a set and dictionary? While a set contains `{any elements here}`, the brackets `{}` defaults to a dictionary.
>> Because there are no other bracket types left, which could determine them.

>   **NOTE:**    Python doesn't comes with an array, where `[]` also does not stands for an array

####    How to convert a tuple into a list
```
t: tuple = (1, 2, 3, "a", "b", "c")             # a simple tuple
l: list = list(t)                               # convert into a list

# => now "l" is a copy of "t" and this can now be
#    modified, whereas "t" still exists

# to "update" the tuple, use:
t = tuple(l)                                    # "updated" tuple t
```

####    How to convert a list into a dictionary
```
l = [1, 2, 3, "A", "B", "C", False, 7, 5]

# way 1 (using zip):
iterator = iter(l)
d = dict(zip(iterator, iterator))
print(f"a simple list: {l} <=> a new directory: {d}")

# way 2 (more pythonic style):
for i,j in enumerate(l):
	d[i] = j
#end for

print(f"a simple list: {l} <=> a new directory: {d}")
```