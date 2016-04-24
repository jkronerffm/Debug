/*
 * Debug.h
 *
 *  Created on: 20.04.2016
 *      Author: Jörg
 */

#ifndef DEBUG_H_
#define DEBUG_H_
#include <iostream>
#include <cstring>
#include <stdarg.h>

using namespace std;

namespace debug {
enum manip {
	endl, eol, hex, dec, oct
};
enum Level {
	Exception, Error, Important, Warning, LessImportant, Information
};
class Debug {
public:
private:
	Level _level;
	ostream* _out;
	Level _currentLevel;
public:
	Debug();
	Debug(ostream& out);
	virtual ~Debug();
	const Level& getLevel() const {
		return _level;
	}
	void setLevel(Level value) {
		_level = value;
	}

	void setLevel(int value) {
		setLevel(Level(value));
	}
	bool isAbove(const Level& value) {
		return value > _level;
	}
	const ostream& Out() const {
		return *_out;
	}
	void Out(ostream& out) {
		_out = &out;
	}
	void Print(const Level& level) {
		if (isAbove(level))
			return;
		if (_out == nullptr)
			return;
		if (!(*_out))
			return;

		(*_out) << std::endl;
	}

	template<typename T, typename ...Args>
	void Print(const Level &level, T t, Args&&... args) {
		if (isAbove(level))
			return;
		if (_out == nullptr)
			return;
		if (!(*_out))
			return;

		(*_out) << t;
		Print(level, args...);
	}

	void Printf(const Level& level, const char* format, ...) {
		if (isAbove(level)) return;
		if (_out == nullptr) return;
		if (!(_out)) return;

		va_list vl;
		va_start(vl, format);
		char buffer[1024];
		memset(buffer, 0, 1024);
		vsnprintf(buffer, 1024, format, vl);
		va_end(vl);
		(*_out) << buffer;
	}
	template<typename T>
	Debug& operator <<(const T &t) {
		if (_currentLevel > _level)
			return *this;
		if (_out == nullptr)
			return *this;
		if (!(*_out))
			return *this;
		(*_out) << t;
		return *this;
	}

	Debug& operator <<(const Level& level) {
		_currentLevel = level;
		return *this;
	}

	Debug& operator <<(const manip& manipulator) {
		if (_currentLevel > _level)
			return *this;
		if (_out == nullptr)
			return *this;
		if (!(*_out))
			return *this;

		switch (manipulator) {
		case debug::eol:
		case debug::endl:
			(*_out) << std::endl;
			break;
		case debug::hex:
			_out->setf(std::ios_base::hex, std::ios_base::basefield);
			break;
		case debug::dec:
			_out->setf(std::ios::dec, std::ios_base::basefield);
			break;
		case debug::oct:
			_out->setf(std::ios::oct, std::ios_base::basefield);
			break;
		default:
			break;
		}
		return *this;
	}

};
extern Debug cdebug;
}

#endif /* DEBUG_H_ */
