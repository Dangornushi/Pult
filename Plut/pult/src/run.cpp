#include"main.hpp"

int main( int argc, char **arg ) {
    string a, b, data, data2, funcname, arg1 = arg[1], funcdata, cont, cont2;
    
    map<string, string> valls;
    map<string, string> funcs;

    vector<string> funclis{};
    vector<string> funcvalls;
    
    int fincount = 0;
    int i = 0;

    ifstream run( arg1 );

    while ( getline ( run, data ) ) {
        if ( data.find( ":" ) != string::npos ) {
            cont2 = "";
            funcdata = split( data, "(" )[0];
            i++;
            funcvalls = import( funcdata, arg1 );
            for (size_t i3 = 0; i3 < funcvalls.size(); ++i3) {
                cont = replace( funcvalls[i3], "    " );
                if ( cont != "" ) {
                    cont2 = cont2 + cont;
                }
            }
            funcs[funcdata] = cont2;
        }
    }
    runf( valls, funcs, arg1, "main" );
}

void runf( map<string, string> valls, map<string, string> funcs, string arg1, string funcname ) {
    ifstream run( arg1 );
    string data, data2, a, b, order, x;

    ostringstream oss;

    vector<string>funcvall;
    vector<string>args2;
    vector<string>args;

    map<string, string>valls2;

    int popcount = 0, y, z, count = 0;

    funcvall = split( split( funcs[funcname], ":" )[1], ";" );

    for (size_t i = 0; i < funcvall.size(); ++i) {
        data = funcvall[i];
        order = replace( data, "    " ).substr( 0, 4 );
        if ( order == "msg " ) {
            a = replace( data, "msg " );
            if ( keyfind(valls, a) ) {
                cout << valls[replace( a, ";" )];
            }
            else {
                cout << replace( replace( a, "\"" ), ";" );
            }
        }
        if ( order == "mov " ) {
            a = replace( split( split( data, "mov " )[1], ", " )[0], "    " );
            b = replace( split( data, ", " )[1], ";" );
            valls[a] = replace( b, "\"" );
        }
        if ( order == "pop " ) {
            oss << popcount;
            valls[ replace(data, "pop " ) ] = valls[oss.str().c_str()];
            popcount++;
        }
        if ( order == "call" ) {
            a = split( replace( data, "call " ), "(" )[0];
            data = split( data, ")" )[0];
            args = split( split( data, "(" )[1], "," );
            for (size_t i = 0; i < args.size(); ++i) {
                data2 = args[i];
                oss << i;
                if ( keyfind(valls, data2) ) {
                    valls2[oss.str().c_str()] = valls[data2];
                }
                else {
                    valls2[oss.str().c_str()] = data2;
                }
            }
            valls.clear();
            runf( valls2, funcs, arg1, a );
        }
        if ( order == "ret " ) {
            a = split( replace( data, "ret " ), ", " )[0];
            b = split( replace( data, "ret " ),  ", ")[1];
            valls[b] = a;
        }
        if ( order == "add " || 
                order == "sub " || 
                    order == "mul " || 
                        order == "div " ) {
            valls = calc( data, valls, order );
        }
        if ( order == "jmp " ) {
            a = split( split( data, ", " )[0], " " )[1];
            b = valls[split( data, ", " )[1]];
            data2 = replace( split( data, "(" )[0], "jmp " );
            while ( 1 ) {
                if ( count == atoi( b.c_str() ) ) {
                    break;
                }
                else {
                    runf( valls, funcs, arg1, data2 );
                    count ++;
                }
            } 
        }
        if ( order == "jne " || data.substr( 0, 3 ) == "ja " ) {
            if( data.substr ( 0, 3 ) == "ja " ) {
                if ( ifj(  data, valls, "ja " ) == 0 ) {
                    runf( valls, funcs, arg1, split( split( data, "(" )[0], ", " )[2] );
                }
            }
            else {
                if ( ifj(  data, valls,"jne " ) == 0 ) {
                    runf( valls, funcs, arg1, split( split( data, "(" )[0], ", " )[2] );
                }
            }
        }
    }
}
