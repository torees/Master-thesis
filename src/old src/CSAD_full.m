function nu_dot = CS2_full(Nu,tau)
X_u		= -0.72253;		
X_uu 	= -1.32742;		
X_uuu	= -5.86643;

Y_v		= -0.88965;            	Y_r		= 0.1052; % Y_r
Y_vv	= -36.47287;			Y_rr	= -3.450; % Y_rr

Y_rv	= -0.805;			Y_vr	= -0.845; % Y_rv, Y_vr


N_v		= 0.03130;				N_r		= -1.900; % N_r
N_vv	= 3.95645;            	N_rr	= -0.750; % N_rr


N_rv	= 0.130;			N_vr	= 0.080; % N_rv, N_vr

X_ud =     -2;											% Table B.1
Y_vd =     -10;		% Table B.1
Y_rd =     -0;		% Table B.1
N_vd =      0;	
N_rd =     -1;

Nur  =     -Y_rd;


u   = Nu(1);
v   = Nu(2);
r   = Nu(3);

U = sqrt(u^2+v^2);
Nuv  =     -(Y_vd-X_ud);
Yur = -0;
d_11 = -X_u-X_uu*abs(u)-X_uuu*u^2;
d_22 = -Y_v - Y_vv*abs(v) - Y_rv*abs(r);
d_33 = -N_r - N_rr*abs(r) - N_vr*abs(v)-Nur*u;

d_23 = -Y_r - Y_rr*abs(r) - Y_vr*abs(v)-Yur*u;
d_32 = -N_v - N_vv*abs(v) - N_rv*abs(r)-Nuv*u;



D    = [d_11 0 0
        0    d_22 d_23
        0    d_32 d_33];

% 
% CA=[0 0 Y_vd*v+Y_rd*r;
%     0 0 -X_ud*u;
%    -Y_rd*r X_ud*u 0]; 
CA=[0 0 Y_vd*v+0.5*(N_vd+Y_rd)*r;
    0 0 -X_ud*u;
    -Y_vd*v-0.5*(N_vd+Y_rd)*r X_ud*u 0];

x_g     =  0.0460; % Table B.1
m       = 23.8000;

CRB=[0 0 -m*(x_g*r+v);
     0 0 m*u;
     m*(x_g*r+v) -m*u    0]; 
C=CRB+CA;
    
I_z     = 1.7600;


        M_RB_c=[m     0      0;
          0     m      m*x_g;
          0     m*x_g  I_z];
    M_A_c=[-X_ud    0          0;
            0          -Y_vd  -Y_rd;
            0          -N_vd  -N_rd];     
    M=M_RB_c+M_A_c;
nu_dot =M\(tau-D*Nu-C*Nu);


end

