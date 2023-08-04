#!/bin/bash

# Collect all the .c files in the current directory
c_files=$(ls *.c 2>/dev/null)

if [ -z "$c_files" ]; then
  echo "No .c files found in the current directory."
  exit 1
fi

# Compile each .c file into .o object files
object_files=""
for c_file in $c_files; do
  object_file="${c_file%.c}.o"
  gcc -c "$c_file" -o "$object_file"
  object_files+=" $object_file"
done

# Create the static library using ar
ar rcs liball.a $object_files

# Clean up the temporary object files
rm -f $object_files

echo "Static library liball.a created successfully."
