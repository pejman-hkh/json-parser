#include "var.h"
#include "json.h"

using namespace vars;



int main( int argc, char** argv  ) {

    json_parser j("[{ \"test\" : \"test1\", \"sss\" : true, \"aaa\" : {\"ppp\" : [1,2,3,4.32]} }, { \"ss\" : false }]");
    var out = j.decode();

    print_r( out );

    echo( j.encode( out ) );
}