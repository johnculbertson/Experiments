

test_statement = '5e3e4e11/+*4e3+3e4e3*+*/'
correct_answer_for_test = 0.1601731601731602


operators = ['+', '-', '*', '/', '^']
enters = ['e', 'E']
input_message = "Use '+', '-', '*', '/', '^' as operators, and 'e' or 'E' to enter.\nInput an RPN statement to be evaluated: "
missed_operator = "You must've missed an operator somewhere."
missed_operand = "You must've missed an operand somewhere."
missed_enter = "You must've missed an enter or an operand somewhere."


def run(statement=test_statement):
    stack = []
    cache = ''
    statement = input(input_message)
    for n in statement:
        if n in enters:
            try:
                stack.append(float(cache))
            except ValueError:
                print(missed_operand)
                return
            cache = ''
        elif n in operators:
            if cache:
                stack.append(float(cache))
                cache = ''
            stack = meat_calculate(stack, n)
            if not stack:
                return
        else:
            cache += n
        continue
    if len(stack) != 1:
        print(missed_operator)  
    else:
        print(stack[0])        


def meat_calculate(meat_stack, operator):
    try:
        if operator == '+':
            evaluation = meat_stack.pop(-2) + meat_stack.pop(-1)
        elif operator == '-':
            evaluation = meat_stack.pop(-2) - meat_stack.pop(-1)
        elif operator == '*':
            evaluation = meat_stack.pop(-2) * meat_stack.pop(-1)
        elif operator == '/':
            evaluation = meat_stack.pop(-2) / meat_stack.pop(-1)
        elif operator == '^':
            evaluation = meat_stack.pop(-2) ** meat_stack.pop(-1)
    except IndexError:
        print(missed_enter)
        return False
    meat_stack.append(evaluation)
    return meat_stack


run()