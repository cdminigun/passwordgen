# passwordgen
A small, probably inefficient, password generator. 

## Description:
This program will generate all permutations of most plausible passwords. Input is taken in via argv / argc. 

## Useage:
Each individual digit entered counts for one character. Each digit also correlates to a string of characters.
I also recommend taking output to a file to save the generated permutations. 
<ul>
<li> 2 - "abc..." all lowercase letters </li>
<li>3 - "ABC..." all uppercase letters</li>
<li>4 - "012..." all numbers</li>
<li>5 - "!@#..." all special characters</li>
<li>6 - "abcABC!@#"  Every character list combined, note this is dangerous and will lead to massive file sizes / long times for outputs. </li>
</ul>

## Examples:

<p>./passwordgen 22222</p>
<p>//Generates all permutations of "abc.." and outputs them. </p>
<p>./passwordgen 666666 > example.txt</p>
<p>//Generates all 6 permutations of every possible character. Builds a fairly good list, but this file will get quite large. </p>


## Future Updates:
Because the files are so massive, I'd like to store things into binary files from these permutations. Then write another program that in tandem will push these passwords out at a router or something. 
