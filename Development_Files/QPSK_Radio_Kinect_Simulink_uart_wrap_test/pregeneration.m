clc;
clear all;
PAD_BITS = 24;
sentTrain = 0;
count = 0;
padding_I = zeros(1,25);
padding_Q = zeros(1,25);
t_i = TB_i;
t_q = TB_q;
for sentTrain=1:25
diLatch = mod(sentTrain,2)*2-1;
dqLatch = mod(sentTrain,2)*2-1;
padding_I(sentTrain)=  diLatch;
padding_Q(sentTrain)= dqLatch;
padding_complex(sentTrain)= complex(diLatch,dqLatch);
end

I=[padding_I t_i'];
Q=[padding_Q t_q'];