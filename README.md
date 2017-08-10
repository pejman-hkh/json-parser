# Json-parser
Simple C++ json parser

# Usage
```c++
json_parser j("[{ \"test\" : \"test1\", \"sss\" : true, \"aaa\" : {\"ppp\" : [1,2,3,4.32]} }, { \"ss\" : false }]");
var out = j.decode();

print_r( out );

echo( j.encode( out ) );
```
# Output
```
Array (
	[0] => Array (
		[test] => test1
		[sss] => 1
		[aaa] => Array (
			[ppp] => Array (
				[0] => 1
				[1] => 2
				[2] => 3
				[3] => 4.32
			)
		)
	)
	[1] => Array (
		[ss] => 0
	)
)
[{"test":"test1","sss":1,"aaa":{"ppp":[1,2,3,4.32]}},{"ss":0}]
```

# C++ vars
See [C++ vars](https://github.com/pejman-hkh/cpp-vars) for var usage

# Building

```
g++ -std=c++11 json.cpp -o test
```
