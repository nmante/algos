file=$1
dir=$2
headerdir=include/$dir
srcdir=src/$dir
header=$headerdir/$file.hpp
source=$srcdir/$file.cpp

mkdir -p $headerdir
mkdir -p $srcdir
touch $header 
touch $source 

upper=`echo "$file" | tr [a-z] [A-Z]`

echo "#ifndef __$upper"'_'"HPP__" >> $header
echo "#define __$upper"'_'"HPP__" >> $header
echo "" >> $header
echo "namespace algos {" >> $header
echo "namespace $file {" >> $header
echo "" >> $header
echo "}" >> $header
echo "}" >> $header
echo "#endif // __$upper"'_'"HPP__" >> $header

# Update source file
echo '#include "../../'$header'"' >> $source
echo "#include <iostream>" >> $source

# Update include/algos.hpp
algos=include/algos.hpp

cp $algos $algos.tmp
sed '$d' $algos.tmp > $algos 
sed '$d' $algos.tmp > $algos 
rm -f $algos.tmp
echo '#include "'$dir"/"$file".hpp"'"' >> $algos 
echo "" >> $algos
echo '#endif // __ALGOS_HPP__' >> $algos


