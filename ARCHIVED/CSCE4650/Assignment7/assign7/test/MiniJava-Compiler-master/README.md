The easiest way to build the project is with the provided Makefile on a linux environment.  Simply running make should build everything for you.

The easiest way to run is to place your code in the "samples" subfolder and then execute the following command (where "TinyJavaFile.java" is the file you wish to compile and resides in the "samples" folder):

make run file=TinyJavaFile.java

To run the compiler, generically, you could manually execute the following command (where "TinyJavaFile.java" is the file you wish to compile):

java -cp ./tools/java-cup-11a.jar:. TinyJavaCompiler TinyJavaFile.java