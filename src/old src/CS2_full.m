function nu_dot = CS2_full(Nu,tau)
X_u		= -2.332;		
X_uu 	= 0;		
X_uuu	= -8.557;

Y_v		= -4.673;            	
Y_vv	= -0.3976;
Y_vvv   = 313.3;
% 
 Y_r		= 0.0; % Y_r
 Y_rr	= 0.0; % Y_rr
% 
% Y_rv	= -0.0;			
 Y_rrr	= 0.0; % Y_rv, Y_vr


N_v		= 0.0;		
N_vv	= 0.0; 
N_vvv   = 0.0;

N_r		= -0.01675; % N_r      	
N_rr	= -0.01148; % N_rr
N_rrr   = 9.0003578;

%N_rv	= 0.0;			
%N_vr	= 0.0; % N_rv, N_vr

X_ud =     3.262;											% Table B.1
Y_vd =     28.89;		% Table B.1
Y_rd =     0.525;		% Table B.1
N_vd =      0.157;	
N_rd =     13.98;

%Nur  =     -Y_rd;


u   = Nu(1);
v   = Nu(2);
r   = Nu(3);



d_11 = X_u +X_uu*abs(u)+X_uuu*u^2;
d_22 = Y_v + Y_vv*abs(v) + Y_vvv*v^2;
d_33 = N_r + N_rr*abs(r) + N_rrr*r^2;

d_23 = Y_r + Y_rr*abs(r) + Y_rrr*r^2;
d_32 = N_v + N_vv*abs(v) + N_vvv*v^2;



D    = [d_11 0 0
        0    d_22 d_23
        0    d_32 d_33];


CA=[0 0 Y_vd*v+0.5*(N_vd+Y_rd)*r;
    0 0 -X_ud*u;
    -Y_vd*v-0.5*(N_vd+Y_rd)*r X_ud*u 0];

x_g     =  0.0375; % Table B.1
m       = 127.92;

CRB=[0 0 -m*(x_g*r+v);
     0 0 m*u;
     m*(x_g*r+v) -m*u    0]; 
C=CRB+CA;
    
I_z     = 61.987;


        M_RB_c=[m     0      0;
          0     m      m*x_g;
          0     m*x_g  I_z];
    M_A_c=[-X_ud    0          0;
            0          -Y_vd  -Y_rd;
            0          -N_vd  -N_rd];     
    M=M_RB_c-M_A_c;


    
    nu_dot =M\(tau-D*Nu-C*Nu);


end

