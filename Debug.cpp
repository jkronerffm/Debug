/*
 * Debug.cpp
 *
 *  Created on: 20.04.2016
 *      Author: Jörg
 */

#include "Debug.h"

namespace debug {
Debug cdebug;

Debug::Debug() {
	_level = Warning;
	_out = nullptr;
	_currentLevel = Information;

}

Debug::Debug(ostream& out) {
	_level = Warning;
	Out(out);
	_currentLevel = Information;

}
Debug::~Debug() {
	// TODO Auto-generated destructor stub
}

Debug cDebug(std::cout);
}
