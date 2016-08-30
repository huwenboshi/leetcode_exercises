nline=$(wc -l file.txt | awk '{print $1}')
if [ $nline -ge 10 ]; then
    head -n 10 file.txt | tail -n 1
fi
