#include "var.h"
#include "json.h"

using namespace vars;

int main( int argc, char** argv  ) {

    ppp_json::json_parser j;
    var out = j.decode("[{ \"test\" : \"test1\", \"sss\" : true, \"aaa\" : {\"ppp\" : [1,2,3,4.32]} }, { \"ss\" : false }]");

    print_r( out );

    echo( j.encode( out ) );
}