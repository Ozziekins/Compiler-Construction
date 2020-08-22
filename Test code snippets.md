

# SNIPPET 1

### Recursive function call test + lambda function test of rounding down

````javascript
var factorial := func(n) is 
    if n = 0 then// Brackets are omitted intentionally
    	return 1;
    else
        return n * factorial(n - 1);
    end;
end;
var lambdafunc := func(x)=> x/1.4;

print  lambdafunc( factorial(4) ), " The output should be 24/1.4 ~= 17";
````

# Snippet 2

### Using the empty keyword + testing dynamic types

````javascript
var uninitialized;
if (not ( is uninitialized = empty ) ) then
	print "Well, this is wrong.... \n It should be empty";
	end;
    
uninitialized := true;
if ( is uninitialized /= bool ) then
	print "Well, this is wrong as well.... \n It should be bool";
	end;

uninitialized := "Everything is good?"
if ( is uninitialized = string ) then
	print uninitialized;
	end;
````

# Snippet 3

### Testing the ".." loop thing and unnamed array concatenation inside of tuples

#### *<u>**IN THIS LANGUAGE EVERYTHING STARTS FROM 1 !!!???**</u>*

````javascript
var testArray := [1];
var weirdStruct := {testArray};

var test = [1];
weirdStruct += test ;// Now it should be like this { Array, Array size }

for (5-4) .. 10/2 loop // Go from 1 to 5, hotya hz chto vklyucheno: [1,5] or [1,5)
     test.1 += test.1;
     test.2 += 1;
end; 
     
print "Array is" test.1, "While size is ", test.2; // Allow printing of arrays???
````
# Snippet 4

### Checking the input capabilities and "in" loop operator

````javascript
var str := readString;

//The same string should be printed in the end
for char in str loop
	print i; 
end;
````
# Snippet 5

### Intentionally broken code

````javascript
var sas := empty;
var syas := empty;

print sas + syas;
````

