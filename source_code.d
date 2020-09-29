var factorial := func (n) is 
    if n = 0 then		// Brackets are omitted intentionally
    	return 1;
    else
        return n * factorial(n - 1);
    end
end;
var lambdafunc := func( x ) => x/1.4;

for i in 1..10 loop
    print factorial( i );
    end

print  lambdafunc( factorial( 4 ) ) , " The output should be 24/1.4 ~= 17,142";