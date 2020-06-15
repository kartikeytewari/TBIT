b = dlmread("brute.txt", " ");
n = b(:,1);
brute = b(:, 2);
plot(n,brute,";brute force;");

hold on

s = dlmread("seg.txt");
n = s(:,1);
seg = s(:, 2);
plot(n,seg,";segment tree;");

f = dlmread("fen.txt", " ");
n = f(:,1);
fen = f(:, 2);
plot(n,fen,";fenwick tree;");

hold off

title('Time Comlexity of diffrent codes');
legend("location","northwest");
