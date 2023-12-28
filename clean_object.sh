object_files=$(find . -type f ! -name "*.*" ! -path '*/.git/*')
echo "${object_files}" | while read line; do
    echo Removing: $line
    rm $line
done