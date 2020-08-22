# D language test cases

### First (arithmetic and loops)
```
func (temp) is
    print temp;
    var id := 0;
    while id < 5
        loop
            print id;
            +id;
            temp := temp + id;
            print id;
        end
    print temp;
end
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
for i in 3
    loop
        print (array[i]);
    end 
  
// adding elements
array[3] := 55.5;
array[4] := 7*9;
array[5] := "experience";
array[6] := [5, 4];
  
print ("Array after insertion : ") ;
for i in 7
    loop
        print (array[i]);
    end  
```

### Fourth (types, literals and logical operators)
```
var this := 7;
var that := 17.9;
var those = "anything";
var e := empty;

var t := is this INTEGER;    //true
var f := is that empty;      //false
var t_2 := is those STRING;  //true
var f_2 := is e REAL;        //false

print t;
print f;
print t_2;
print f_2;

var a := t and t_2;
var b := not t;
var c := f xor f_2;
var d := t or t_2;

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
var t := {one:=1, two:=2, three:=3, four:=4, five:=5};
for n in t.three
    var total := 0;
    loop
        total := total + range[n];
    end
    print total;
```