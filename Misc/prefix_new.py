
def prefixHelper(expression):
    myStack = []

    operators = set(['+','-','*','/'])

    # Scan each letter from last
    for ind, letter in reversed(list(enumerate(expression))):
        # If expression is operand, push it to stack
        if letter not in operators:
            myStack.append(letter)
        else:
            firstExp = myStack.pop()
            secondExp = myStack.pop()
            result = firstExp + secondExp + letter
            # Append it as operand + operand + operator
            myStack.append(result)
    print (myStack.pop())


def prefixToPostfix(prefixes):
    for x in prefixes:
        prefixHelper(x)

prefixStringTestCases = ['*34', '+1*23', '+12']
prefixToPostfix(prefixStringTestCases)