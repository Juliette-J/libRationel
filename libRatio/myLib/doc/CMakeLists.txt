find_package (Doxygen)

message(VERBOSE "Doxigen settings :")
message(VERBOSE "Rational_SOURCE_DIR :  " ${Rational_SOURCE_DIR})
message(VERBOSE "Rational_BINARY_DIR :  " ${Rational_BINARY_DIR})
message(VERBOSE "Rational_EXECUTABLE :  " ${DOXYGEN_EXECUTABLE})

if(DOXYGEN_FOUND)
  configure_file (${Rational_SOURCE_DIR}/doc/Doxyfile-html.cmake ${Rational_BINARY_DIR}/doc/Doxyfile-html)
  add_custom_target (html ${DOXYGEN_EXECUTABLE} ${Rational_BINARY_DIR}/doc/Doxyfile-html)
endif (DOXYGEN_FOUND)