# Json-parser
Simple json parser

# Usage
```c++
#include "var.h"
#include "json.h"

using namespace vars;

int main( int argc, char** argv  ) {

	json_parser j("[{ \"test\" : \"test1\", \"sss\" : true, \"aaa\" : {\"ppp\" : [1,2,3,4.32]} }, { \"ss\" : false }]");
	var out = j.start();

	print_r( out );

}
```
# Out put
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
```

# C++ vars
See [C++ vars](https://github.com/pejman-hkh/cpp-vars) for var usage

# Building

```
g++ -std=c++11 json.cpp -o test
```

# Json escape
Will added soon ...
