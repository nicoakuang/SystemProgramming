PUSH "Hello, "
PUSH "World!"
CONCAT
PRINT
PUSH "OpenAI"
LEN
PRINT

expected result is 
Hello world
6,

why 6? because OpenAI is 6 

PUSH "OpenAI": Pushes the string "OpenAI" onto the stack.
LEN: Pops the top string from the stack, calculates its length, and pushes the length (an integer) back onto the stack. The length of "OpenAI" is 6.