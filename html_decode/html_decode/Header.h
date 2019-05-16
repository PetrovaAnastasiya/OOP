#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char APOS = '’';
const char QUOT = '\"';
const char LESSER = '<';
const char GREATER = '>';
const char AMP = '&';

const vector<string> REPLACEEABLE_CHARACTERS = { "&quot;", "&apos;", "&lt;", "&gt;", "&amp;" };

string HtmlDecode(string const& html);