/// @file
/// @version 2.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause
/// 
/// @section DESCRIPTION
/// 
/// Defines macros for DLL exports/imports.

#ifndef THEORAPLAYER_EXPORT_H
#define THEORAPLAYER_EXPORT_H

	#ifdef _LIB
		#define theoraplayerExport
		#define theoraplayerFnExport
	#else
		#ifdef _WIN32
			#ifdef THEORAPLAYER_EXPORTS
				#define theoraplayerExport __declspec(dllexport)
				#define theoraplayerFnExport __declspec(dllexport)
			#else
				#define theoraplayerExport __declspec(dllimport)
				#define theoraplayerFnExport __declspec(dllimport)
			#endif
		#else
			#define theoraplayerExport __attribute__ ((visibility("default")))
			#define theoraplayerFnExport __attribute__ ((visibility("default")))
		#endif
	#endif
	#ifndef DEPRECATED_ATTRIBUTE
		#ifdef _MSC_VER
			#define DEPRECATED_ATTRIBUTE(message) __declspec(deprecated(message))
		#elif !defined(__APPLE__) || __has_extension(attribute_deprecated_with_message) || (defined(__GNUC) && ((GNUC >= 5) || ((GNUC == 4) && (GNUC_MINOR__ >= 5))))
			#define DEPRECATED_ATTRIBUTE(message) __attribute__((deprecated(message)))
		#else
			#define DEPRECATED_ATTRIBUTE(message) __attribute__((deprecated))
		#endif
	#endif

#endif

