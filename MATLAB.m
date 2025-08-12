% AMPLITUDE MODULATION
Am = 1;       % Amplitude of message signal
Ac = 5;       % Amplitude of carrier signal
fm = 2;       % Frequency of message signal (Hz)
fc = 20;      % Frequency of carrier signal (Hz)

t = 0:0.0001:1;
m = Am * sin(2 * pi * fm * t);
c = Ac * sin(2 * pi * fc * t);
s = (1 + m / Am) .* c;

subplot(3,1,1);
plot(t, m);
title('Message Signal');

subplot(3,1,2);
plot(t, c);
title('Carrier Signal');

subplot(3,1,3);
plot(t, s);
title('Amplitude Modulated Signal');


% FREQUENCY MODULATION
Am = 1;       % Amplitude of message signal
Ac = 5;       % Amplitude of carrier signal
fm = 2;       % Frequency of message signal (Hz)
fc = 20;      % Frequency of carrier signal (Hz)
kf = 50;      % Frequency sensitivity

t = 0:0.0001:1;
m = Am * sin(2 * pi * fm * t);
c = Ac * sin(2 * pi * fc * t);
int_m = cumsum(m) * (t(2) - t(1));
s = Ac * cos(2 * pi * fc * t + 2 * pi * kf * int_m);

subplot(3,1,1);
plot(t, m);
title('Message Signal');

subplot(3,1,2);
plot(t, c);
title('Carrier Signal');

subplot(3,1,3);
plot(t, s);
title('Frequency Modulated Signal');


% PHASE MODULATION
Am = 1;       % Amplitude of message signal
Ac = 5;       % Amplitude of carrier signal
fm = 2;       % Frequency of message signal (Hz)
fc = 20;      % Frequency of carrier signal (Hz)
kp = pi/2;    % Phase sensitivity

t = 0:0.0001:1;
m = Am * sin(2 * pi * fm * t);
c = Ac * sin(2 * pi * fc * t);
s = Ac * cos(2 * pi * fc * t + kp * m);

subplot(3,1,1);
plot(t, m);
title('Message Signal');

subplot(3,1,2);
plot(t, c);
title('Carrier Signal');

subplot(3,1,3);
plot(t, s);
title('Phase Modulated Signal');


% ASK (Amplitude Shift Keying)
bit_seq = [1 0 1 1 0];
Ac = 5;
fc = 10;
bit_rate = 1; % bits per second

n = length(bit_seq);
t = 0:1/(bit_rate*100):n;
msg = zeros(1, length(t));
c = Ac * sin(2 * pi * fc * t);

for i = 1:n
    msg((t >= (i-1)) & (t < i)) = bit_seq(i);
end
s = msg .* c;

subplot(3,1,1);
plot(t, msg);
title('Message Signal');

subplot(3,1,2);
plot(t, c);
title('Carrier Signal');

subplot(3,1,3);
plot(t, s);
title('ASK Signal');


% FSK (Frequency Shift Keying)
bit_seq = [1 0 1 1 0];
Ac = 5;
f0 = 5;   % Frequency for binary 0 (Hz)
f1 = 15;  % Frequency for binary 1 (Hz)
bit_rate = 1; % bits per second

n = length(bit_seq);
t = 0:1/(bit_rate*100):n;
msg = zeros(1, length(t));
s = zeros(1, length(t));

for i = 1:n
    idx = (t >= (i-1)) & (t < i);
    msg(idx) = bit_seq(i);
    if bit_seq(i) == 1
        s(idx) = Ac * sin(2 * pi * f1 * t(idx));
    else
        s(idx) = Ac * sin(2 * pi * f0 * t(idx));
    end
end

c = Ac * sin(2 * pi * f1 * t);

subplot(3,1,1);
plot(t, msg);
title('Message Signal');

subplot(3,1,2);
plot(t, c);
title('Carrier Signal');

subplot(3,1,3);
plot(t, s);
title('FSK Signal');

% PSK (Phase Shift Keying)
bit_seq = [1 0 1 1 0];
Ac = 5;
fc = 10;
bit_rate = 1; % bits per second

n = length(bit_seq);
t = 0:1/(bit_rate*100):n;
msg = zeros(1, length(t));
s = zeros(1, length(t));

for i = 1:n
    idx = (t >= (i-1)) & (t < i);
    msg(idx) = bit_seq(i);
    if bit_seq(i) == 1
        s(idx) = Ac * sin(2 * pi * fc * t(idx));
    else
        s(idx) = Ac * sin(2 * pi * fc * t(idx) + pi);
    end
end

c = Ac * sin(2 * pi * fc * t);

subplot(3,1,1);
plot(t, msg);
title('Message Signal');

subplot(3,1,2);
plot(t, c);
title('Carrier Signal');

subplot(3,1,3);
plot(t, s);
title('PSK Signal');
