function [tau,phi_dot_hat]  = Immersion(tau,Eta_t, Eta_t_dot,Eta_t_ddot, Eta, Nu,model,phi_hat)

M = model(1:3,1:3);
C = model(1:3,4:6);
D = model(1:3,7:9);

K1 = diag([0.05, 0.05, 0.22]/10);
K2 = diag([12, 7, 10]*3);%diag([5, 7, 15]);
Gamma= diag([8, 4, 8, 8, 8, 4, 8, 8,0.4,0.4,0.4]);

psi = Eta(3);
r = Nu(3);
v=Nu(2);

S = [0 -r  0; r  0  0; 0  0  0];
S_T = S';
R = [cos(psi) -sin(psi) 0; sin(psi) cos(psi) 0; 0 0 1];
R_T = R';


z_1 = R_T*(Eta-Eta_t);


alpha = R_T*Eta_t_dot - K1*z_1;

z_2 = Nu - alpha;
z_1_dot = S_T * z_1 - K1 * z_1 + z_2;
alpha_dot = R_T*Eta_t_ddot + S_T*R_T*Eta_t_dot - K1*z_1_dot;

Phi = [0 0 0 0 0 0 0 0; abs(r)*v r abs(v)*r abs(r)*r 0 0 0 0; 0 0 0 0 abs(r)*v r abs(v)*r abs(r)*r];
Phi = [Phi R_T];
phi_dot_hat = -Gamma* Phi' * ( tau- C*Nu - D*Nu  +  Phi*(phi_hat + Gamma*Phi'*z_2)- M*alpha_dot);

tau = -K2*z_2 - z_1 + C*Nu - D*Nu  +  Phi*(phi_hat + Gamma*Phi'*z_2)- M*alpha_dot;

end