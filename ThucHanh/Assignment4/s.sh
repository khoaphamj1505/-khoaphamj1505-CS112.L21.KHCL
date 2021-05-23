    for(( i = 1; i <= 1000 ; i++)); do
        echo $i
        ./gen $i > in
        python3 SuaHangRao.py < in > out2;
        ./brute < in > out1
        diff -w out1 out2 || break

done
