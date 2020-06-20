brute=dlmread("../data/brute_100_dw.txt"," ");
seg_tree=dlmread("../data/seg_tree_100_dw.txt"," ");
fen_tree=dlmread("../data/fen_tree_100_dw.txt"," ");

n=brute(:,1);
time_brute=brute(:,2);
plot(n,time_brute,";brute force algorithm;");

hold on
n=seg_tree(:,1);
time_seg=seg_tree(:,2);
plot(n,time_seg,";segment tree;");

n=fen_tree(:,1);
time_fen=fen_tree(:,2);
plot(n,time_fen,";TBIT;");
hold off

title("Time Complexity of different algorithms (query is 100% of n)");
legend("location","northwest");
