# usually, you don't need to define a datatype elsewhere,
# because the python interpreter does this job, however,
# it may also be a good advise to know, which type is expected

# typical way:
data_0 = "Hello World!"

# you can also use:
data_1: str = "Hello World!"

# the python interpreter usually don't care about this given
# datatype, unless you're using specific modules, which watchs
# for the correct or expected type
#
# these are typical used data types:
# int                := integer
# float              := floating point
# str                := string
# bool               := boolean expression
# list[type]         := list with an expected type, can also be defined as a raw list  => "list"      *
# tuple[type]        := tuple, similar to the list above | a raw tuple declaration: "tuple"           *
# set[type]          := set, similar to the list | raw set declaration: "set"                         *
# dict[type, type]   := dictionary with key and value | raw dictionary declaration: "dict"            *
#
# * := take a look to section a, chapter 6 (collections)
#
# class              := more in use, if you declare a specific class **
#
# ** := take a look to section b, chapter 7 (python and oop)
#
# finally, if you're using a type, which does not match, no error appears
# - unless the python interpreter runs into a real error on runtime

# data_2 shall be interpreted as an integer, but a string is given
# since this string is not mentioned to work with integer operations,
# everything works fine, but it causes confusions
data_2: int = "Hello World"

# every output is a string ('str')
print("data_0 = " + str(type(data_0)))
print("data_1 = " + str(type(data_1)))
print("data_2 = " + str(type(data_2)))