# Fib sequence 

#######################################################################
# A recursive function is comprised of two parts                      #
#  -  a exit clause, which allows the programs to exit the program    # 
#  -  a recursive part, which calls the function                      #
#######################################################################

def fib(n):
    if n <= 1: # exit clause
        return n
    else:
        return fib(n-1) + fib(n-2) # recursion

if __name__ == '__main__':
    print(fib(4))
