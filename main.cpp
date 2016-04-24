/*
 * main.cpp
 *
 *  Created on: 20.04.2016
 *      Author: Jörg
 */
#include <iostream>
#include <typeinfo>
#include "Debug.h"

using namespace std;

int main(int argc, char** argv) {
	using namespace debug;
	Debug __dbg;
	__dbg.setLevel(Warning);
	__dbg.Out(cout);

	__dbg.Print(Important, __FILE__, ":", __LINE__, " ", __FUNCTION__, "(argc=", argc, "): ", "enter function");
	__dbg.Print(Warning, "--> going on, ", "myvalue=", 5, ", another value: ", 10);
	__dbg.Print(Error, "--> not important ", __DATE__, " ", __TIME__, " ", std::hex, 255);
	__dbg.Print(Warning, "--> very important");
	__dbg.Print(LessImportant, "--> end of function");

	__dbg.Printf(Important, "%s:%d %s(): call to Debug::Printf()\n", __FILE__, __LINE__, __FUNCTION__);
	cout << "set debug level to less important" << std::endl;
	cdebug.Out(cout);
	cdebug.setLevel(4);
	cdebug << Important << debug::dec << __FILE__ << ":" << __LINE__ << " " << __FUNCTION__ << "() " << "Das ist eine wichige Nachricht" << eol;
	cdebug << LessImportant << "Diese Nachricht ist weniger wichtig" << eol;
	cdebug << Important << "Auch diese Nachricht ist wichtig:" << LessImportant << debug::dec << 267 << "=" << debug::oct << "0" << 267 << "=" << debug::hex << "0x" << 267 << debug::dec << eol;
}

