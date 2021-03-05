/* 2/5~ */
#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <regex>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

//----------------------

using namespace std;

//----------------------

void run ( string filename );
vector <string> split( string str, string separator ) ; 
map <string, string> todict ( string sent, map <string, string> dict ) ;
void print ( string word ) ;
void printint ( int word) ;
int find( vector<string> vec, string number ) ;
vector<string> import( string funcname, string filename ) ;
string replace( string data, string replace_word ) ;
void runf( map<string, string> valls, map<string, string> funcs, string arg1, string funcname ) ;
vector<string> remove(vector<string> vector, int index) ;
bool keyfind(map<string, string> m, string v) ;
map<string, string> calc( string data, map<string, string> valls, string mark ) ;
int ifj( string data, map<string, string> valls, string mark ) ;