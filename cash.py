from cs50 import get_float
import math

remaining = 0
change = 0.00

while (True):
    change = get_float("Enter change owed in dollars: ")
    if change > 0:
        break

#find remainder/divisibility of change in quarters, dimes and nickels:

number = 0
cents = round(change * 100)
mod25 = cents % 25
mod10 = mod25 % 10
mod5 = mod10 % 5

#find number of coins

#number of quarters if perfectly divisible
if mod25 == 0:
    number = cents / 25
#number of dimes
elif mod10 == 0:
    number = math.floor(cents / 25) + mod25 / 10
#number of nickels
elif mod5 == 0:
    number = math.floor(cents / 25) + math.floor(mod25 / 10) + mod10 / 5
#number of pennies
elif mod5 != 0:
    number = math.floor(cents / 25) + math.floor(mod25 / 10) + math.floor(mod10 / 5) + mod5

print(number)