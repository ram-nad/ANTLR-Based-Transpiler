## A Small Transpiler using ANTLR4

This is a small transpiler made for changing a extremely minimal (it does not even support if, else, loops) subset of [Chapel Language](https://chapel-lang.org) to C. This is a toy project. Made with the purpose of learning ANTLR. No guarantee is made in any way about correctness of the Transpiler. (It may be completely wrong also. Again this was made for learning purpose and a very limited timeframe.)

ANTLR Grammar Files can be found under `grammar` folder. This project uses Visitors for working with parse trees. The code for visitor can be found under visitor folder.

Currently implemented constructs:

- Functions

- Records (Very Minimal, Treating them similar to structs in C)

- Methods

- Variable Declaration

- Cast Expression
