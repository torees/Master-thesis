function nu_dot = CSAD_full(Nu,tau,gamma,sigma)
X_u		= -5.1;		
X_uu 	=  0;		
X_uuu	= -18.6312;

Y_v		= -10.16;   
Y_vv	= -0.8647;
Y_vvv	= -665.1745;	

Y_r		= -6.25;
Y_rr	= -3.65;
Y_rrr   = 0;

N_v		= 0;		
N_vv	= -0.2388;
N_vvv = 0;

N_r		= -14.55;
N_rr	= -9.9597;
N_rrr	= -0.3101;

N_rv	= 0.08;	
N_vr	= 0.08;
Y_rv	= -0.805;			
Y_vr	= -0.845;

X_ud =     -10;
Y_vd =     -105;
Y_rd =     -0.525;
N_vd =     -0.157;	
N_rd =     -3.4950;

Nur  = -Y_rd;
Nuv  = -(Y_vd-X_ud);
Yur  = -X_ud;

x_g     = 0.0375;
m       = 127.92;
I_z     = 61.967;

u   = Nu(1);
v   = Nu(2);
r   = Nu(3);

d_11 = - X_u - X_uu*abs(u) - X_uuu*u^2;
d_22 = - Y_v - Y_vv*abs(v) - Y_rv*abs(r) - Y_vvv*v^2;
d_23 = - Y_r - Y_rr*abs(r) - Y_vr*abs(v) - Y_rrr*r^2 - Yur*u;
d_32 = - N_v - N_vv*abs(v) - N_rv*abs(r) - N_vvv*v^2 - Nuv*u;
d_33 = - N_r - N_rr*abs(r) - N_vr*abs(v) - N_rrr*r^2 - Nur*u;

D    = [d_11  0     0
        0     d_22  d_23
        0     d_32  d_33];

CA=[0                            0          Y_vd*v+Y_rd*r;
    0                            0                -X_ud*u;
    -Y_rd*r-Y_vd*v               X_ud*u                0];

CRB=[0             0     -m*(x_g*r+v);
     0             0      m*u;
     m*(x_g*r+v) -m*u     0]; 

C=CRB+CA;

M_RB_c=[m     0      0;
        0     m      m*x_g;
        0     m*x_g  I_z];

M_A_c=[-X_ud    0      0;
         0    -Y_vd  -Y_rd;
         0    -N_vd  -N_rd];     
    
M = M_RB_c + M_A_c;



M = M*gamma;
C = C*gamma;
D = D*sigma;

nu_dot = M\(tau-  C*Nu - D*Nu);
end

