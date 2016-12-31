import math

SMALLE = 1e-8

# return the numerical derivative using three-point formula
#def deriv(func, x):
#    return (func(x+SMALLE) - func(x-SMALLE)) / (2 * SMALLE)

# return the numerical derivative using five-point formula
def deriv(func, x):
    try:
        return (func(x-2*SMALLE)-8*func(x-SMALLE)+8*func(x+SMALLE)-func(x+2*SMALLE)) / (12*SMALLE)
    except ZeroDivisionError:
        print('Attempting to divide by zero...')
        return None

def test_deriv(func, expected, x):
    print('x = {}: expected: {}; computed: {}'.format(x, expected(x), deriv(func, x)))

# lambda function for a line
line = lambda x : x
deriv_line = lambda x : 1

# printing the derivative of the line evaluated at 5
test_deriv(line, deriv_line, 5)

# lambda function for a quadratic
quad = lambda x : x * x
deriv_quad = lambda x : 2 * x

print('deriv quad | x = 5: expected: {}; computed: {}'.format(deriv_quad(5), deriv(quad, 5)))

print('deriv quad | x = 1: expected: {}; computed: {}'.format(deriv_quad(1), deriv(quad, 1)))

print('deriv quad | x = 100: expected: {}; computed: {}'.format(deriv_quad(100), deriv(quad, 100)))

something = lambda x : 5 * x**2 + 10 * x + 20000
deriv_something = lambda x : 10 * x + 10

print('deriv something | x = 1: expected: {}; computed: {}'.format(deriv_something(1), deriv(something, 1)))

print('deriv something | x = 1000: expected: {}; computed: {}'.format(deriv_something(1000), deriv(something, 1000)))

print('deriv something | x = 5: expected: {}; computed: {}'.format(deriv_something(5), deriv(something, 5)))

deriv_e = lambda x : math.e ** x
print('deriv e^x | x = 5: expected: {}; computed: {}'.format(deriv_e(5), deriv(math.exp, 5)))

print('deriv e^x | x = 1: expected: {}; computed: {}'.format(deriv_e(1), deriv(math.exp, 1)))

recip = lambda x : 1.0 / x
deriv_recip = lambda x : - 1.0 / (x**2)

print('deriv 1/x | x = 5: expected: {}; computed: {}'.format(deriv_recip(5), deriv(recip, 5)))
print('deriv 1/x | x = 1: expected: {}; computed: {}'.format(deriv_recip(1), deriv(recip, 1)))
print('deriv 1/x | x = 1000: expected: {}; computed: {}'.format(deriv_recip(1000), deriv(recip, 1000)))

print('deriv 1/x | x = 0: expected: {}; computed: {}'.format('???', deriv(recip, 0)))
print('deriv 1/x | x = SMALLE: expected: {}; computed: {}'.format('???', deriv(recip, SMALLE)))

