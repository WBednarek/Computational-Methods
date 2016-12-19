
expRichtmyer025=[0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
-1.61118e-313
-1.77324e-290
-2.53714e-268
-4.71925e-247
-1.14118e-226
-3.58747e-207
-1.46614e-188
-7.78955e-171
-5.38026e-154
-4.83111e-138
-5.63952e-123
-8.55835e-109
-1.68846e-95
-4.33055e-83
-1.44394e-71
-6.25902e-61
-3.52709e-51
-2.58392e-42
-2.4609e-34
-3.04692e-27
-4.90434e-21
-1.02625e-15
-2.79181e-11
-9.87466e-08
-4.54473e-05
-0.00273675
-0.0217463
0.0183293
0.386176
0.411036
0.0661032
0.00933926
0.0047643
0.00267883
0.00150684
0.000847598
0.000476774
0.000268185
0.000150854
8.48555e-05
4.77312e-05
2.68488e-05
1.51025e-05
8.49514e-06
4.77851e-06
2.68791e-06
1.51195e-06
8.50473e-07
4.78391e-07
2.69095e-07
1.51366e-07
8.51433e-08
4.78931e-08
2.69399e-08
1.51537e-08
8.52395e-09
4.79472e-09
2.69703e-09
1.51708e-09
8.53357e-10
4.80013e-10
2.70008e-10
1.51879e-10
8.54321e-11
4.80555e-11
2.70312e-11
1.52051e-11
8.55285e-12
4.81098e-12
2.70618e-12
1.52222e-12
8.56251e-13
4.81641e-13
2.70923e-13
1.52394e-13
8.57218e-14
4.82185e-14
3.96769e-14
0
]; 
expRichtmyer050=[]; 
expRichtmyer075=[]; 
expRichtmyer0999=[]; 
expRichtmyerPoints200=[]; 
expRichtmyerPoints400=[]; 
expRichtmyerTime10=[];


%% Different Courant numer

%  p = plot(x,analitycal); 
%   hold on
%  p1 = plot(x,expRichtmyer025 ); 
%  hold on
%  p2 = plot(x,expRichtmyer050);
%   hold on
%  p3 = plot(x,expRichtmyer075 );
%   hold on
%  p4 = plot(x,expRichtmyer0999);
% 
% xlabel('space[units]')
% ylabel('f(space. time)')
% title('Schemes compare results')
% legend('Analytical solution','Explicit Upwind Scheme', 'C =0.25' ,'C =0.5', 'C =0.75', 'C =0.999', 'C = 1.25', 'C =1.5', 'C =1.75', 'C =2' );
% %All C < 1
% legend('Analytical solution', 'C =0.25' ,'C =0.5', 'C =0.75', 'C =0.999');
% p(1).LineWidth = 2;
% p1(1).LineWidth = 2;
% p2(1).LineWidth = 2;
% p3(1).LineWidth = 2;
% p4(1).LineWidth = 2;
%% Different time

%  p = plot(x,expRichtmyer0999); 
%  hold on
%  p1 = plot(x,expRichtmyerTime10 );
%  hold on
%  xlabel('space[units]')
% ylabel('f(space. time)')
% title('Time compare results')
% legend('Time = 5', 'Time = 10');
% p(1).LineWidth = 2;
% p1(1).LineWidth = 2;

% figure
% waterfall(TimeAllTo10_2);

%% Different number of points

p3 = plot(x,analitycal );
hold on
p = plot(x, expRichtmyer0999); 
hold on
p1 = plot(x1,expRichtmyerPoints200);
hold on
p2 = plot(x3,expRichtmyerPoints400 );


xlabel('space[units]')
ylabel('f(space. time)')
title('Comparing results by number of points')
legend('Analytical solution', '100 points', '200 points', '400 points');
 p(1).LineWidth = 2;
 p1(1).LineWidth = 2;
 p2(1).LineWidth = 2;
 p3(1).LineWidth = 2;