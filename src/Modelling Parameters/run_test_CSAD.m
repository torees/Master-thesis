
yaw_test = 0.6387;
Tau_test = [0;  0; yaw_test];
sim('test_CSAD')

plot(rad2deg(Nu(:,3)))
grid on;
rad2deg(Nu(end,3))