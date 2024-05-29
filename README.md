# ascii
output a text in ascii numerics

How to use:

compilation is easy.
If you're using Linux:
  $ gcc ascii.c -o ascii

Optional configuration to make the executable feel like a terminal command:
  Go to ~/.bashrc
  Add this line:
    alias ascii='./ascii'
  Now you can use it like this:
    $ ascii [OPTIONS] [OPTIONAL_TEXT]
    where your options are -b to output the characters in binary
    or -x to output the characters in hexadecimal
    [OPTIONAL_TEXT] is used much the same way it is used in the 'echo' command
    If [OPTIONAL_TEXT] was not given, ascii will read from standard input

Here's a cool trick you can try:

Find a text_file you want to translate
Type:
$ cat <text_file> ascii [OPTIONS]
This will output the whole file text to standard output in the number format you gave it,
or in decimal numbers by default.
