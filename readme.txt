We used the loophole in fprintf function. In fprintf
function, %n will write the number of bytes printed
in front after expending the formatted string. We 
make the number of bytes in front to be the starting
address of the argv[1] (i.e.shellcode). And then we
write the result to ret, which is the return address
of fprintf function. 

This program appears to be an echo program. But when
a shellcode is input, shell would be executed. 
Otherwise we handle the segmentation fault and echo
the normal message. 

Example usage:
./myvulnerable 123
123

Besides we use strncpy instead of strcpy to prevent
buffer overflow, another reason which make our program
difficult to be hacked is that you cannot hack the
program directly by putting the shellcode into the
argument. This is because "\x" is recogized as two
characters "\" and "x" instead of a hexdecimal value.
We need myexploit.c to put the shellcode into an 
environment variable $EGG and execute myvulnerable.c 
with $EGG in order to spawn a shell successfully.

You can try the hacking simply using the following 
commands:
make clean all
./myexploit