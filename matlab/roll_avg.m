function avg = roll_avg(input,N,alpha)
prev = input(1);
output = zeros(N,1);
output(1) = input(1);
for i=2:N,
    output(i) = alpha*(input(i))+(1-alpha)*prev;
    prev = output(i-1);
end
avg = output;
end