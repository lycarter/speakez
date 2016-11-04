%Load file
%[y,Fs] = audioread('1_derp.wav');
%N = length(y);
%t = (1:N)/Fs;
%length(t)
%length(y)
%ts_y = [t' y];
%plot(t',y)
figure(1)
plot(input)
title('Input sound')
ylim([-0.8 0.8])
figure(2)
plot(outputhigh)
title('Upper range output')

ylim([-0.8 0.8])
%figure
%plot(outputlower)
figure(3)
plot(outputlow)
title('Lower range output')
ylim([-0.8 0.8])
%lowpassed
%audiowrite('derpout.wav',lowpassed.data,44100)
