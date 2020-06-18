brute=dlmread("brute_40_dw.txt"," ");
seg_tree=dlmread("seg_tree_40_dw.txt"," ");
fen_tree=dlmread("fen_tree_40_dw.txt"," ");

n=brute(:,1);
time_brute=brute(:,2);
plot(n,time_brute,";brute force algorithm;");

hold on
n=seg_tree(:,1);
time_seg=seg_tree(:,2);
plot(n,time_seg,";segment tree;");

n=fen_tree(:,1);
time_fen=fen_tree(:,2);
plot(n,time_fen,";fenwick tree;");
hold off

title("Time Complexity of diffrent algorithms (query is 40% of n)");
legend("location","northwest");