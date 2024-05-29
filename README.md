# ascii
output a text in ascii numerics

How to use:




compilation is easy.


If you're using Linux:

    $ gcc ascii.c -o ascii








Optional configuration to make the executable feel like a terminal command utility:

  Go to ~/.bashrc in vim or nano
  
  Add this line:
  
    alias ascii='/path/to/ascii'
  
  Now you can use it like this:
  
    $ ascii [OPTIONS] [OPTIONAL_TEXT]

where your options are '-b' to output the characters in binary
    or '-x' to output the characters in hexadecimal
    
[OPTIONAL_TEXT] is used much the same way it is used in the 'echo' command

If [OPTIONAL_TEXT] was not given, ascii will read from standard input

Here's a cool trick you can try:

Find a text_file you want to translate

Type:

    $ cat [text_file] ascii [OPTIONS] >> [new_file]

This will output the whole file text to 'new_file' in the number format you gave it,
or in decimal numbers by default. Make sure 'new_file' has a unique file name so that you
don't accidentally concatenate the output to an existing file.



