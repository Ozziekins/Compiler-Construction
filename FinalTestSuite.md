# Types, Literals and Logical operators

## SNIPPET 1
```javascript
var positiveNumber := true;
var evenNumber := true;
if (positiveNumber and evenNumber) then
	print “number is even and positive”;
end

if (positiveNumber or evenNumber) then
	print “number is even or positive or both even and positive”;
end

if (positiveNumber xor evenNumber) then
	print “number is even or positive”;
end

if (not positiveNumber) then
	print “number is negative”;
else 
	print “number is positive”;
end
```
## SNIPPET 2
```javascript
var this := 7;
var that := 17.9;
var those = "anything";
var e;

var r := is this;    //INTEGER
var s := is that;      //REAL
var t := is those;  //STRING
var u := is e;        //empty

var sas := empty;
var syas := empty;

print sas + syas;	//ERROR

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

## SNIPPET 3: Using the empty keyword + testing dynamic types

````javascript
var uninitialized;

//Should not print
if (not ( is uninitialized = empty ) ) then
	print "Well, this is wrong.... \n It should be empty";
end;
  
//Should not print too
uninitialized := true;
if ( is uninitialized /= bool ) then
	print "Well, this is wrong as well.... \n It should be bool";
end;

// This one should print 
uninitialized := "Everything is good?"
if ( is uninitialized = string ) then
	print uninitialized;
end;
````


## SNIPPET 4: Comparison Operations
```javascript
var x := 0;
var y := -1;
var z:= 4;

if x > y and x > z then
    if y > z then
        print z; // z is minimum
    else
        print y; // y is minimum
    end
else
    if y > x and y > z then
        if x > z then
            print z; // z is minimum
        else 
            print x; // x is minimum
        end
    else 
        if z > x and z > y then
            if x > y then 
                print y; // y is minimum
            else 
                print x; // x is minimum
            end
        end
    end
end 
```

## SNIPPET 5 
```javascript
var yearOfBirth := 1998;

var adult := yearOfBirth <= 2002;
print adult;       // true

var minor := yearOfBirth > 2002;
print minor;       // false

var PI := 3.14;
var testReal := 2;
var isPi := testReal = PI;
var isNotPi := testReal /= PI;
print isPi, isNotPi;        //false true
```

## SNIPPET 6
```javascript
var x := 15; 
var y := 36; 

if x > y then 
    print x; 
else 
    print y; 
end 

print "The max var from x and y is "; // 36 

var mult := x * y; 

print "x * y = "; 
print mult; //540
```

## SNIPPET 7: Arithmetic operations & Dynamic Type conversion
```javascript
var inumber1 := 10, inumber2 := 2, rnumber1 := 2.4, rnumber2 := 0.1;
var result;

result := inumber1 + rnumber2;
print result;		//10.1

result := inumber1 - inumber2;
print result;		//8

result := inumber1 * rnumber1;
print result;		//24.0

result := inumber1 / rnumber1;
print result;		//4.16
```


# Arrays, Tuples, Input and Loops

## SNIPPET 8: Testing the ".." loop thing and unnamed array concatenation inside of tuples
#### *<u>**IN THIS LANGUAGE EVERYTHING STARTS FROM 1 !!!???**</u>*

````javascript
var testArray := [1];
var weirdStruct := {testArray};

var test := 1;
weirdStruct := weirdStruct + {test} ;// Now it should be like this { Array, Array size }

for i in (5-4) .. 10/2 loop // Go from 1 to 5, hotya hz chto vklyucheno: [1,5] or [1,5)
     test.1 := test.1 + test.1;
     test.2 := test.2 + 1;
end; 
     
print "Array is" test.1, "While size is ", test.2; // Allow printing of arrays???
````

## SNIPPET 9: Checking the input capabilities and "in" loop operator

````javascript
var str := readString;

//The same string should be printed in the end
for char in str loop
	print char; 
end;
````

## SNIPPET 10: array operations and loops

```javascript
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


## SNIPPET 11 
```javascript
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


## SNIPPET 12
```javascript
var carDescription := {brand := “KIA”, model := “Seltos”, year := 2019};
carDescription := carDescription + {color := “red”};

print “This car is a ”, carDescription.color, “ ”, carDescription.1, “ ”,
        carDescription.model, “ made in “, carDescription.3;

//This car is a red KIA Seltos made in 2019

var arrayRandom := [];
arrayRandom[2] := 20;
arrayRandom[4] := func (x, y) => x * y;
arrayRandom[6] := {x:=15, y:= 17};
arrayRandom[8] := [“Monday”, “Friday”];

print arrayRandom[4](5,4);     //20
print arrayRandom[6].x;      //15
print arrayRandom[8][1];     //Monday
```


# Functions

## SNIPPET 13
```javascript
var something := 1;
something := func(x) is
   return x + 1;
end
print something(5); //6
```


## SNIPPET 14
```javascript
var c;
c := func (x, y, z) is 
  var count := 0;
    while x >= y loop
        if y > z then
            y := y + 1;
        else
            z := z - 1;
        end
    count := count + 1;
    end
    return count;
 end
 print c(10, 5, 7);
```

## SNIPPET 15: (summation of the first N numbers)
```javascript
var summation := func (N) is
	var counter := 1, result := 0
	while counter <= N loop
		result := result + counter
		counter := counter + 1
	end
return result
end 

print summation(5);			//15
```


## SNIPPET 16: Recursive function call test + lambda function 

````javascript
var factorial := func(n) is 
    if n = 0 then		// Brackets are omitted intentionally
    	return 1;
    else
        return n * factorial(n - 1);
    end;
end;
var lambdafunc := func(x)=> x/1.4;

print  lambdafunc( factorial(4) ), " The output should be 24/1.4 ~= 17,142";
````
