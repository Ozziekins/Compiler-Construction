##### Test 1: Logical operations
```
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

##### Test 2: Comparison Operations
```
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

##### Test 3: Arithmetic operations & Dynamic Type conversion
```
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

##### Test 4: Tuples and Arrays
```
var carDescription := {brand := “KIA”, model := “Seltos”, year := 2019};
carDescription := carDescription + {color := “red”};

print “This car is a ”, carDescription.color, “ ”, carDescription.1, “ ”,
        carDescription.model, “ made in “, carDescription.3;

//This car is a red KIA Seltos made in 2019

Var arrayRandom := [];
arrayRandom[2] := 20;
arrayRandom[4] := func (x, y) => x * y;
arrayRandom[6] := {x:=15, y:= 17};
arrayRandom[8] := [“Monday”, “Friday”];

print arrayRandom[4](5,4);     //20
print arrayRandom[6].x;      //15
print arrayRandom[8][1];     //Monday
```

##### Test 5: Functions and Loops (summation of the first N numbers)
```
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
