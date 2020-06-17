for((i=1;i<=1001;i++)); do
	echo s $i
	echo 20
	utility/small_gen_20 $i > utility/input1.txt
	brute/brute < utility/input1.txt >> brute/brute_20.txt
	seg_tree/seg_tree < utility/input1.txt >> seg_tree/seg_tree_20.txt
	fen_tree/fen_tree < utility/input1.txt >> fen_tree/fen_tree_20.txt

	echo 40
	utility/small_gen_40 $i > utility/input1.txt
	brute/brute < utility/input1.txt >> brute/brute_40.txt
	seg_tree/seg_tree < utility/input1.txt >> seg_tree/seg_tree_40.txt
	fen_tree/fen_tree < utility/input1.txt >> fen_tree/fen_tree_40.txt

	echo 60
	utility/small_gen_60 $i > utility/input1.txt
	brute/brute < utility/input1.txt >> brute/brute_60.txt
	seg_tree/seg_tree < utility/input1.txt >> seg_tree/seg_tree_60.txt
	fen_tree/fen_tree < utility/input1.txt >> fen_tree/fen_tree_60.txt

	echo 80
	utility/small_gen_80 $i > utility/input1.txt
	brute/brute < utility/input1.txt >> brute/brute_80.txt
	seg_tree/seg_tree < utility/input1.txt >> seg_tree/seg_tree_80.txt
	fen_tree/fen_tree < utility/input1.txt >> fen_tree/fen_tree_80.txt

	echo 100
	utility/small_gen_100 $i > utility/input1.txt
	brute/brute < utility/input1.txt >> brute/brute_100.txt
	seg_tree/seg_tree < utility/input1.txt >> seg_tree/seg_tree_100.txt
	fen_tree/fen_tree < utility/input1.txt >> fen_tree/fen_tree_100.txt
done

for((i=1;i<=1090;i++)); do
	echo b $i
	echo 20
	utility/big_gen_20 $i > utility/input1.txt
	seg_tree/seg_tree < utility/input1.txt >> seg_tree/seg_tree_20.txt
	fen_tree/fen_tree < utility/input1.txt >> fen_tree/fen_tree_20.txt

	echo 40
	utility/big_gen_40 $i > utility/input1.txt
	seg_tree/seg_tree < utility/input1.txt >> seg_tree/seg_tree_40.txt
	fen_tree/fen_tree < utility/input1.txt >> fen_tree/fen_tree_40.txt

	echo 60
	utility/big_gen_60 $i > utility/input1.txt
	seg_tree/seg_tree < utility/input1.txt >> seg_tree/seg_tree_60.txt
	fen_tree/fen_tree < utility/input1.txt >> fen_tree/fen_tree_60.txt

	echo 80
	utility/big_gen_80 $i > utility/input1.txt
	seg_tree/seg_tree < utility/input1.txt >> seg_tree/seg_tree_80.txt
	fen_tree/fen_tree < utility/input1.txt >> fen_tree/fen_tree_80.txt

	echo 100
	utility/big_gen_100 $i > utility/input1.txt
	seg_tree/seg_tree < utility/input1.txt >> seg_tree/seg_tree_100.txt
	fen_tree/fen_tree < utility/input1.txt >> fen_tree/fen_tree_100.txt
done