# all source files
set(SRC filedrop.cpp)

if(SFML_OS_IOS)
    set_source_files_properties(${RESOURCES} PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
endif()

# define the event_handling target
sfml_add_example(basic_filedrop GUI_APP
                 SOURCES ${SRC}
                 BUNDLE_RESOURCES ${RESOURCES}
                 DEPENDS SFML::Graphics)
