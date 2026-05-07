print("--- bitwise operations ---")

# values to use
a = 10
b = 20

# bitwise and
print(a & b)

# bitwise or
print(a | b)

# bitwise xor
print(a ^ b)

# negation
print(~a)

# combination...
print(~(a ^ b))

# shift rigt (the value of a will be smaller up to 0)
print(a >> 4)

# shift left (the value of a will be larger)
print(b << 4)

print("-------------------------------------")

a = 0b01001001               # 73
b = 0b00101010               # 42

print(a & b)                 # a bit and b
print(a | b)                 # a bit or b
print(a ^ b)                 # a exclusive or b
print(~a)                    # bit negated value of a
print(a >> 4)                # right bit shift of a by 4 fields
print(b << 4)                # left bit shift of b by 4 fields