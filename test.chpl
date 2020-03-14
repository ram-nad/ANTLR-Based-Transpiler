record data{
    var a:int;
    var b:uint(32);
    var c:bool;

    proc func1(a:int, b:int): uint{
        var c, d:int = this.a;
        return (a + b + c*d):uint + this.b:uint;
    }

    proc func2(): int{
        return (this.a + this.b):int;
    }
}

proc globalFunc(a:data, b:data): uint(32){
    return a.b + b.b;
}