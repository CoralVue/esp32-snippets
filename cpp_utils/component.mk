#
# Main component makefile.
#
# This Makefile can be left empty. By default, it will take the sources in the 
# src/ directory, compile them and link them into lib(subdirectory_name).a 
# in the build directory. This behaviour is entirely configurable,
# please read the ESP-IDF documents if you need to do this.

COMPONENT_ADD_INCLUDEDIRS += .
COMPONENT_PRIV_INCLUDEDIRS += .

## Uncomment the following line to enable exception handling 
#CXXFLAGS+=-fexceptions
#CXXFLAGS+= -std=c++11
#COMPONENT_PRIV_INCLUDEDIRS += ../../../../../../../SysGCC/esp32/usr/xtensa-esp32-elf/include/c++/5.2.0 ../../../../../../../SysGCC/esp32/usr/xtensa-esp32-elf/include/c++/5.2.0/xtensa-esp32-elf