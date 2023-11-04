sed -n "10p" file.txt

# another method
awk "NR==10{print}" file.txt