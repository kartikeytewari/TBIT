for((i=1;i<=500;i++)); do
	echo $i
	./gen.out $i > input1.txt
	# ./brute.out < input1.txt >> brute_100.txt
	./seg_tree.out < input1.txt >> seg_tree_20.txt
	# diff -w <(./brute.out < input1.txt) <(./seg_tree.out < input1.txt)|| break
	# diff -w <(./brute.out < input1.txt) <(./fen_tree2.out < input1.txt)|| break
done