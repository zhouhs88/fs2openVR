
IF(WIN32)
	IF(IS_64BIT)
		# 64-bit
		set(ARCH "x64")
	ELSE()
		# 32-bit
		set(ARCH "x86")
	ENDIF()

	add_library(sdlmain INTERFACE)
	IF(MSVC)
		add_library(sdl SHARED IMPORTED GLOBAL)
		set_target_properties(sdl
			PROPERTIES
				IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/${ARCH}/SDL2.dll"
				IMPORTED_IMPLIB "${CMAKE_CURRENT_SOURCE_DIR}/lib/${ARCH}/SDL2.lib"
		)
		target_link_libraries(sdlmain INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/lib/${ARCH}/SDL2main.lib")
	ELSE(MSVC) #MINGW
		add_library(sdl INTERFACE)
		target_link_libraries(sdl INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/lib/${ARCH}/SDL2.dll")
		target_link_libraries(sdlmain INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/lib/${ARCH}/SDL2main.a")
	ENDIF(MSVC)
	set_target_properties(sdl PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include")

	add_target_copy_files("${CMAKE_CURRENT_SOURCE_DIR}/lib/${ARCH}/SDL2.dll")
	INSTALL(FILES "${CMAKE_CURRENT_SOURCE_DIR}/README-SDL.txt"
			DESTINATION ${BINARY_DESTINATION}
	)

	SET(SDL_LIBS sdl CACHE INTERNAL "")
ELSE(WIN32)
	# CMake can't check for SDL2 so we'll just use PkgConfig
	find_package(PkgConfig)
	INCLUDE(util)

	IF(APPLE)
		PKG_SEARCH_MODULE(SDL2 sdl2)

		IF(NOT SDL2_FOUND)
			SET(FSO_USE_SDL_FRAMEWORK ON) # We ship these for mac
		ENDIF(NOT SDL2_FOUND)
	ELSE(APPLE)
		PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
	ENDIF(APPLE)

	IF(FSO_USE_SDL_FRAMEWORK)
		find_library(SDL2_LIBRARY SDL2 PATHS "${FSO_MAC_FRAMEWORKS}")

		add_library(sdl INTERFACE)
		target_link_libraries(sdl INTERFACE ${SDL2_LIBRARY})
		target_include_directories(sdl INTERFACE ${SDL2_LIBRARY}/Headers)
	ELSE(FSO_USE_SDL_FRAMEWORK)
		PKG_CONFIG_LIB_RESOLVE(SDL2 SDL2_LIB)
		ADD_IMPORTED_LIB(sdl "${SDL2_INCLUDE_DIRS}" "${SDL2_LIB}")
	ENDIF(FSO_USE_SDL_FRAMEWORK)

	SET(SDL_LIBS sdl CACHE INTERNAL "")
ENDIF(WIN32)
