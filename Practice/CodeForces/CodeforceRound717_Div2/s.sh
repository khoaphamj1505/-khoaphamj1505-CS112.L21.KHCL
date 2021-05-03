    for(( i = 1; i <= 10000 ; i++)); do
        echo $i
        ./gen $i > in
        ./b < in > out2;
        python3 brute.py < in > out1
        diff -w out1 out2 || break

done
