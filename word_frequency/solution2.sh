while read line
do
    for word in $(echo $line);
    do
        echo $word $(grep -o $word words.txt | wc -w)
    done
done < words.txt | sort -rnk2 | uniq
