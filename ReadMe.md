# Lab 4

1) A registry is a collection of files that will be used for building a project.

2) A package can be a framework, library, etc that provides utility to a project but, obviously, must first be installed.

3) An interface library allows for files that don't need to be compiled immediately. Ie, Verilog has no 'runtime', so there's no way for it to be compiled and run, so we instead use an interface library to include it without compiling it. This could also be useful for header files that involve templated classes, like in C++. Since they aren't compiled until they're assigned a type, they could be kept in the library without compilation.

4) The top module is the "master" CML file that assembles together all the small CML files in the subdirectories.