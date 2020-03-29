```chapel
record Name{
    var a: int;
    var b: int(64);
    var a: int;
}

proc func(a: Name){
    return a.c;
}

var b: Name;

func(b, b);
```

### Error

> NameError at Line 4 Column 8: Already declared a member with this name.

> NameError at Line 8 Column 11: No such member exists for Name record type.

> CallError at Line 13 Column 4: Too many arguments supplied. Expected 1 arguments. Got 2.

```chapel
proc b(a: int, b:int, c:string): int {
c = "Hello";
b = a + c;
return c;
}
```

### Error

> TypeError at Line 25 Column 10: + operator is not supported for int(64) and string expressions.

> TypeError at Line 26 Column 4: Wrong Return Type for given function b.

```chapel
proc test(c: int){
this.a = c;
a = c;
}
```

### Error

> TypeError at Line 37 Column 4: `this` is not valid outside of a method.

> TypeError at Line 38 Column 4: This variable does not exist.
