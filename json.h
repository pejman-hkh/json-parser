#include "var.h"
#include <complex>

using namespace vars;

class json_parser {
   
	private:
		int _offset = 0;
		std::string str;
		std::string _error;
		int _length;
	public:
		json_parser( std::string str ) : str( str ), _length( str.length() ) {}

		var start() {
			return get_val();
			 
		}

		var get_val() {
			skip_space();

			switch( str[_offset] ) {
				case '[' :
					_offset++;
					return do_array();
				case '"' :
					_offset++;
					return do_string();
				case '{' :
					_offset++;
					return do_object();
				default :
	 
					if( ( str[_offset] <= '9' && str[_offset] >= '0' ) || str[_offset] == '-' )
						return do_number();
					else
						return do_another();
			}

			return 0;
		}

		var get_str( const int &end ) {
			if( end > _length ) { _error = "Error"; return 0; }

			std::string strp;
			while( _offset < end && end < _length ) {
				strp += str[_offset++];
			}

			return strp;
		}

		var do_another() {
 
			switch( str[_offset] ) {
				case 't' :
 
					if( get_str( _offset + 4 ) == "true" )
						return true;
					
					break;	
				case 'f' :
					if( get_str( _offset + 5 ) == "false" )
						return false;
					
					break;			  
				case 'n':
					if( get_str( _offset + 4 ) == "null" )
						return "";
					
					break;
				default :
					_error = " Error: Value !";		 
			}

			return 0;
		}

		var do_number() {

			var out;
			std::string val, exp_str;
			char c;
			bool is_double = false;
			long exp = 0;
			while( _offset < _length ) {
				c = str[ _offset++ ];

				if( (c == '-') || (c >= '0' && c <= '9') )
					val += c;
				else if( c == '.' ) {
					val += c; 
					is_double = true;
				}
				else
					break;
			}

			if( c == 'E' || c == 'e' ) {
				c = str[ _offset++ ];
				if( c == '-' ){ ++_offset; exp_str += '-';}
				while( _offset < _length ) {
					c = str[ _offset++ ];
					if( c >= '0' && c <= '9' )
						exp_str += c;
					else
						break;
				}
				

				exp = std::stol( exp_str );
			}
			
			--_offset;
			
			if( is_double )
				out = std::stod( val ) * std::pow( 10, exp );
			else {
				if( ! exp_str.empty() ) {

					out = std::stol( val ) * std::pow( 10, exp );
				}
				else {
					out = std::stol( val );
				}
			}
			
			return out;
		}
		
		void skip_space() {
			while( str[_offset] == ' ' && _offset < _length ) _offset++;
		}

		var do_string() {
			std::string pass;
			while( str[_offset] != '"' ) {
				pass += str[_offset++];
			}
			_offset++;
			
			skip_space();

			return pass;			
		}

		var do_array() {

			int i = 0;
			var arr;
			while( _offset < _length ) {
				
				arr[i++] = get_val();
				
				skip_space();

				if( str[_offset] == ',' ) {
					_offset++;
					continue;
				} else if( str[_offset] == ']' ) {
					_offset++;
					return arr;
				} else {
					break;
				}
			}
		}

		var do_object() {
			int i;
			var arr;
			while( _offset < _length ) {
				var index = get_val();

				if( str[_offset] != ':' ) {
					break;
				}
				_offset++;

				arr[index] = get_val();
				
				skip_space();

				if( str[_offset] == ',' ) {
					_offset++;
					continue;
				} else if( str[_offset] == '}' ) {
					_offset++;
					return arr;
				} else {
					break;
				}
			}
		}
};
