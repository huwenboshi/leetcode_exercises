for line in $(cat words.txt | sed 's/ /\n/g' | grep -e '[a-z]'* | sort | uniq);
do
    echo $line $(grep -o $line words.txt | wc -w)
done | sort -rnk2
