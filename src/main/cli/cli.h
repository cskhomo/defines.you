#pragma once
#include <string>
#include "../libs/argh.h"

using namespace std;
using namespace argh;

string parse_args(parser& cmdl);
void render_output(const string& term, const string& definition, const string& example);