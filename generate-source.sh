file=$1
header=include/$file.hpp
source=src/$file.cpp

touch $header 
touch $source 

upper=`echo "$file" | tr [a-z] [A-Z]`

echo "#ifndef __$upper""HPP__" >> $header
echo "#define __$upper""HPP__" >> $header
echo "" >> $header
echo "namespace algos {" >> $header
echo "namespace $file {" >> $header
echo "" >> $header
echo "}" >> $header
echo "}" >> $header
echo "#endif // __$upper""HPP__" >> $header


echo "#include ../$header" >> $source
echo "#include <iostream>" >> $source
