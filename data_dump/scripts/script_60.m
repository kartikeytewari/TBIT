brute=dlmread("../data/brute_60_dw.txt"," ");
seg_tree=dlmread("../data/seg_tree_60_dw.txt"," ");
fen_tree=dlmread("../data/fen_tree_60_dw.txt"," ");

n=brute(:,1);
time_brute=brute(:,2);
brute_val=plot(n,time_brute,";Brute Force algorithm;","linewidth", 2);

hold on
n=seg_tree(:,1);
time_seg=seg_tree(:,2);
seg_val=plot(n,time_seg,";Segment Tree;", "linewidth", 2);

n=fen_tree(:,1);
time_fen=fen_tree(:,2);
fen_val=plot(n,time_fen,";TBIT;", "linewidth", 2);
hold off

x_val=xlabel("Sum of update and query operations");
y_val=ylabel("Time in microseconds");
h=legend("location","northwest");
set(h,"fontsize",22);
set(x_val, "linewidth", 10, "fontsize", 22);
set(y_val, "linewidth", 10, "fontsize", 22);
set(gca, "linewidth", 6, "fontsize",22);
