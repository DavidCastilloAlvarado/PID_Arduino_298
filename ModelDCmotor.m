clc
clear all
close all
%% PC 3 - Avión -  LQR para el integrador
% Autor: Castillo Alvarado, David
% Código: 
% fecha: ENE 2018
%% Calculo de la ganancia para el efecto integrador + controlador
%% Control del angulo de elevación de un Avión 
%num=[118.16];
%den=[1 4.7676 1.516005];

%num=[42.46];
%den=[0.0754 0.6782 1];

%num=[33.44];
%den=[0.1106 0.5778 1];

num=[0                   0                   56.462491251101589];
den=[1.000000000000000   2.794767194634439   5.577706235274729];

F=tf(num,den);
FF=ss(F);
[A,B,C,D]=ssdata(FF);
%A=[-4.76765 -1.516005;
%   1               0];
%B=[8 ;0];
%C=[0 14.77];
%D=0;


x0_ob=[0 0 ];

%% Matrices aumentadas
Aa=[A  zeros(2,1); C  0];
Ba=[B;0];
Ca=[C 0];

%% Detectando polos y ceros 
GG=ss(Aa,Ba,Ca,0);
%Hallando polos y ceros
[z, p, k]=zpkdata(GG,'v');

%% Matriz de peso Q y R
% alpha   = angulo de ataque del avión
% tetha.p = velocidad angular del angulo de elevación
% tetha   = angulo de elevación con respecto a la horizontal
% Considerando varios casos de pesos para q33
% Considerando varios casos de pesos para R
% q33 y  RR deben ser de la misma dimensión
q22= [1 ]; 
RR = [0   ];    

nn=size(q22,2);

% Cantidad de muestras a tomar en 80 segundos
TD=600;
%%
for i=1:nn

%% Armando la leyenda
    leyend1=strcat('Test=',num2str(q22(i)));
    leyend2=strcat(' R=',num2str(RR(i)));
    leyend =strcat(leyend1,leyend2);
    leyenda{i}=leyend;
    
%% Simulación Simulink
sim('TestLQR3');
% Almacenando resultados
x1_k(:,i)=x1(1:TD,1);
x2_k(:,i)=x2(1:TD,1);

x_k(:,1:2,i)=x(1:TD,1:2);
u_k(:,i)=u(1:TD,1);

end

%% Igualando muestras para el tiempo, 
t=t(1:TD);
%% Sub plot
figure(1)

%% Posición Angular para diversos controladores LQR
subplot(2,2,1)
plot(t,x2_k,'LineWidth',2);
legend(leyenda);
title('Posición Angular Y');
grid
xlabel('x(t)')
ylabel('y(rad)')
%axis([5 25 0.2 0.32])
%%
subplot(2,2,2)
% todos los estados
plot(t,x_k(:,1:2,nn),'LineWidth',2)
legend('x1','x2','x3');
title(leyenda(nn));
grid
xlabel('x(t)')
ylabel('y(rad)')
%axis([0 50 -0.5 1.5])
%%
subplot(2,2,3)
% grafica el esfuerzo óptimo de control
plot(t,u_k,'LineWidth',2)
legend(leyenda);
title('Esfuerzos de Control U');
grid
xlabel('x(t)')
ylabel('y(rad)')
%axis([0 20 -0.1 .3])
%% Posición Angular para diversos controladores LQR -Stados observados
%subplot(2,2,4)
%plot(t,x3_obk,'LineWidth',2);
%legend(leyenda);
%title('Posición Angular X3 para diversos controladores LQR + Observador');
%grid
%xlabel('x(t)')
%ylabel('y(rad)')
%axis([5 30 0.2 0.35])


