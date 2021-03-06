#include "main.hpp"

void print ( string word ) {
    cout << word << endl;
    return;
}

void printint ( int word ) {
    cout << word << endl;
    return;
}

vector<string> import(string funcname, string filename) {
    ifstream ifs(filename);
    string data;
    vector<string> result{};
    int count = 0;
    int count2 = 0;
    int j = 0;
    int j2 = 0;

    while ( getline( ifs, data ) ) {
        if ( data.find( ":" ) != string::npos && split( funcname, "(" )[0] == split( data, "(" )[0] ) {
            count++;
            j = 1;
        }
        if ( data.find( ":" ) != string::npos && split( funcname, "(" )[0] != split( data, "(" )[0] ) {
            count++;
            j = 0;
        }
        if ( data.substr( 0, 7 ) == "    fin" ) {
            count2++;
            if ( count == count2 ) {
                
            }
        }
        if ( j == 1 ) {
            result.resize(j2+1);
            result[j2] = data;
            j2++;
        }
    }
    ifs.close();
    return result;
}

int ifj( string data, map<string, string> valls, string mark ) {
    string funcname = split( data, ", " )[2], a, b;
    a = split( replace( data, mark ), ", " )[0];
    b = split( data, ", " )[1];
    if ( mark == "jne " ) {
        if ( keyfind( valls, a ) ) {
            if ( keyfind( valls, b ) ) {
                if ( atoi(valls[a].c_str() ) > atoi(valls[b].c_str() ) ) {
                    return 0;
                }
                else {
                    return 1;
                }
            }
            else {
                if ( atoi(valls[a].c_str()) > atoi(b.c_str() ) ) {
                    return 0;
                }
                else {
                    return 1;
                }
            }
        }
        if ( keyfind( valls, b ) ) {
            if ( atoi( a.c_str() ) < atoi( valls[b].c_str() ) ) {
                return 0;
            }
        }
        else {
            if ( atoi( a.c_str() ) > atoi( b.c_str() ) ) {
                return 0;
            }
            else {
                return 1;
            }
        }
    }
    if ( mark == "ja " ) {
        if ( keyfind( valls, a ) ) {
            if ( keyfind( valls, b ) ) {
                if ( atoi( valls[a].c_str() ) < atoi( valls[b].c_str() ) ) {
                    return 0;
                }
                else {
                    return 1;
                }
            }
            else {
                if ( atoi( valls[a].c_str() ) < atoi( b.c_str() ) ) {
                    return 0;
                }
                else {
                    return 1;
                }
            }
        }
        if ( keyfind( valls, b ) ) {
            if ( atoi( a.c_str() ) < atoi( valls[b].c_str() ) ) {
                return 0;
            }
        }
        else {
            if ( atoi( a.c_str() ) < atoi( b.c_str() ) ) {
                return 0;
            }
            else {
                return 1;
            }
        }
    }
    return 1;
}

map<string, string> calc( string data, map<string, string> valls, string mark ) {
    ostringstream oss;
    string a = split( data, ", " )[1].c_str();
    string b = split( data, ", " )[2].c_str();
    string x = replace( split( data, ", " )[0], mark );
    int y = atoi( split( data, ", " )[1].c_str() );
    int z = atoi( split( data, ", " )[2].c_str() );

    if ( keyfind(valls, a) ) {
        if ( keyfind(valls, b) ) {
            if ( mark == "add " ) { oss << atoi(valls[a].c_str()) + atoi(valls[b].c_str()); }
            if ( mark == "sub " ) { oss << atoi(valls[a].c_str()) - atoi(valls[b].c_str()); }
            if ( mark == "mul " ) { oss << atoi(valls[a].c_str()) * atoi(valls[b].c_str()); }
            if ( mark == "div " ) { oss << atoi(valls[a].c_str()) / atoi(valls[b].c_str()); }
        }
        else {
            if ( mark == "add " ) { oss << atoi(valls[a].c_str()) + z; }
            if ( mark == "sub " ) { oss << atoi(valls[a].c_str()) - z; }
            if ( mark == "mul " ) { oss << atoi(valls[a].c_str()) * z; }
            if ( mark == "div " ) { oss << atoi(valls[a].c_str()) / z; }
        }
    }
    else {
        if ( keyfind(valls, b) ) {
            if ( mark == "add " ) { oss << y + atoi(valls[b].c_str()); }
            if ( mark == "sub " ) { oss << y - atoi(valls[b].c_str()); }
            if ( mark == "mul " ) { oss << y * atoi(valls[b].c_str()); }
            if ( mark == "div " ) { oss << y / atoi(valls[b].c_str()); }
        }
        else {
            if ( mark == "add " ) { oss << y + z; }
            if ( mark == "sub " ) { oss << y - z; }
            if ( mark == "mul " ) { oss << y * z; }
            if ( mark == "div " ) { oss << y / z; }
        }
    }
    valls[x] = oss.str().c_str();
    return valls;
}

string replace( string data, string replace_word ) {
    data = regex_replace( data, regex( replace_word ), "" );
    return data;
}

vector<string> split(string str, string separator) {
    if (separator == "") return {str};
    vector<string> result;
    string tstr = str + separator;
    long l = tstr.length(), sl = separator.length();
    string::size_type pos = 0, prev = 0;
    
    for (;pos < l && (pos = tstr.find(separator, pos)) != string::npos; prev = (pos += sl)) {
        result.emplace_back(tstr, prev, pos - prev);
    }
    return result;
}

vector<string> remove(vector<string> vector, int index) {
    vector.erase(vector.begin() + index);
    return vector;
}

bool keyfind(map<string, string> m, string v) {
    return m.find(v) != m.end(); // find??????????????????????????????
}

int find(vector<string> vec, string number) {
    auto itr = find(vec.begin(), vec.end(), number);
    size_t index = distance( vec.begin(), itr );
    if (index != vec.size()) { // ?????????????????????
        return 1;
    }
    else { // ??????????????????????????????
        return 0;
    }
}
