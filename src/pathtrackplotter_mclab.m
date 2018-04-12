function pathtrackplotter_mclab(eta, tsamp, dec,color1,color2)

eta_plot = eta';

x = eta_plot(:,1);
y = eta_plot(:,2);
psi = eta_plot(:,3);

plot(y,x,color2,'LineWidth',1.5)
L=200/6;
tnow=0;

for now=1:dec:length(x)
   
    R = [cos(psi(now)) -sin(psi(now)); sin(psi(now)) cos(psi(now))];
    boat = R/50*[6*L/9 5*L/9 3*L/9 -5*L/9 -5*L/9 3*L/9 5*L/9 6*L/9;
                0 1*L/9 2*L/9 2*L/9 -2*L/9 -2*L/9 -1*L/9 0];

    plot(y(now)+boat(2,:),x(now)+boat(1,:),color1,'LineWidth',1.5)
    
    tnow=tnow+tsamp*dec;

end
end