clc
num=[0                   0                   56.462491251101589];
den=[1.000000000000000   2.794767194634439   5.577706235274729];
F=tf(num,den);
% fORMA MODAL OBSERVABLE 
A=[ 0 1;
    -den(3) -den(2)];
b=[0;1];
c=[num(3) 0];
A=transpose(A);
B=transpose(c);
C=transpose(b);

FF=ss(F);
[A,B,C,D]=ssdata(FF);
A
B
C
D
