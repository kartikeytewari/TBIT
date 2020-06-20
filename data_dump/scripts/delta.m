brute=dlmread("../data/brute_delta.txt"," ");
seg_tree=dlmread("../data/segment_delta.txt"," ");
fen_tree=dlmread("../data/fenwick_delta.txt"," ");

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

title("Deviation of different algorithms from theoretical Time Complexity");
legend("location","northwest");
