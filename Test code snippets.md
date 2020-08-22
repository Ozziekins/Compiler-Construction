

# SNIPPET 1

### Recursive function call test + lambda function test of rounding down

````javascript
var factorial := func(n) is 
    if n = 0 then// Brackets are omitted intentionally
    	return 1;
    else
        return n * factorial(n - 1);
    end 
end
var lambdafunc(x) => x/1.4;

print  lambdafunc( factorial(4) ), " The output should be 24/1.4 ~= 17"
````

# Snippet 2

### Using the empty keyword + testing dynamic types

````javascript
var uninitialized;
if ( uninitialized is not empty ) then
	print "Well, this is wrong.... \n It should be empty";
	end
    
uninitialized := true;
if ( uninitialized is not bool ) then
	print "Well, this is wrong as well.... \n It should be bool";
	end

uninitialized := "Everything is good?"
if ( uninitialized is string ) then
	print uninitialized;
	end
````

# Snippet 3

### Testing the ".." loop thing and unnamed array concatenation inside of tuples

#### *<u>**IN THIS LANGUAGE EVERYTHING STARTS FROM 1 !!!???**</u>*

````javascript
var testArray := [1];
var weirdStruct := {testArray}

var test = [1];
weirdStruct += test // Now it should be like this { Array, Array size } 

for (5-4) .. 10/2 loop // Go from 1 to 5, hotya hz chto vklyucheno: [1,5] or [1,5)
     test.1 += test.1;
     test.2 += 1

print "Array is" test.1, "While size is ", test.2 // Allow printing of arrays???
````
# Snippet 4

````javascript
func
````
# Snippet 5

````javascript
func
````

