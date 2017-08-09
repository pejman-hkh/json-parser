#include "var.h"
#include "json.h"

using namespace vars;

int main( int argc, char** argv  ) {

	json_parser j("[{ \"test\" : \"test1\", \"sss\" : \"aaaa\", \"aaa\" : {\"ppp\" : [1,2,3,4.32]} }, { \"ss\" : \"123\" }]");
	var out = j.start();

	print_r( out );

}