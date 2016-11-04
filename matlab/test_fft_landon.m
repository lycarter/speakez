%Load File
file_n = '2_female_nomask_clipped.wav';
file_y = '3_female_mask_clipped.wav';

[y_n,Fs_n] = audioread(file_n);
[y_y,Fs_y] = audioread(file_y);

L=min(length(y_n),length(y_y));     %Make files same length
y_n = y_n(1:L); y_y = y_y(1:L);

dt = 1/Fs_n;                        %time step
Nn = length(y_n);
Ny = length(y_y);

n_fft = abs(fft(y_n,Nn));
%n_fft = roll_avg(n_fft,Nn,0.005)*dt;
n_fft = tsmovavg(n_fft.', 's', 1000);
y_fft = abs(fft(y_y,Ny));
%y_fft = roll_avg(y_fft,Ny,0.005)*dt;
y_fft = tsmovavg(y_fft.', 's', 1000);

t_n = dt*(1:Nn/2);
t_y = dt*(1:Ny/2);

f_n = Fs_n*(0:Nn/2-1)/Nn;
f_y = Fs_y*(0:Ny/2-1)/Ny;

figure(1)
plot(f_n.',n_fft(1:Nn/2),f_y.',y_fft(1:Ny/2))
grid on;
axis([0 5000 0 700]);

figure(2)
%loglog(f_n,n_fft(1:Nn/2))
loglog(f_y,y_fft(1:Ny/2)./n_fft(1:Ny/2))
grid on;

%xlim([0 5000])



% 
% Nsamps_n = length(y_n);             %Prepare time data for plot
% t_n = (1/Fs_n)*(1:Nsamps_n);          
% Nsamps_y = length(y_y);
% t_y = (1/Fs_y)*(1:Nsamps_y);
% 
% %Do Fourier Transform
% y_fft_n = abs(fft(y_n));            %Retain Magnitude
% y_fft_n = y_fft_n(1:Nsamps_n/2);      %Discard Half of Points
% f_n = Fs_n*(0:Nsamps_n/2-1)/Nsamps_n;   %Prepare freq data for plot
% 
% y_fft_y = abs(fft(y_y));            %Retain Magnitude
% y_fft_y = y_fft_y(1:Nsamps_y/2);      %Discard Half of Points
% f_y = Fs_y*(0:Nsamps_y/2-1)/Nsamps_y;   %Prepare freq data for plot

%Plot Sound File in Time Domain
% figure
% plot(t_n, y_n)
% xlabel('Time (s)')
% ylabel('Amplitude')
% title('Female No Mask')
% 
% figure
% plot(t_y, y_y)
% xlabel('Time (s)')
% ylabel('Amplitude')
% title('Female With Mask')

%Plot Sound File in Frequency Domain
% figure
% plot(f_n, y_fft_n)
% xlim([0 5000])
% xlabel('Frequency (Hz)')
% ylabel('Amplitude')
% title('Female No Mask')
% 
% figure
% plot(f_y, y_fft_y)
% xlim([0 5000])
% xlabel('Frequency (Hz)')
% ylabel('Amplitude')
% title('Female With Mask')
% 
% figure
% div = y_fft_n./y_fft_y;
% loglog(f_y,div)
% xlim([0 5000])
% xlabel('Frequency (Hz)')
% ylabel('Amplitude')
% title('No Mask/Mask')