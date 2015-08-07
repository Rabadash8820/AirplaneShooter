#pragma once

#ifdef LUAPARSER_EXPORTS
#define LUA_PARSER_API __declspec(dllexport)
#else
#define LUA_PARSER_API __declspec(dllimport)
#endif
