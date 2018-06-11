mkdir cache
mkdir bin

echo "compiling Logger..."
javac -d ./bin -cp bin src/logger/*.java

echo "compiling Fetch..."
javac -d ./bin -cp bin src/fetch/*.java

echo "compiling Client..."
javac -d ./bin -cp bin src/Client.java

echo "compiling Server..."
javac -d ./bin -cp bin src/Server.java