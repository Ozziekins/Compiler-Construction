## First case ##
```
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
## Second case ##
```
var array := [];
var initial_value = -10;
var k := 1;
for i in 2..4 loop
    array[i] = initial_value + 1;
    k := k + 1;
end

for i in array loop
    if array[i] > 0 then
        print array[i]
    end 
end
```
## Third case ##
```
var something := 1;
something := func(x) is
   return x + 1;
end
print something;
```
## Fourth case ##
```
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
## Fifth case ##
```
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
