# This thing takes a number, and reverses that number. 
# This reversed number is either added to or subtracted 
# from the original number, depending on if the original 
# number is positive or negative. The final # of "operations" 
# is recorded and printed. If the number will loop infinitely,
# the program will crash. (Still working on that!).

# Thought it would be cool to make a game out of this, where the user
# is given a random number, and they choose to add or subtract the flipped number,
# with the goal being to get to zero in as few operations as possible.

# Examples:
# 3029
# 3029 - 9203 = -6174
# -6174 + 4716 = -1458
# -1458 + 8541 = 7083
# 7083 - 3807 = 3276
# 3276 - 6723 = -3447
# -3447 + 7443 = 3996
# 3996 - 6993 = -2997
# -2997 + 7992 = 4995
# 4995 - 5994 = -999
# -999 + 999 = 0

# 2178 (will crash)
# 2178 - 8712 = -6534
# -6534 + 4356 = -2178
# -2178 + 8712 = 6534
# 6534 - 4356 = 2178 (and there's the infinite loop)

# take in a number, return the flipped number
def flipNumber( input ):
	if input<0:
		input*=-1
	x = str(input)[::-1]
	return int(x)

# checklist: add flippedNumber to another num, subtract a flippedNumber, detect if 0, detect if loop (keep track of numbers, if you encounter a # you will encounter it again)

number = 3029
originalNumber = number
operations = 0
additions = 0
subtractions = 0

while (number != 0):
	if (number > 0):
		print " - "
		operations+=1
		subtractions+=1
		number=number-flipNumber(number) 
		print number
	elif (number < 0):
		print " + "
		operations+=1
		additions+=1
		number=number+flipNumber(number) 
		print number

print originalNumber," took ",operations," operations: ",additions," additions and ",subtractions," subtractions."
