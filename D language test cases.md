# D language test cases

### First (arithmetic and loops)
```
var thing := func (t) is
    print t;
    var id := 0;
    while id < 5
        loop
            print id;
            id := id + 1;
            print id;
        end
    t := t + id;
    print t;
end

print thing(2); //6
```

### Second (if then else)
```
if (7 < 0) and (0 < -7) then
    print("abcd");
else
    if (7 > 0) or false then
        print("compilers");
    else
        print("cc");
    end
end
```

### Third (array operations and loops)
```
var temp := [0, 0, 0]
var new := []; // empty array declaration 
var array := temp + new 
print ("Array before insertion : ");
for i in array
    loop
        print i;
    end 
  
// adding elements
array[4] := 55.5;
array[5] := 7*9;
array[6] := "experience";
array[7] := [5, 4];
  
print ("Array after insertion : ") ;
for i in array
    loop
        print i;
    end  
```

### Fourth (types, literals and logical operators)
```
var this := 7;
var that := 17.9;
var those = "anything";
var e;

var r := is this;    //INTEGER
var s := is that;      //REAL
var t := is those;  //STRING
var u := is e;        //empty

print r;
print s;
print t;
print u;

var a := true and true;
var b := not true;
var c := false xor false;
var d := true or true;

print("if " + a + " then not " + b + " but " + " if " + c + " then " + d);
```

### Fifth (arrays, tuples and loops)
```
var arr := ["cherry", "pie", "or", "cherry", "truffle"];

for a in arr
    loop
        print a;
    end
    
var range := [5000.07, 204, 555.90, 78];
var t := {one:=1, two:=2, three:=3, four:=4};
var total := 0;

for n in t
    loop
        total := total + range[n];
    end
print total;
```