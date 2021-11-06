# hanoi
quick personal project that outputs the optimal sequence of move to solve the hanoi tower problem

compile (for example) with :
gcc -D MAIN -o hanoi hanoi.c

# Example output 
>> ./hanoi 3
legend : plate O was moved to X
O    
M    
M   X
_ _ _
*****
     
O    
M X M
_ _ _
*****
     
  X  
M M O
_ _ _
*****
     
  M  
O M X
_ _ _
*****
     
  O  
X M M
_ _ _
*****
     
    X
M O M
_ _ _
*****
    X
    M
O   M
_ _ _
*****
