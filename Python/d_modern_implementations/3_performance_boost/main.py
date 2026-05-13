# ---
# Boosting performance is often necessary, otherwise instructions will
# slow down your application (very) fast. Boosting up a recursion,
# like the fibonacci series for high numbers gives you the power of control.
# ---

from time_decorator import time_measurment
from functools import cache, lru_cache

# default way to handle the fibonacci series
# NOTE: It's not a good idea to use this for high numbers, like n > 40,
# unless you've enough time to waste.
@time_measurment
def fibonacci_0(n: int) -> int:
	if n < 2:
		return n
	#end if

	return fibonacci_0(n=n-1) + fibonacci_0(n=n-2)
#end function

# create an internal buffer to figure out, if F(n) has
# already been calculated
@time_measurment
def fibonacci_1(n: int, already_handled: dict[int] = {}) -> int:
	if n in already_handled:
		return already_handled[n]
	#end if

	if n < 2:
		already_handled[n] = n
	else:
		already_handled[n] = fibonacci_1(n-1, already_handled) + fibonacci_1(n-2, already_handled)
	#end if

	return already_handled[n]
#end function

# use the cache decorator instead
@cache
@time_measurment
def fibonacci_2(n: int) -> int:
	if n < 2:
		return n
	#end if

	return fibonacci_2(n-1) + fibonacci_2(n-2)
#end function

# use lru_cache decorator instead
@time_measurment
@lru_cache
def fibonacci_3(n: int) -> int:
	if n < 2:
		return n
	#end if

	return fibonacci_3(n-1) + fibonacci_3(n-2)
#end function

# use bottom_up implementation instead
@time_measurment
def fibonacci_4(n: int) -> int:
	if n < 2:
		return n
	#end if

	already_handled: list[int] = [0, 1]
	for _ in range(2, n + 1):
		already_handled.append(already_handled[-1] + already_handled[-2])
	#end for

	return already_handled[n]
#end function

# use a loop function instead
@time_measurment
def fibonacci_5(n: int) -> list[int]:
	fib_series: list[int] = []
	ctr: int = 0

	while ctr < n:
		match ctr:
			case (0 | 1):
				fib_series.append(ctr)
			case _:
				fn: int = fib_series[ctr - 1] + fib_series[ctr -2]
				fib_series.append(fn)
			#end cases
		#end match

		ctr += 1
	#end while

	return fib_series[-1] + fib_series[-2]
#end function

# use a matrix implementation instead
@time_measurment
def fibinacci_6(n: int):
	if n == 0:
		return 0
	#end if

	def helper(k: int):
		if k == 0:
			return (0,1)
		#end if

		a,b = helper(k >> 1)
		c = a * (2 * b - a)
		d = a*a + b*b

		return (d, c+d) if k & 1 else (c,d)
	#end function

	return helper(n)[0]
#end function

# O(n)
@time_measurment
def regular_loop(n: int) -> None:
	summary: int = 0

	for i in range(1, n+1):
		summary += i
	#end for
#end function

# O(1)
@time_measurment
def fast_loop(n: int) -> None:
	_ = n * (n + 1) // 2
#end function

if __name__ == "__main__":
	upper_boundary: int = 40    # F(40) = 102,334,155

	# NOTE: Depends on how much RAM is available and how much applications are also running at the same time.
	#       If you have multiple virtual desktops, then the time amount also differs, when an another
	#       virtual desktop is in use.
	#               |    59 s    |   28 µs   |     37 µs   |    44 µs   |    10 µs    |   8 µs    |    7 µs    | => estimated time amount
	fib_functions = [fibonacci_0, fibonacci_1, fibonacci_2, fibonacci_3, fibonacci_4, fibonacci_5, fibinacci_6]

	for f in fib_functions:
		_ = f(upper_boundary)
	#end for

	upper_boundary: int = 1000   # sum(1000) = 500,500
	regular_loop(n=upper_boundary)
	fast_loop(n=upper_boundary)

	# use the summary dictionary to figure out which function
	# has had which time consuming in µs
	from time_decorator import summary

	fastest = min(summary.items(), key=lambda item: item[1])
	slowest = max(summary.items(), key=lambda item: item[1])

	print(f"fastest function: {fastest[0]} ({fastest[1]} µs)")
	print(f"slowest function: {slowest[0]} ({slowest[1]} µs)")

#end entry point